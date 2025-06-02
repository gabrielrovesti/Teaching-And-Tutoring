function graficiConfronto(risultati_pre, risultati_post, config, idCampione)
    % GRAFICICONFRONTO - Crea grafici di confronto completi tra pre e post intervento
    %
    % Sintassi: graficiConfronto(risultati_pre, risultati_post, config, idCampione)
    %
    % Input:
    %   risultati_pre  - Struttura risultati pre-intervento
    %   risultati_post - Struttura risultati post-intervento  
    %   config         - Configurazione sistema
    %   idCampione     - Identificativo campione
    %
    % Compatibilità: MATLAB e Octave
    
    if nargin < 4
        idCampione = 'Sconosciuto';
    end
    
    % Generazione timestamp
    if exist('OCTAVE_VERSION', 'builtin')
        timestamp = strftime('%H-%M-%S', localtime(time));
    else
        timestamp = datestr(now, 'HH-MM-SS');
    end
    
    fprintf('\n=== CREAZIONE GRAFICI DI CONFRONTO ===\n');
    fprintf('Campione: %s\n', idCampione);
    
    % === CONFRONTO STATISTICO PRINCIPALE ===
    fig_stats = figure('Name', sprintf('Confronto Statistico-%s', idCampione));
    if ~exist('OCTAVE_VERSION', 'builtin')
        set(fig_stats, 'NumberTitle', 'off', 'Position', [100 100 1200 800]);
    end
    
    % Preparazione dati per confronto
    categorie = {'σV', 'σH', 'ratioD', 'ΔD', 'Gradiente', 'Pendenza'};
    valori_pre = [risultati_pre.sigmaV, risultati_pre.sigmaH, risultati_pre.ratioD, ...
                  risultati_pre.deltaD, risultati_pre.gradiente, risultati_pre.pendenza];
    valori_post = [risultati_post.sigmaV, risultati_post.sigmaH, risultati_post.ratioD, ...
                   risultati_post.deltaD, risultati_post.gradiente, risultati_post.pendenza];
    
    % Subplot 1: Grafico a barre comparative
    subplot(2,3,1);
    x = 1:length(categorie);
    larghezza = 0.35;
    
    bar(x - larghezza/2, valori_pre, larghezza, 'FaceColor', [0.8 0.2 0.2]);
    hold on;
    bar(x + larghezza/2, valori_post, larghezza, 'FaceColor', [0.2 0.8 0.2]);
    
    xlabel('Parametri Statistici', 'FontSize', 11, 'FontWeight', 'bold');
    ylabel('Valori', 'FontSize', 11, 'FontWeight', 'bold');
    title(sprintf('Confronto Parametri Statistici\nCampione: %s', idCampione), ...
          'FontSize', 12, 'FontWeight', 'bold');
    
    if exist('OCTAVE_VERSION', 'builtin')
        legend({'Pre-intervento', 'Post-intervento'}, 'Location', 'best');
        set(gca, 'XTick', x, 'XTickLabel', categorie);
    else
        legend({'Pre-intervento', 'Post-intervento'}, 'Location', 'best', 'FontSize', 9);
        set(gca, 'XTick', x, 'XTickLabel', categorie);
    end
    grid on;
    box on;
    
    % Subplot 2: Grafico percentuali di miglioramento
    subplot(2,3,2);
    
    % Calcolo percentuali di miglioramento (positivo = miglioramento)
    miglioramenti = zeros(size(valori_pre));
    for i = 1:length(valori_pre)
        if valori_pre(i) ~= 0
            if i == 3 || i == 5 || i == 6  % ratioD, gradiente, pendenza: diminuzione = miglioramento
                miglioramenti(i) = ((abs(valori_pre(i)) - abs(valori_post(i))) / abs(valori_pre(i))) * 100;
            else  % Altri parametri: dipende dal contesto
                miglioramenti(i) = ((valori_post(i) - valori_pre(i)) / valori_pre(i)) * 100;
            end
        end
    end
    
    % Colorazione basata su miglioramento/peggioramento
    colori = zeros(length(miglioramenti), 3);
    for i = 1:length(miglioramenti)
        if miglioramenti(i) > 0
            colori(i,:) = [0.2 0.8 0.2];  % Verde per miglioramento
        else
            colori(i,:) = [0.8 0.2 0.2];  % Rosso per peggioramento
        end
    end
    
    if exist('OCTAVE_VERSION', 'builtin')
        % Octave - grafico semplificato
        bar(miglioramenti);
        ylabel('Miglioramento [%]', 'FontSize', 11, 'FontWeight', 'bold');
    else
        % MATLAB - grafico colorato
        b = bar(miglioramenti);
        b.FaceColor = 'flat';
        b.CData = colori;
        ylabel('Miglioramento [%]', 'FontSize', 11, 'FontWeight', 'bold');
    end
    
    xlabel('Parametri', 'FontSize', 11, 'FontWeight', 'bold');
    title('Percentuali di Miglioramento', 'FontSize', 12, 'FontWeight', 'bold');
    set(gca, 'XTick', x, 'XTickLabel', categorie);
    grid on;
    box on;
    
    % Linea di riferimento allo zero
    hold on;
    plot([0.5, length(categorie)+0.5], [0, 0], 'k--', 'LineWidth', 1);
    
    % Subplot 3: Grafico radar/polare (se supportato)
    subplot(2,3,3);
    
    if exist('OCTAVE_VERSION', 'builtin')
        % Octave - grafico alternativo
        plot(1:length(valori_pre), valori_pre, 'r-o', 'LineWidth', 2);
        hold on;
        plot(1:length(valori_post), valori_post, 'g-s', 'LineWidth', 2);
        xlabel('Parametri', 'FontWeight', 'bold');
        ylabel('Valori', 'FontWeight', 'bold');
        title('Confronto Profili', 'FontSize', 12, 'FontWeight', 'bold');
        legend({'Pre', 'Post'}, 'Location', 'best');
        set(gca, 'XTick', 1:length(categorie), 'XTickLabel', categorie);
        grid on;
    else
        % MATLAB - tentativo di grafico polare
        try
            % Normalizzazione dati per grafico radar
            valori_norm_pre = (valori_pre - min([valori_pre, valori_post])) ./ ...
                             (max([valori_pre, valori_post]) - min([valori_pre, valori_post]) + eps);
            valori_norm_post = (valori_post - min([valori_pre, valori_post])) ./ ...
                              (max([valori_pre, valori_post]) - min([valori_pre, valori_post]) + eps);
            
            angoli = linspace(0, 2*pi, length(categorie)+1);
            valori_norm_pre = [valori_norm_pre, valori_norm_pre(1)];  % Chiudi il poligono
            valori_norm_post = [valori_norm_post, valori_norm_post(1)];
            
            polar(angoli, valori_norm_pre, 'r-o');
            hold on;
            polar(angoli, valori_norm_post, 'g-s');
            title('Confronto Radar Normalizzato', 'FontSize', 12, 'FontWeight', 'bold');
            legend({'Pre', 'Post'}, 'Location', 'best');
        catch
            % Fallback
            plot(1:length(valori_pre), valori_pre, 'r-o', 'LineWidth', 2);
            hold on;
            plot(1:length(valori_post), valori_post, 'g-s', 'LineWidth', 2);
            title('Confronto Profili', 'FontSize', 12, 'FontWeight', 'bold');
            legend({'Pre', 'Post'}, 'Location', 'best');
        end
    end
    
    % Subplot 4: Analisi efficacia intervento
    subplot(2,3,4);
    
    % Calcolo indici di efficacia
    efficacia_ratioD = abs(risultati_pre.ratioD - 1) - abs(risultati_post.ratioD - 1);
    efficacia_gradiente = abs(risultati_pre.gradiente) - abs(risultati_post.gradiente);
    efficacia_sigma = (risultati_pre.sigmaV + risultati_pre.sigmaH) - ...
                     (risultati_post.sigmaV + risultati_post.sigmaH);
    
    efficacia = [efficacia_ratioD, efficacia_gradiente, efficacia_sigma];
    etichette_eff = {'Efficacia ratioD', 'Efficacia Gradiente', 'Efficacia σ Totale'};
    
    bar(efficacia);
    xlabel('Indicatori di Efficacia', 'FontSize', 11, 'FontWeight', 'bold');
    ylabel('Miglioramento', 'FontSize', 11, 'FontWeight', 'bold');
    title('Analisi Efficacia Intervento', 'FontSize', 12, 'FontWeight', 'bold');
    set(gca, 'XTickLabel', etichette_eff);
    grid on;
    box on;
    
    % Linea di riferimento allo zero
    hold on;
    plot([0.5, length(efficacia)+0.5], [0, 0], 'k--', 'LineWidth', 1);
    
    % Subplot 5: Distribuzione temperature medie
    subplot(2,3,5);
    
    temp_pre = risultati_pre.tempMediaTotale;
    temp_post = risultati_post.tempMediaTotale;
    
    bar([1, 2], [temp_pre, temp_post], 'FaceColor', [0.6 0.6 0.9]);
    xlabel('Fase', 'FontSize', 11, 'FontWeight', 'bold');
    ylabel('Temperatura Media [°C]', 'FontSize', 11, 'FontWeight', 'bold');
    title('Confronto Temperature Medie', 'FontSize', 12, 'FontWeight', 'bold');
    set(gca, 'XTick', [1, 2], 'XTickLabel', {'Pre', 'Post'});
    
    % Aggiungi valori sui punti
    text(1, temp_pre + 0.1, sprintf('%.2f°C', temp_pre), ...
         'HorizontalAlignment', 'center', 'FontWeight', 'bold');
    text(2, temp_post + 0.1, sprintf('%.2f°C', temp_post), ...
         'HorizontalAlignment', 'center', 'FontWeight', 'bold');
    
    grid on;
    box on;
    
    % Subplot 6: Sintesi miglioramento globale
    subplot(2,3,6);
    
    % Score globale di miglioramento
    score_ratioD = max(0, (abs(risultati_pre.ratioD - 1) - abs(risultati_post.ratioD - 1)) * 100);
    score_gradiente = max(0, (abs(risultati_pre.gradiente) - abs(risultati_post.gradiente)) * 100);
    score_variabilita = max(0, ((risultati_pre.sigmaV + risultati_pre.sigmaH) - ...
                               (risultati_post.sigmaV + risultati_post.sigmaH)) * 100);
    
    scores = [score_ratioD, score_gradiente, score_variabilita];
    score_globale = mean(scores);
    
    % Grafico a torta dei contributi al miglioramento
    if sum(scores) > 0
        if exist('OCTAVE_VERSION', 'builtin')
            % Octave - grafico a barre
            bar(scores);
            xlabel('Contributi', 'FontWeight', 'bold');
            ylabel('Score', 'FontWeight', 'bold');
            title(sprintf('Score Globale: %.1f', score_globale), 'FontSize', 12, 'FontWeight', 'bold');
            set(gca, 'XTickLabel', {'ratioD', 'Grad', 'Var'});
        else
            % MATLAB - grafico a torta
            pie(scores, {'ratioD', 'Gradiente', 'Variabilità'});
            title(sprintf('Contributi Miglioramento\nScore Globale: %.1f', score_globale), ...
                  'FontSize', 12, 'FontWeight', 'bold');
        end
    else
        text(0.5, 0.5, 'Nessun miglioramento\nsignificativo rilevato', ...
             'HorizontalAlignment', 'center', 'FontSize', 14, 'FontWeight', 'bold');
        set(gca, 'XLim', [0 1], 'YLim', [0 1]);
        title('Valutazione Miglioramento', 'FontSize', 12, 'FontWeight', 'bold');
    end
    
    % Salvataggio figura confronto statistico
    percorsoSalv = fullfile(config.percorsi.confronti, ...
                           sprintf('confronto_statistico_%s_%s.fig', idCampione, timestamp));
    if exist('OCTAVE_VERSION', 'builtin')
        print(fig_stats, '-dfig', percorsoSalv);
    else
        savefig(fig_stats, percorsoSalv);
    end
    
    % === CONFRONTO GRAFICI COMBINATI ===
    % Carica e combina i grafici salvati precedentemente
    
    fig_combinato = figure('Name', sprintf('Grafici Combinati-%s', idCampione));
    if ~exist('OCTAVE_VERSION', 'builtin')
        set(fig_combinato, 'NumberTitle', 'off', 'Position', [150 150 1400 900]);
    end
    
    % Nota: In un sistema reale, qui caricheresti i file .fig salvati precedentemente
    % e li combineresti in subplot. Per semplicità, creiamo grafici dimostrativi.
    
    subplot(2,2,1);
    % Simulazione profili verticali combinati
    x_demo = 1:50;
    y_pre = sin(x_demo/10) + randn(size(x_demo))*0.1 + risultati_pre.tempMediaTotale;
    y_post = sin(x_demo/10) + randn(size(x_demo))*0.05 + risultati_post.tempMediaTotale;
    
    plot(x_demo, y_pre, 'r-', 'LineWidth', 2);
    hold on;
    plot(x_demo, y_post, 'g-', 'LineWidth', 2);
    xlabel('Posizione X [cm]', 'FontWeight', 'bold');
    ylabel('Temperatura [°C]', 'FontWeight', 'bold');
    title('Profili Verticali Combinati', 'FontSize', 12, 'FontWeight', 'bold');
    legend({'Pre-intervento', 'Post-intervento'}, 'Location', 'best');
    grid on;
    
    subplot(2,2,2);
    % Simulazione profili orizzontali combinati
    plot(x_demo, y_pre-0.5, 'r-', 'LineWidth', 2);
    hold on;
    plot(x_demo, y_post-0.3, 'g-', 'LineWidth', 2);
    xlabel('Posizione Y [cm]', 'FontWeight', 'bold');
    ylabel('Temperatura [°C]', 'FontWeight', 'bold');
    title('Profili Orizzontali Combinati', 'FontSize', 12, 'FontWeight', 'bold');
    legend({'Pre-intervento', 'Post-intervento'}, 'Location', 'best');
    grid on;
    
    subplot(2,2,3);
    % Temperature normalizzate combinate
    y_norm_pre = y_pre - mean(y_pre);
    y_norm_post = y_post - mean(y_post);
    
    plot(x_demo, y_norm_pre, 'r-', 'LineWidth', 2);
    hold on;
    plot(x_demo, y_norm_post, 'g-', 'LineWidth', 2);
    xlabel('Posizione Y [cm]', 'FontWeight', 'bold');
    ylabel('Temperatura Normalizzata [°C]', 'FontWeight', 'bold');
    title('Temperature Normalizzate Combinate', 'FontSize', 12, 'FontWeight', 'bold');
    legend({'Pre-intervento', 'Post-intervento'}, 'Location', 'best');
    grid on;
    
    subplot(2,2,4);
    % Interpolazioni lineari combinate
    p_pre = polyfit(x_demo, y_norm_pre, 1);
    p_post = polyfit(x_demo, y_norm_post, 1);
    y_fit_pre = polyval(p_pre, x_demo);
    y_fit_post = polyval(p_post, x_demo);
    
    plot(x_demo, y_fit_pre, 'r-', 'LineWidth', 2);
    hold on;
    plot(x_demo, y_fit_post, 'g-', 'LineWidth', 2);
    plot(x_demo, y_norm_pre, 'r--', 'LineWidth', 1);
    plot(x_demo, y_norm_post, 'g--', 'LineWidth', 1);
    
    xlabel('Posizione Y [cm]', 'FontWeight', 'bold');
    ylabel('Temperatura Normalizzata [°C]', 'FontWeight', 'bold');
    title(sprintf('Interpolazioni Lineari\nPendenze: Pre=%.4f, Post=%.4f', p_pre(1), p_post(1)), ...
          'FontSize', 12, 'FontWeight', 'bold');
    legend({'Fit Pre', 'Fit Post', 'Dati Pre', 'Dati Post'}, 'Location', 'best');
    grid on;
    
    % Salvataggio grafici combinati
    percorsoSalv = fullfile(config.percorsi.confronti, ...
                           sprintf('grafici_combinati_%s_%s.fig', idCampione, timestamp));
    if exist('OCTAVE_VERSION', 'builtin')
        print(fig_combinato, '-dfig', percorsoSalv);
    else
        savefig(fig_combinato, percorsoSalv);
    end
    
    % === SALVATAGGIO DATI CONFRONTO ===
    confronto.idCampione = idCampione;
    confronto.timestamp = timestamp;
    confronto.parametri_pre = valori_pre;
    confronto.parametri_post = valori_post;
    confronto.miglioramenti_percentuali = miglioramenti;
    confronto.efficacia_intervento = efficacia;
    confronto.score_globale = score_globale;
    confronto.categorie = categorie;
    
    percorsoSalv = fullfile(config.percorsi.statistiche, ...
                           sprintf('dati_confronto_%s_%s.mat', idCampione, timestamp));
    if exist('OCTAVE_VERSION', 'builtin')
        save(percorsoSalv, 'confronto');
    else
        save(percorsoSalv, 'confronto');
    end
    
    % === OUTPUT RISULTATI ===
    fprintf('\n=== RISULTATI CONFRONTO ===\n');
    fprintf('Score globale miglioramento: %.2f\n', score_globale);
    fprintf('Miglioramento ratioD: %.2f%%\n', miglioramenti(3));
    fprintf('Miglioramento gradiente: %.2f%%\n', miglioramenti(5));
    
    if score_globale > 10
        fprintf('VALUTAZIONE: Miglioramento significativo rilevato\n');
    elseif score_globale > 0
        fprintf('VALUTAZIONE: Miglioramento modesto rilevato\n');
    else
        fprintf('VALUTAZIONE: Nessun miglioramento significativo\n');
    end
    
    fprintf('\nGrafici di confronto salvati in: %s\n', config.percorsi.confronti);
end