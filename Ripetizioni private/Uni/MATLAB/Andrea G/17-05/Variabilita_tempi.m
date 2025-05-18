%% ANALISI DELLA VARIABILITÀ DEI TEMPI DI PRE-ASSEMBLAGGIO
% 
% Questo script calcola e visualizza:
% 1. Il coefficiente di variazione (CV) per ogni pre-assemblato
% 2. La classificazione della variabilità (Bassa/Media/Alta)
% 3. La visualizzazione grafica dei risultati
% 4. Il riepilogo statistico per ogni pre-assemblato

%% CONFIGURAZIONE INIZIALE
clc;         % Pulisce la finestra dei comandi
clear;       % Rimuove tutte le variabili dall'area di lavoro
close all;   % Chiude tutte le figure aperte

%% INSERIMENTO DATI DI INPUT

% Definizione dei nomi dei pre-assemblati
preassemblati = {'Trasformatore', 'Induttanza', 'Dissipatore', 'Lamiera tunnel', 'Ventole', ...
                'Sensore hall', 'Lamiera prese frontale', 'Lamiera prese posteriore', ...
                'Pannello posteriore', 'Pannello frontale con display', 'Plastica frontale', ...
                'Plastica posteriore', 'Interruttore', 'Motore', 'Attacco euro', ...
                'Scheda di potenza', 'Lamiera rocchetto', 'Lamiera superiore', ...
                'Lamiera supporto pannello', 'Lamiera piano interna', 'Adesivo con manopole'};

% Tempi di assemblaggio per ogni pre-assemblato su diverse macchine
% Righe = pre-assemblati, Colonne = modelli di macchine
% NaN indica che il pre-assemblato non è presente in quel modello
tempi_assemblaggio = {
    [0.75, 7.68, 2.64, 1.24, 2.74, 2.74, 2.63, 1.38],  % Trasformatore
    [NaN, NaN, 1.35, NaN, 0.50, 0.50, NaN, NaN],      % Induttanza
    [2.03, 3.28, 9.54, 3.69, 0.84, 0.84, 4.04, 4.56],  % Dissipatore
    [1.71, 1.30, 2.66, 2.61, 2.01, 2.01, NaN, NaN],    % Lamiera tunnel
    [1.31, 1.46, 2.63, 1.24, NaN, NaN, 1.49, 2.81],    % Ventole
    [0.39, 0.66, 1.03, 1.06, 0.66, 0.66, NaN, 0.49],  % Sensore hall
    [NaN, 2.33, 8.49, 2.46, 2.36, 1.71, 3.24, 2.71],  % Lamiera prese frontale
    [0.82, 0.58, 0.63, NaN, NaN, NaN, NaN, 0.54],      % Lamiera prese posteriore
    [7.88, 8.05, 11.37, 1.39, 4.36, 4.36, 9.28, 8.14], % Pannello posteriore
    [0.92, 0.92, 0.73, NaN, NaN, NaN, NaN, NaN],      % Pannello frontale con display
    [0.60, 0.60, 0.86, NaN, NaN, NaN, 0.52, 0.44],    % Plastica frontale
    [NaN, 0.64, 0.60, NaN, NaN, NaN, 0.64, 0.80],     % Plastica posteriore
    [NaN, NaN, 2.35, 0.85, 1.09, 1.09, NaN, 1.35],    % Interruttore
    [NaN, NaN, NaN, 3.41, 2.16, 1.16, 4.58, NaN],     % Motore
    [NaN, NaN, NaN, 3.37, 2.62, 2.62, 2.92, NaN],     % Attacco euro
    [NaN, NaN, NaN, 2.67, 2.89, 3.48, NaN, NaN],      % Scheda di potenza
    [NaN, NaN, NaN, NaN, 0.89, 0.89, 1.22, NaN],      % Lamiera rocchetto
    [0.69, NaN, NaN, 1.59, NaN, NaN, NaN, NaN],       % Lamiera superiore
    [NaN, NaN, NaN, NaN, 2.90, 4.92, NaN, NaN],       % Lamiera supporto pannello
    [0.58, NaN, NaN, 0.84, NaN, NaN, 0.58, NaN],      % Lamiera piano interna
    [NaN, NaN, NaN, NaN, 5.04, 3.88, NaN, NaN],       % Adesivo con manopole
};

