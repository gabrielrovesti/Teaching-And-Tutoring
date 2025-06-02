function mainSistemaCompleto(mat_pre, mat_post, nomeProgetto, idCampione)
    % MAINSISTEMACOMPLETO - Script principale per analisi termografica automatizzata
    %
    % Sintassi: mainSistemaCompleto(mat_pre, mat_post, nomeProgetto, idCampione)
    %
    % Input:
    %   mat_pre      - Matrice termografia pre-intervento
    %   mat_post     - Matrice termografia post-intervento  
    %   nomeProgetto - Nome del progetto (opzionale)
    %   idCampione   - Identificativo campione (opzionale)
    %
    % Esempio d'uso:
    %   load('T04_1129.mat');
    %   load('T04_2_1129.mat');
    %   mainSistemaCompleto(T04_1129, T04_2_1129, 'StudioUmidita2024', 'T04_Campione');
    %
    % Compatibilità: MATLAB e Octave
    
    % === GESTIONE PARAMETRI INPUT ===
    if nargin < 4
        if exist('OCTAVE_VERSION', 'builtin')
            idCampione = sprintf('Campione_%s', strftime('%H%M%S', localtime(time)));
        else
            idCampione = sprintf('Campione_%s', datestr(now, 'HHMMSS'));
        end
    end
    
    if nargin < 3
        nomeProgetto = 'AnalisiTermica';
    end
    
    if nargin < 2
        error('Sono necessarie almeno due matrici: mat_pre e mat_post');
    end
    
    % === CONTROLLI PRELIMINARI ===
    fprintf('\n=================================================================\n');
    fprintf('    SISTEMA AUTOMATIZZATO ANALISI TERMOGRAFICA AVANZATO\n');
    fprintf('         Studio Umidità di Risalita CNT-APPs\n');
    fprintf('=================================================================\n\n');
    
    % Verifica presenza matrici
    if isempty(mat_pre) || isempty(mat_post)
        error('Le matrici di input non possono essere vuote');
    end
    
    % Verifica dimensioni matrici
    fprintf('Controllo matrici input:\n');
    fprintf('  - Matrice pre-intervento: %dx%d\n', size(mat_pre, 1), size(mat_pre, 2));
    fprintf('  - Matrice post-intervento: %dx%d\n', size(mat_post, 1), size(mat_post, 2));
    
    if size(mat_pre, 1) < 10 || size(mat_pre, 2) < 10
        warning('Matrice pre-intervento molto piccola - risultati potrebbero essere inaffidabili');
    end
    
    if size(mat_post, 1) < 10 || size(mat_post, 2) < 10
        warning('Matrice post-intervento molto piccola - risultati potrebbero essere inaffidabili');
    end
    
    % Verifica range temperature
    range_pre = [min(mat_pre(:)), max(mat_pre(:))];
    range_post = [min(mat_post(:)), max(mat_post(:))];
    
    fprintf('  - Range temperature pre: %.2f - %.2f °C\n', range_pre(1), range_pre(2));
    fprintf('  - Range temperature post: %.2f - %.2f °C\n', range_post(1), range_post(2));
    
    if range_pre(2) - range_pre(1) < 1
        warning('Range temperature pre-intervento molto limitato (<1°C)');
    end
    
    if range_post(2) - range_post(1) < 1
        warning('Range temperature post-intervento molto limitato (<1°C)');
    end
    
    fprintf('✓ Controlli preliminari completati\n\n');
    
    % === INIZIALIZZAZIONE SISTEMA ===
    try
        fprintf('FASE 1: Inizializzazione ambiente analisi...\n');
        config = setupAmbienteAnalisi(nomeProgetto);
        fprintf('✓ Ambiente inizializzato: %s\n\n', config.cartellaP);
        
        % Salva configurazione estesa
        config.matrici.pre_size = size(mat_pre);
        config.matrici.post_size = size(mat_post);
        config.matrici.pre_range = range_pre;
        config.matrici.post_range = range_post;
        config.analisi.idCampione = idCampione;
        
        if exist('OCTAVE_VERSION', 'builtin')
            config.analisi.software = sprintf('GNU Octave %s', version);
            config.analisi.timestamp_inizio = strftime('%Y-%m-%d %H:%M:%S', localtime(time));
        else
            config.analisi.software = sprintf('MATLAB %s', version);
            config.analisi.timestamp_inizio = datestr(now, 'yyyy-mm-dd HH:MM:SS');
        end
        
        % Salva configurazione estesa
        save(fullfile(config.cartellaP, 'configurazione_completa.mat'), 'config');
        
    catch ME
        fprintf('❌ ERRORE nell''inizializzazione: %s\n', ME.message);
        rethrow(ME);
    end
    
    % === ANALISI PRE-INTERVENTO ===
    try
        fprintf('FASE 2: Avvio analisi pre-intervento...\n');
        risultati_pre = analisiPreMigliorata(mat_pre, config, idCampione);
        fprintf('✓ Analisi pre-intervento completata\n\n');
        
    catch ME
        fprintf('❌ ERRORE nell''analisi pre-intervento: %s\n', ME.message);
        
        % Tentativo di recupero con parametri automatici
        fprintf('Tentativo recupero con parametri automatici...\n');
        try
            risultati_pre = analisiPreAutomatica(mat_pre, config, idCampione);
            fprintf('✓ Recupero riuscito con parametri automatici\n\n');
        catch ME2
            fprintf('❌ Recupero fallito: %s\n', ME2.message);
            rethrow(ME);
        end
    end
    
    % === ANALISI POST-INTERVENTO ===
    try
        fprintf('FASE 3: Avvio analisi post-intervento...\n');
        risultati_post = analisiPostMigliorata(mat_post, config, idCampione);
        fprintf('✓ Analisi post-intervento completata\n\n');
        
    catch ME
        fprintf('❌ ERRORE nell''analisi post-intervento: %s\n', ME.message);
        
        % Tentativo di recupero con parametri automatici
        fprintf('Tentativo recupero con parametri automatici...\n');
        try
            risultati_post = analisiPostAutomatica(mat_post, config, idCampione);
            fprintf('✓ Recupero riuscito con parametri automatici\n\n');
        catch ME2
            fprintf('❌ Recupero fallito: %s\n', ME2.message);
            rethrow(ME);
        end
    end
    
    % === VISUALIZZAZIONI 3D ===
    try
        fprintf('FASE 4: Creazione visualizzazioni 3D...\n');
        visualizzazioni3D(risultati_pre, risultati_post, mat_pre, mat_post, config, idCampione);
        fprintf('✓ Visualizzazioni 3D completate\n\n');
        
        % Carica metriche 3D se disponibili
        try
            metriche_file = fullfile(config.percorsi.statistiche, ...
                                   sprintf('metriche_3D_%s_*.mat', idCampione));
            file_list = dir(metriche_file);
            if ~isempty(file_list)
                % Carica il file più recente
                [~, idx] = max([file_list.datenum]);
                load(fullfile(file_list(idx).folder, file_list(idx).name), 'metriche_3d');
            else
                metriche_3d = [];
            end
        catch
            metriche_3d = [];
            fprintf('⚠️  Metriche 3D non disponibili per il report\n');
        end
        
    catch ME
        fprintf('❌ ERRORE nelle visualizzazioni 3D: %s\n', ME.message);
        fprintf('Continuando senza visualizzazioni 3D...\n\n');
        metriche_3d = [];
    end
    
    % === GRAFICI DI CONFRONTO ===
    try
        fprintf('FASE 5: Generazione grafici di confronto...\n');
        graficiConfronto(risultati_pre, risultati_post, config, idCampione);
        fprintf('✓ Grafici di confronto completati\n\n');
        
    catch ME
        fprintf('❌ ERRORE nei grafici di confronto: %s\n', ME.message);
        fprintf('Continuando senza grafici di confronto dettagliati...\n\n');
    end
    
    % === GENERAZIONE REPORT ===
    try
        fprintf('FASE 6: Generazione report automatico...\n');
        generaReport(risultati_pre, risultati_post, config, idCampione, metriche_3d);
        fprintf('✓ Report automatico generato\n\n');
        
    catch ME
        fprintf('❌ ERRORE nella generazione report: %s\n', ME.message);
        fprintf('Continuando senza report automatico...\n\n');
    end
    
    % === RIEPILOGO FINALE ===
    fprintf('=================================================================\n');
    fprintf('                    ANALISI COMPLETATA CON SUCCESSO\n');
    fprintf('=================================================================\n\n');
    
    fprintf('RISULTATI PRINCIPALI:\n');
    fprintf('Progetto: %s\n', nomeProgetto);
    fprintf('Campione: %s\n', idCampione);
    fprintf('Directory output: %s\n\n', config.cartellaP);
    
    % Calcolo metriche finali
    miglioramento_ratioD = ((risultati_pre.ratioD - risultati_post.ratioD) / risultati_pre.ratioD) * 100;
    miglioramento_gradiente = ((abs(risultati_pre.gradiente) - abs(risultati_post.gradiente)) / abs(risultati_pre.gradiente)) * 100;
    
    fprintf('PARAMETRI PRE-INTERVENTO:\n');
    fprintf('  σV: %.4f | σH: %.4f | RatioD: %.4f | Gradiente: %.6f\n', ...
            risultati_pre.sigmaV, risultati_pre.sigmaH, risultati_pre.ratioD, risultati_pre.gradiente);
    
    fprintf('PARAMETRI POST-INTERVENTO:\n');
    fprintf('  σV: %.4f | σH: %.4f | RatioD: %.4f | Gradiente: %.6f\n', ...
            risultati_post.sigmaV, risultati_post.sigmaH, risultati_post.ratioD, risultati_post.gradiente);
    
    fprintf('MIGLIORAMENTI:\n');
    fprintf('  RatioD: %.2f%% | Gradiente: %.2f%%\n\n', miglioramento_ratioD, miglioramento_gradiente);
    
    % Valutazione finale
    score_globale = (max(0, miglioramento_ratioD) + max(0, miglioramento_gradiente)) / 2;
    
    if score_globale > 15
        valutazione = '🟢 ECCELLENTE';
    elseif score_globale > 10
        valutazione = '🟡 BUONO';
    elseif score_globale > 5
        valutazione = '🟠 MODERATO';
    else
        valutazione = '🔴 LIMITATO';
    end
    
    fprintf('VALUTAZIONE FINALE: %s (Score: %.2f)\n\n', valutazione, score_globale);
    
    % Lista file generati
    fprintf('FILE GENERATI:\n');
    fprintf('📁 Termografie elaborate: %d file\n', length(dir(fullfile(config.percorsi.termografie, '*.fig'))));
    fprintf('📊 Grafici elaborati: %d file\n', length(dir(fullfile(config.percorsi.grafici, '*.fig'))));
    fprintf('📈 Grafici confronto: %d file\n', length(dir(fullfile(config.percorsi.confronti, '*.fig'))));
    fprintf('🎯 Visualizzazioni 3D: %d file\n', length(dir(fullfile(config.percorsi.vis3d, '*.fig'))));
    fprintf('📋 Dati statistici: %d file\n', length(dir(fullfile(config.percorsi.statistiche, '*.mat'))));
    fprintf('📄 Report: %d file\n', length(dir(fullfile(config.percorsi.report, '*.txt'))));
    
    fprintf('\n=================================================================\n');
    fprintf('Per visualizzare i risultati, navigare in: %s\n', config.cartellaP);
    fprintf('=================================================================\n\n');
    
    % Salvataggio risultati principali in workspace
    if exist('OCTAVE_VERSION', 'builtin')
        % Octave
        assignin('base', 'risultati_analisi_pre', risultati_pre);
        assignin('base', 'risultati_analisi_post', risultati_post);
        assignin('base', 'config_analisi', config);
    else
        % MATLAB
        assignin('base', 'risultati_analisi_pre', risultati_pre);
        assignin('base', 'risultati_analisi_post', risultati_post);
        assignin('base', 'config_analisi', config);
    end
    
    fprintf('✓ Risultati salvati nel workspace come:\n');
    fprintf('  - risultati_analisi_pre\n');
    fprintf('  - risultati_analisi_post\n');
    fprintf('  - config_analisi\n\n');
    
