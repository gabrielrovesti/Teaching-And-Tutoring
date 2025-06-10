:- lib(fd).
:- lib(fd_global).
:- lib(listut).
:- [matrimonio].
:- lib(propia).

tav(Invitati) :-
    num_invitati(NI),
    num_tavoli(NT),
    capacita(C),
    findall(conflitto(P1,P2), conflitto(P1,P2), LConf),
    findall(conosce(P1,P2), conosce(P1,P2), Lcon),
    
    % a ogni invitato associo il suo tavolo
    length(Invitati, NI),
    Invitati :: 1..NT,

    % vincolo su conflitti e persone per tavolo
    conf(LConf,Invitati),
    persone_per_tavolo(Invitati,Invitati,C),

    % guadagno su persone che si conoscono
    guadagno(Lcon,Invitati,G),
    min_max(labelingffc(Invitati),-G).


labelingffc([]).
labelingffc(List) :-
    deleteffc(X,List,Resto),
    indomain(X),
    labelingffc(Resto).

conf([],_).
conf([conflitto(P1,P2)|T], Invitati):-
    nth1(P1, Invitati, Tav1),
    nth1(P2, Invitati, Tav2),
    %Tav1 #\= Tav2, % senza questo è più rapido, tanto se è < è anche diverso
    Tav1 #< Tav2, % vincolo per togliere simmetria e accelerare
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