%% ANALISI DELLA VARIABILITÀ

% Inizializza array per risultati
num_preassemblati = length(preassemblati);
CV_percentuali = NaN(1, num_preassemblati);       % Coefficiente di variazione
colori = zeros(num_preassemblati, 3);             % RGB per ogni barra
classificazione_variabilita = strings(1, num_preassemblati);
media_tempi = NaN(1, num_preassemblati);          % Media dei tempi
dev_std_tempi = NaN(1, num_preassemblati);        % Deviazione standard
num_modelli_validi = zeros(1, num_preassemblati); % Numero di modelli con questo pre-assemblato

% Intestazione della tabella di output
fprintf('\n==================================================================\n');
fprintf('ANALISI VARIABILITÀ TEMPI DI PRE-ASSEMBLAGGIO\n');
fprintf('==================================================================\n\n');

% Analisi per ogni pre-assemblato
for i = 1:num_preassemblati
    % Estrai i tempi per questo pre-assemblato
    tempi = tempi_assemblaggio{i};
    
    % Filtra i tempi validi (non NaN)
    tempi_validi = tempi(~isnan(tempi));
    num_modelli_validi(i) = length(tempi_validi);
    
    % Se ci sono almeno 2 tempi validi, calcola le statistiche
    if num_modelli_validi(i) >= 2
        % Calcola media e deviazione standard
        media_tempi(i) = mean(tempi_validi);
        dev_std_tempi(i) = std(tempi_validi);
        
        % Calcola il coefficiente di variazione (CV) in percentuale
        coeff_var = (dev_std_tempi(i) / media_tempi(i)) * 100;
        CV_percentuali(i) = coeff_var;
        
        % Classificazione della variabilità
        if coeff_var < 15
            classificazione_variabilita(i) = 'Bassa variabilità';
            colori(i,:) = [0.2, 0.8, 0.2]; % Verde per bassa variabilità
        elseif coeff_var > 20
            classificazione_variabilita(i) = 'Alta variabilità';
            colori(i,:) = [1, 0.2, 0.2]; % Rosso per alta variabilità
        else
            classificazione_variabilita(i) = 'Variabilità intermedia';
            colori(i,:) = [1, 0.8, 0]; % Giallo per variabilità intermedia
        end
        
        % Output testuale per questo pre-assemblato
        fprintf('Pre-assemblato: %s\n', preassemblati{i});
        fprintf('  Presente in %d modelli su 8\n', num_modelli_validi(i));
        fprintf('  Media tempi: %.2f minuti\n', media_tempi(i));
        fprintf('  Deviazione standard: %.2f minuti\n', dev_std_tempi(i));
        fprintf('  Coefficiente di variazione: %.2f%% → %s\n\n', coeff_var, classificazione_variabilita(i));
    else
        % Se c'è solo un modello o nessuno, non calcolare il CV
        fprintf('Pre-assemblato: %s\n', preassemblati{i});
        fprintf('  Presente in %d modelli su 8 (insufficiente per calcolare la variabilità)\n\n', num_modelli_validi(i));
    end
end

%% VISUALIZZAZIONE GRAFICA DEI RISULTATI

% Crea un vettore di indici dei pre-assemblati con dati validi
idx_validi = find(~isnan(CV_percentuali));
if isempty(idx_validi)
    error('Non ci sono pre-assemblati con dati sufficienti per l''analisi.');
end

% Estrai solo i pre-assemblati con dati validi per il grafico
preassemblati_validi = preassemblati(idx_validi);
CV_validi = CV_percentuali(idx_validi);
colori_validi = colori(idx_validi, :);

% Crea il grafico a barre
figure('Name', 'Variabilità Tempi Pre-Assemblati', 'NumberTitle', 'off', 'Position', [100, 100, 1000, 600]);
b = bar(CV_validi, 'FaceColor', 'flat');
b.CData = colori_validi; % Assegna colore individuale a ciascuna barra

