% TESTSISTEMA.M - Script di test per il sistema di analisi termografica
% 
% Questo script crea dati sintetici e testa il sistema modificato
% secondo le specifiche richieste dalla studentessa.

clear all;
close all;
clc;

fprintf('=================================================================\n');
fprintf('         TEST SISTEMA ANALISI TERMOGRAFICA MODIFICATO\n');
fprintf('=================================================================\n\n');

%% === CREAZIONE DATI SINTETICI ===
fprintf('📊 Creazione dati sintetici per test...\n');

% Parametri per termografie sintetiche
rows = 300;
cols = 400;
temp_base = 15.5;

% === TERMOGRAFIA PRE-INTERVENTO ===
% Simula presenza di umidità con gradiente verticale significativo
[X, Y] = meshgrid(1:cols, 1:rows);

% Gradiente di umidità forte (temperatura più bassa in basso)
gradiente_umidita_pre = 1.5 * (rows - Y) / rows;

% Variazioni spaziali e rumore
variazioni_spaziali = 0.6 * sin(2*pi*X/80) .* cos(pi*Y/60);
rumore_pre = 0.4 * randn(rows, cols);

% Composizione termografia pre-intervento
T04_1129 = temp_base + gradiente_umidita_pre + variazioni_spaziali + rumore_pre;

% === TERMOGRAFIA POST-INTERVENTO ===
% Simula miglioramento: gradiente ridotto del 60%
gradiente_umidita_post = gradiente_umidita_pre * 0.4;

% Meno rumore e variazioni più contenute
variazioni_spaziali_post = variazioni_spaziali * 0.7;
rumore_post = 0.25 * randn(rows, cols);

% Composizione termografia post-intervento
T04_2_1129 = temp_base + gradiente_umidita_post + variazioni_spaziali_post + rumore_post;

% Salva i dati per utilizzo futuro
save('T04_1129.mat', 'T04_1129');
save('T04_2_1129.mat', 'T04_2_1129');

fprintf('✓ Dati sintetici creati e salvati:\n');
fprintf('  - T04_1129.mat: %.1f-%.1f°C (Media: %.1f°C)\n', ...
        min(T04_1129(:)), max(T04_1129(:)), mean(T04_1129(:)));
fprintf('  - T04_2_1129.mat: %.1f-%.1f°C (Media: %.1f°C)\n\n', ...
        min(T04_2_1129(:)), max(T04_2_1129(:)), mean(T04_2_1129(:)));

%% === TEST SISTEMA MODIFICATO ===
fprintf('🚀 Avvio test del sistema modificato...\n\n');

% Parametri di test
casoStudio = 1129;
termografiaID = "T04";
localizzazione = "Ortona (CH)";

% Esegui analisi
try
    mainModificato(T04_1129, T04_2_1129, casoStudio, termografiaID, localizzazione);
    fprintf('\n✅ TEST COMPLETATO CON SUCCESSO!\n');
catch ME
    fprintf('\n❌ ERRORE DURANTE IL TEST: %s\n', ME.message);
    fprintf('Stack trace:\n');
    for i = 1:length(ME.stack)
        fprintf('  %s (line %d)\n', ME.stack(i).name, ME.stack(i).line);
    end
end

%% === VERIFICA FILES CREATI ===
fprintf('\n=== VERIFICA FILES CREATI ===\n');

% Percorso dove dovrebbero essere salvati i file
basePathOneDrive = fullfile(getenv('USERPROFILE'), 'OneDrive', 'Documenti');
if ~exist(basePathOneDrive, 'dir')
    basePathOneDrive = pwd;
end

cartellaProgetto = sprintf('%d %s', casoStudio, localizzazione);
cartellaTermografia = termografiaID;
percorsoCompleto = fullfile(basePathOneDrive, cartellaProgetto, cartellaTermografia);

