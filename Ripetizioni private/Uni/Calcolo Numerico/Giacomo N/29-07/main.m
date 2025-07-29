clc; clear; close all;

fprintf('=== PROGETTO NODI DI LEJA APPROSSIMATI ===\n\n');

% Parametri del problema
N = 10000;  % Punti della mesh
x = linspace(-1, 1, N)';
d = 10;     % Grado del polinomio di test

fprintf('Generazione mesh con N=%d punti in [-1,1]\n', N);
fprintf('Test con polinomio di grado d=%d\n\n', d);

% Test dei due algoritmi per un grado specifico
fprintf('--- CONFRONTO ALGORITMI PER d=%d ---\n', d);

% Algoritmo DLP
tic;
nodi_dlp = DLP(x, d);
tempo_dlp = toc;
fprintf('DLP:  tempo = %.6f s\n', tempo_dlp);

% Algoritmo DLP2
tic;
nodi_dlp2 = DLP2(x, d);
tempo_dlp2 = toc;
fprintf('DLP2: tempo = %.6f s\n', tempo_dlp2);

% Calcolo costanti di Lebesgue
L_dlp = leb_con(nodi_dlp, x);
L_dlp2 = leb_con(nodi_dlp2, x);

fprintf('\nCostanti di Lebesgue:\n');
fprintf('DLP:  L = %.4f\n', L_dlp);
fprintf('DLP2: L = %.4f\n\n', L_dlp2);

% Sperimentazione completa
fprintf('--- SPERIMENTAZIONE COMPLETA ---\n');
sperimentazione(x, N);

% Test di interpolazione
fprintf('--- TEST INTERPOLAZIONE ---\n');
test_interpolazione(x, N);

fprintf('\nProgetto completato!\n');