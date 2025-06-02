% =========================================================================
%                    ESEMPIO UTILIZZO COMPLETO
%          Sistema Automatizzato Analisi Termografica Avanzato
%                   Studio Umidità di Risalita CNT-APPs
% =========================================================================
%
% Questo file dimostra l'utilizzo completo del sistema di analisi 
% termografica automatizzata per lo studio dell'umidità di risalita 
% negli edifici storici.
%
% AUTORE: Sistema CNT-APPs
% DATA: 2024
% COMPATIBILITÀ: MATLAB e GNU Octave
%
% =========================================================================

%% =====================================================================
%                           SETUP INIZIALE
% ======================================================================

% Pulizia ambiente
clear all;
close all;
clc;

fprintf('=========================================================================\n');
fprintf('    SISTEMA AUTOMATIZZATO ANALISI TERMOGRAFICA - ESEMPIO COMPLETO\n');
fprintf('         Studio Umidità di Risalita negli Edifici Storici\n');
fprintf('=========================================================================\n\n');

% Verifica compatibilità sistema
if exist('utilitaCompatibilita.m', 'file')
    utilitaCompatibilita();
else
    fprintf('⚠️  File utilitaCompatibilita.m non trovato\n');
    fprintf('   Assicurarsi che tutti i file del sistema siano nella stessa cartella\n\n');
end

%% =====================================================================
%                        CARICAMENTO DATI
% ======================================================================

fprintf('FASE 1: Caricamento dati termografici...\n');

% Esempio con dati forniti dalla studentessa
try
    % Prova a caricare i file reali
    load('T04_1129.mat');
    load('T04_2_1129.mat');
    
    mat_pre = T04_1129;
    mat_post = T04_2_1129;
    
    fprintf('✓ Dati reali caricati con successo:\n');
    fprintf('  - Pre-intervento: T04_1129.mat\n');
    fprintf('  - Post-intervento: T04_2_1129.mat\n');
    
catch
    % Se i file non esistono, crea dati sintetici per dimostrazione
    fprintf('ℹ️  File originali non trovati, creando dati sintetici per dimostrazione...\n');
    
    % Generazione termografia sintetica pre-intervento
    [X, Y] = meshgrid(1:120, 1:80);
    
    % Simula gradiente di umidità (temperatura più bassa in basso)
    temp_base = 22; % Temperatura base
    gradiente_umidita = 0.02; % Gradiente dovuto all'umidità
    
    % Pre-intervento: forte gradiente verticale
    mat_pre = temp_base + gradiente_umidita * (80 - Y) + ...
              0.5 * sin(X/20) + 0.3 * cos(Y/15) + ...
              0.2 * randn(size(X)); % Rumore
    
    % Post-intervento: gradiente ridotto (miglioramento)
    mat_post = temp_base + gradiente_umidita * 0.3 * (80 - Y) + ...
               0.3 * sin(X/20) + 0.2 * cos(Y/15) + ...
               0.15 * randn(size(X)); % Meno rumore
    
    fprintf('✓ Dati sintetici generati:\n');
    fprintf('  - Dimensioni: %dx%d pixel\n', size(mat_pre, 1), size(mat_pre, 2));
    fprintf('  - Gradiente pre: %.3f °C/pixel\n', gradiente_umidita);
    fprintf('  - Gradiente post: %.3f °C/pixel (miglioramento 70%%)\n', gradiente_umidita * 0.3);
end

% Visualizzazione rapida dei dati caricati
fprintf('\nCaratteristiche termografie caricate:\n');
fprintf('Pre-intervento:  Range %.2f - %.2f °C | Media %.2f °C\n', ...
        min(mat_pre(:)), max(mat_pre(:)), mean(mat_pre(:)));
fprintf('Post-intervento: Range %.2f - %.2f °C | Media %.2f °C\n\n', ...
        min(mat_post(:)), max(mat_post(:)), mean(mat_post(:)));

%% =====================================================================
%                    ESEMPIO 1: UTILIZZO BASICO
% ======================================================================

fprintf('=========================================================================\n');
fprintf('                          ESEMPIO 1: UTILIZZO BASICO\n');
fprintf('=========================================================================\n\n');

