function mainOctaveSafe(mat_pre, mat_post, nomeProgetto, idCampione)
    % MAINOCT AVESAFE - Versione semplificata per Octave senza problemi grafici
    %
    % Input:
    %   mat_pre      - Matrice termografia pre-intervento
    %   mat_post     - Matrice termografia post-intervento  
    %   nomeProgetto - Nome del progetto (opzionale)
    %   idCampione   - Identificativo campione (opzionale)
    
    if nargin < 4
        idCampione = sprintf('Campione_%s', datestr(now, 'HHMMSS'));
    end
    
    if nargin < 3
        nomeProgetto = 'AnalisiTermica';
    end
    
    fprintf('\n=================================================================\n');
    fprintf('    SISTEMA ANALISI TERMOGRAFICA - VERSIONE OCTAVE SAFE\n');
    fprintf('=================================================================\n\n');
    
    % === ANALISI DIRETTA SENZA GRAFICI PROBLEMATICI ===
    
    fprintf('📊 ANALISI PRE-INTERVENTO...\n');
    risultati_pre = analisiSemplificata(mat_pre, 'PRE', idCampione);
    
    fprintf('📊 ANALISI POST-INTERVENTO...\n');
    risultati_post = analisiSemplificata(mat_post, 'POST', idCampione);
    
    % === CONFRONTO RISULTATI ===
    fprintf('\n=================================================================\n');
    fprintf('                        RISULTATI FINALI\n');
    fprintf('=================================================================\n\n');
    
    fprintf('CAMPIONE: %s\n', idCampione);
    fprintf('PROGETTO: %s\n\n', nomeProgetto);
    
    fprintf('PARAMETRI PRE-INTERVENTO:\n');
    fprintf('  σV (dev std verticale):    %.4f\n', risultati_pre.sigmaV);
    fprintf('  σH (dev std orizzontale):  %.4f\n', risultati_pre.sigmaH);
    fprintf('  RatioD (σV/σH):           %.4f\n', risultati_pre.ratioD);
    fprintf('  Gradiente termico:        %.6f °C/cm\n', risultati_pre.gradiente);
    fprintf('  Temperatura media:        %.2f °C\n\n', risultati_pre.tempMedia);
    
    fprintf('PARAMETRI POST-INTERVENTO:\n');
    fprintf('  σV (dev std verticale):    %.4f\n', risultati_post.sigmaV);
    fprintf('  σH (dev std orizzontale):  %.4f\n', risultati_post.sigmaH);
    fprintf('  RatioD (σV/σH):           %.4f\n', risultati_post.ratioD);
    fprintf('  Gradiente termico:        %.6f °C/cm\n', risultati_post.gradiente);
    fprintf('  Temperatura media:        %.2f °C\n\n', risultati_post.tempMedia);
    
    % === CALCOLO MIGLIORAMENTI ===
    miglioramento_ratioD = ((risultati_pre.ratioD - risultati_post.ratioD) / risultati_pre.ratioD) * 100;
    miglioramento_gradiente = ((abs(risultati_pre.gradiente) - abs(risultati_post.gradiente)) / abs(risultati_pre.gradiente)) * 100;
    variazione_temp = risultati_post.tempMedia - risultati_pre.tempMedia;
    
    fprintf('MIGLIORAMENTI:\n');
    fprintf('  RatioD:           %+.2f%% (%.4f → %.4f)\n', miglioramento_ratioD, risultati_pre.ratioD, risultati_post.ratioD);
    fprintf('  Gradiente:        %+.2f%% (%.6f → %.6f)\n', miglioramento_gradiente, risultati_pre.gradiente, risultati_post.gradiente);
    fprintf('  Temperatura:      %+.2f °C (%.2f → %.2f)\n\n', variazione_temp, risultati_pre.tempMedia, risultati_post.tempMedia);
    
    % === VALUTAZIONE EFFICACIA ===
    score_globale = (max(0, miglioramento_ratioD) + max(0, miglioramento_gradiente)) / 2;
    
    if score_globale > 20
        valutazione = '🟢 ECCELLENTE';
        raccomandazione = 'Intervento molto efficace. Continuare monitoraggio.';
    elseif score_globale > 10
        valutazione = '🟡 BUONO';
        raccomandazione = 'Intervento efficace. Verificare stabilità nel tempo.';
    elseif score_globale > 5
        valutazione = '🟠 MODERATO';
        raccomandazione = 'Miglioramento limitato. Considerare ottimizzazioni.';
    else
        valutazione = '🔴 LIMITATO';
        raccomandazione = 'Intervento poco efficace. Rivedere approccio.';
    end
    
    fprintf('VALUTAZIONE FINALE: %s (Score: %.1f)\n', valutazione, score_globale);
    fprintf('RACCOMANDAZIONE: %s\n\n', raccomandazione);
    
    % === INTERPRETAZIONE FISICA ===
    fprintf('INTERPRETAZIONE FISICA:\n');
    
    if risultati_pre.ratioD > 1.5
        fprintf('  PRE-intervento:  Presenza significativa umidità di risalita\n');
    elseif risultati_pre.ratioD > 1.2
        fprintf('  PRE-intervento:  Moderata presenza umidità\n');
    else
        fprintf('  PRE-intervento:  Distribuzione termica uniforme\n');
    end
    
    if risultati_post.ratioD > 1.5
        fprintf('  POST-intervento: Umidità ancora significativa\n');
    elseif risultati_post.ratioD > 1.2
        fprintf('  POST-intervento: Umidità residua moderata\n');
    else
        fprintf('  POST-intervento: Distribuzione termica uniforme\n');
    end
    
    % === SALVATAGGIO RISULTATI IN FILE TESTO ===
    nomeFile = sprintf('risultati_%s_%s.txt', idCampione, datestr(now, 'yyyy-mm-dd_HH-MM'));
    
    try
        fid = fopen(nomeFile, 'w');
        fprintf(fid, 'ANALISI TERMOGRAFICA - %s\n', idCampione);
        fprintf(fid, 'Data: %s\n\n', datestr(now));
        fprintf(fid, 'PRE-INTERVENTO:\n');
        fprintf(fid, 'σV: %.4f | σH: %.4f | RatioD: %.4f | Gradiente: %.6f\n\n', ...
                risultati_pre.sigmaV, risultati_pre.sigmaH, risultati_pre.ratioD, risultati_pre.gradiente);
        fprintf(fid, 'POST-INTERVENTO:\n');
        fprintf(fid, 'σV: %.4f | σH: %.4f | RatioD: %.4f | Gradiente: %.6f\n\n', ...
                risultati_post.sigmaV, risultati_post.sigmaH, risultati_post.ratioD, risultati_post.gradiente);
        fprintf(fid, 'MIGLIORAMENTI:\n');
        fprintf(fid, 'RatioD: %.2f%% | Gradiente: %.2f%%\n\n', miglioramento_ratioD, miglioramento_gradiente);
        fprintf(fid, 'VALUTAZIONE: %s (Score: %.1f)\n', valutazione, score_globale);
        fclose(fid);
        
        fprintf('✅ Risultati salvati in: %s\n\n', nomeFile);
    catch
        fprintf('⚠️  Impossibile salvare file risultati\n\n');
    end
    
    fprintf('=================================================================\n');
    fprintf('                      ANALISI COMPLETATA\n');
    fprintf('=================================================================\n\n');
    
