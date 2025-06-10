function mainOctaveSafe(mat_pre, mat_post, casoStudio, termografiaID, localizzazione)
    % MAINOCT AVESAFE - Sistema compatibile Octave/MATLAB con tutte le specifiche richieste
    %
    % Input:
    %   mat_pre        - Matrice termografia pre-intervento
    %   mat_post       - Matrice termografia post-intervento
    %   casoStudio     - Numero caso studio (es: 1468)
    %   termografiaID  - ID termografia (es: "T05") 
    %   localizzazione - Localizzazione (es: "Verona (VR)")
    
    if nargin < 5
        localizzazione = "TestLocation";
    end
    if nargin < 4
        termografiaID = "T04";
    end
    if nargin < 3
        casoStudio = 1129;
    end
    
    % Converti stringhe per compatibilità
    if ischar(termografiaID)
        termografiaID = string(termografiaID);
    end
    if ischar(localizzazione)
        localizzazione = string(localizzazione);
    end
    
    fprintf('\n=================================================================\n');
    fprintf('    SISTEMA ANALISI TERMOGRAFICA - VERSIONE OCTAVE SAFE\n');
    fprintf('=================================================================\n\n');
    
    fprintf('Caso Studio: %d %s\n', casoStudio, char(localizzazione));
    fprintf('Termografia: %s\n', char(termografiaID));
    
    % Rileva software
    if exist('OCTAVE_VERSION', 'builtin')
        fprintf('Software: GNU Octave %s\n\n', version);
        isOctave = true;
    else
        fprintf('Software: MATLAB %s\n\n', version);
        isOctave = false;
    end
    
    % === SETUP PATHS ===
    basePathOneDrive = pwd; % Usa directory corrente per sicurezza
    
    % Prova percorso OneDrive se disponibile
    if ~isOctave
        try
            oneDrivePath = fullfile(getenv('USERPROFILE'), 'OneDrive', 'Documenti');
            if exist(oneDrivePath, 'dir')
                basePathOneDrive = oneDrivePath;
                fprintf('✓ Usando OneDrive: %s\n', basePathOneDrive);
            end
        catch
            % Ignora errori
        end
    end
    
    % Struttura cartelle
    cartellaProgetto = sprintf('%d %s', casoStudio, char(localizzazione));
    cartellaTermografia = char(termografiaID);
    
    percorsoCompleto = fullfile(basePathOneDrive, cartellaProgetto, cartellaTermografia);
    
    % Crea cartelle
    if ~exist(percorsoCompleto, 'dir')
        [success, msg] = mkdir(percorsoCompleto);
        if success
            fprintf('✓ Creata cartella: %s\n\n', percorsoCompleto);
        else
            fprintf('⚠️  Errore creazione cartella: %s\n', msg);
            percorsoCompleto = pwd; % Fallback
        end
    end
    
    % === ANALISI ===
    fprintf('📊 Analisi PRE-intervento...\n');
    risultati_pre = analisiTermograficaSafe(mat_pre, 'PRE', percorsoCompleto, casoStudio, termografiaID, isOctave);
    
    fprintf('📊 Analisi POST-intervento...\n');
    risultati_post = analisiTermograficaSafe(mat_post, 'POST', percorsoCompleto, casoStudio, termografiaID, isOctave);
    
    fprintf('📈 Creazione grafici combinati...\n');
    creaGraficiCombinatiSafe(risultati_pre, risultati_post, percorsoCompleto, casoStudio, termografiaID, isOctave);
    
    % === SALVATAGGIO DATI ===
    try
        salvaRisultatiSafe(risultati_pre, risultati_post, percorsoCompleto, casoStudio, termografiaID, isOctave);
        fprintf('✓ Dati salvati\n');
    catch ME
        fprintf('⚠️  Errore salvataggio: %s\n', ME.message);
    end
    
    % === RISULTATI FINALI ===
    fprintf('\n=================================================================\n');
    fprintf('                        RISULTATI FINALI\n');
    fprintf('=================================================================\n\n');
    
    fprintf('PARAMETRI STATISTICI:\n');
    fprintf('PRE-INTERVENTO:\n');
    fprintf('  σV: %.4f | σH: %.4f | ratioD: %.4f\n', risultati_pre.sigmaV, risultati_pre.sigmaH, risultati_pre.ratioD);
    fprintf('  m: %.4f | q: %.4f | gradiente: %.6f\n', risultati_pre.m, risultati_pre.q, risultati_pre.gradiente);
    
    fprintf('POST-INTERVENTO:\n');
    fprintf('  σV: %.4f | σH: %.4f | ratioD: %.4f\n', risultati_post.sigmaV, risultati_post.sigmaH, risultati_post.ratioD);
    fprintf('  m: %.4f | q: %.4f | gradiente: %.6f\n', risultati_post.m, risultati_post.q, risultati_post.gradiente);
    
    % Calcola miglioramenti
    miglioramento_ratioD = ((risultati_pre.ratioD - risultati_post.ratioD) / risultati_pre.ratioD) * 100;
    miglioramento_gradiente = ((abs(risultati_pre.gradiente) - abs(risultati_post.gradiente)) / abs(risultati_pre.gradiente)) * 100;
    
    fprintf('\nMIGLIORAMENTI:\n');
    fprintf('  RatioD: %+.2f%% (%.4f → %.4f)\n', miglioramento_ratioD, risultati_pre.ratioD, risultati_post.ratioD);
    fprintf('  Gradiente: %+.2f%% (%.6f → %.6f)\n', miglioramento_gradiente, risultati_pre.gradiente, risultati_post.gradiente);
    
    % Valutazione finale
    score = (max(0, miglioramento_ratioD) + max(0, miglioramento_gradiente)) / 2;
    
    if score > 15
        valutazione = '🟢 ECCELLENTE';
    elseif score > 10
        valutazione = '🟡 BUONO';
    elseif score > 5
        valutazione = '🟠 MODERATO';
    else
        valutazione = '🔴 LIMITATO';
    end
    
    fprintf('\nVALUTAZIONE: %s (Score: %.1f)\n', valutazione, score);
    fprintf('\nTutti i file salvati in: %s\n', percorsoCompleto);
    
    fprintf('\n=================================================================\n');
    fprintf('                    ANALISI COMPLETATA\n');
    fprintf('=================================================================\n\n');
