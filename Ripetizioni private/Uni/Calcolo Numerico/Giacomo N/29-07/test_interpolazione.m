function test_interpolazione(x, N)
% TEST_INTERPOLAZIONE - Confronta errori di interpolazione
%
% Input:
%   x - vettore della mesh di punti
%   N - numero di punti della mesh
%
% Confronta l'interpolazione con:
% - Nodi di Leja approssimati (algoritmo più efficiente)
% - Nodi equispaziati
%
% Funzione test: f(x) = 1/(x - 1.3)

    fprintf('Test di interpolazione con f(x) = 1/(x - 1.3)...\n');
    
    % Parametri
    d_max = 50;
    gradi = 1:d_max;
    
    % Funzione di test (con singolarità fuori dall'intervallo)
    f = @(x) 1 ./ (x - 1.3);
    f_vals = f(x);
    
    % Inizializzazione vettori errori
    errori_leja = zeros(size(gradi));
    errori_equi = zeros(size(gradi));
    
    % Determina quale algoritmo usare (test preliminare)
    tic; DLP(x, 10); t1 = toc;
    tic; DLP2(x, 10); t2 = toc;
    usa_dlp2 = (t2 < t1);
    
    if usa_dlp2
        fprintf('Usando DLP2 (più efficiente)\n');
        algoritmo_leja = @DLP2;
    else
        fprintf('Usando DLP (più efficiente)\n');
        algoritmo_leja = @DLP;
    end
    
    fprintf('Progresso: ');
    
    % Loop sui gradi
    for i = 1:length(gradi)
        d = gradi(i);
        
        if mod(d, 10) == 0
            fprintf('%d ', d);
        end
        
        % === NODI DI LEJA ===
        nodi_leja = algoritmo_leja(x, d);
        f_leja = f(nodi_leja);
        
        % Interpolazione con nodi di Leja
        p_leja = interp_chebyshev(nodi_leja, f_leja, x);
        errori_leja(i) = max(abs(p_leja - f_vals));
        
        % === NODI EQUISPAZIATI ===
        nodi_equi = linspace(-1, 1, d+1)';
        f_equi = f(nodi_equi);
        
        % Interpolazione con nodi equispaziati
        p_equi = interp_chebyshev(nodi_equi, f_equi, x);
        errori_equi(i) = max(abs(p_equi - f_vals));
    end
    
    fprintf('\nCompletato!\n\n');
    
    % === GRAFICO: Confronto errori ===
    figure('Name', 'Confronto Errori di Interpolazione', 'NumberTitle', 'off');
    
    semilogy(gradi, errori_leja, 'b-o', 'LineWidth', 2, 'MarkerSize', 4);
    hold on;
    semilogy(gradi, errori_equi, 'r-s', 'LineWidth', 2, 'MarkerSize', 4);
    
    xlabel('Grado del polinomio d');
    ylabel('Errore massimo');
    title(sprintf('Errori di Interpolazione: f(x) = 1/(x - 1.3), N = %d', N));
    legend('Nodi di Leja', 'Nodi Equispaziati', 'Location', 'best');
    grid on;
    
    % Analisi dei risultati
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
        crescita_leja = errori_leja(end) / errori_leja(end-9);  % ultimi 10 punti
        crescita_equi = errori_equi(end) / errori_equi(end-9);
        
        fprintf('  Crescita errore (ultimi 10 gradi):\n');
        fprintf('    Leja: %.2fx\n', crescita_leja);
        fprintf('    Equispaziati: %.2fx\n', crescita_equi);
    end
    
    fprintf('\nTest di interpolazione completato!\n\n');
end