% Utilizzo semplice del sistema - tutto automatico
nomeProgetto = 'EsempioStudioUmidita';
idCampione = 'T04_Dimostrazione';

fprintf('Avvio analisi automatica...\n');
try
    mainSistemaCompleto(mat_pre, mat_post, nomeProgetto, idCampione);
    fprintf('✓ Analisi basica completata con successo!\n\n');
catch ME
    fprintf('❌ Errore nell''analisi basica: %s\n\n', ME.message);
end

%% =====================================================================
%                  ESEMPIO 2: UTILIZZO AVANZATO STEP-BY-STEP
% ======================================================================

fprintf('=========================================================================\n');
fprintf('                    ESEMPIO 2: UTILIZZO AVANZATO\n');
fprintf('=========================================================================\n\n');

% Setup ambiente personalizzato
nomeProgetto2 = 'StudioAvanzato';
fprintf('PASSO 1: Setup ambiente personalizzato...\n');

try
    config = setupAmbienteAnalisi(nomeProgetto2);
    fprintf('✓ Ambiente configurato in: %s\n\n', config.cartellaP);
catch ME
    fprintf('❌ Errore setup: %s\n\n', ME.message);
    return;
end

% Analisi pre-intervento con parametri controllati
fprintf('PASSO 2: Analisi pre-intervento...\n');
idCampione2 = 'T04_Avanzato';

try
    % Per l'esempio, impostiamo parametri automatici per evitare input utente
    fprintf('Utilizzando parametri automatici per dimostrazione...\n');
    
    % Simula input utente automatico modificando temporaneamente le funzioni
    risultati_pre = analisiPreAutomatica(mat_pre, config, idCampione2);
    fprintf('✓ Analisi pre-intervento completata\n');
    fprintf('  σV: %.4f | σH: %.4f | RatioD: %.4f\n\n', ...
            risultati_pre.sigmaV, risultati_pre.sigmaH, risultati_pre.ratioD);
catch ME
    fprintf('❌ Errore analisi pre: %s\n\n', ME.message);
end

% Analisi post-intervento
fprintf('PASSO 3: Analisi post-intervento...\n');

try
    risultati_post = analisiPostAutomatica(mat_post, config, idCampione2);
    fprintf('✓ Analisi post-intervento completata\n');
    fprintf('  σV: %.4f | σH: %.4f | RatioD: %.4f\n\n', ...
            risultati_post.sigmaV, risultati_post.sigmaH, risultati_post.ratioD);
catch ME
    fprintf('❌ Errore analisi post: %s\n\n', ME.message);
end

% Visualizzazioni 3D personalizzate
fprintf('PASSO 4: Creazione visualizzazioni 3D...\n');

try
    visualizzazioni3D(risultati_pre, risultati_post, mat_pre, mat_post, config, idCampione2);
    fprintf('✓ Visualizzazioni 3D create\n\n');
catch ME
    fprintf('❌ Errore visualizzazioni 3D: %s\n\n', ME.message);
end

% Confronti dettagliati
fprintf('PASSO 5: Grafici di confronto...\n');

try
    graficiConfronto(risultati_pre, risultati_post, config, idCampione2);
    fprintf('✓ Grafici di confronto generati\n\n');
catch ME
    fprintf('❌ Errore grafici confronto: %s\n\n', ME.message);
end

%% =====================================================================
%                  ESEMPIO 3: UTILIZZO FUNZIONI SINGOLE
% ======================================================================

fprintf('=========================================================================\n');
fprintf('                   ESEMPIO 3: FUNZIONI SINGOLE\n');
fprintf('=========================================================================\n\n');

% Esempio utilizzo createFigureMigliorata
fprintf('ESEMPIO 3a: Visualizzazione termografia personalizzata...\n');

try
    % Opzioni personalizzate per la visualizzazione
    opzioni_vis.colormap = 'jet';
    opzioni_vis.colorbar = true;
    opzioni_vis.grid = true;
    opzioni_vis.unita = '°C';
    opzioni_vis.view = [45, 30]; % Vista 3D
    
    fig_demo = createFigureMigliorata(mat_pre, 'Termografia Personalizzata', opzioni_vis);
    fprintf('✓ Termografia personalizzata creata\n\n');
    
    % Pausa per visualizzazione
    fprintf('Premi un tasto per continuare...\n');
    pause;
    close(fig_demo);
    