end

% === FUNZIONI AUSILIARIE DI RECUPERO ===

function risultati_pre = analisiPreAutomatica(mat_pre, config, idCampione)
    % Versione automatica con parametri predefiniti in caso di errore nell'input
    
    fprintf('Utilizzando parametri automatici per analisi pre-intervento...\n');
    
    % Parametri automatici basati sulle dimensioni della matrice
    [h, w] = size(rot90(mat_pre));
    
    % Regione automatica (80% centrale)
    margine_x = round(w * 0.1);
    margine_y = round(h * 0.1);
    
    xi = margine_x + 1;
    xf = w - margine_x;
    yi = margine_y + 1;
    yf = h - margine_y;
    
    % Calibrazione automatica (stima 1 pixel = 1 cm)
    fattoreCalibrazione = 1.0;
    
    % Continua con l'analisi usando parametri automatici...
    % (implementazione semplificata)
    
    IR = rot90(mat_pre);
    subIR = IR(yi:yf, xi:xf);
    
    V_AVG = mean(subIR);
    V_dev = std(subIR);
    sigmaV = mean(V_dev);
    Tot_AVG = mean(subIR(:));
    
    tsubIR = subIR';
    H_AVG = mean(tsubIR);
    H_dev = std(tsubIR);
    sigmaH = mean(H_dev);
    
    sz = size(subIR);
    h_subIR = sz(1);
    
    dV = linspace(0, (yf-yi)/fattoreCalibrazione, h_subIR);
    DH_AVG = H_AVG - Tot_AVG;
    
    T_int = polyfit(dV, DH_AVG, 1);
    m = T_int(1);
    q = T_int(2);
    
    L = max(dV);
    max_DH = max(DH_AVG);
    min_DH = min(DH_AVG);
    grad_pre = (max_DH - min_DH) / L;
    
    % Timestamp
    if exist('OCTAVE_VERSION', 'builtin')
        timestamp = strftime('%H-%M-%S', localtime(time));
    else
        timestamp = datestr(now, 'HH-MM-SS');
    end
    
    % Struttura risultati
    risultati_pre.idCampione = idCampione;
    risultati_pre.timestamp = timestamp;
    risultati_pre.sigmaV = sigmaV;
    risultati_pre.sigmaH = sigmaH;
    risultati_pre.ratioD = sigmaV / sigmaH;
    risultati_pre.deltaD = sigmaV - sigmaH;
    risultati_pre.gradiente = grad_pre;
    risultati_pre.pendenza = m;
    risultati_pre.intercetta = q;
    risultati_pre.fattoreCalibrazione = fattoreCalibrazione;
    risultati_pre.regione = [xi-1, xf, yi-1, yf];
    risultati_pre.tempMediaTotale = Tot_AVG;
    
    fprintf('Parametri automatici utilizzati: regione [%d,%d,%d,%d], calibrazione %.1f\n', ...
            xi-1, xf, yi-1, yf, fattoreCalibrazione);
