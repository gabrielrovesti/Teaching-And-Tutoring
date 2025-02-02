%% File: main.m
% Script principale per l'interpolazione con punti di Leja
function main()
    % Pulizia ambiente di lavoro
    clear all; close all; clc;
    
    % Impostazione dei parametri
    n_points = 1e4;        % Numero di punti nella mesh
    max_degree = 50;       % Grado massimo del polinomio
    x = linspace(-1, 1, n_points)';
    
    % Esecuzione dei test
    fprintf('Inizio esecuzione dei test...\n\n');
    
    % 1. Test dei tempi computazionali
    [times_DLP, times_DLP2] = test_computational_times(x, max_degree);
    
    % 2. Test della costante di Lebesgue
    lebesgue_constants = test_lebesgue_constant(x, max_degree);
    
    % 3. Test dell'interpolazione
    test_interpolation_comparison(x);
    
    fprintf('\nEsecuzione completata con successo!\n');
end

%% File: DLP.m
function dlp = DLP(x, d)
    % Function per calcolare i punti di Leja usando la produttoria
    % Input:
    %   x: vettore dei punti nell'intervallo [-1,1]
    %   d: grado del polinomio (output sarà d+1 punti)
    % Output:
    %   dlp: vettore dei d+1 punti di Leja approssimati
    
    n = length(x);
    dlp = zeros(d+1, 1);
    dlp(1) = x(1);  % Primo punto
    
    for k = 1:d
        % Calcolo efficiente della produttoria
        prod = ones(n, 1);
        for j = 1:k
            prod = prod .* abs(x - dlp(j));
        end
        [~, max_idx] = max(prod);
        dlp(k+1) = x(max_idx);
    end
end

%% File: DLP2.m
function dlp = DLP2(x, d)
    % Costruzione matrice di Vandermonde con base Chebyshev
    V = build_chebyshev_vandermonde(x, d);
    
    % Fattorizzazione LU con pivoting
    [~, ~, P] = lu(V, 'vector');
    
    % Estrazione dei punti di Leja
    dlp = x(P(1:d+1));
end


%% File: leb_con.m
function L = leb_con(z, x)
    % Function per calcolare la costante di Lebesgue
    % Input:
    %   z: vettore riga dei nodi dell'interpolante
    %   x: vettore colonna dei punti di valutazione
    % Output:
    %   L: costante di Lebesgue (scalare)
    
    n = length(z);
    L_vals = zeros(length(x), 1);
    
    for i = 1:length(x)
        sum = 0;
        for j = 1:n
            % Calcolo efficiente del polinomio di Lagrange
            num = 1; den = 1;
            for k = 1:n
                if k ~= j
                    num = num * (x(i) - z(k));
                    den = den * (z(j) - z(k));
                end
            end
            sum = sum + abs(num/den);
        end
        L_vals(i) = sum;
    end
    
    L = max(L_vals);
end

%% File: test_computational_times.m
function [times_DLP, times_DLP2] = test_computational_times(x, max_degree)
    % Test dei tempi computazionali per entrambi gli algoritmi
    
    times_DLP = zeros(max_degree, 1);
    times_DLP2 = zeros(max_degree, 1);
    
    fprintf('Test dei tempi computazionali...\n');
    for d = 1:max_degree
        % Test DLP
        tic;
        DLP(x, d);
        times_DLP(d) = toc;
        
        % Test DLP2
        tic;
        DLP2(x, d);
        times_DLP2(d) = toc;
        
        if mod(d, 10) == 0
            fprintf('Completato grado %d di %d\n', d, max_degree);
        end
    end
    
    % Plot dei risultati
    figure('Name', 'Confronto Tempi Computazionali');
    plot(1:max_degree, times_DLP, 'b-', 'LineWidth', 1.5);
    hold on;
    plot(1:max_degree, times_DLP2, 'r--', 'LineWidth', 1.5);
    legend('DLP', 'DLP2', 'Location', 'northwest');
    xlabel('Grado del polinomio');
    ylabel('Tempo computazionale (s)');
    title('Confronto tempi computazionali DLP vs DLP2');
    grid on;
end

%% File: test_lebesgue_constant.m
function lebesgue_constants = test_lebesgue_constant(x, max_degree)
    % Test della costante di Lebesgue
    
    lebesgue_constants = zeros(max_degree, 1);
    x_eval = linspace(-1, 1, 1000)';
    
    fprintf('Calcolo delle costanti di Lebesgue...\n');
    for d = 1:max_degree
        nodes = DLP2(x, d);
        lebesgue_constants(d) = leb_con(nodes', x_eval);
        
        if mod(d, 10) == 0
            fprintf('Completato grado %d di %d\n', d, max_degree);
        end
    end
    
    % Plot dei risultati
    figure('Name', 'Costante di Lebesgue');
    semilogy(1:max_degree, lebesgue_constants, 'b-', 'LineWidth', 1.5);
    grid on;
    xlabel('Grado del polinomio');
    ylabel('Costante di Lebesgue (scala log)');
    title('Costante di Lebesgue dei punti di Leja approssimati');
end

%% File: test_interpolation_comparison.m
function test_interpolation_comparison(x)
    % Test del confronto delle interpolazioni
    
    % Funzione test
    f = @(x) 1./(x - 1.3);
    test_points = linspace(-1, 1, 1000)';
    d_test = 20;  % Grado per il test
    
    fprintf('Test di interpolazione con grado %d...\n', d_test);
    
    % Calcolo nodi
    points_leja = DLP2(x, d_test);
    points_equi = linspace(-1, 1, d_test+1)';
    
    % Costruzione matrici di Vandermonde
    V_leja = build_chebyshev_vandermonde(points_leja, d_test);
    V_equi = build_chebyshev_vandermonde(points_equi, d_test);
    V_eval = build_chebyshev_vandermonde(test_points, d_test);
    
    % Calcolo coefficienti
    f_leja = f(points_leja);
    f_equi = f(points_equi);
    coeff_leja = V_leja \ f_leja;
    coeff_equi = V_equi \ f_equi;
    
    % Valutazione interpolanti
    interp_leja = V_eval * coeff_leja;
    interp_equi = V_eval * coeff_equi;
    
    % Plot risultati
    figure('Name', 'Confronto Interpolazioni');
    plot(test_points, f(test_points), 'k-', 'LineWidth', 1.5);
    hold on;
    plot(test_points, interp_leja, 'b--', 'LineWidth', 1.5);
    plot(test_points, interp_equi, 'r:', 'LineWidth', 1.5);
    legend('Funzione originale', 'Interpolazione Leja', ...
           'Interpolazione equispaz.', 'Location', 'best');
    xlabel('x');
    ylabel('f(x)');
    title('Confronto interpolazioni');
    grid on;
end

%% File: build_chebyshev_vandermonde.m
function V = build_chebyshev_vandermonde(x, d)
    % Costruzione della matrice di Vandermonde con base di Chebyshev
    n = length(x);
    V = zeros(n, d+1);
    for i = 1:n
        for j = 1:d+1
            V(i,j) = cos((j-1) * acos(x(i)));
        end
    end
end