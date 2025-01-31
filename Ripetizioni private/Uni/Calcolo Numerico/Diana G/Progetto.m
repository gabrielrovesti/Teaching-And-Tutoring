% -------------------------------------------------------------------------
% File principale: main.m
% -------------------------------------------------------------------------
function main()
    % Impostazione dei parametri
    n_points = 1e4;        % Numero di punti nella mesh
    max_degree = 50;       % Grado massimo del polinomio
    x = linspace(-1, 1, n_points)';
    
    % Esecuzione dei test
    test_computational_times(x, max_degree);
    test_interpolation_comparison(x, max_degree);
    test_lebesgue_constant(x, max_degree);
end

% -------------------------------------------------------------------------
% Function DLP - Calcolo dei punti di Leja approssimati usando la produttoria
% -------------------------------------------------------------------------
function dlp = DLP(x, d)
    n = length(x);
    dlp = zeros(d+1, 1);
    dlp(1) = x(1);  % Primo punto
    
    for k = 1:d
        max_prod = -Inf;
        max_idx = -1;
        
        for i = 1:n
            prod = 1;
            for j = 1:k
                prod = prod * abs(x(i) - dlp(j));
            end
            
            if prod > max_prod
                max_prod = prod;
                max_idx = i;
            end
        end
        
        dlp(k+1) = x(max_idx);
    end
end

% -------------------------------------------------------------------------
% Function DLP2 - Calcolo dei punti di Leja usando la fattorizzazione LU
% -------------------------------------------------------------------------
function dlp = DLP2(x, d)
    n = length(x);
    % Costruzione della matrice di Vandermonde con base di Chebyshev
    V = zeros(n, d+1);
    for i = 1:n
        for j = 1:d+1
            V(i,j) = cos((j-1) * acos(x(i)));
        end
    end
    
    % Fattorizzazione LU con pivoting
    [L, U, P] = lu(V);
    
    % Estrazione dei punti di Leja dalla permutazione
    [~, idx] = sort(P * (1:n)', 'ascend');
    dlp = x(idx(1:d+1));
end

% -------------------------------------------------------------------------
% Function leb_con - Calcolo della costante di Lebesgue
% -------------------------------------------------------------------------
function L = leb_con(z, x)
    n = length(z);
    m = length(x);
    
    % Calcolo dei polinomi di Lagrange
    L_vals = zeros(m, 1);
    for i = 1:m
        sum = 0;
        for j = 1:n
            % Calcolo del j-esimo polinomio di Lagrange nel punto x(i)
            num = 1;
            den = 1;
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
    
    % Massimo della funzione di Lebesgue
    L = max(L_vals);
end

% -------------------------------------------------------------------------
% Function di test per i tempi computazionali
% -------------------------------------------------------------------------
function test_computational_times(x, max_degree)
    time_dlp = zeros(max_degree, 1);
    time_dlp2 = zeros(max_degree, 1);
    
    fprintf('Test dei tempi computazionali...\n');
    for d = 1:max_degree
        % Test DLP
        tic;
        nodes_dlp = DLP(x, d);
        time_dlp(d) = toc;
        
        % Test DLP2
        tic;
        nodes_dlp2 = DLP2(x, d);
        time_dlp2(d) = toc;
        
        fprintf('Grado %d completato\n', d);
    end
    
    % Plot dei tempi computazionali
    figure('Name', 'Confronto Tempi Computazionali');
    plot(1:max_degree, time_dlp, 'b-', 'LineWidth', 1.5);
    hold on;
    plot(1:max_degree, time_dlp2, 'r--', 'LineWidth', 1.5);
    legend('DLP', 'DLP2');
    xlabel('Grado del polinomio');
    ylabel('Tempo computazionale (s)');
    title('Confronto tempi computazionali DLP vs DLP2');
    grid on;
end

% -------------------------------------------------------------------------
% Function di test per il confronto delle interpolazioni
% -------------------------------------------------------------------------
function test_interpolation_comparison(x, max_degree)
    % Funzione test
    f = @(x) 1./(x - 1.3);
    
    % Punti di test
    test_points = linspace(-1, 1, 1000)';
    
    % Test per diversi gradi
    degrees = [5, 10, 15, 20];
    colors = {'b', 'r', 'g', 'm'};
    
    figure('Name', 'Confronto Interpolazioni');
    
    % Plot della funzione originale
    plot(test_points, f(test_points), 'k-', 'LineWidth', 1.5);
    hold on;
    
    for i = 1:length(degrees)
        d = degrees(i);
        
        % Nodi di Leja e nodi equispaziati
        leja_nodes = DLP2(x, d);
        equi_nodes = linspace(-1, 1, d+1)';
        
        % Costruzione delle matrici di Vandermonde
        V_leja = build_chebyshev_vandermonde(leja_nodes, d);
        V_equi = build_chebyshev_vandermonde(equi_nodes, d);
        
        % Calcolo dei coefficienti
        f_leja = f(leja_nodes);
        f_equi = f(equi_nodes);
        coeff_leja = V_leja \ f_leja;
        coeff_equi = V_equi \ f_equi;
        
        % Valutazione degli interpolanti
        V_test = build_chebyshev_vandermonde(test_points, d);
        interp_leja = V_test * coeff_leja;
        interp_equi = V_test * coeff_equi;
        
        % Plot
        plot(test_points, interp_leja, [colors{i}, '--'], 'LineWidth', 1.2);
        plot(test_points, interp_equi, [colors{i}, ':'], 'LineWidth', 1.2);
    end
    
    legend('Funzione originale', ...
           'Leja n=5', 'Equi n=5', ...
           'Leja n=10', 'Equi n=10', ...
           'Leja n=15', 'Equi n=15', ...
           'Leja n=20', 'Equi n=20');
    xlabel('x');
    ylabel('y');
    title('Confronto interpolazioni con nodi di Leja e nodi equispaziati');
    grid on;
end

% -------------------------------------------------------------------------
% Function di test per la costante di Lebesgue
% -------------------------------------------------------------------------
function test_lebesgue_constant(x, max_degree)
    fprintf('Calcolo delle costanti di Lebesgue...\n');
    lebesgue_constants = zeros(max_degree, 1);
    x_eval = linspace(-1, 1, 1000)';
    
    for d = 1:max_degree
        nodes = DLP2(x, d);
        lebesgue_constants(d) = leb_con(nodes', x_eval);
        fprintf('Grado %d completato\n', d);
    end
    
    % Plot della costante di Lebesgue
    figure('Name', 'Costante di Lebesgue');
    semilogy(1:max_degree, lebesgue_constants, 'b-', 'LineWidth', 1.5);
    grid on;
    xlabel('Grado del polinomio');
    ylabel('Costante di Lebesgue (scala log)');
    title('Costante di Lebesgue dei punti di Leja approssimati');
end

% -------------------------------------------------------------------------
% Function di supporto per la costruzione della matrice di Vandermonde
% -------------------------------------------------------------------------
function V = build_chebyshev_vandermonde(x, d)
    n = length(x);
    V = zeros(n, d+1);
    for i = 1:n
        for j = 1:d+1
            V(i,j) = cos((j-1) * acos(x(i)));
        end
    end
end