end

function risultati = analisiTermograficaSafe(termografia, fase, percorsoSalvataggio, casoStudio, termografiaID, isOctave)
    % ANALISITERMOGRAFICASAFE - Versione compatibile per entrambi i software
    
    % Rotazione e preprocessing
    IR = rot90(termografia);
    [maxY, maxX] = size(IR);
    
    % Parametri automatici (regione centrale 80%)
    margine_x = round(maxX * 0.1);
    margine_y = round(maxY * 0.1);
    
    xi = max(1, margine_x + 1);
    xf = min(maxX, maxX - margine_x);
    yi = max(1, margine_y + 1);
    yf = min(maxY, maxY - margine_y);
    
    subIR = IR(yi:yf, xi:xf);
    calibrationFactor = 1.0; % 1 pixel = 1 cm
    
    % === CALCOLI STATISTICI ===
    V_AVG = mean(subIR);
    V_dev = std(subIR);
    sigmaV = mean(V_dev);
    
    tsubIR = subIR';
    H_AVG = mean(tsubIR);
    H_dev = std(tsubIR);
    sigmaH = mean(H_dev);
    
    Tot_AVG = mean(subIR(:));
    
    sz = size(subIR);
    h_subIR = sz(1);
    b_subIR = sz(2);
    
    dH = linspace(0, (xf-xi)/calibrationFactor, b_subIR);
    dV = linspace(0, (yf-yi)/calibrationFactor, h_subIR);
    
    DH_AVG = H_AVG - Tot_AVG;
    T_int = polyfit(dV, DH_AVG, 1);
    m = T_int(1);
    q = T_int(2);
    
    L = max(dV);
    gradiente = (max(DH_AVG) - min(DH_AVG)) / L;
    
    % === CREAZIONE GRAFICI ===
    colore = strcmp(fase, 'PRE') ? 'r' : 'g';
    
    % 1. PROFILI VERTICALI
    fig1 = creaGraficoSafe(isOctave);
    plot(dH, V_AVG, [colore '-'], 'LineWidth', 2);
    hold on;
    plot(dH, V_AVG+2*V_dev, 'k--', 'LineWidth', 1);
    plot(dH, V_AVG-2*V_dev, 'k--', 'LineWidth', 1);
    
    xlabel('Posizione X [cm]');
    ylabel('Temperatura media [°C]');
    title('Temperatura profili verticali');
    
    if strcmp(fase, 'PRE')
        legend('μ pre intervento', 'μ+2σ', 'μ-2σ', 'Location', 'best');
    else
        legend('μ post intervento', 'μ+2σ', 'μ-2σ', 'Location', 'best');
    end
    grid on;
    
    nomeFile = sprintf('PV_%s_%d', char(termografiaID), casoStudio);
    salvaFiguraSafe(fig1, fullfile(percorsoSalvataggio, nomeFile), isOctave);
    
    % 2. PROFILI ORIZZONTALI
    fig2 = creaGraficoSafe(isOctave);
    plot(dV, H_AVG, [colore '-'], 'LineWidth', 2);
    hold on;
    plot(dV, H_AVG+2*H_dev, 'k--', 'LineWidth', 1);
    plot(dV, H_AVG-2*H_dev, 'k--', 'LineWidth', 1);
    
    xlabel('Posizione Y [cm]');
    ylabel('Temperatura media [°C]');
    title('Temperatura profili orizzontali');
    
    if strcmp(fase, 'PRE')
        legend('μ pre intervento', 'μ+2σ', 'μ-2σ', 'Location', 'best');
    else
        legend('μ post intervento', 'μ+2σ', 'μ-2σ', 'Location', 'best');
    end
    grid on;
    
    nomeFile = sprintf('PO_%s_%d', char(termografiaID), casoStudio);
    salvaFiguraSafe(fig2, fullfile(percorsoSalvataggio, nomeFile), isOctave);
    
    % 3. TEMPERATURA NORMALIZZATA
    fig3 = creaGraficoSafe(isOctave);
    plot(dV, DH_AVG, [colore '-'], 'LineWidth', 2);
    hold on;
    plot(dV, DH_AVG+2*H_dev, 'k--', 'LineWidth', 1);
    plot(dV, DH_AVG-2*H_dev, 'k--', 'LineWidth', 1);
    
    xlabel('Posizione Y [cm]');
    ylabel('Temperatura normalizzata [°C]');
    title('Temperatura normalizzata profili orizzontali');
    
    if strcmp(fase, 'PRE')
        legend('μ pre intervento', 'μ+2σ', 'μ-2σ', 'Location', 'best');
    else
        legend('μ post intervento', 'μ+2σ', 'μ-2σ', 'Location', 'best');
    end
    grid on;
    
    nomeFile = sprintf('TN_%s_%d', char(termografiaID), casoStudio);
    salvaFiguraSafe(fig3, fullfile(percorsoSalvataggio, nomeFile), isOctave);
    
    % 4. INTERPOLAZIONE LINEARE
    r_int = T_int(2) + T_int(1) * dV;
    fig4 = creaGraficoSafe(isOctave);
    plot(dV, r_int, [colore '-'], 'LineWidth', 2);
    hold on;
    plot(dV, DH_AVG, [colore '--'], 'LineWidth', 1);
    
    xlabel('Posizione Y [cm]');
    ylabel('Temperatura normalizzata [°C]');
    title('Interpolazione lineare temperatura');
    
    if strcmp(fase, 'PRE')
        legend('interpolazione lineare pre intervento', 'μ pre intervento', 'Location', 'best');
    else
        legend('interpolazione lineare post intervento', 'μ post intervento', 'Location', 'best');
    end
    grid on;
    
    nomeFile = sprintf('I_%s_%d', char(termografiaID), casoStudio);
    salvaFiguraSafe(fig4, fullfile(percorsoSalvataggio, nomeFile), isOctave);
    
    % === RISULTATI ===
    risultati.fase = fase;
    risultati.sigmaV = sigmaV;
    risultati.sigmaH = sigmaH;
    risultati.ratioD = sigmaV / sigmaH;
    risultati.deltaD = sigmaV - sigmaH;
    risultati.gradiente = gradiente;
    risultati.m = m;
    risultati.q = q;
    risultati.tempMedia = Tot_AVG;
    risultati.dH = dH;
    risultati.dV = dV;
    risultati.V_AVG = V_AVG;
    risultati.V_dev = V_dev;
    risultati.H_AVG = H_AVG;
    risultati.H_dev = H_dev;
    risultati.DH_AVG = DH_AVG;
    risultati.r_int = r_int;
    
    fprintf('  %s: σV=%.4f | σH=%.4f | ratioD=%.4f | grad=%.6f\n', ...
            fase, sigmaV, sigmaH, sigmaV/sigmaH, gradiente);
