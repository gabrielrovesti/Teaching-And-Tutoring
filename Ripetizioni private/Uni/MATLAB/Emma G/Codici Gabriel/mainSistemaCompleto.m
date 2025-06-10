% Parametri
casoStudio = 1129;
termografiaID = 'T04';
localizzazione = 'Ortona (CH)';
function mainCompleto(mat_pre, mat_post, casoStudio, termografiaID, localizzazione)
    % MAINCOMPLETO - Funzione principale per l'analisi termografica automatizzatamainCompleto
    %
    % Input:
    %   mat_pre        - Matrice termografia pre-intervento
    %   mat_post       - Matrice termografia post-intervento
    %   casoStudio     - Numero caso studio (es: 1468)
    %   termografiaID  - ID termografia (es: "T05")
    %   localizzazione - Localizzazione (es: "Verona (VR)")
    %
    % Esempio:
    %   mainCompleto(T04_1129, T04_2_1129, 1129, "T04", "Ortona (CH)")
    
    if nargin < 5
        localizzazione = "TestLocation";
    end
    if nargin < 4
        termografiaID = "T04";
    end
    if nargin < 3
        casoStudio = 1129;
    end
    
    fprintf('\n=== ANALISI TERMOGRAFICA AUTOMATIZZATA ===\n');
    fprintf('Caso Studio: %d %s\n', casoStudio, localizzazione);
    fprintf('Termografia: %s\n\n', termografiaID);
    
    % === SETUP PATHS ===
    % Percorso OneDrive (adatta questo al tuo sistema)
    basePathOneDrive = fullfile(getenv('USERPROFILE'), 'OneDrive', 'Documenti');
    if ~exist(basePathOneDrive, 'dir')
        basePathOneDrive = pwd; % Fallback alla directory corrente
        fprintf('⚠️  OneDrive non trovato, usando directory corrente\n');
    end
    
    % Struttura cartelle come richiesto: "numero localizzazione" / "T+numero"
    cartellaProgetto = sprintf('%d %s', casoStudio, localizzazione);
    cartellaTermografia = termografiaID;
    
    percorsoCompleto = fullfile(basePathOneDrive, cartellaProgetto, cartellaTermografia);
    
    % Crea cartelle se non esistono
    if ~exist(percorsoCompleto, 'dir')
        mkdir(percorsoCompleto);
        fprintf('✓ Creata cartella: %s\n', percorsoCompleto);
    end
    
    % === ANALISI PRE-INTERVENTO ===
    fprintf('📊 Analisi PRE-intervento...\n');
    risultati_pre = analisiTermografica(mat_pre, 'PRE', percorsoCompleto, casoStudio, termografiaID);
    
    % === ANALISI POST-INTERVENTO ===
    fprintf('📊 Analisi POST-intervento...\n');
    risultati_post = analisiTermografica(mat_post, 'POST', percorsoCompleto, casoStudio, termografiaID);
    
    % === CREAZIONE GRAFICI COMBINATI ===
    fprintf('📈 Creazione grafici combinati...\n');
    creaGraficiCombinati(risultati_pre, risultati_post, percorsoCompleto, casoStudio, termografiaID);
    
    % === SALVATAGGIO EXCEL ===
    try
        salvaInExcel(risultati_pre, risultati_post, percorsoCompleto, casoStudio, termografiaID);
        fprintf('✓ Dati salvati in Excel\n');
    catch
        fprintf('⚠️  Salvataggio Excel non riuscito (normale in Octave)\n');
    end
    
    % === RISULTATI FINALI ===
    fprintf('\n=== RISULTATI COMPLETATI ===\n');
    fprintf('PRE:  σV=%.4f | σH=%.4f | ratioD=%.4f | grad=%.6f\n', ...
            risultati_pre.sigmaV, risultati_pre.sigmaH, risultati_pre.ratioD, risultati_pre.gradiente);
    fprintf('POST: σV=%.4f | σH=%.4f | ratioD=%.4f | grad=%.6f\n', ...
            risultati_post.sigmaV, risultati_post.sigmaH, risultati_post.ratioD, risultati_post.gradiente);
    
    % Calcola miglioramenti
    miglioramento_ratioD = ((risultati_pre.ratioD - risultati_post.ratioD) / risultati_pre.ratioD) * 100;
    miglioramento_gradiente = ((abs(risultati_pre.gradiente) - abs(risultati_post.gradiente)) / abs(risultati_pre.gradiente)) * 100;
    
    fprintf('\nMIGLIORAMENTI:\n');
    fprintf('RatioD: %.2f%% | Gradiente: %.2f%%\n', miglioramento_ratioD, miglioramento_gradiente);
    fprintf('\nTutti i file salvati in: %s\n', percorsoCompleto);
end

