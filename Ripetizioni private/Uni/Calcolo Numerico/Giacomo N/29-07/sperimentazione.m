function sperimentazione(x, N)
% SPERIMENTAZIONE - Confronta gli algoritmi DLP e DLP2
%
% Input:
%   x - vettore della mesh di punti
%   N - numero di punti della mesh
%
% Produce grafici per:
% 1. Confronto dei tempi computazionali
% 2. Andamento della costante di Lebesgue

    fprintf('Esecuzione sperimentazione completa...\n');
    
    % Parametri
    d_max = 50;
    gradi = 1:d_max;
    
    % Inizializzazione vettori risultati
    tempi_DLP = zeros(size(gradi));
    tempi_DLP2 = zeros(size(gradi));
    lebesgue_vals = zeros(size(gradi));
    
    % Barra di progresso semplice
    fprintf('Progresso: ');
    
    % Loop sui gradi
    for i = 1:length(gradi)
        d = gradi(i);
        
        % Mostra progresso ogni 10 iterazioni
        if mod(d, 10) == 0
            fprintf('%d ', d);
        end
        
        % Misurazione tempo DLP
        tic;
        nodi_dlp = DLP(x, d);
        tempi_DLP(i) = toc;
        
        % Misurazione tempo DLP2
        tic;
        nodi_dlp2 = DLP2(x, d);
        tempi_DLP2(i) = toc;
        
        % Calcola costante di Lebesgue per l'algoritmo più veloce
        if tempi_DLP2(i) < tempi_DLP(i)
            lebesgue_vals(i) = leb_con(nodi_dlp2, x);
        else
            lebesgue_vals(i) = leb_con(nodi_dlp, x);
        end
    end
    
    fprintf('\nCompletato!\n\n');
    
    % === GRAFICO 1: Confronto tempi computazionali ===
    figure('Name', 'Confronto Tempi Computazionali', 'NumberTitle', 'off');
    plot(gradi, tempi_DLP, 'r-o', 'LineWidth', 2, 'MarkerSize', 4);
    hold on;
    plot(gradi, tempi_DLP2, 'b-s', 'LineWidth', 2, 'MarkerSize', 4);
    
    xlabel('Grado del polinomio d');
    ylabel('Tempo di esecuzione (s)');
    title(sprintf('Confronto Tempi Computazionali (N = %d)', N));
    legend('DLP (Produttoria)', 'DLP2 (LU)', 'Location', 'northwest');
    grid on;
    
    % Determina quale algoritmo è più veloce in media
    tempo_medio_DLP = mean(tempi_DLP);
    tempo_medio_DLP2 = mean(tempi_DLP2);
    
    if tempo_medio_DLP2 < tempo_medio_DLP
        fprintf('DLP2 è mediamente più veloce (%.6f s vs %.6f s)\n', ...
                tempo_medio_DLP2, tempo_medio_DLP);
    else
        fprintf('DLP è mediamente più veloce (%.6f s vs %.6f s)\n', ...
                tempo_medio_DLP, tempo_medio_DLP2);
    end
    
    % === GRAFICO 2: Costante di Lebesgue ===
    figure('Name', 'Costante di Lebesgue', 'NumberTitle', 'off');
    semilogy(gradi, lebesgue_vals, 'g-o', 'LineWidth', 2, 'MarkerSize', 4);
    
    xlabel('Grado del polinomio d');
    ylabel('Costante di Lebesgue');
    title('Stabilità: Costante di Lebesgue per Nodi di Leja');
    grid on;
    
    % Statistiche sulla costante di Lebesgue
    L_min = min(lebesgue_vals);
    L_max = max(lebesgue_vals);
    L_finale = lebesgue_vals(end);
    
    fprintf('Costante di Lebesgue:\n');
    fprintf('  Minima: %.4f (d=%d)\n', L_min, find(lebesgue_vals == L_min, 1));
    fprintf('  Massima: %.4f (d=%d)\n', L_max, find(lebesgue_vals == L_max, 1));
    fprintf('  Finale (d=%d): %.4f\n', d_max, L_finale);
    
    fprintf('\nSperimentazione completata!\n\n');
end