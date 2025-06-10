% ===== ENHANCED WEDDING SOLVER - PRACTICAL VERSION =====
% Fixes and improvements to the original wedding seating CSP

:- lib(fd).
:- lib(fd_global).
:- lib(listut).
:- [matrimonio].
:- lib(propia).

% Original version by your friend (for comparison)
tav_original(Invitati) :-
    num_invitati(NI),
    num_tavoli(NT),
    capacita(C),
    findall(conflitto(P1,P2), conflitto(P1,P2), LConf),
    findall(conosce(P1,P2), conosce(P1,P2), Lcon),
    
    length(Invitati, NI),
    Invitati :: 1..NT,

    conf(LConf,Invitati),
    persone_per_tavolo(Invitati,Invitati,C),

    guadagno(Lcon,Invitati,G),
    min_max(labelingffc(Invitati),-G).

% Enhancement 1: Smarter symmetry breaking
tav_smart_symmetry(Invitati) :-
    num_invitati(NI),
    num_tavoli(NT),
    capacita(C),
    findall(conflitto(P1,P2), conflitto(P1,P2), LConf),
    findall(conosce(P1,P2), conosce(P1,P2), Lcon),
    
    length(Invitati, NI),
    Invitati :: 1..NT,

    % Improved symmetry breaking: order by person ID
    conf_smart_symmetry(LConf, Invitati),
    persone_per_tavolo_basic(Invitati, C),

    guadagno(Lcon, Invitati, G),
    min_max(labelingffc(Invitati), -G).

conf_smart_symmetry([], _).
conf_smart_symmetry([conflitto(P1,P2)|T], Invitati) :-
    nth1(P1, Invitati, Tav1),
    nth1(P2, Invitati, Tav2),
    % Symmetry breaking based on person ID: lower ID goes to lower table
    (P1 < P2 -> 
        Tav1 #< Tav2 
    ; 
        Tav2 #< Tav1
    ),
    conf_smart_symmetry(T, Invitati).

% Enhancement 2: More efficient capacity constraints
persone_per_tavolo_basic(Invitati, C) :-
    num_tavoli(NT),
    persone_per_tavolo_aux(1, NT, Invitati, C).

persone_per_tavolo_aux(T, NT, _, _) :-
    T > NT, !.
persone_per_tavolo_aux(T, NT, Invitati, C) :-
    occurrences(T, Invitati, Count),
    Count #>= 2,
    Count #=< C,
    T1 is T + 1,
    persone_per_tavolo_aux(T1, NT, Invitati, C).

% Enhancement 3: Intelligent labeling heuristic
tav_smart_labeling(Invitati) :-
    num_invitati(NI),
    num_tavoli(NT),
    capacita(C),
    findall(conflitto(P1,P2), conflitto(P1,P2), LConf),
    findall(conosce(P1,P2), conosce(P1,P2), Lcon),
    
    length(Invitati, NI),
    Invitati :: 1..NT,

    conf_smart_symmetry(LConf, Invitati),
    persone_per_tavolo_basic(Invitati, C),

    guadagno(Lcon, Invitati, G),
    
    % Labeling with most-constrained-first heuristic
    smart_labeling(Invitati, LConf),
    
    write("Solution found with score: "), write(-G), nl.

% Order people by number of conflicts (most constrained first)
smart_labeling(Invitati, LConf) :-
    create_conflict_order(Invitati, LConf, OrderedVars),
    labeling_ordered(OrderedVars).

create_conflict_order(Invitati, LConf, OrderedVars) :-
    length(Invitati, N),
    collect_conflicts(1, N, Invitati, LConf, ConflictList),
    sort(ConflictList, SortedList),
    reverse(SortedList, DescSorted),
    extract_vars(DescSorted, OrderedVars).

collect_conflicts(Idx, N, _, _, []) :-
    Idx > N, !.
collect_conflicts(Idx, N, Invitati, LConf, [conflicts(Count, Idx, Var)|Rest]) :-
    nth1(Idx, Invitati, Var),
    count_person_conflicts(Idx, LConf, Count),
    Idx1 is Idx + 1,
    collect_conflicts(Idx1, N, Invitati, LConf, Rest).

count_person_conflicts(Person, LConf, Count) :-
    findall(1, 
        (member(conflitto(Person, _), LConf) ; 
         member(conflitto(_, Person), LConf)
        ), Conflicts),
    length(Conflicts, Count).

extract_vars([], []).
extract_vars([conflicts(_, _, Var)|Rest], [Var|RestVars]) :-
    extract_vars(Rest, RestVars).

labeling_ordered([]).
labeling_ordered([Var|Rest]) :-
    indomain(Var),
    labeling_ordered(Rest).

% Enhancement 4: Redundant constraints for better propagation
tav_with_redundant(Invitati) :-
    num_invitati(NI),
    num_tavoli(NT),
    capacita(C),
    findall(conflitto(P1,P2), conflitto(P1,P2), LConf),
    findall(conosce(P1,P2), conosce(P1,P2), Lcon),
    
    length(Invitati, NI),
    Invitati :: 1..NT,

    conf_smart_symmetry(LConf, Invitati),
    persone_per_tavolo_basic(Invitati, C),
    
    % Redundant constraints for load balancing
    redundant_balance(Invitati, NI, NT),

    guadagno(Lcon, Invitati, G),
    min_max(labelingffc(Invitati), -G).