end

function risultati_post = analisiPostAutomatica(mat_post, config, idCampione)
    % Versione automatica con parametri predefiniti in caso di errore nell'input
    
    fprintf('Utilizzando parametri automatici per analisi post-intervento...\n');
    
    % Parametri automatici basati sulle dimensioni della matrice
    [h, w] = size(rot90(mat_post));
    
    % Regione automatica (80% centrale)
    margine_x = round(w * 0.1);
    margine_y = round(h * 0.1);
    
    xi = margine_x + 1;
    xf = w - margine_x;
    yi = margine_y + 1;
    yf = h - margine_y;
    
    % Calibrazione automatica (stima 1 pixel = 1 cm)
    fattoreCalibrazione = 1.0;
    
    % Continua con l'analisi usando parametri automatici...
    % (implementazione semplificata)
    
    IR = rot90(mat_post);
    subIR = IR(yi:yf, xi:xf);
    
    V_AVG = mean(subIR);
    V_dev = std(subIR);
    sigmaV = mean(V_dev);
    Tot_AVG = mean(subIR(:));
    
    tsubIR = subIR';
    H_AVG = mean(tsubIR);
    H_dev = std(tsubIR);
    sigmaH = mean(H_dev);
    
    sz = size(subIR);
    h_subIR = sz(1);
    
    dV = linspace(0, (yf-yi)/fattoreCalibrazione, h_subIR);
    DH_AVG = H_AVG - Tot_AVG;
    
    T_int = polyfit(dV, DH_AVG, 1);
    m = T_int(1);
    q = T_int(2);
    
    L = max(dV);
    max_DH = max(DH_AVG);
    min_DH = min(DH_AVG);
    grad_post = (max_DH - min_DH) / L;
    
    % Timestamp
    if exist('OCTAVE_VERSION', 'builtin')
        timestamp = strftime('%H-%M-%S', localtime(time));
    else
        timestamp = datestr(now, 'HH-MM-SS');
    end
    
    % Struttura risultati
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
    
    fprintf('Parametri automatici utilizzati: regione [%d,%d,%d,%d], calibrazione %.1f\n', ...
            xi-1, xf, yi-1, yf, fattoreCalibrazione);
end