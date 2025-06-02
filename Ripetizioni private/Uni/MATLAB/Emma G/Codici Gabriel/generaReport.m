function generaReport(risultati_pre, risultati_post, config, idCampione, metriche_3d)
    % GENERAREPORT - Genera report automatico completo dell'analisi termografica
    %
    % Sintassi: generaReport(risultati_pre, risultati_post, config, idCampione, metriche_3d)
    %
    % Input:
    %   risultati_pre  - Struttura risultati pre-intervento
    %   risultati_post - Struttura risultati post-intervento
    %   config         - Configurazione sistema
    %   idCampione     - Identificativo campione
    %   metriche_3d    - Metriche analisi 3D (opzionale)
    %
    % Compatibilità: MATLAB e Octave
    
    if nargin < 5
        metriche_3d = [];
    end
    if nargin < 4
        idCampione = 'Sconosciuto';
    end
    
    % Generazione timestamp
    if exist('OCTAVE_VERSION', 'builtin')
        timestamp_completo = strftime('%Y-%m-%d %H:%M:%S', localtime(time));
        timestamp_file = strftime('%Y-%m-%d_%H-%M', localtime(time));
    else
        timestamp_completo = datestr(now, 'yyyy-mm-dd HH:MM:SS');
        timestamp_file = datestr(now, 'yyyy-mm-dd_HH-MM');
    end
    
    % Creazione percorso file report
    nomeFile = sprintf('report_analisi_%s_%s.txt', idCampione, timestamp_file);
    percorsoReport = fullfile(config.percorsi.report, nomeFile);
    
    % Apertura file per scrittura
    fid = fopen(percorsoReport, 'w');
    if fid == -1
        error('Impossibile creare il file di report: %s', percorsoReport);
    end
    
    try
        % === INTESTAZIONE REPORT ===
        fprintf(fid, '===============================================================\n');
        fprintf(fid, '           REPORT AUTOMATICO ANALISI TERMOGRAFICA\n');
        fprintf(fid, '        Studio Umidità di Risalita negli Edifici Storici\n');
        fprintf(fid, '===============================================================\n\n');
        
        fprintf(fid, 'Progetto: %s\n', config.nomeProgetto);
        fprintf(fid, 'Campione: %s\n', idCampione);
        fprintf(fid, 'Data Analisi: %s\n', timestamp_completo);
        fprintf(fid, 'Sistema: %s\n', computer);
        
        if exist('OCTAVE_VERSION', 'builtin')
            fprintf(fid, 'Software: GNU Octave %s\n', version);
        else
            fprintf(fid, 'Software: MATLAB %s\n', version);
        end
        
        fprintf(fid, '\n');
        
        % === SOMMARIO ESECUTIVO ===
        fprintf(fid, '===============================================================\n');
        fprintf(fid, '                      SOMMARIO ESECUTIVO\n');
        fprintf(fid, '===============================================================\n\n');
        
        % Calcolo indicatori chiave
        miglioramento_ratioD = ((risultati_pre.ratioD - risultati_post.ratioD) / risultati_pre.ratioD) * 100;
        miglioramento_gradiente = ((abs(risultati_pre.gradiente) - abs(risultati_post.gradiente)) / abs(risultati_pre.gradiente)) * 100;
        riduzione_sigma_totale = ((risultati_pre.sigmaV + risultati_pre.sigmaH) - (risultati_post.sigmaV + risultati_post.sigmaH));
        
        fprintf(fid, 'RISULTATI PRINCIPALI:\n');
        fprintf(fid, '- Miglioramento RatioD: %.2f%%\n', miglioramento_ratioD);
        fprintf(fid, '- Riduzione Gradiente Termico: %.2f%%\n', miglioramento_gradiente);
        fprintf(fid, '- Riduzione Sigma Totale: %.4f\n', riduzione_sigma_totale);
        
        % Valutazione qualitativa
        if miglioramento_ratioD > 15 && miglioramento_gradiente > 15
            valutazione = 'ECCELLENTE - Miglioramento significativo in tutti i parametri';
        elseif miglioramento_ratioD > 10 || miglioramento_gradiente > 10
            valutazione = 'BUONO - Miglioramento rilevabile nei parametri chiave';
        elseif miglioramento_ratioD > 5 || miglioramento_gradiente > 5
            valutazione = 'MODERATO - Miglioramento modesto ma presente';
        else
            valutazione = 'LIMITATO - Nessun miglioramento significativo rilevato';
        end
        
        fprintf(fid, '\nVALUTAZIONE COMPLESSIVA: %s\n\n', valutazione);
        
        % === DATI TECNICI PRE-INTERVENTO ===
        fprintf(fid, '===============================================================\n');
        fprintf(fid, '                  ANALISI PRE-INTERVENTO\n');
        fprintf(fid, '===============================================================\n\n');
        
        fprintf(fid, 'PARAMETRI STATISTICI:\n');
        fprintf(fid, '  - Deviazione Standard Verticale (σV): %.6f\n', risultati_pre.sigmaV);
        fprintf(fid, '  - Deviazione Standard Orizzontale (σH): %.6f\n', risultati_pre.sigmaH);
        fprintf(fid, '  - Ratio D (σV/σH): %.6f\n', risultati_pre.ratioD);
        fprintf(fid, '  - Delta D (σV-σH): %.6f\n', risultati_pre.deltaD);
        fprintf(fid, '  - Gradiente Termico: %.6f °C/cm\n', risultati_pre.gradiente);
        fprintf(fid, '  - Temperatura Media Totale: %.3f °C\n\n', risultati_pre.tempMediaTotale);
        
        fprintf(fid, 'INTERPOLAZIONE LINEARE:\n');
        fprintf(fid, '  - Pendenza (m): %.6f\n', risultati_pre.pendenza);
        fprintf(fid, '  - Intercetta (q): %.6f\n', risultati_pre.intercetta);
        fprintf(fid, '  - Equazione retta: y = %.6fx + %.6f\n\n', risultati_pre.pendenza, risultati_pre.intercetta);
        
        fprintf(fid, 'PARAMETRI TECNICI:\n');
        fprintf(fid, '  - Fattore Calibrazione: %.3f pixel/cm\n', risultati_pre.fattoreCalibrazione);
        fprintf(fid, '  - Regione Analizzata: [%d, %d, %d, %d] (xi, xf, yi, yf)\n', ...
                risultati_pre.regione(1), risultati_pre.regione(2), risultati_pre.regione(3), risultati_pre.regione(4));
        fprintf(fid, '  - Timestamp Analisi: %s\n\n', risultati_pre.timestamp);
        
        % === DATI TECNICI POST-INTERVENTO ===
        fprintf(fid, '===============================================================\n');
        fprintf(fid, '                 ANALISI POST-INTERVENTO\n');
        fprintf(fid, '===============================================================\n\n');
        
        fprintf(fid, 'PARAMETRI STATISTICI:\n');
        fprintf(fid, '  - Deviazione Standard Verticale (σV): %.6f\n', risultati_post.sigmaV);
        fprintf(fid, '  - Deviazione Standard Orizzontale (σH): %.6f\n', risultati_post.sigmaH);
        fprintf(fid, '  - Ratio D (σV/σH): %.6f\n', risultati_post.ratioD);
        fprintf(fid, '  - Delta D (σV-σH): %.6f\n', risultati_post.deltaD);
        fprintf(fid, '  - Gradiente Termico: %.6f °C/cm\n', risultati_post.gradiente);
        fprintf(fid, '  - Temperatura Media Totale: %.3f °C\n\n', risultati_post.tempMediaTotale);
        
        fprintf(fid, 'INTERPOLAZIONE LINEARE:\n');
        fprintf(fid, '  - Pendenza (m): %.6f\n', risultati_post.pendenza);
        fprintf(fid, '  - Intercetta (q): %.6f\n', risultati_post.intercetta);
        fprintf(fid, '  - Equazione retta: y = %.6fx + %.6f\n\n', risultati_post.pendenza, risultati_post.intercetta);
        
        fprintf(fid, 'PARAMETRI TECNICI:\n');
        fprintf(fid, '  - Fattore Calibrazione: %.3f pixel/cm\n', risultati_post.fattoreCalibrazione);
        fprintf(fid, '  - Regione Analizzata: [%d, %d, %d, %d] (xi, xf, yi, yf)\n', ...
                risultati_post.regione(1), risultati_post.regione(2), risultati_post.regione(3), risultati_post.regione(4));
        fprintf(fid, '  - Timestamp Analisi: %s\n\n', risultati_post.timestamp);
        
        % === ANALISI COMPARATIVA DETTAGLIATA ===
        fprintf(fid, '===============================================================\n');
        fprintf(fid, '                 ANALISI COMPARATIVA DETTAGLIATA\n');
        fprintf(fid, '===============================================================\n\n');
        
        fprintf(fid, 'VARIAZIONI ASSOLUTE:\n');
        fprintf(fid, '  - Δ σV: %.6f (%.2f%%)\n', risultati_post.sigmaV - risultati_pre.sigmaV, ...
                ((risultati_post.sigmaV - risultati_pre.sigmaV) / risultati_pre.sigmaV) * 100);
        fprintf(fid, '  - Δ σH: %.6f (%.2f%%)\n', risultati_post.sigmaH - risultati_pre.sigmaH, ...
                ((risultati_post.sigmaH - risultati_pre.sigmaH) / risultati_pre.sigmaH) * 100);
        fprintf(fid, '  - Δ RatioD: %.6f (%.2f%%)\n', risultati_post.ratioD - risultati_pre.ratioD, miglioramento_ratioD);
        fprintf(fid, '  - Δ Gradiente: %.6f (%.2f%%)\n', risultati_post.gradiente - risultati_pre.gradiente, ...
                ((risultati_post.gradiente - risultati_pre.gradiente) / risultati_pre.gradiente) * 100);
        fprintf(fid, '  - Δ Temperatura Media: %.3f °C\n\n', risultati_post.tempMediaTotale - risultati_pre.tempMediaTotale);
        
        fprintf(fid, 'INTERPRETAZIONE FISICA:\n');
        
        % Interpretazione RatioD
        if risultati_pre.ratioD > 1.5
            interp_pre = 'significativo gradiente verticale (possibile umidità)';
        elseif risultati_pre.ratioD > 1.2
            interp_pre = 'moderato gradiente verticale';
        else
            interp_pre = 'distribuzione termica uniforme';
        end
        
        if risultati_post.ratioD > 1.5
            interp_post = 'significativo gradiente verticale (umidità persistente)';
        elseif risultati_post.ratioD > 1.2
            interp_post = 'moderato gradiente verticale';
        else
            interp_post = 'distribuzione termica uniforme';
        end
        
        fprintf(fid, '  - Condizione Pre-intervento: %s (RatioD = %.3f)\n', interp_pre, risultati_pre.ratioD);
        fprintf(fid, '  - Condizione Post-intervento: %s (RatioD = %.3f)\n\n', interp_post, risultati_post.ratioD);
        
        % Interpretazione gradiente
        if abs(risultati_pre.gradiente) > 0.01
            grad_interp_pre = 'elevato gradiente termico';
        elseif abs(risultati_pre.gradiente) > 0.005
            grad_interp_pre = 'moderato gradiente termico';
        else
            grad_interp_pre = 'gradiente termico trascurabile';
        end
        
        if abs(risultati_post.gradiente) > 0.01
            grad_interp_post = 'elevato gradiente termico';
        elseif abs(risultati_post.gradiente) > 0.005
            grad_interp_post = 'moderato gradiente termico';
        else
            grad_interp_post = 'gradiente termico trascurabile';
        end
        
        fprintf(fid, '  - Gradiente Pre: %s (%.6f °C/cm)\n', grad_interp_pre, risultati_pre.gradiente);
        fprintf(fid, '  - Gradiente Post: %s (%.6f °C/cm)\n\n', grad_interp_post, risultati_post.gradiente);
        
        % === ANALISI 3D (se disponibile) ===
        if ~isempty(metriche_3d)
            fprintf(fid, '===============================================================\n');
            fprintf(fid, '                    ANALISI TRIDIMENSIONALE\n');
            fprintf(fid, '===============================================================\n\n');
            
            fprintf(fid, 'METRICHE AVANZATE 3D:\n');
            
            if isfield(metriche_3d, 'correlazione_media')
                fprintf(fid, '  - Correlazione Media Pre-Post: %.4f\n', metriche_3d.correlazione_media);
                if metriche_3d.correlazione_media > 0.8
                    fprintf(fid, '    Interpretazione: Alta correlazione - cambiamenti localizzati\n');
                elseif metriche_3d.correlazione_media > 0.6
                    fprintf(fid, '    Interpretazione: Media correlazione - cambiamenti moderati\n');
                else
                    fprintf(fid, '    Interpretazione: Bassa correlazione - cambiamenti diffusi\n');
                end
            end
            
            if isfield(metriche_3d, 'variabilita_media')
                fprintf(fid, '  - Variabilità Locale Media: %.4f\n', metriche_3d.variabilita_media);
            end
            
            if isfield(metriche_3d, 'gradiente_max')
                fprintf(fid, '  - Gradiente Massimo Spaziale: %.4f\n', metriche_3d.gradiente_max);
            end
            
            if isfield(metriche_3d, 'percentuale_cambiamento_significativo')
                fprintf(fid, '  - Percentuale Area Cambiamento Significativo: %.2f%%\n', ...
                        metriche_3d.percentuale_cambiamento_significativo);
                
                if metriche_3d.percentuale_cambiamento_significativo > 30
                    fprintf(fid, '    Interpretazione: Cambiamenti estesi su gran parte della superficie\n');
                elseif metriche_3d.percentuale_cambiamento_significativo > 15
                    fprintf(fid, '    Interpretazione: Cambiamenti moderati e localizzati\n');
                else
                    fprintf(fid, '    Interpretazione: Cambiamenti limitati o puntuali\n');
                end
            end
            
            fprintf(fid, '\nFORME RICORRENTI IDENTIFICATE:\n');
            fprintf(fid, '  - Clustering spaziale-termico: Analizzato per identificare zone omogenee\n');
            fprintf(fid, '  - Analisi frequenze spaziali: Ricerca pattern periodici nella distribuzione termica\n');
            fprintf(fid, '  - Mappe correlazione: Identificazione zone di cambiamento coerente\n');
            fprintf(fid, '  - Variabilità locale: Rilevazione irregolarità e discontinuità\n\n');
        end
        
        % === CONCLUSIONI E RACCOMANDAZIONI ===
        fprintf(fid, '===============================================================\n');
        fprintf(fid, '                CONCLUSIONI E RACCOMANDAZIONI\n');
        fprintf(fid, '===============================================================\n\n');
        
        fprintf(fid, 'EFFICACIA DELL''INTERVENTO:\n');
        
        % Score finale
        score_finale = (max(0, miglioramento_ratioD) + max(0, miglioramento_gradiente)) / 2;
        
        if score_finale > 20
            efficacia_classe = 'ELEVATA';
            raccomandazione = 'L''intervento ha prodotto risultati eccellenti. Si raccomanda di mantenere il sistema attivo e monitorare nel tempo.';
        elseif score_finale > 10
            efficacia_classe = 'BUONA';
            raccomandazione = 'L''intervento ha prodotto risultati positivi. Si consiglia monitoraggio periodico e possibili ottimizzazioni.';
        elseif score_finale > 5
            efficacia_classe = 'MODERATA';
            raccomandazione = 'L''intervento ha prodotto risultati limitati. Si raccomanda verifica parametri operativi e possibili interventi aggiuntivi.';
        else
            efficacia_classe = 'SCARSA';
            raccomandazione = 'L''intervento non ha prodotto miglioramenti significativi. Si raccomanda revisione completa dell''approccio.';
        end
        
        fprintf(fid, '  - Classe Efficacia: %s (Score: %.2f)\n', efficacia_classe, score_finale);
        fprintf(fid, '  - Raccomandazione: %s\n\n', raccomandazione);
        
        fprintf(fid, 'INDICAZIONI TECNICHE:\n');
        
        if risultati_post.ratioD > risultati_pre.ratioD
            fprintf(fid, '  - ATTENZIONE: RatioD aumentato - possibile peggioramento delle condizioni\n');
        end
        
        if abs(risultati_post.gradiente) > abs(risultati_pre.gradiente)
            fprintf(fid, '  - ATTENZIONE: Gradiente termico aumentato - verificare cause\n');
        end
        
        if risultati_post.tempMediaTotale > risultati_pre.tempMediaTotale + 1
            fprintf(fid, '  - NOTA: Significativo aumento temperatura media - considerare fattori stagionali\n');
        end
        
        fprintf(fid, '  - Continuare monitoraggio per almeno 12 mesi\n');
        fprintf(fid, '  - Verificare stabilità risultati nelle diverse stagioni\n');
        fprintf(fid, '  - Documentare eventuali interventi di manutenzione\n\n');
        
        % === APPENDICE TECNICA ===
        fprintf(fid, '===============================================================\n');
        fprintf(fid, '                      APPENDICE TECNICA\n');
        fprintf(fid, '===============================================================\n\n');
        
        fprintf(fid, 'METODOLOGIA ANALISI:\n');
        fprintf(fid, '  - Software utilizzato: %s\n', computer);
        fprintf(fid, '  - Algoritmo elaborazione: Analisi statistica matrici termiche\n');
        fprintf(fid, '  - Risoluzione calibrazione: %.3f pixel/cm\n', risultati_post.fattoreCalibrazione);
        fprintf(fid, '  - Metodo normalizzazione: Sottrazione temperatura media\n');
        fprintf(fid, '  - Interpolazione: Metodo dei minimi quadrati (ordine 1)\n\n');
        
        fprintf(fid, 'FILES GENERATI:\n');
        fprintf(fid, '  - Termografie elaborate: %s/\n', config.percorsi.termografie);
        fprintf(fid, '  - Grafici elaborati: %s/\n', config.percorsi.grafici);
        fprintf(fid, '  - Confronti: %s/\n', config.percorsi.confronti);
        fprintf(fid, '  - Visualizzazioni 3D: %s/\n', config.percorsi.vis3d);
        fprintf(fid, '  - Dati statistici: %s/\n', config.percorsi.statistiche);
        fprintf(fid, '  - Report: %s/\n\n', config.percorsi.report);
        
        fprintf(fid, 'FORMULE UTILIZZATE:\n');
        fprintf(fid, '  - RatioD = σV / σH\n');
        fprintf(fid, '  - DeltaD = σV - σH\n');
        fprintf(fid, '  - Gradiente = (T_max - T_min) / L\n');
        fprintf(fid, '  - Normalizzazione = T_i - T_media\n');
        fprintf(fid, '  - Miglioramento%% = ((Pre - Post) / Pre) × 100\n\n');
        
        % === FOOTER ===
        fprintf(fid, '===============================================================\n');
        fprintf(fid, 'Report generato automaticamente dal Sistema di Analisi Termografica\n');
        fprintf(fid, 'Progetto CNT-APPs - Studio Umidità di Risalita\n');
        fprintf(fid, 'Data generazione: %s\n', timestamp_completo);
        fprintf(fid, '===============================================================\n');
        
        % Chiusura file
        fclose(fid);
        
        % === OUTPUT CONSOLE ===
        fprintf('\n=== REPORT AUTOMATICO GENERATO ===\n');
        fprintf('File: %s\n', percorsoReport);
        fprintf('Dimensione: %.2f KB\n', dir(percorsoReport).bytes / 1024);
        fprintf('Valutazione: %s (Score: %.2f)\n', efficacia_classe, score_finale);
        fprintf('Raccomandazione: %s\n', raccomandazione);
        
        % Creazione versione riassuntiva per console
        fprintf('\n=== RIASSUNTO RISULTATI ===\n');
        fprintf('Campione: %s\n', idCampione);
        fprintf('Pre-intervento  -> RatioD: %.3f | Gradiente: %.6f | σV: %.4f | σH: %.4f\n', ...
                risultati_pre.ratioD, risultati_pre.gradiente, risultati_pre.sigmaV, risultati_pre.sigmaH);
        fprintf('Post-intervento -> RatioD: %.3f | Gradiente: %.6f | σV: %.4f | σH: %.4f\n', ...
                risultati_post.ratioD, risultati_post.gradiente, risultati_post.sigmaV, risultati_post.sigmaH);
        fprintf('Miglioramenti   -> RatioD: %.2f%% | Gradiente: %.2f%%\n', miglioramento_ratioD, miglioramento_gradiente);
        
    catch ME
        % Gestione errori
        fclose(fid);
        fprintf('Errore durante la generazione del report: %s\n', ME.message);
        rethrow(ME);
    end
    
end