end

function risultati = analisiSemplificata(termografia, fase, idCampione)
    % ANALISISSEMPLIFICATA - Analisi senza grafici problematici
    
    fprintf('  Fase: %s | Campione: %s\n', fase, idCampione);
    
    % Rotazione standard
    IR = rot90(termografia);
    [maxY, maxX] = size(IR);
    
    % Parametri automatici (regione centrale 80%)
    margine_x = round(maxX * 0.1);
    margine_y = round(maxY * 0.1);
    
    xi = margine_x + 1;
    xf = maxX - margine_x;
    yi = margine_y + 1;
    yf = maxY - margine_y;
    
    fprintf('  Regione analizzata: [%d,%d,%d,%d]\n', xi-1, xf, yi-1, yf);
    
    % Estrazione sottomatrice
    subIR = IR(yi:yf, xi:xf);
    
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
    
    % Normalizzazione e gradiente
    sz = size(subIR);
    h_subIR = sz(1);
    
    % Calibrazione fissa: 1 pixel = 1 cm
    calibrationFactor = 1.0;
    dV = linspace(0, (yf-yi)/calibrationFactor, h_subIR);
    
    DH_AVG = H_AVG - Tot_AVG;
    
    % Gradiente
    L = max(dV);
    max_DH = max(DH_AVG);
    min_DH = min(DH_AVG);
    gradiente = (max_DH - min_DH) / L;
    
    % Interpolazione lineare
    T_int = polyfit(dV, DH_AVG, 1);
    pendenza = T_int(1);
    
    % === RISULTATI ===
    risultati.sigmaV = sigmaV;
    risultati.sigmaH = sigmaH;
    risultati.ratioD = sigmaV / sigmaH;
    risultati.deltaD = sigmaV - sigmaH;
    risultati.gradiente = gradiente;
    risultati.pendenza = pendenza;
    risultati.tempMedia = Tot_AVG;
    risultati.regione = [xi-1, xf, yi-1, yf];
    
    fprintf('  σV: %.4f | σH: %.4f | RatioD: %.4f | Gradiente: %.6f\n', ...
            sigmaV, sigmaH, sigmaV/sigmaH, gradiente);
    
end