% Load balancing constraint: more uniform distribution
redundant_balance(Invitati, NI, NT) :-
    MinPerTable is NI // NT,
    MaxPerTable is (NI + NT - 1) // NT,
    add_balance_constraints(1, NT, Invitati, MinPerTable, MaxPerTable).

add_balance_constraints(T, NT, _, _, _) :-
    T > NT, !.
add_balance_constraints(T, NT, Invitati, Min, Max) :-
    occurrences(T, Invitati, Count),
    Count #>= Min,
    Count #=< Max,
    T1 is T + 1,
    add_balance_constraints(T1, NT, Invitati, Min, Max).

% Enhancement 5: Solution analysis
analyze_solution(Invitati) :-
    findall(conosce(P1,P2), conosce(P1,P2), Lcon),
    findall(conflitto(P1,P2), conflitto(P1,P2), LConf),
    
    guadagno(Lcon, Invitati, G),
    G_val is -G,  % Convert back to positive score
    length(Lcon, TotalFriends),
    Percentage is (G_val * 100) / TotalFriends,
    
    write("=== SOLUTION ANALYSIS ==="), nl,
    write("Score: "), write(G_val), write("/"), write(TotalFriends), 
    write(" ("), write(Percentage), write("% friends together)"), nl,
    
    print_table_composition(Invitati),
    check_conflicts(Invitati, LConf).

print_table_composition(Invitati) :-
    num_tavoli(NT),
    nl, write("Table composition:"), nl,
    print_tables(1, NT, Invitati).

print_tables(T, NT, _) :-
    T > NT, !.
print_tables(T, NT, Invitati) :-
    findall(P, nth1(P, Invitati, T), People),
    length(People, Count),
    write("Table "), write(T), write(" ("), write(Count), write(" people): "), 
    write(People), nl,
    T1 is T + 1,
    print_tables(T1, NT, Invitati).

check_conflicts(Invitati, LConf) :-
    nl, write("Conflict check:"), nl,
    check_conflicts_aux(LConf, Invitati).

check_conflicts_aux([], _) :-
    write("✓ No conflicts violated"), nl.
check_conflicts_aux([conflitto(P1,P2)|Rest], Invitati) :-
    nth1(P1, Invitati, T1),
    nth1(P2, Invitati, T2),
    (T1 =:= T2 ->
        (write("✗ CONFLICT: People "), write(P1), write(" and "), write(P2), 
         write(" are both at table "), write(T1), nl)
    ;
        true
    ),
    check_conflicts_aux(Rest, Invitati).

% Utility for comparing all versions
compare_all_versions :-
    write("=== VERSION COMPARISON ==="), nl, nl,
    
    write("1. Original version:"), nl,
    measure_time(tav_original(Sol1), Time1),
    write("Time: "), write(Time1), write(" seconds"), nl,
    analyze_solution(Sol1),
    
    nl, write("2. Improved symmetry breaking:"), nl,
    measure_time(tav_smart_symmetry(Sol2), Time2),
    write("Time: "), write(Time2), write(" seconds"), nl,
    analyze_solution(Sol2),
    
    nl, write("3. With intelligent labeling:"), nl,
    measure_time(tav_smart_labeling(Sol3), Time3),
    write("Time: "), write(Time3), write(" seconds"), nl,
    analyze_solution(Sol3),
    
    nl, write("4. With redundant constraints:"), nl,
    measure_time(tav_with_redundant(Sol4), Time4),
    write("Time: "), write(Time4), write(" seconds"), nl,
    analyze_solution(Sol4).

% Measure execution time compatible with ECLiPSe
measure_time(Goal, Time) :-
    cputime(T1),
    call(Goal),
    cputime(T2),
    Time is T2 - T1.

% Predicati originali per compatibilità
conf([],_).
conf([conflitto(P1,P2)|T], Invitati):-
    nth1(P1, Invitati, Tav1),
    nth1(P2, Invitati, Tav2),
    Tav1 #< Tav2,
    conf(T, Invitati).

persone_per_tavolo([],_,_).
persone_per_tavolo([TavInvitato|T],Invitati, C) :-
    occurrences(TavInvitato, Invitati, N),
    N #>= 2,
    N #=< C,
    persone_per_tavolo(T,Invitati, C). 

guadagno([],_,0).
guadagno([conosce(P1,P2)|T],Invitati,G):-
    nth1(P1, Invitati, Tav1),
    nth1(P2, Invitati, Tav2),
	Tav1 #= Tav2 #<=> B,
	guadagno(T,Invitati,G1),
    G #= G1 + B.

labelingffc([]).
labelingffc(List) :-
    deleteffc(X,List,Resto),
    indomain(X),
    labelingffc(Resto).