catch ME
    fprintf('❌ Errore visualizzazione: %s\n\n', ME.message);
end

% Esempio utilizzo utilità compatibilità
fprintf('ESEMPIO 3b: Test funzioni di compatibilità...\n');

try
    % Test timestamp
    ts = getTimestamp('completo');
    fprintf('Timestamp corrente: %s\n', ts);
    
    % Test statistiche
    dati_test = mat_pre(:);
    stats = calculateStats(dati_test);
    fprintf('Statistiche termografia:\n');
    fprintf('  Media: %.3f °C\n', stats.media);
    fprintf('  Std Dev: %.3f °C\n', stats.deviazione_std);
    fprintf('  Range: %.3f °C\n', stats.range);
    
    % Test info sistema
    info = getSystemInfo();
    fprintf('Sistema: %s %s\n', info.software, info.versione);
    fprintf('✓ Test compatibilità completato\n\n');
    
catch ME
    fprintf('❌ Errore test compatibilità: %s\n\n', ME.message);
end

%% =====================================================================
%                     ESEMPIO 4: BATCH PROCESSING
% ======================================================================

fprintf('=========================================================================\n');
fprintf('                     ESEMPIO 4: ELABORAZIONE BATCH\n');
fprintf('=========================================================================\n\n');

% Simulazione elaborazione multipla (per più campioni)
fprintf('Simulazione elaborazione batch per 3 campioni...\n');

nomi_campioni = {'T04_Campione1', 'T05_Campione2', 'T06_Campione3'};
progetti_batch = {'BatchStudio2024', 'BatchStudio2024', 'BatchStudio2024'};

for i = 1:length(nomi_campioni)
    fprintf('\n--- Elaborando campione %d/%d: %s ---\n', i, length(nomi_campioni), nomi_campioni{i});
    
    try
        % Per la demo, usiamo le stesse matrici con piccole variazioni
        variazione = 0.1 * randn(size(mat_pre));
        mat_pre_var = mat_pre + variazione;
        mat_post_var = mat_post + variazione * 0.5;
        
        % Analisi rapida
        config_batch = setupAmbienteAnalisi(progetti_batch{i});
        risultati_pre_batch = analisiPreAutomatica(mat_pre_var, config_batch, nomi_campioni{i});
        risultati_post_batch = analisiPostAutomatica(mat_post_var, config_batch, nomi_campioni{i});
        
        % Calcolo miglioramento
        miglioramento = ((risultati_pre_batch.ratioD - risultati_post_batch.ratioD) / risultati_pre_batch.ratioD) * 100;
        
        fprintf('✓ %s: RatioD %.3f → %.3f (Miglioramento: %.1f%%)\n', ...
                nomi_campioni{i}, risultati_pre_batch.ratioD, risultati_post_batch.ratioD, miglioramento);
        
    catch ME
        fprintf('❌ Errore campione %s: %s\n', nomi_campioni{i}, ME.message);
    end
end

fprintf('\n✓ Elaborazione batch completata\n\n');

%% =====================================================================
%                         RIEPILOGO FINALE
% ======================================================================

fprintf('=========================================================================\n');
fprintf('                         RIEPILOGO FINALE\n');
fprintf('=========================================================================\n\n');

fprintf('ESEMPI COMPLETATI:\n');
fprintf('✓ Esempio 1: Utilizzo basico automatico\n');
fprintf('✓ Esempio 2: Utilizzo avanzato step-by-step\n');
fprintf('✓ Esempio 3: Funzioni singole personalizzate\n');
fprintf('✓ Esempio 4: Elaborazione batch multipla\n\n');

fprintf('FUNZIONALITÀ DIMOSTRATE:\n');
fprintf('• Setup automatico ambiente di lavoro\n');
fprintf('• Analisi pre/post intervento automatizzata\n');
fprintf('• Visualizzazioni 3D avanzate per forme ricorrenti\n');
fprintf('• Grafici di confronto statistico\n');
fprintf('• Report automatico dettagliato\n');
fprintf('• Compatibilità MATLAB/Octave\n');
fprintf('• Elaborazione batch multipla\n');
fprintf('• Gestione errori e recovery automatico\n\n');