function risultati = analisiTermografica(termografia, fase, percorsoSalvataggio, casoStudio, termografiaID)
    % ANALISITERMOGRAFICA - Analisi singola termografia con parametri automatici
    
    % Rotazione standard
    IR = rot90(termografia);
    [maxY, maxX] = size(IR);
    
    % Parametri automatici (80% centrale per evitare input utente)
    margine_x = round(maxX * 0.1);
    margine_y = round(maxY * 0.1);
    
    xi = max(1, margine_x + 1);
    xf = min(maxX, maxX - margine_x);
    yi = max(1, margine_y + 1);
    yf = min(maxY, maxY - margine_y);
    
    % Estrazione regione
    subIR = IR(yi:yf, xi:xf);
    
    % Calibrazione automatica (1 pixel = 1 cm)
    calibrationFactor = 1.0;
    
    % === CALCOLI STATISTICI ===
    
    % Profili verticali
    V_AVG = mean(subIR);
    V_dev = std(subIR);
    sigmaV = mean(V_dev);
    
    % Profili orizzontali
    tsubIR = subIR';
    H_AVG = mean(tsubIR);
    H_dev = std(tsubIR);
    sigmaH = mean(H_dev);
    
    % Temperatura media totale
    Tot_AVG = mean(subIR(:));
    
    % Dimensioni
    sz = size(subIR);
    h_subIR = sz(1);
    b_subIR = sz(2);
    
    % Coordinate per grafici
    dH = linspace(0, (xf-xi)/calibrationFactor, b_subIR);  % Profili verticali
    dV = linspace(0, (yf-yi)/calibrationFactor, h_subIR);  % Profili orizzontali
    
    % Normalizzazione
    DH_AVG = H_AVG - Tot_AVG;
    
    % Interpolazione lineare
    T_int = polyfit(dV, DH_AVG, 1);
    m = T_int(1);
    q = T_int(2);
    
    % Gradiente
    L = max(dV);
    max_DH = max(DH_AVG);
    min_DH = min(DH_AVG);
    gradiente = (max_DH - min_DH) / L;
    
    % === CREAZIONE GRAFICI INDIVIDUALI ===
    colore = strcmp(fase, 'PRE') ? 'r' : 'g';
    
    % 1. GRAFICO PROFILI VERTICALI
    fig1 = figure('Visible', 'off');
    plot(dH, V_AVG, [colore '-'], 'LineWidth', 2.0);
    hold on;
    plot(dH, V_AVG+2*V_dev, 'k--', 'LineWidth', 1.0);
    plot(dH, V_AVG-2*V_dev, 'k--', 'LineWidth', 1.0);
    
    xlabel('Posizione X [cm]');
    ylabel('Temperatura media [°C]');
    title('Temperatura profili verticali');
    if strcmp(fase, 'PRE')
        legend('μ pre intervento', 'μ+2σ', 'μ-2σ', 'Location', 'best');
    else
        legend('μ post intervento', 'μ+2σ', 'μ-2σ', 'Location', 'best');
    end
    grid on;
    
    % Salva con nomenclatura richiesta
    nomeFile1 = sprintf('PV_%s_%d.fig', termografiaID, casoStudio);
    savefig(fig1, fullfile(percorsoSalvataggio, nomeFile1));
    close(fig1);
    
    % 2. GRAFICO PROFILI ORIZZONTALI
    fig2 = figure('Visible', 'off');
    plot(dV, H_AVG, [colore '-'], 'LineWidth', 2.0);
    hold on;
    plot(dV, H_AVG+2*H_dev, 'k--', 'LineWidth', 1.0);
    plot(dV, H_AVG-2*H_dev, 'k--', 'LineWidth', 1.0);
    
    xlabel('Posizione Y [cm]');
    ylabel('Temperatura media [°C]');
    title('Temperatura profili orizzontali');
    if strcmp(fase, 'PRE')
        legend('μ pre intervento', 'μ+2σ', 'μ-2σ', 'Location', 'best');
    else
        legend('μ post intervento', 'μ+2σ', 'μ-2σ', 'Location', 'best');
    end
    grid on;
    
    nomeFile2 = sprintf('PO_%s_%d.fig', termografiaID, casoStudio);
    savefig(fig2, fullfile(percorsoSalvataggio, nomeFile2));
    close(fig2);
    
    % 3. GRAFICO TEMPERATURA NORMALIZZATA
    fig3 = figure('Visible', 'off');
    plot(dV, DH_AVG, [colore '-'], 'LineWidth', 2.0);
    hold on;
    plot(dV, DH_AVG+2*H_dev, 'k--', 'LineWidth', 1.0);
    plot(dV, DH_AVG-2*H_dev, 'k--', 'LineWidth', 1.0);
    
    xlabel('Posizione Y [cm]');
    ylabel('Temperatura normalizzata [°C]');
    title('Temperatura normalizzata profili orizzontali');
    if strcmp(fase, 'PRE')
        legend('μ pre intervento', 'μ+2σ', 'μ-2σ', 'Location', 'best');
    else
        legend('μ post intervento', 'μ+2σ', 'μ-2σ', 'Location', 'best');
    end
    grid on;
    
    nomeFile3 = sprintf('TN_%s_%d.fig', termografiaID, casoStudio);
    savefig(fig3, fullfile(percorsoSalvataggio, nomeFile3));
    close(fig3);
    
    % 4. GRAFICO INTERPOLAZIONE LINEARE
    r_int = T_int(2) + T_int(1) * dV;
    fig4 = figure('Visible', 'off');
    plot(dV, r_int, [colore '-'], 'LineWidth', 2.0);
    hold on;
    plot(dV, DH_AVG, [colore '--'], 'LineWidth', 1.0);
    
    xlabel('Posizione Y [cm]');
    ylabel('Temperatura normalizzata [°C]');
    title('Interpolazione lineare temperatura');
    if strcmp(fase, 'PRE')
        legend('interpolazione lineare pre intervento', 'μ pre intervento', 'Location', 'best');
    else
        legend('interpolazione lineare post intervento', 'μ post intervento', 'Location', 'best');
    end
    grid on;
    
    nomeFile4 = sprintf('I_%s_%d.fig', termografiaID, casoStudio);
    savefig(fig4, fullfile(percorsoSalvataggio, nomeFile4));
    close(fig4);
    
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
    
    % Output console come richiesto
    fprintf('  %s: σV=%.4f | σH=%.4f | m=%.4f | q=%.4f | grad=%.6f\n', ...
            fase, sigmaV, sigmaH, m, q, gradiente);