% Imposta etichette e titoli
title('Coefficiente di Variazione per Pre-Assemblato', 'FontSize', 14);
xlabel('Pre-Assemblato', 'FontSize', 12);
ylabel('Coefficiente di Variazione (%)', 'FontSize', 12);
xticks(1:length(preassemblati_validi));
xticklabels(preassemblati_validi);
xtickangle(45); % Ruota le etichette per leggibilità
grid on;

% Aggiungi linee orizzontali per le soglie di classificazione
hold on;
yline(15, '--', 'Soglia bassa variabilità (15%)', 'LineWidth', 1.5, 'Color', [0.5 0.5 0.5], 'Alpha', 0.7);
yline(20, '--', 'Soglia alta variabilità (20%)', 'LineWidth', 1.5, 'Color', [0.5 0.5 0.5], 'Alpha', 0.7);

% Aggiungi etichette con i valori precisi sopra ogni barra
for i = 1:length(CV_validi)
    text(i, CV_validi(i) + 2, sprintf('%.1f%%', CV_validi(i)), ...
        'HorizontalAlignment', 'center', 'FontSize', 9);
end

% Aggiusta i limiti dell'asse y per una migliore visualizzazione
current_ylim = ylim;
ylim([0, max(max(CV_validi) * 1.2, current_ylim(2))]);

% Legenda per i colori
legend({'Coefficiente di Variazione'}, 'Location', 'northwest');

hold off;

% Salva il grafico (opzionale)
saveas(gcf, 'variabilita_premontaggi.png');

%% GRAFICO AGGIUNTIVO: ISTOGRAMMA DELLA DISTRIBUZIONE DEI CV

figure('Name', 'Distribuzione Variabilità', 'NumberTitle', 'off');
histogram(CV_validi, 10, 'FaceColor', [0.3, 0.6, 0.9], 'EdgeColor', 'white');
title('Distribuzione dei Coefficienti di Variazione');
xlabel('Coefficiente di Variazione (%)');
ylabel('Frequenza');
grid on;

% Aggiungi linee verticali per le soglie
hold on;
xline(15, '--', 'Soglia bassa (15%)', 'LineWidth', 1.5, 'Color', [0.2, 0.8, 0.2]);
xline(20, '--', 'Soglia alta (20%)', 'LineWidth', 1.5, 'Color', [1, 0.2, 0.2]);
hold off;

% Salva il grafico (opzionale)
saveas(gcf, 'distribuzione_variabilita.png');

%% RIEPILOGO FINALE

% Conta quanti pre-assemblati rientrano in ciascuna categoria
n_bassa = sum(CV_percentuali < 15 & ~isnan(CV_percentuali));
n_media = sum(CV_percentuali >= 15 & CV_percentuali <= 20 & ~isnan(CV_percentuali));
n_alta = sum(CV_percentuali > 20 & ~isnan(CV_percentuali));
n_totale = n_bassa + n_media + n_alta;

fprintf('==================================================================\n');
fprintf('RIEPILOGO FINALE DELL''ANALISI\n');
fprintf('==================================================================\n\n');

fprintf('Totale pre-assemblati analizzati: %d\n', n_totale);
fprintf('  - Pre-assemblati con BASSA variabilità (CV < 15%%): %d (%.1f%%)\n', n_bassa, (n_bassa/n_totale)*100);
fprintf('  - Pre-assemblati con MEDIA variabilità (15%% <= CV <= 20%%): %d (%.1f%%)\n', n_media, (n_media/n_totale)*100);
fprintf('  - Pre-assemblati con ALTA variabilità (CV > 20%%): %d (%.1f%%)\n\n', n_alta, (n_alta/n_totale)*100);

fprintf('Pre-assemblati con maggiore variabilità:\n');
% Trova i 3 pre-assemblati con CV più alto
[~, idx_sorted] = sort(CV_percentuali, 'descend');
for i = 1:min(3, length(idx_sorted))
    if ~isnan(CV_percentuali(idx_sorted(i)))
        fprintf('  %d. %s (CV = %.2f%%)\n', i, preassemblati{idx_sorted(i)}, CV_percentuali(idx_sorted(i)));
    end
end

fprintf('\nAnalisi completata con successo!\n');
