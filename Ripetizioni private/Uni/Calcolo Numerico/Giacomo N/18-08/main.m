clc; clear; close all;

%% =================================================================
%% PROGETTO 1: INTERPOLAZIONE POLINOMIALE CON NODI DI LEJA APPROSSIMATI
%% =================================================================

fprintf('=== PROGETTO NODI DI LEJA APPROSSIMATI ===\n\n');

%% PARAMETRI DEL PROBLEMA
N = 10000;  % Punti della mesh
x = linspace(-1, 1, N)';
d_test = 10;     % Grado del polinomio di test iniziale

fprintf('Generazione mesh con N=%d punti in [-1,1]\n', N);
fprintf('Test iniziale con polinomio di grado d=%d\n\n', d_test);

%% TEST CONFRONTO ALGORITMI PER UN GRADO SPECIFICO
fprintf('--- CONFRONTO ALGORITMI PER d=%d ---\n', d_test);

% Algoritmo DLP
tic;
nodi_dlp = DLP(x, d_test);
tempo_dlp = toc;
fprintf('DLP:  tempo = %.6f s\n', tempo_dlp);

% Algoritmo DLP2
tic;
nodi_dlp2 = DLP2(x, d_test);
tempo_dlp2 = toc;
fprintf('DLP2: tempo = %.6f s\n', tempo_dlp2);

% Calcolo costanti di Lebesgue
L_dlp = leb_con(nodi_dlp, x);
L_dlp2 = leb_con(nodi_dlp2, x);
fprintf('\nCostanti di Lebesgue:\n');
fprintf('DLP:  L = %.4f\n', L_dlp);
fprintf('DLP2: L = %.4f\n\n', L_dlp2);

%% SPERIMENTAZIONE COMPLETA: CONFRONTO TEMPI E STABILITÀ
fprintf('--- SPERIMENTAZIONE COMPLETA ---\n');
fprintf('Esecuzione sperimentazione completa...\n');

% Parametri per la sperimentazione
d_max = 50;
gradi = 1:d_max;

% Inizializzazione vettori risultati
tempi_DLP = zeros(size(gradi));
tempi_DLP2 = zeros(size(gradi));
lebesgue_vals = zeros(size(gradi));

% Barra di progresso
fprintf('Progresso sperimentazione: ');

% Loop sui gradi per confronto prestazioni
for i = 1:length(gradi)
    d = gradi(i);
    
    % Mostra progresso ogni 10 iterazioni
    if mod(d, 10) == 0
        fprintf('%d ', d);
    end
    
    % Misurazione tempo DLP
    tic;
    nodi_dlp_temp = DLP(x, d);
    tempi_DLP(i) = toc;
    
    % Misurazione tempo DLP2
    tic;
    nodi_dlp2_temp = DLP2(x, d);
    tempi_DLP2(i) = toc;
    
    % Calcola costante di Lebesgue per l'algoritmo più veloce
    if tempi_DLP2(i) < tempi_DLP(i)
        lebesgue_vals(i) = leb_con(nodi_dlp2_temp, x);
    else
        lebesgue_vals(i) = leb_con(nodi_dlp_temp, x);
    end
end

fprintf('\nSperimentazione completata!\n\n');

% ANALISI PRESTAZIONI
tempo_medio_DLP = mean(tempi_DLP);
tempo_medio_DLP2 = mean(tempi_DLP2);

if tempo_medio_DLP2 < tempo_medio_DLP
    fprintf('DLP2 è mediamente più veloce (%.6f s vs %.6f s)\n', ...
            tempo_medio_DLP2, tempo_medio_DLP);
    algoritmo_migliore = @DLP2;
    nome_algoritmo = 'DLP2';
else
    fprintf('DLP è mediamente più veloce (%.6f s vs %.6f s)\n', ...
            tempo_medio_DLP, tempo_medio_DLP2);
    algoritmo_migliore = @DLP;
    nome_algoritmo = 'DLP';
end

%% GRAFICO 1: CONFRONTO TEMPI COMPUTAZIONALI
figure('Name', 'Confronto Tempi Computazionali', 'NumberTitle', 'off');
plot(gradi, tempi_DLP, 'r-o', 'LineWidth', 2, 'MarkerSize', 4);
hold on;
plot(gradi, tempi_DLP2, 'b-s', 'LineWidth', 2, 'MarkerSize', 4);

xlabel('Grado del polinomio d');
ylabel('Tempo di esecuzione (s)');
title(sprintf('Confronto Tempi Computazionali (N = %d)', N));
legend('DLP (Produttoria)', 'DLP2 (LU)', 'Location', 'northwest');
grid on;

%% GRAFICO 2: COSTANTE DI LEBESGUE
figure('Name', 'Costante di Lebesgue', 'NumberTitle', 'off');
semilogy(gradi, lebesgue_vals, 'g-o', 'LineWidth', 2, 'MarkerSize', 4);

xlabel('Grado del polinomio d');
ylabel('Costante di Lebesgue');
title('Stabilità: Costante di Lebesgue per Nodi di Leja');
grid on;

% Statistiche costante di Lebesgue
L_min = min(lebesgue_vals);
L_max = max(lebesgue_vals);
L_finale = lebesgue_vals(end);

fprintf('Costante di Lebesgue:\n');
fprintf('  Minima: %.4f (d=%d)\n', L_min, find(lebesgue_vals == L_min, 1));
fprintf('  Massima: %.4f (d=%d)\n', L_max, find(lebesgue_vals == L_max, 1));
fprintf('  Finale (d=%d): %.4f\n', d_max, L_finale);

