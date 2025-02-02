%% File: DLP.m
% Funzione per calcolare i punti di Leja usando la produttoria
function dlp = DLP(x, d)
    % Input:
    % x: vettore dei punti in cui cercare i punti di Leja
    % d: grado del polinomio interpolante (output sarà d+1 punti)
    
    % Output:
    % dlp: vettore dei d+1 punti di Leja approssimati
    
    % Inizializzazione vettore output
    dlp = zeros(d+1, 1);
    dlp(1) = x(1);  % Primo punto è il primo del vettore input
    
    % Per ogni punto successivo
    for k = 2:d+1
        % Inizializza produttoria per ogni punto candidato
        prod = ones(length(x), 1);
        
        % Calcola la produttoria per ogni punto candidato
        for i = 1:k-1
            prod = prod .* abs(x - dlp(i));
        end
        
        % Trova il punto che massimizza la produttoria
        [~, idx] = max(prod);
        dlp(k) = x(idx);
    end
end

%% File: DLP2.m
% Funzione per calcolare i punti di Leja usando fattorizzazione LU
function dlp = DLP2(x, d)
    % Input:
    % x: vettore dei punti in cui cercare i punti di Leja
    % d: grado del polinomio interpolante (output sarà d+1 punti)
    
    % Output:
    % dlp: vettore dei d+1 punti di Leja approssimati
    
    % Costruzione della matrice di Vandermonde con base Chebyshev
    M = length(x);
    V = zeros(M, d+1);
    
    % Riempimento matrice con polinomi di Chebyshev
    for i = 1:M
        for j = 1:d+1
            V(i,j) = cos((j-1) * acos(x(i)));
        end
    end
    
    % Fattorizzazione LU con pivoting
    [~, ~, P] = lu(V);
    
    % Estrai i primi d+1 punti secondo la permutazione
    dlp = x(P(1:d+1));
end

%% File: leb_con.m
% Funzione per calcolare la costante di Lebesgue
function L = leb_con(z, x)
    % Input:
    % z: vettore riga dei nodi dell'interpolante
    % x: vettore colonna di punti in cui valutare la funzione
    
    % Output:
    % L: costante di Lebesgue (scalare)
    
    n = length(z);
    sum_abs = zeros(length(x), 1);
    
    % Calcolo dei polinomi di Lagrange
    for i = 1:n
        % Calcola il polinomio di Lagrange i-esimo
        num = ones(length(x), 1);
        den = 1;
        for j = 1:n
            if j ~= i
                num = num .* (x - z(j));
                den = den * (z(i) - z(j));
            end
        end
        % Aggiungi il valore assoluto alla somma
        sum_abs = sum_abs + abs(num / den);
    end
    
    % La costante di Lebesgue è il massimo della somma
    L = max(sum_abs);
end

%% File: test_interpolazione.m
% Script principale per testare l'interpolazione con punti di Leja
clear all
close all
clc

% Parametri iniziali
n_points = 10^4;  % Numero di punti nella mesh
x = linspace(-1, 1, n_points)';  % Mesh di punti equidistanti
degrees = 1:50;   % Gradi da testare

% Inizializzazione arrays per i risultati
times_DLP = zeros(size(degrees));
times_DLP2 = zeros(size(degrees));
lebesgue_constants = zeros(size(degrees));

% Test per ogni grado
fprintf('Inizio test per diversi gradi...\n');
for i = 1:length(degrees)
    d = degrees(i);
    fprintf('Testing grado %d di %d\n', d, max(degrees));
    
    % Test DLP
    tic;
    points_DLP = DLP(x, d);
    times_DLP(i) = toc;
    
    % Test DLP2
    tic;
    points_DLP2 = DLP2(x, d);
    times_DLP2(i) = toc;
    
    % Calcolo costante di Lebesgue
    x_test = linspace(-1, 1, 1000)';
    lebesgue_constants(i) = leb_con(points_DLP2, x_test);
end

% Creazione dei grafici
% 1. Confronto tempi computazionali
figure('Name', 'Confronto Tempi Computazionali')
plot(degrees, times_DLP, 'b-', 'LineWidth', 2)
hold on
plot(degrees, times_DLP2, 'r--', 'LineWidth', 2)
legend('DLP', 'DLP2')
xlabel('Grado del polinomio')
ylabel('Tempo di esecuzione (s)')
title('Confronto tempi computazionali')
grid on

% 2. Costante di Lebesgue
figure('Name', 'Costante di Lebesgue')
semilogy(degrees, lebesgue_constants, 'k-', 'LineWidth', 2)
xlabel('Grado del polinomio')
ylabel('Costante di Lebesgue')
title('Costante di Lebesgue per punti di Leja approssimati')
grid on

% Test con la funzione f(x) = 1/(x-1.3)
fprintf('\nTest con funzione f(x) = 1/(x-1.3)\n');

x_eval = linspace(-1, 1, 1000)';
f = @(x) 1./(x - 1.3);

% Scelta del grado per il test
d_test = 20;
fprintf('Usando grado %d per il test finale\n', d_test);

points_leja = DLP2(x, d_test);
points_equi = linspace(-1, 1, d_test+1)';

% Costruzione matrici di Vandermonde
V_leja = zeros(d_test+1, d_test+1);
V_equi = zeros(d_test+1, d_test+1);
for i = 1:d_test+1
    for j = 1:d_test+1
        V_leja(i,j) = cos((j-1) * acos(points_leja(i)));
        V_equi(i,j) = cos((j-1) * acos(points_equi(i)));
    end
end

% Calcolo coefficienti
f_leja = f(points_leja);
f_equi = f(points_equi);
coeff_leja = V_leja \ f_leja;
coeff_equi = V_equi \ f_equi;

% Valutazione interpolanti
V_eval = zeros(length(x_eval), d_test+1);
for i = 1:length(x_eval)
    for j = 1:d_test+1
        V_eval(i,j) = cos((j-1) * acos(x_eval(i)));
    end
end

interp_leja = V_eval * coeff_leja;
interp_equi = V_eval * coeff_equi;

% Plot risultati finali
figure('Name', 'Confronto Interpolazioni')
plot(x_eval, f(x_eval), 'k-', 'LineWidth', 2)
hold on
plot(x_eval, interp_leja, 'b--', 'LineWidth', 2)
plot(x_eval, interp_equi, 'r:', 'LineWidth', 2)
legend('Funzione originale', 'Interpolazione Leja', 'Interpolazione equispaz.')
xlabel('x')
ylabel('f(x)')
title('Confronto interpolazioni')
grid on

fprintf('\nEsecuzione completata!\n');