end

function creaGraficiCombinati(risultati_pre, risultati_post, percorsoSalvataggio, casoStudio, termografiaID)
    % CREAGRAFICICOMBINATI - Crea i 4 grafici combinati come mostrato nelle immagini
    
    % 1. PROFILI VERTICALI COMBINATI
    fig1 = figure('Position', [100, 100, 800, 600]);
    plot(risultati_pre.dH, risultati_pre.V_AVG, 'r-', 'LineWidth', 2.0);
    hold on;
    plot(risultati_pre.dH, risultati_pre.V_AVG+2*risultati_pre.V_dev, 'k--', 'LineWidth', 1.0);
    plot(risultati_pre.dH, risultati_pre.V_AVG-2*risultati_pre.V_dev, 'k--', 'LineWidth', 1.0);
    plot(risultati_post.dH, risultati_post.V_AVG, 'g-', 'LineWidth', 2.0);
    plot(risultati_post.dH, risultati_post.V_AVG+2*risultati_post.V_dev, 'k--', 'LineWidth', 1.0);
    plot(risultati_post.dH, risultati_post.V_AVG-2*risultati_post.V_dev, 'k--', 'LineWidth', 1.0);
    
    xlabel('Posizione X [cm]');
    ylabel('Temperatura media [°C]');
    title('Temperatura profili verticali');
    legend('μ pre intervento', 'μ+2σ', 'μ-2σ', 'μ post intervento', 'Location', 'best');
    grid on;
    
    nomeFile1 = sprintf('PV_%s_%d_combinato.fig', termografiaID, casoStudio);
    savefig(fig1, fullfile(percorsoSalvataggio, nomeFile1));
    close(fig1);
    
    % 2. PROFILI ORIZZONTALI COMBINATI
    fig2 = figure('Position', [100, 100, 800, 600]);
    plot(risultati_pre.dV, risultati_pre.H_AVG, 'r-', 'LineWidth', 2.0);
    hold on;
    plot(risultati_pre.dV, risultati_pre.H_AVG+2*risultati_pre.H_dev, 'k--', 'LineWidth', 1.0);
    plot(risultati_pre.dV, risultati_pre.H_AVG-2*risultati_pre.H_dev, 'k--', 'LineWidth', 1.0);
    plot(risultati_post.dV, risultati_post.H_AVG, 'g-', 'LineWidth', 2.0);
    plot(risultati_post.dV, risultati_post.H_AVG+2*risultati_post.H_dev, 'k--', 'LineWidth', 1.0);
    plot(risultati_post.dV, risultati_post.H_AVG-2*risultati_post.H_dev, 'k--', 'LineWidth', 1.0);
    
    xlabel('Posizione Y [cm]');
    ylabel('Temperatura media [°C]');
    title('Temperatura profili orizzontali');
    legend('μ pre intervento', 'μ+2σ', 'μ-2σ', 'μ post intervento', 'Location', 'best');
    grid on;
    
    nomeFile2 = sprintf('PO_%s_%d_combinato.fig', termografiaID, casoStudio);
    savefig(fig2, fullfile(percorsoSalvataggio, nomeFile2));
    close(fig2);
    
    % 3. TEMPERATURA NORMALIZZATA COMBINATA
    fig3 = figure('Position', [100, 100, 800, 600]);
    plot(risultati_pre.dV, risultati_pre.DH_AVG, 'r-', 'LineWidth', 2.0);
    hold on;
    plot(risultati_pre.dV, risultati_pre.DH_AVG+2*risultati_pre.H_dev, 'k--', 'LineWidth', 1.0);
    plot(risultati_pre.dV, risultati_pre.DH_AVG-2*risultati_pre.H_dev, 'k--', 'LineWidth', 1.0);
    plot(risultati_post.dV, risultati_post.DH_AVG, 'g-', 'LineWidth', 2.0);
    plot(risultati_post.dV, risultati_post.DH_AVG+2*risultati_post.H_dev, 'k--', 'LineWidth', 1.0);
    plot(risultati_post.dV, risultati_post.DH_AVG-2*risultati_post.H_dev, 'k--', 'LineWidth', 1.0);
    
    xlabel('Posizione Y [cm]');
    ylabel('Temperatura normalizzata [°C]');
    title('Temperatura normalizzata profili orizzontali');
    legend('μ pre intervento', 'μ+2σ', 'μ-2σ', 'μ post intervento', 'Location', 'best');
    grid on;
    
    nomeFile3 = sprintf('TN_%s_%d_combinato.fig', termografiaID, casoStudio);
    savefig(fig3, fullfile(percorsoSalvataggio, nomeFile3));
    close(fig3);
    
    % 4. INTERPOLAZIONE LINEARE COMBINATA
    fig4 = figure('Position', [100, 100, 800, 600]);
    plot(risultati_pre.dV, risultati_pre.r_int, 'r-', 'LineWidth', 2.0);
    hold on;
    plot(risultati_pre.dV, risultati_pre.DH_AVG, 'r--', 'LineWidth', 1.0);
    plot(risultati_post.dV, risultati_post.r_int, 'g-', 'LineWidth', 2.0);
    plot(risultati_post.dV, risultati_post.DH_AVG, 'g--', 'LineWidth', 1.0);
    
    xlabel('Posizione Y [cm]');
    ylabel('Temperatura normalizzata [°C]');
    title('Interpolazione lineare temperatura');
    legend('interpolazione lineare pre intervento', 'μ pre intervento', ...
           'interpolazione lineare post intervento', 'μ post intervento', 'Location', 'best');
    grid on;
    
    nomeFile4 = sprintf('I_%s_%d_combinato.fig', termografiaID, casoStudio);
    savefig(fig4, fullfile(percorsoSalvataggio, nomeFile4));
    close(fig4);
    
    fprintf('✓ Grafici combinati salvati\n');
