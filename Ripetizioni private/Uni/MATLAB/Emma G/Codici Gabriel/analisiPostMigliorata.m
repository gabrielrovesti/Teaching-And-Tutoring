function risultati_post = analisiPostMigliorata(termografia, config, idCampione)
    % ANALISIPOST_MIGLIORATA - Analisi post-intervento con etichettatura e salvataggio automatico
    %
    % Sintassi: risultati_post = analisiPostMigliorata(termografia, config, idCampione)
    %
    % Input:
    %   termografia - Matrice numerica della termografia
    %   config      - Struttura di configurazione da setupAmbienteAnalisi
    %   idCampione  - Identificativo del campione (stringa)
    %
    % Output:
    %   risultati_post - Struttura con tutti i risultati statistici
    %
    % Compatibilità: MATLAB e Octave
    
    if nargin < 3
        idCampione = 'Sconosciuto';
    end
    
    % Generazione timestamp per questa analisi
    if exist('OCTAVE_VERSION', 'builtin')
        % Octave
        timestamp = strftime('%H-%M-%S', localtime(time));
    else
        % MATLAB
        timestamp = datestr(now, 'HH-MM-SS');
    end
    
    % === VISUALIZZAZIONE TERMOGRAFIA INIZIALE ===
    fig_termo = figure('Name', sprintf('Termografia Post-%s', idCampione));
    if ~exist('OCTAVE_VERSION', 'builtin')
        set(fig_termo, 'NumberTitle', 'off', 'Position', [100 100 800 600]);
    end
    
    axes1 = axes('Parent', fig_termo);
    hold(axes1, 'on');
    surf(termografia, 'Parent', axes1, 'EdgeColor', 'none');
    view(axes1, [-180 90]);
    grid(axes1, 'on');
    
    % Colorbar compatibile
    c = colorbar(axes1);
    if exist('OCTAVE_VERSION', 'builtin')
        % In Octave il colorbar può essere gestito diversamente
        ylabel(c, 'Temperatura [°C]', 'FontSize', 12, 'FontWeight', 'bold');
    else
        % MATLAB
        c.Label.String = 'Temperatura [°C]';
        c.Label.FontSize = 12;
        c.Label.FontWeight = 'bold';
    end
    
    title(sprintf('Termografia Post-Intervento - Campione: %s', idCampione), ...
          'FontSize', 14, 'FontWeight', 'bold');
    
    % Salvataggio termografia
    percorsoSalv = fullfile(config.percorsi.termografie, ...
                           sprintf('termografia_post_%s_%s.fig', idCampione, timestamp));
    if exist('OCTAVE_VERSION', 'builtin')
        % Octave - usa print per salvare
        print(fig_termo, '-dfig', percorsoSalv);
    else
        % MATLAB
        savefig(fig_termo, percorsoSalv);
    end
    
    % === ROTAZIONE E PREPARAZIONE DATI ===
    IR = rot90(termografia);
    
    % === INPUT SELEZIONE REGIONE ===
    % Funzione di input compatibile con Octave/MATLAB
    prompt = {'Valore minimo asse X:', 'Valore massimo asse X:', ...
              'Valore minimo asse Y:', 'Valore massimo asse Y:'};
    titolo_dlg = sprintf('Selezione Regione - Post-intervento [%s]', idCampione);
    
    if exist('OCTAVE_VERSION', 'builtin')
        % Octave - input più semplice
        fprintf('\n=== SELEZIONE REGIONE POST - %s ===\n', idCampione);
        xi = input('Valore minimo asse X: ') + 1;
        xf = input('Valore massimo asse X: ');
        yi = input('Valore minimo asse Y: ') + 1;
        yf = input('Valore massimo asse Y: ');
    else
        % MATLAB - dialog più avanzato
        dims = [1 60];
        definput = {'1', '100', '1', '100'};
        answer = inputdlg(prompt, titolo_dlg, dims, definput);
        
        if isempty(answer)
            error('Analisi annullata dall''utente');
        end
        
        xi = str2double(answer{1}) + 1;
        xf = str2double(answer{2});
        yi = str2double(answer{3}) + 1;
        yf = str2double(answer{4});
    end
    
    % Validazione coordinate
    [maxY, maxX] = size(IR);
    if xf > maxX || xi < 1 || yf > maxY || yi < 1
        error('Regione selezionata fuori dai limiti immagine. Max X: %d, Max Y: %d', maxX, maxY);
    end
    
    % Estrazione regione di interesse
    subIR = IR(yi:yf, xi:xf);
    
    % === CALIBRAZIONE ===
    if exist('OCTAVE_VERSION', 'builtin')
        % Octave
        fprintf('\n=== CALIBRAZIONE POST ===\n');
        distanzaInPixel = input('Distanza in pixel: ');
        distanzaInCm = input('Distanza in centimetri: ');
    else
        % MATLAB
        prompt = {'Distanza in pixel:', 'Distanza in centimetri:'};
        titolo_dlg = 'Calibrazione - Conversione pixel in cm';
        dims = [1 60];
        definput = {'100', '50'};
        answer = inputdlg(prompt, titolo_dlg, dims, definput);
        
        distanzaInPixel = str2double(answer{1});
        distanzaInCm = str2double(answer{2});
    end
    
    fattoreCalibrazione = distanzaInPixel / distanzaInCm;
    
    % === CALCOLI STATISTICI ===
    V_AVG = mean(subIR);
    V_dev = std(subIR);
    sigmaV = mean(V_dev);
    Tot_AVG = mean(subIR(:));  % Compatibile con entrambi
    
    sz = size(subIR);
    h_subIR = sz(1);
    b_subIR = sz(2);
    
    % === GRAFICO PROFILI VERTICALI ===
    dH = linspace(0, (xf-xi)/fattoreCalibrazione, b_subIR);
    fig_vert_post = figure('Name', sprintf('Profili Verticali Post-%s', idCampione));
    if ~exist('OCTAVE_VERSION', 'builtin')
        set(fig_vert_post, 'NumberTitle', 'off', 'Position', [100 100 800 600]);
    end
    
    plot(dH, V_AVG, 'g-', 'LineWidth', 2.0);  % Verde per post-intervento
    hold on;
    plot(dH, V_AVG+2*V_dev, 'k--', 'LineWidth', 1.5);
    plot(dH, V_AVG-2*V_dev, 'k--', 'LineWidth', 1.5);
    
    xlabel('Posizione Orizzontale X [cm]', 'FontSize', 12, 'FontWeight', 'bold');
    ylabel('Temperatura Media [°C]', 'FontSize', 12, 'FontWeight', 'bold');
    title(sprintf('Profili Verticali Temperatura - Post-intervento\nCampione: %s | Analisi: %s', ...
          idCampione, timestamp), 'FontSize', 14, 'FontWeight', 'bold');
    
    % Legenda compatibile
    if exist('OCTAVE_VERSION', 'builtin')
        legend({'μ post-intervento', 'μ+2σ', 'μ−2σ'}, 'Location', 'best');
    else
        legend({'μ post-intervento', 'μ+2σ', 'μ−2σ'}, 'Location', 'best', 'FontSize', 10);
    end
    
    grid on;
    box on;
    set(gca, 'FontSize', 10);
    
    % Salvataggio con nomenclatura automatica
    percorsoSalv = fullfile(config.percorsi.grafici, ...
                           sprintf('profili_verticali_post_%s_%s.fig', idCampione, timestamp));
    if exist('OCTAVE_VERSION', 'builtin')
        print(fig_vert_post, '-dfig', percorsoSalv);
    else
        savefig(fig_vert_post, percorsoSalv);
    end
    
    % === PROFILI ORIZZONTALI ===
    tsubIR = subIR';
    H_AVG = mean(tsubIR);
    H_dev = std(tsubIR);
    sigmaH = mean(H_dev);
    
    dV = linspace(0, (yf-yi)/fattoreCalibrazione, h_subIR);
    fig_orr_post = figure('Name', sprintf('Profili Orizzontali Post-%s', idCampione));
    if ~exist('OCTAVE_VERSION', 'builtin')
        set(fig_orr_post, 'NumberTitle', 'off', 'Position', [150 150 800 600]);
    end
    
    plot(dV, H_AVG, 'g-', 'LineWidth', 2.0);  % Verde per post-intervento
    hold on;
    plot(dV, H_AVG+2*H_dev, 'k--', 'LineWidth', 1.5);
    plot(dV, H_AVG-2*H_dev, 'k--', 'LineWidth', 1.5);
    
    xlabel('Posizione Verticale Y [cm]', 'FontSize', 12, 'FontWeight', 'bold');
    ylabel('Temperatura Media [°C]', 'FontSize', 12, 'FontWeight', 'bold');
    title(sprintf('Profili Orizzontali Temperatura - Post-intervento\nCampione: %s | Analisi: %s', ...
          idCampione, timestamp), 'FontSize', 14, 'FontWeight', 'bold');
    
    if exist('OCTAVE_VERSION', 'builtin')
        legend({'μ post-intervento', 'μ+2σ', 'μ−2σ'}, 'Location', 'best');
    else
        legend({'μ post-intervento', 'μ+2σ', 'μ−2σ'}, 'Location', 'best', 'FontSize', 10);
    end
    
    grid on;
    box on;
    set(gca, 'FontSize', 10);
    
    percorsoSalv = fullfile(config.percorsi.grafici, ...
                           sprintf('profili_orizzontali_post_%s_%s.fig', idCampione, timestamp));
    if exist('OCTAVE_VERSION', 'builtin')
        print(fig_orr_post, '-dfig', percorsoSalv);
    else
        savefig(fig_orr_post, percorsoSalv);
    end
    
    % === TEMPERATURA NORMALIZZATA ===
    DH_AVG = H_AVG - Tot_AVG;
    fig_norm_post = figure('Name', sprintf('Temp Normalizzata Post-%s', idCampione));
    if ~exist('OCTAVE_VERSION', 'builtin')
        set(fig_norm_post, 'NumberTitle', 'off', 'Position', [200 200 800 600]);
    end
    
    plot(dV, DH_AVG, 'g-', 'LineWidth', 2.0);  % Verde per post-intervento
    hold on;
    plot(dV, DH_AVG+2*H_dev, 'k--', 'LineWidth', 1.5);
    plot(dV, DH_AVG-2*H_dev, 'k--', 'LineWidth', 1.5);
    
    xlabel('Posizione Verticale Y [cm]', 'FontSize', 12, 'FontWeight', 'bold');
    ylabel('Temperatura Normalizzata [°C]', 'FontSize', 12, 'FontWeight', 'bold');
    title(sprintf('Normalizzazione Temperatura - Post-intervento\nCampione: %s | Analisi: %s', ...
          idCampione, timestamp), 'FontSize', 14, 'FontWeight', 'bold');
    
    if exist('OCTAVE_VERSION', 'builtin')
        legend({'μ post-intervento', 'μ+2σ', 'μ−2σ'}, 'Location', 'best');
    else
        legend({'μ post-intervento', 'μ+2σ', 'μ−2σ'}, 'Location', 'best', 'FontSize', 10);
    end
    
    grid on;
    box on;
    set(gca, 'FontSize', 10);
    
    percorsoSalv = fullfile(config.percorsi.grafici, ...
                           sprintf('temperatura_normalizzata_post_%s_%s.fig', idCampione, timestamp));
    if exist('OCTAVE_VERSION', 'builtin')
        print(fig_norm_post, '-dfig', percorsoSalv);
    else
        savefig(fig_norm_post, percorsoSalv);
    end
    
    % === INTERPOLAZIONE LINEARE ===
    T_int = polyfit(dV, DH_AVG, 1);
    m = T_int(1);
    q = T_int(2);
    r_int = T_int(2) + T_int(1) * dV;
    
    fig_int_post = figure('Name', sprintf('Interpolazione Lineare Post-%s', idCampione));
    if ~exist('OCTAVE_VERSION', 'builtin')
        set(fig_int_post, 'NumberTitle', 'off', 'Position', [250 250 800 600]);
    end
    
    plot(dV, r_int, 'g-', 'LineWidth', 2.0);  % Verde per post-intervento
    hold on;
    plot(dV, DH_AVG, 'g--', 'LineWidth', 1.5);
    
    xlabel('Posizione Verticale Y [cm]', 'FontSize', 12, 'FontWeight', 'bold');
    ylabel('Temperatura Normalizzata [°C]', 'FontSize', 12, 'FontWeight', 'bold');
    title(sprintf('Analisi Interpolazione Lineare - Post-intervento\nCampione: %s | Pendenza: %.4f | Intercetta: %.4f', ...
          idCampione, m, q), 'FontSize', 14, 'FontWeight', 'bold');
    
    if exist('OCTAVE_VERSION', 'builtin')
        legend({'Interpolazione lineare post', 'μ post-intervento'}, 'Location', 'best');
    else
        legend({'Interpolazione lineare post', 'μ post-intervento'}, 'Location', 'best', 'FontSize', 10);
    end
    
    grid on;
    box on;
    set(gca, 'FontSize', 10);
    
    percorsoSalv = fullfile(config.percorsi.grafici, ...
                           sprintf('interpolazione_lineare_post_%s_%s.fig', idCampione, timestamp));
    if exist('OCTAVE_VERSION', 'builtin')
        print(fig_int_post, '-dfig', percorsoSalv);
    else
        savefig(fig_int_post, percorsoSalv);
    end
    
    % === CALCOLO GRADIENTE ===
    L = max(dV);
    max_DH = max(DH_AVG);
    min_DH = min(DH_AVG);
    grad_post = (max_DH - min_DH) / L;
    
    % === STRUTTURA RISULTATI ===
    risultati_post.idCampione = idCampione;
    risultati_post.timestamp = timestamp;
    risultati_post.sigmaV = sigmaV;
    risultati_post.sigmaH = sigmaH;
    risultati_post.ratioD = sigmaV / sigmaH;
    risultati_post.deltaD = sigmaV - sigmaH;
    risultati_post.gradiente = grad_post;
    risultati_post.pendenza = m;
    risultati_post.intercetta = q;
    risultati_post.fattoreCalibrazione = fattoreCalibrazione;
    risultati_post.regione = [xi-1, xf, yi-1, yf];
    risultati_post.tempMediaTotale = Tot_AVG;
    
    % Salvataggio dati statistici
    percorsoSalv = fullfile(config.percorsi.statistiche, ...
                           sprintf('risultati_post_%s_%s.mat', idCampione, timestamp));
    if exist('OCTAVE_VERSION', 'builtin')
        save(percorsoSalv, 'risultati_post');
    else
        save(percorsoSalv, 'risultati_post');
    end
    
    % === OUTPUT CONSOLE ===
    fprintf('\n=== ANALISI POST-INTERVENTO COMPLETATA ===\n');
    fprintf('Campione: %s\n', idCampione);
    fprintf('σV: %.4f | σH: %.4f | ratioD: %.4f | gradiente: %.4f\n', ...
            sigmaV, sigmaH, sigmaV/sigmaH, grad_post);
    fprintf('Pendenza interpolazione: %.4f | Intercetta: %.4f\n', m, q);
    fprintf('File salvati in: %s\n', config.percorsi.grafici);
end