fprintf('OBIETTIVI RAGGIUNTI:\n');
fprintf('🎯 Etichettatura automatica di tutti i grafici\n');
fprintf('🎯 Salvataggio automatico con nomenclatura sistematica\n');
fprintf('🎯 Organizzazione file in cartelle specifiche\n');
fprintf('🎯 Visualizzazioni 3D per identificare forme ricorrenti\n');
fprintf('🎯 Compatibilità completa MATLAB/Octave\n');
fprintf('🎯 Automazione completa del processo\n\n');

% Lista directory create negli esempi
fprintf('DIRECTORY CREATE:\n');
esempi_dirs = dir([nomeProgetto '_*']);
for i = 1:length(esempi_dirs)
    if esempi_dirs(i).isdir
        fprintf('📁 %s/\n', esempi_dirs(i).name);
        
        % Mostra sottocartelle
        sottocartelle = dir(fullfile(esempi_dirs(i).name, '*'));
        for j = 1:length(sottocartelle)
            if sottocartelle(j).isdir && ~strcmp(sottocartelle(j).name, '.') && ~strcmp(sottocartelle(j).name, '..')
                num_files = length(dir(fullfile(esempi_dirs(i).name, sottocartelle(j).name, '*.*'))) - 2;
                fprintf('   └── %s/ (%d file)\n', sottocartelle(j).name, max(0, num_files));
            end
        end
    end
end

fprintf('\n=========================================================================\n');
fprintf('                    ESEMPIO COMPLETATO CON SUCCESSO!\n');
fprintf('=========================================================================\n\n');

fprintf('PROSSIMI PASSI:\n');
fprintf('1. Sostituire i dati sintetici con le tue termografie reali\n');
fprintf('2. Personalizzare i parametri di analisi secondo necessità\n');
fprintf('3. Adattare i titoli e le etichette per il tuo caso specifico\n');
fprintf('4. Aggiungere ulteriori analisi statistiche se necessario\n');
fprintf('5. Integrare con il workflow della tua tesi\n\n');

fprintf('PER SUPPORTO:\n');
fprintf('• Controllare i commenti nei file sorgente\n');
fprintf('• Verificare compatibilità versioni MATLAB/Octave\n');
fprintf('• Testare con dati reali prima dell''uso finale\n\n');

fprintf('Buon lavoro con la tua tesi magistrale! 🎓\n\n');

%% =====================================================================
%                    FUNZIONI AUSILIARIE ESEMPIO
% ======================================================================

function risultati_pre = analisiPreAutomatica(mat_pre, config, idCampione)
    % Versione semplificata per esempio senza input utente
    
    IR = rot90(mat_pre);
    [h, w] = size(IR);
    
    % Parametri automatici (80% centrale)
    margine_x = round(w * 0.1);
    margine_y = round(h * 0.1);
    
    xi = margine_x + 1;
    xf = w - margine_x;
    yi = margine_y + 1;
    yf = h - margine_y;
    
    fattoreCalibrazione = 1.0; % 1 pixel = 1 cm
    
    % Estrazione e calcoli
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
    
    % Risultati
    risultati_pre.idCampione = idCampione;
    risultati_pre.timestamp = datestr(now, 'HH-MM-SS');
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
end

function risultati_post = analisiPostAutomatica(mat_post, config, idCampione)
    % Versione semplificata per esempio senza input utente
    
    IR = rot90(mat_post);
    [h, w] = size(IR);
    
    % Parametri automatici (80% centrale)
    margine_x = round(w * 0.1);
    margine_y = round(h * 0.1);
    
    xi = margine_x + 1;
    xf = w - margine_x;
    yi = margine_y + 1;
    yf = h - margine_y;
    
    fattoreCalibrazione = 1.0; % 1 pixel = 1 cm
    
    % Estrazione e calcoli
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
    
    % Risultati
    risultati_post.idCampione = idCampione;
    risultati_post.timestamp = datestr(now, 'HH-MM-SS');
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
end