end

function salvaInExcel(risultati_pre, risultati_post, percorsoSalvataggio, casoStudio, termografiaID)
    % SALVAINEXCEL - Salva i risultati in formato Excel (solo MATLAB)
    
    % Prepara i dati
    dati = {
        casoStudio, termografiaID, ...
        risultati_pre.sigmaV, risultati_pre.sigmaH, risultati_pre.deltaD, risultati_pre.ratioD, ...
        risultati_pre.m, risultati_pre.q, risultati_pre.gradiente, ...
        risultati_post.sigmaV, risultati_post.sigmaH, risultati_post.deltaD, risultati_post.ratioD, ...
        risultati_post.m, risultati_post.q, risultati_post.gradiente
    };
    
    % Headers
    headers = {
        'CasoStudio', 'Termografia', ...
        'sigmaV_pre', 'sigmaH_pre', 'deltaD_pre', 'ratioD_pre', 'm_pre', 'q_pre', 'grad_pre', ...
        'sigmaV_post', 'sigmaH_post', 'deltaD_post', 'ratioD_post', 'm_post', 'q_post', 'grad_post'
    };
    
    % Crea tabella
    tabella = [headers; dati];
    
    % Salva in Excel
    nomeFileExcel = sprintf('Risultati_%s_%d.xlsx', termografiaID, casoStudio);
    percorsoExcel = fullfile(percorsoSalvataggio, nomeFileExcel);
    
    if exist('OCTAVE_VERSION', 'builtin')
        % Octave - salva in CSV
        percorsoCSV = strrep(percorsoExcel, '.xlsx', '.csv');
        writecell(tabella, percorsoCSV);
        fprintf('✓ Dati salvati in CSV: %s\n', percorsoCSV);
    else
        % MATLAB - salva in Excel
        writecell(tabella, percorsoExcel);
        fprintf('✓ Dati salvati in Excel: %s\n', percorsoExcel);
    end
end