%% TEST DI INTERPOLAZIONE: LEJA VS EQUISPAZIATI
fprintf('\n--- TEST INTERPOLAZIONE ---\n');
fprintf('Test di interpolazione con f(x) = 1/(x - 1.3)...\n');
fprintf('Usando %s (più efficiente)\n', nome_algoritmo);

% Funzione di test (con singolarità fuori dall'intervallo)
f = @(x) 1 ./ (x - 1.3);
f_vals = f(x);

% Inizializzazione vettori errori
errori_leja = zeros(size(gradi));
errori_equi = zeros(size(gradi));

fprintf('Progresso interpolazione: ');

% Loop sui gradi per test di interpolazione
for i = 1:length(gradi)
    d = gradi(i);
    
    if mod(d, 10) == 0
        fprintf('%d ', d);
    end
    
 % === NODI DI LEJA ===
    nodi_leja = algoritmo_migliore(x, d);
    z = nodi_leja(:);
    f_z = f(z);
    
    % Vandermonde-Chebyshev CORRETTA (righe = punti, colonne = gradi)
    n_leja = numel(z);
    V_leja = cos(acos(z) * (0:n_leja-1));
    c_leja = V_leja \ f_z;
    
    % Valutazione CORRETTA su tutta la mesh
    Xe = x(:);
    V_eval_leja = cos(acos(Xe) * (0:n_leja-1));
    p_leja = V_eval_leja * c_leja;
    errori_leja(i) = max(abs(p_leja - f_vals));
    
    % === NODI EQUISPAZIATI ===
    z = linspace(-1, 1, d+1).';
    f_z = f(z);
    
    n_equi = numel(z);
    V_equi = cos(acos(z) * (0:n_equi-1));
    c_equi = V_equi \ f_z;
    
    V_eval_equi = cos(acos(Xe) * (0:n_equi-1));
    p_equi = V_eval_equi * c_equi;
    errori_equi(i) = max(abs(p_equi - f_vals));
end

fprintf('\nTest interpolazione completato!\n\n');

%% GRAFICO 3: CONFRONTO ERRORI DI INTERPOLAZIONE
figure('Name', 'Confronto Errori di Interpolazione', 'NumberTitle', 'off');

semilogy(gradi, errori_leja, 'b-o', 'LineWidth', 2, 'MarkerSize', 4);
hold on;
semilogy(gradi, errori_equi, 'r-s', 'LineWidth', 2, 'MarkerSize', 4);

xlabel('Grado del polinomio d');
ylabel('Errore massimo');
title(sprintf('Errori di Interpolazione: f(x) = 1/(x - 1.3), N = %d', N));
legend('Nodi di Leja', 'Nodi Equispaziati', 'Location', 'best');
grid on;

%% ANALISI RISULTATI INTERPOLAZIONE
fprintf('Analisi errori di interpolazione:\n');

% Trova dove i nodi di Leja sono migliori
leja_migliori = errori_leja < errori_equi;
perc_leja_migliori = 100 * sum(leja_migliori) / length(gradi);

fprintf('  Nodi di Leja migliori: %.1f%% dei casi\n', perc_leja_migliori);

% Errori finali
err_leja_finale = errori_leja(end);
err_equi_finale = errori_equi(end);

fprintf('  Errore finale (d=%d):\n', d_max);
fprintf('    Leja: %.2e\n', err_leja_finale);
fprintf('    Equispaziati: %.2e\n', err_equi_finale);

if err_leja_finale < err_equi_finale
    rapporto = err_equi_finale / err_leja_finale;
    fprintf('    Leja è %.1fx più accurato\n', rapporto);
else
    rapporto = err_leja_finale / err_equi_finale;
    fprintf('    Equispaziati sono %.1fx più accurati\n', rapporto);
end

% Controlla stabilità (crescita dell'errore)
if length(errori_leja) > 10
    crescita_leja = errori_leja(end) / errori_leja(end-9);
    crescita_equi = errori_equi(end) / errori_equi(end-9);
    
    fprintf('  Crescita errore (ultimi 10 gradi):\n');
    fprintf('    Leja: %.2fx\n', crescita_leja);
    fprintf('    Equispaziati: %.2fx\n', crescita_equi);
end

%% RIEPILOGO FINALE
fprintf('\n=== RIEPILOGO FINALE ===\n');
fprintf('1. Algoritmo più efficiente: %s\n', nome_algoritmo);
fprintf('2. Costante di Lebesgue finale: %.4f\n', L_finale);
fprintf('3. Nodi di Leja migliori nel %.1f%% dei casi\n', perc_leja_migliori);

if err_leja_finale < err_equi_finale
    fprintf('4. Nodi di Leja sono %.1fx più accurati per f(x) = 1/(x-1.3)\n', ...
            err_equi_finale / err_leja_finale);
else
    fprintf('4. Nodi equispaziati sono %.1fx più accurati per f(x) = 1/(x-1.3)\n', ...
            err_leja_finale / err_equi_finale);
end

fprintf('\n🎉 PROGETTO COMPLETATO CON SUCCESSO! 🎉\n');

% Salva i risultati (opzionale)
save('risultati_nodi_leja.mat', 'tempi_DLP', 'tempi_DLP2', 'lebesgue_vals', ...
     'errori_leja', 'errori_equi', 'gradi', 'N', 'd_max');