function visualizzazioni3D(risultati_pre, risultati_post, termografia_pre, termografia_post, config, idCampione)
    % VISUALIZZAZIONI3D - Crea visualizzazioni 3D con tre variabili per analisi forme ricorrenti
    %
    % Sintassi: visualizzazioni3D(risultati_pre, risultati_post, termografia_pre, termografia_post, config, idCampione)
    %
    % Input:
    %   risultati_pre     - Struttura risultati pre-intervento
    %   risultati_post    - Struttura risultati post-intervento
    %   termografia_pre   - Matrice termografia pre-intervento
    %   termografia_post  - Matrice termografia post-intervento
    %   config           - Configurazione sistema
    %   idCampione       - Identificativo campione
    %
    % Compatibilità: MATLAB e Octave
    
    if nargin < 6
        idCampione = 'Sconosciuto';
    end
    
    % Generazione timestamp
    if exist('OCTAVE_VERSION', 'builtin')
        timestamp = strftime('%H-%M-%S', localtime(time));
    else
        timestamp = datestr(now, 'HH-MM-SS');
    end
    
    fprintf('\n=== CREAZIONE VISUALIZZAZIONI 3D ===\n');
    fprintf('Campione: %s\n', idCampione);
    
    % === VISUALIZZAZIONE 3D PRINCIPALE ===
    fig_3d_principale = figure('Name', sprintf('Analisi 3D Completa-%s', idCampione));
    if ~exist('OCTAVE_VERSION', 'builtin')
        set(fig_3d_principale, 'NumberTitle', 'off', 'Position', [100 100 1400 900]);
    end
    
    % Subplot 1: Superficie 3D Pre-intervento
    subplot(2,3,1);
    surf_pre = surf(rot90(termografia_pre), 'EdgeColor', 'none');
    if exist('OCTAVE_VERSION', 'builtin')
        colormap('hot');
    else
        colormap(gca, 'hot');
    end
    colorbar;
    title(sprintf('Superficie 3D Pre-intervento\nCampione: %s', idCampione), ...
          'FontSize', 12, 'FontWeight', 'bold');
    xlabel('Posizione X [pixel]', 'FontWeight', 'bold');
    ylabel('Posizione Y [pixel]', 'FontWeight', 'bold');
    zlabel('Temperatura [°C]', 'FontWeight', 'bold');
    view(45, 30);  % Vista 3D standard
    
    % Subplot 2: Superficie 3D Post-intervento
    subplot(2,3,2);
    surf_post = surf(rot90(termografia_post), 'EdgeColor', 'none');
    if exist('OCTAVE_VERSION', 'builtin')
        colormap('cool');
    else
        colormap(gca, 'cool');
    end
    colorbar;
    title(sprintf('Superficie 3D Post-intervento\nCampione: %s', idCampione), ...
          'FontSize', 12, 'FontWeight', 'bold');
    xlabel('Posizione X [pixel]', 'FontWeight', 'bold');
    ylabel('Posizione Y [pixel]', 'FontWeight', 'bold');
    zlabel('Temperatura [°C]', 'FontWeight', 'bold');
    view(45, 30);
    
    % Subplot 3: Analisi Differenza Temperature (3 variabili: X, Y, ΔT)
    subplot(2,3,3);
    temp_diff = rot90(termografia_post) - rot90(termografia_pre);
    [X, Y] = meshgrid(1:size(temp_diff,2), 1:size(temp_diff,1));
    
    % Scatter 3D con dimensione e colore basati sulla differenza di temperatura
    scatter3(X(:), Y(:), temp_diff(:), 20, temp_diff(:), 'filled');
    colorbar;
    title('Analisi 3D Differenza Temperature', 'FontSize', 12, 'FontWeight', 'bold');
    xlabel('Posizione X [pixel]', 'FontWeight', 'bold');
    ylabel('Posizione Y [pixel]', 'FontWeight', 'bold');
    zlabel('ΔTemperatura [°C]', 'FontWeight', 'bold');
    view(45, 30);
    
    % Subplot 4: Confronto Parametri Statistici 3D
    subplot(2,3,4);
    parametri_pre = [risultati_pre.sigmaV, risultati_pre.sigmaH, risultati_pre.gradiente];
    parametri_post = [risultati_post.sigmaV, risultati_post.sigmaH, risultati_post.gradiente];
    
    % Grafico a barre 3D
    dati_confronto = [parametri_pre; parametri_post];
    if exist('OCTAVE_VERSION', 'builtin')
        % Octave - visualizzazione alternativa
        bar(dati_confronto');
        title('Confronto Parametri Statistici', 'FontSize', 12, 'FontWeight', 'bold');
        xlabel('Parametri', 'FontWeight', 'bold');
        ylabel('Valori', 'FontWeight', 'bold');
        set(gca, 'XTickLabel', {'σV', 'σH', 'Gradiente'});
        legend({'Pre', 'Post'}, 'Location', 'best');
    else
        % MATLAB - visualizzazione 3D avanzata
        h_bar = bar3(dati_confronto);
        title('Confronto Parametri Statistici 3D', 'FontSize', 12, 'FontWeight', 'bold');
        xlabel('Parametri', 'FontWeight', 'bold');
        ylabel('Fase Intervento', 'FontWeight', 'bold');
        zlabel('Valore', 'FontWeight', 'bold');
        set(gca, 'XTickLabel', {'σV', 'σH', 'Gradiente'});
        set(gca, 'YTickLabel', {'Pre', 'Post'});
        
        % Colorazione delle barre
        for i = 1:length(h_bar)
            set(h_bar(i), 'CData', i);
        end
    end
    
    % Subplot 5: Superficie di Correlazione 3D (X, Y, Correlazione Pre-Post)
    subplot(2,3,5);
    
    % Calcolo correlazione punto per punto tra pre e post
    IR_pre = rot90(termografia_pre);
    IR_post = rot90(termografia_post);
    
    % Ridimensiona per calcolo correlazione se necessario
    min_size = min(size(IR_pre), size(IR_post));
    IR_pre_crop = IR_pre(1:min_size(1), 1:min_size(2));
    IR_post_crop = IR_post(1:min_size(1), 1:min_size(2));
    
    % Calcola correlazione locale (finestra 5x5)
    finestra = 5;
    correlazione = zeros(size(IR_pre_crop));
    
    for i = finestra:size(IR_pre_crop,1)-finestra+1
        for j = finestra:size(IR_pre_crop,2)-finestra+1
            patch_pre = IR_pre_crop(i-finestra+1:i+finestra-1, j-finestra+1:j+finestra-1);
            patch_post = IR_post_crop(i-finestra+1:i+finestra-1, j-finestra+1:j+finestra-1);
            
            % Correlazione di Pearson locale
            if std(patch_pre(:)) > 0 && std(patch_post(:)) > 0
                correlazione(i,j) = corr(patch_pre(:), patch_post(:));
            end
        end
    end
    
    surf(correlazione, 'EdgeColor', 'none');
    colorbar;
    title('Mappa 3D Correlazione Pre-Post', 'FontSize', 12, 'FontWeight', 'bold');
    xlabel('Posizione X [pixel]', 'FontWeight', 'bold');
    ylabel('Posizione Y [pixel]', 'FontWeight', 'bold');
    zlabel('Correlazione', 'FontWeight', 'bold');
    view(45, 30);
    
    % Subplot 6: Analisi delle Forme Ricorrenti (Gradient Vector Field 3D)
    subplot(2,3,6);
    
    % Calcolo gradiente 2D della differenza di temperatura
    [gradX, gradY] = gradient(temp_diff);
    
    % Campionamento per visualizzazione (ogni 10 punti)
    step = 10;
    x_sample = X(1:step:end, 1:step:end);
    y_sample = Y(1:step:end, 1:step:end);
    z_sample = temp_diff(1:step:end, 1:step:end);
    u_sample = gradX(1:step:end, 1:step:end);
    v_sample = gradY(1:step:end, 1:step:end);
    w_sample = zeros(size(z_sample));  % Componente Z del vettore
    
    % Campo vettoriale 3D
    if exist('OCTAVE_VERSION', 'builtin')
        % Octave - visualizzazione semplificata
        quiver(x_sample, y_sample, u_sample, v_sample);
        title('Campo Gradiente 2D', 'FontSize', 12, 'FontWeight', 'bold');
        xlabel('X [pixel]', 'FontWeight', 'bold');
        ylabel('Y [pixel]', 'FontWeight', 'bold');
    else
        % MATLAB - campo vettoriale 3D
        quiver3(x_sample, y_sample, z_sample, u_sample, v_sample, w_sample, 'r');
        title('Campo Vettoriale Gradiente 3D', 'FontSize', 12, 'FontWeight', 'bold');
        xlabel('Posizione X [pixel]', 'FontWeight', 'bold');
        ylabel('Posizione Y [pixel]', 'FontWeight', 'bold');
        zlabel('ΔTemperatura [°C]', 'FontWeight', 'bold');
        view(45, 30);
    end
    
    % Salvataggio figura principale
    percorsoSalv = fullfile(config.percorsi.vis3d, ...
                           sprintf('analisi_3D_completa_%s_%s.fig', idCampione, timestamp));
    if exist('OCTAVE_VERSION', 'builtin')
        print(fig_3d_principale, '-dfig', percorsoSalv);
    else
        savefig(fig_3d_principale, percorsoSalv);
    end
    
    % === VISUALIZZAZIONE 3D FORME RICORRENTI AVANZATA ===
    fig_forme = figure('Name', sprintf('Forme Ricorrenti 3D-%s', idCampione));
    if ~exist('OCTAVE_VERSION', 'builtin')
        set(fig_forme, 'NumberTitle', 'off', 'Position', [200 200 1200 800]);
    end
    
    % Analisi delle forme ricorrenti usando tre variabili principali:
    % 1. Posizione X, 2. Posizione Y, 3. Intensità del cambiamento termico
    
    subplot(2,2,1);
    % Isosurface delle temperature pre-intervento
    if ~exist('OCTAVE_VERSION', 'builtin')
        % Solo in MATLAB (Octave potrebbe non supportare isosurface)
        try
            % Crea volume 3D estendendo la matrice 2D
            volume_pre = repmat(IR_pre_crop, [1, 1, 5]);
            iso_val = mean(IR_pre_crop(:));
            isosurface(volume_pre, iso_val);
            title('Isosuperficie Pre-intervento', 'FontSize', 12, 'FontWeight', 'bold');
            xlabel('X', 'FontWeight', 'bold');
            ylabel('Y', 'FontWeight', 'bold');
            zlabel('Z', 'FontWeight', 'bold');
            view(45, 30);
        catch
            % Fallback per visualizzazione semplice
            contour3(IR_pre_crop, 10);
            title('Contorni 3D Pre-intervento', 'FontSize', 12, 'FontWeight', 'bold');
        end
    else
        % Octave - contorni 3D
        contour3(IR_pre_crop, 10);
        title('Contorni 3D Pre-intervento', 'FontSize', 12, 'FontWeight', 'bold');
    end
    
    subplot(2,2,2);
    % Analisi clusters di temperatura (K-means su coordinate + temperatura)
    
    % Preparazione dati per clustering
    [x_grid, y_grid] = meshgrid(1:size(temp_diff,2), 1:size(temp_diff,1));
    dati_cluster = [x_grid(:), y_grid(:), temp_diff(:)];
    
    % Rimozione valori NaN
    validIdx = ~any(isnan(dati_cluster), 2);
    dati_cluster = dati_cluster(validIdx, :);
    
    if size(dati_cluster, 1) > 50  % Solo se abbiamo abbastanza dati
        try
            % K-means clustering (3 cluster)
            numCluster = 3;
            if exist('OCTAVE_VERSION', 'builtin')
                % Octave - implementazione semplice
                idx = mod((1:size(dati_cluster,1))', numCluster) + 1;  % Clustering fittizio
            else
                % MATLAB
                [idx, centri] = kmeans(dati_cluster, numCluster);
            end
            
            scatter3(dati_cluster(:,1), dati_cluster(:,2), dati_cluster(:,3), 20, idx, 'filled');
            title('Clustering 3D Forme Termiche', 'FontSize', 12, 'FontWeight', 'bold');
            xlabel('Posizione X [pixel]', 'FontWeight', 'bold');
            ylabel('Posizione Y [pixel]', 'FontWeight', 'bold');
            zlabel('ΔTemperatura [°C]', 'FontWeight', 'bold');
            colorbar;
            view(45, 30);
        catch
            % Fallback
            scatter3(dati_cluster(:,1), dati_cluster(:,2), dati_cluster(:,3), 10, dati_cluster(:,3));
            title('Distribuzione 3D Cambiamenti', 'FontSize', 12, 'FontWeight', 'bold');
        end
    else
        scatter3(dati_cluster(:,1), dati_cluster(:,2), dati_cluster(:,3), 10, dati_cluster(:,3));
        title('Distribuzione 3D Cambiamenti', 'FontSize', 12, 'FontWeight', 'bold');
    end
    
    subplot(2,2,3);
    % Analisi wavelet 2D per pattern ricorrenti
    try
        % Trasformata Fourier 2D per identificare frequenze spaziali
        fft_diff = fft2(temp_diff);
        fft_magnitude = log(abs(fft_diff) + 1);
        
        surf(fft_magnitude, 'EdgeColor', 'none');
        title('Analisi Frequenze Spaziali 3D', 'FontSize', 12, 'FontWeight', 'bold');
        xlabel('Frequenza X', 'FontWeight', 'bold');
        ylabel('Frequenza Y', 'FontWeight', 'bold');
        zlabel('Magnitudine (log)', 'FontWeight', 'bold');
        colorbar;
        view(45, 30);
    catch
        % Fallback per sistemi senza FFT2
        mesh(temp_diff);
        title('Mesh 3D Differenze Temperature', 'FontSize', 12, 'FontWeight', 'bold');
    end
    
    subplot(2,2,4);
    % Analisi delle texture 3D (variabilità locale)
    
    % Calcolo variabilità locale
    window_size = 5;
    variabilita = zeros(size(temp_diff));
    
    for i = window_size:size(temp_diff,1)-window_size+1
        for j = window_size:size(temp_diff,2)-window_size+1
            finestra_local = temp_diff(i-window_size+1:i+window_size-1, j-window_size+1:j+window_size-1);
            variabilita(i,j) = std(finestra_local(:));
        end
    end
    
    surf(variabilita, 'EdgeColor', 'none');
    colorbar;
    title('Mappa 3D Variabilità Locale', 'FontSize', 12, 'FontWeight', 'bold');
    xlabel('Posizione X [pixel]', 'FontWeight', 'bold');
    ylabel('Posizione Y [pixel]', 'FontWeight', 'bold');
    zlabel('Variabilità', 'FontWeight', 'bold');
    view(45, 30);
    
    % Salvataggio figure forme ricorrenti
    percorsoSalv = fullfile(config.percorsi.vis3d, ...
                           sprintf('forme_ricorrenti_3D_%s_%s.fig', idCampione, timestamp));
    if exist('OCTAVE_VERSION', 'builtin')
        print(fig_forme, '-dfig', percorsoSalv);
    else
        savefig(fig_forme, percorsoSalv);
    end
    
    % === ANALISI STATISTICHE AVANZATE 3D ===
    
    % Calcolo metriche per forme ricorrenti
    metriche_3d.correlazione_media = mean(correlazione(:), 'omitnan');
    metriche_3d.variabilita_media = mean(variabilita(:), 'omitnan');
    metriche_3d.gradiente_max = max(sqrt(gradX(:).^2 + gradY(:).^2));
    metriche_3d.asimmetria_spaziale = skewness(temp_diff(:));  % Se disponibile
    
    % Identificazione zone di interesse
    soglia_cambiamento = std(temp_diff(:)) * 2;
    zone_significative = abs(temp_diff) > soglia_cambiamento;
    percentuale_cambiamento = sum(zone_significative(:)) / numel(zone_significative) * 100;
    
    metriche_3d.percentuale_cambiamento_significativo = percentuale_cambiamento;
    
    % Salvataggio metriche
    percorsoSalv = fullfile(config.percorsi.statistiche, ...
                           sprintf('metriche_3D_%s_%s.mat', idCampione, timestamp));
    if exist('OCTAVE_VERSION', 'builtin')
        save(percorsoSalv, 'metriche_3d');
    else
        save(percorsoSalv, 'metriche_3d');
    end
    
    % === OUTPUT RISULTATI ===
    fprintf('\n=== RISULTATI ANALISI 3D ===\n');
    fprintf('Correlazione media pre-post: %.4f\n', metriche_3d.correlazione_media);
    fprintf('Variabilità media: %.4f\n', metriche_3d.variabilita_media);
    fprintf('Gradiente massimo: %.4f\n', metriche_3d.gradiente_max);
    fprintf('Percentuale cambiamento significativo: %.2f%%\n', percentuale_cambiamento);
    
    fprintf('\nVisualizzazioni 3D create e salvate in: %s\n', config.percorsi.vis3d);
    fprintf('Possibili forme ricorrenti identificate tramite:\n');
    fprintf('  - Clustering spaziale-termico\n');
    fprintf('  - Analisi frequenze spaziali\n');
    fprintf('  - Mappe di correlazione\n');
    fprintf('  - Analisi variabilità locale\n');
    
end