end

function creaGraficiCombinatiSafe(risultati_pre, risultati_post, percorsoSalvataggio, casoStudio, termografiaID, isOctave)
    % CREAGRAFICICOMBINATI - Versione safe per Octave/MATLAB
    
    % 1. PROFILI VERTICALI COMBINATI
    fig = creaGraficoSafe(isOctave);
    plot(risultati_pre.dH, risultati_pre.V_AVG, 'r-', 'LineWidth', 2);
    hold on;
    plot(risultati_pre.dH, risultati_pre.V_AVG+2*risultati_pre.V_dev, 'k--', 'LineWidth', 1);
    plot(risultati_pre.dH, risultati_pre.V_AVG-2*risultati_pre.V_dev, 'k--', 'LineWidth', 1);
    plot(risultati_post.dH, risultati_post.V_AVG, 'g-', 'LineWidth', 2);
    plot(risultati_post.dH, risultati_post.V_AVG+2*risultati_post.V_dev, 'k--', 'LineWidth', 1);
    plot(risultati_post.dH, risultati_post.V_AVG-2*risultati_post.V_dev, 'k--', 'LineWidth', 1);
    
    xlabel('Posizione X [cm]');
    ylabel('Temperatura media [°C]');
    title('Temperatura profili verticali');
    legend('μ pre intervento', 'μ+2σ', 'μ-2σ', 'μ post intervento', 'Location', 'best');
    grid on;
    
    nomeFile = sprintf('PV_%s_%d_combinato', char(termografiaID), casoStudio);
    salvaFiguraSafe(fig, fullfile(percorsoSalvataggio, nomeFile), isOctave);
    
    % 2. PROFILI ORIZZONTALI COMBINATI
    fig = creaGraficoSafe(isOctave);
    plot(risultati_pre.dV, risultati_pre.H_AVG, 'r-', 'LineWidth', 2);
    hold on;
    plot(risultati_pre.dV, risultati_pre.H_AVG+2*risultati_pre.H_dev, 'k--', 'LineWidth', 1);
    plot(risultati_pre.dV, risultati_pre.H_AVG-2*risultati_pre.H_dev, 'k--', 'LineWidth', 1);
    plot(risultati_post.dV, risultati_post.H_AVG, 'g-', 'LineWidth', 2);
    plot(risultati_post.dV, risultati_post.H_AVG+2*risultati_post.H_dev, 'k--', 'LineWidth', 1);
    plot(risultati_post.dV, risultati_post.H_AVG-2*risultati_post.H_dev, 'k--', 'LineWidth', 1);
    
    xlabel('Posizione Y [cm]');
    ylabel('Temperatura media [°C]');
    title('Temperatura profili orizzontali');
    legend('μ pre intervento', 'μ+2σ', 'μ-2σ', 'μ post intervento', 'Location', 'best');
    grid on;
    
    nomeFile = sprintf('PO_%s_%d_combinato', char(termografiaID), casoStudio);
    salvaFiguraSafe(fig, fullfile(percorsoSalvataggio, nomeFile), isOctave);
    
    % 3. TEMPERATURA NORMALIZZATA COMBINATA
    fig = creaGraficoSafe(isOctave);
    plot(risultati_pre.dV, risultati_pre.DH_AVG, 'r-', 'LineWidth', 2);
    hold on;
    plot(risultati_pre.dV, risultati_pre.DH_AVG+2*risultati_pre.H_dev, 'k--', 'LineWidth', 1);
    plot(risultati_pre.dV, risultati_pre.DH_AVG-2*risultati_pre.H_dev, 'k--', 'LineWidth', 1);
    plot(risultati_post.dV, risultati_post.DH_AVG, 'g-', 'LineWidth', 2);
    plot(risultati_post.dV, risultati_post.DH_AVG+2*risultati_post.H_dev, 'k--', 'LineWidth', 1);
    plot(risultati_post.dV, risultati_post.DH_AVG-2*risultati_post.H_dev, 'k--', 'LineWidth', 1);
    
    xlabel('Posizione Y [cm]');
    ylabel('Temperatura normalizzata [°C]');
    title('Temperatura normalizzata profili orizzontali');
    legend('μ pre intervento', 'μ+2σ', 'μ-2σ', 'μ post intervento', 'Location', 'best');
    grid on;
    
    nomeFile = sprintf('TN_%s_%d_combinato', char(termografiaID), casoStudio);
    salvaFiguraSafe(fig, fullfile(percorsoSalvataggio, nomeFile), isOctave);
    
    % 4. INTERPOLAZIONE LINEARE COMBINATA
    fig = creaGraficoSafe(isOctave);
    plot(risultati_pre.dV, risultati_pre.r_int, 'r-', 'LineWidth', 2);
    hold on;
    plot(risultati_pre.dV, risultati_pre.DH_AVG, 'r--', 'LineWidth', 1);
    plot(risultati_post.dV, risultati_post.r_int, 'g-', 'LineWidth', 2);
    plot(risultati_post.dV, risultati_post.DH_AVG, 'g--', 'LineWidth', 1);
    
    xlabel('Posizione Y [cm]');
    ylabel('Temperatura normalizzata [°C]');
    title('Interpolazione lineare temperatura');
    legend('interpolazione lineare pre intervento', 'μ pre intervento', ...
           'interpolazione lineare post intervento', 'μ post intervento', 'Location', 'best');
    grid on;
    
    nomeFile = sprintf('I_%s_%d_combinato', char(termografiaID), casoStudio);
    salvaFiguraSafe(fig, fullfile(percorsoSalvataggio, nomeFile), isOctave);