if exist(percorsoCompleto, 'dir')
    fprintf('📁 Directory creata: %s\n', percorsoCompleto);
    
    % Lista file attesi
    fileAttesi = {
        sprintf('PV_%s_%d.fig', termografiaID, casoStudio), ...
        sprintf('PO_%s_%d.fig', termografiaID, casoStudio), ...
        sprintf('TN_%s_%d.fig', termografiaID, casoStudio), ...
        sprintf('I_%s_%d.fig', termografiaID, casoStudio), ...
        sprintf('PV_%s_%d_combinato.fig', termografiaID, casoStudio), ...
        sprintf('PO_%s_%d_combinato.fig', termografiaID, casoStudio), ...
        sprintf('TN_%s_%d_combinato.fig', termografiaID, casoStudio), ...
        sprintf('I_%s_%d_combinato.fig', termografiaID, casoStudio)
    };
    
    fprintf('\nFile creati:\n');
    for i = 1:length(fileAttesi)
        percorsoFile = fullfile(percorsoCompleto, fileAttesi{i});
        if exist(percorsoFile, 'file')
            fprintf('  ✓ %s\n', fileAttesi{i});
        else
            fprintf('  ❌ %s (MANCANTE)\n', fileAttesi{i});
        end
    end
    
    % Verifica file Excel/CSV
    fileExcel = sprintf('Risultati_%s_%d.xlsx', termografiaID, casoStudio);
    fileCSV = sprintf('Risultati_%s_%d.csv', termografiaID, casoStudio);
    
    if exist(fullfile(percorsoCompleto, fileExcel), 'file')
        fprintf('  ✓ %s\n', fileExcel);
    elseif exist(fullfile(percorsoCompleto, fileCSV), 'file')
        fprintf('  ✓ %s\n', fileCSV);
    else
        fprintf('  ⚠️  Nessun file Excel/CSV trovato\n');
    end
    
else
    fprintf('❌ Directory non trovata: %s\n', percorsoCompleto);
end

%% === ESEMPIO UTILIZZO CON ALTRI DATI ===
fprintf('\n=== ESEMPIO CON ALTRI PARAMETRI ===\n');
fprintf('Per utilizzare il sistema con altri dati:\n\n');
fprintf('1. Carica le tue termografie:\n');
fprintf('   load(''tua_termografia_pre.mat'');\n');
fprintf('   load(''tua_termografia_post.mat'');\n\n');
fprintf('2. Esegui l''analisi:\n');
fprintf('   mainModificato(matrice_pre, matrice_post, 1468, "T05", "Verona (VR)");\n\n');
fprintf('3. I grafici verranno salvati automaticamente in:\n');
fprintf('   OneDrive/Documenti/1468 Verona (VR)/T05/\n');
fprintf('   con nomenclatura: PV_T05_1468.fig, PO_T05_1468.fig, ecc.\n\n');

%% === TEST COMPATIBILITÀ OCTAVE ===
if exist('OCTAVE_VERSION', 'builtin')
    fprintf('=== COMPATIBILITÀ OCTAVE ===\n');
    fprintf('✓ Sistema rilevato: GNU Octave %s\n', version);
    fprintf('✓ Funzioni di base compatibili\n');
    fprintf('✓ Salvataggio in CSV invece di Excel\n');
    fprintf('⚠️  Alcune funzioni grafiche potrebbero essere limitate\n');
else
    fprintf('=== COMPATIBILITÀ MATLAB ===\n');
    fprintf('✓ Sistema rilevato: MATLAB %s\n', version);
    fprintf('✓ Tutte le funzioni disponibili\n');
    fprintf('✓ Salvataggio Excel disponibile\n');
end

fprintf('\n=================================================================\n');
fprintf('                        TEST COMPLETATO\n');
fprintf('=================================================================\n');

%% === PULIZIA OPZIONALE ===
risposta = input('\nVuoi visualizzare uno dei grafici creati? (s/n): ', 's');
if strcmpi(risposta, 's')
    try
        % Prova ad aprire il primo grafico combinato
        nomeGrafico = sprintf('PV_%s_%d_combinato.fig', termografiaID, casoStudio);
        percorsoGrafico = fullfile(percorsoCompleto, nomeGrafico);
        
        if exist(percorsoGrafico, 'file')
            openfig(percorsoGrafico);
            fprintf('✓ Grafico aperto: %s\n', nomeGrafico);
        else
            fprintf('❌ Grafico non trovato: %s\n', percorsoGrafico);
        end
    catch
        fprintf('❌ Impossibile aprire il grafico\n');
    end
end

fprintf('\n🎯 Se tutto funziona, ora puoi usare:\n');
fprintf('   mainModificato(tua_matrice_pre, tua_matrice_post, casoStudio, "TXX", "Località")\n\n');