end

function fig = creaGraficoSafe(isOctave)
    % CREAGRAFICOSAFE - Crea figura compatibile
    if isOctave
        fig = figure('visible', 'off');
    else
        fig = figure('Visible', 'off', 'Position', [100, 100, 800, 600]);
    end
end

function salvaFiguraSafe(fig, percorsoBase, isOctave)
    % SALVAFIGURASAFE - Salva figura in modo compatibile
    try
        if isOctave
            % Octave - usa print
            print(fig, '-dpng', [percorsoBase '.png']);
        else
            % MATLAB - usa savefig
            savefig(fig, [percorsoBase '.fig']);
            saveas(fig, [percorsoBase '.png'], 'png'); % Backup PNG
        end
        close(fig);
    catch ME
        fprintf('⚠️  Errore salvataggio figura: %s\n', ME.message);
        try
            close(fig);
        catch
            % Ignora
        end
    end
end

function salvaRisultatiSafe(risultati_pre, risultati_post, percorsoSalvataggio, casoStudio, termografiaID, isOctave)
    % SALVARISULTATISAFE - Salva risultati in CSV/Excel
    
    % Prepara dati
    headers = {'CasoStudio', 'Termografia', 'sigmaV_pre', 'sigmaH_pre', 'deltaD_pre', 'ratioD_pre', ...
               'm_pre', 'q_pre', 'grad_pre', 'sigmaV_post', 'sigmaH_post', 'deltaD_post', ...
               'ratioD_post', 'm_post', 'q_post', 'grad_post'};
    
    dati = {casoStudio, char(termografiaID), risultati_pre.sigmaV, risultati_pre.sigmaH, ...
            risultati_pre.deltaD, risultati_pre.ratioD, risultati_pre.m, risultati_pre.q, ...
            risultati_pre.gradiente, risultati_post.sigmaV, risultati_post.sigmaH, ...
            risultati_post.deltaD, risultati_post.ratioD, risultati_post.m, risultati_post.q, ...
            risultati_post.gradiente};
    
    % Salva in formato compatibile
    nomeFile = sprintf('Risultati_%s_%d.csv', char(termografiaID), casoStudio);
    percorsoFile = fullfile(percorsoSalvataggio, nomeFile);
    
    try
        % Scrivi CSV manualmente per massima compatibilità
        fid = fopen(percorsoFile, 'w');
        
        % Headers
        for i = 1:length(headers)
            fprintf(fid, '%s', headers{i});
            if i < length(headers)
                fprintf(fid, ',');
            end
        end
        fprintf(fid, '\n');
        
        % Dati
        for i = 1:length(dati)
            if ischar(dati{i}) || isstring(dati{i})
                fprintf(fid, '%s', char(dati{i}));
            else
                fprintf(fid, '%.6f', dati{i});
            end
            if i < length(dati)
                fprintf(fid, ',');
            end
        end
        fprintf(fid, '\n');
        
        fclose(fid);
        fprintf('✓ Risultati salvati in: %s\n', nomeFile);
        
    catch ME
        fprintf('⚠️  Errore salvataggio CSV: %s\n', ME.message);
    end
end