%% ANALISI DELL'INCIDENZA DEI TEMPI DI PRE-ASSEMBLAGGIO
% Autore: [Nome Studente]
% Data: 17 Maggio 2025
% 
% Questo script calcola e visualizza:
% 1. L'incidenza percentuale dei pre-assemblati sul tempo totale di produzione
% 2. La classificazione dell'incidenza (Bassa/Media/Alta)
% 3. La produttività (pezzi/ora) con due scenari: pre-assemblati in linea o fuori linea
% 4. I grafici comparativi per entrambe le analisi

%% CONFIGURAZIONE INIZIALE
clc;         % Pulisce la finestra dei comandi
clear;       % Rimuove tutte le variabili dall'area di lavoro
close all;   % Chiude tutte le figure aperte

%% INSERIMENTO DATI DI INPUT

% Definizione dei nomi delle macchine (sostituire con i nomi reali)
nomi_macchine = {'MSR', '3200K', 'Modello3', 'Modello4', 'Modello5', 'Modello6', 'Modello7', 'Modello8'};

% Dati di input: tempi task e pre-assemblati (in minuti) per ciascun modello
tempi_task = [65.49, 69.95, 88.77, 103.87, 96.53, 117.72, 66.05, 58.66]; % tempi di montaggio in linea (no pre-assemblati)
tempi_premontaggi = [21.95, 34.02, 51.54, 41.54, 34.64, 35.82, 35.02, 23.99]; % tempi dei pre-assemblati

%% CALCOLI PRINCIPALI

% Numero di modelli
n_modelli = length(tempi_task);

% Calcolo incidenza in percentuale dei pre-assemblati sulla linea
% Formula: (tempo_premontaggio / tempo_totale) * 100
incidenza = (tempi_premontaggi ./ (tempi_task + tempi_premontaggi)) * 100;

% Classificazione dell'incidenza in base a soglie predefinite
classificazione = strings(1, n_modelli);
for i = 1:n_modelli
    if incidenza(i) < 15
        classificazione(i) = "Bassa";
    elseif incidenza(i) <= 25
        classificazione(i) = "Media";
    else
        classificazione(i) = "Alta";
    end
end

% Calcolo produttività (pezzi/ora) in due scenari
tempo_totale_in_linea = tempi_task + tempi_premontaggi;     % Scenario 1: pre-assemblati fatti in linea
tempo_totale_fuori_linea = tempi_task;                      % Scenario 2: pre-assemblati fatti fuori linea
prod_in_linea = 60 ./ tempo_totale_in_linea;                % Produttività in [pz/h] - Scenario 1
prod_fuori_linea = 60 ./ tempo_totale_fuori_linea;          % Produttività in [pz/h] - Scenario 2

% Calcolo del miglioramento percentuale della produttività
miglioramento = ((prod_fuori_linea - prod_in_linea) ./ prod_in_linea) * 100;

%% VISUALIZZAZIONE RISULTATI - GRAFICO DELL'INCIDENZA

figure('Name', 'Incidenza Pre-Assemblati', 'NumberTitle', 'off');
b = bar(incidenza, 'FaceColor', 'flat');

% Colora le barre in base alla classificazione
for i = 1:n_modelli
    if strcmp(classificazione(i), "Bassa")
        b.CData(i,:) = [0.2, 0.8, 0.2]; % Verde per bassa incidenza
    elseif strcmp(classificazione(i), "Media")
        b.CData(i,:) = [1, 0.8, 0]; % Giallo per media incidenza
    else
        b.CData(i,:) = [0.8, 0.2, 0.2]; % Rosso per alta incidenza
    end
end

title('Incidenza dei pre-assemblati sulla linea principale');
xlabel('Macchina');
ylabel('Incidenza (%)');
xticks(1:n_modelli);
xticklabels(nomi_macchine);
grid on;
ylim([0 100]);

% Aggiungi etichette di classificazione sopra le barre
for i = 1:n_modelli
    text(i, incidenza(i) + 2, classificazione(i), 'HorizontalAlignment', 'center');
    text(i, incidenza(i)/2, [num2str(round(incidenza(i),1)) '%'], 'HorizontalAlignment', 'center', 'Color', 'white', 'FontWeight', 'bold');
end

% Aggiungi linee orizzontali per le soglie di classificazione
hold on;
yline(15, '--', 'Soglia Bassa-Media', 'LineWidth', 1.5, 'Color', [0.5 0.5 0.5], 'Alpha', 0.7);
yline(25, '--', 'Soglia Media-Alta', 'LineWidth', 1.5, 'Color', [0.5 0.5 0.5], 'Alpha', 0.7);
hold off;

% Salva il grafico (opzionale)
saveas(gcf, 'incidenza_premontaggi.png');

%% VISUALIZZAZIONE RISULTATI - GRAFICO DELLA PRODUTTIVITÀ

figure('Name', 'Confronto Produttività', 'NumberTitle', 'off');
bar_data = [prod_in_linea; prod_fuori_linea]';
b = bar(bar_data, 'grouped');

% Personalizza i colori delle barre
b(1).FaceColor = [0.2, 0.4, 0.8]; % Blu per produttività "in linea"
b(2).FaceColor = [0.2, 0.8, 0.4]; % Verde per produttività "fuori linea"

title('Confronto della produttività: pre-assemblati in linea vs fuori linea');
xlabel('Macchina');
ylabel('Produttività (pezzi/ora)');
xticks(1:n_modelli);
xticklabels(nomi_macchine);
legend('In linea', 'Fuori linea', 'Location', 'northwest');
grid on;

% Aggiungi le etichette dei valori sopra le barre
for i = 1:2
    for j = 1:n_modelli
        if i == 1
            val = prod_in_linea(j);
        else
            val = prod_fuori_linea(j);
        end
        text(j + (i-1.5)*0.3, val + 0.02, sprintf('%.1f', val), ...
            'HorizontalAlignment', 'center', 'FontSize', 8);
    end
end

% Salva il grafico (opzionale)
saveas(gcf, 'produttivita_confronto.png');

%% OUTPUT TESTUALE DEI RISULTATI
fprintf('\n==================================================================\n');
fprintf('RISULTATI ANALISI INCIDENZA TEMPI DI PRE-ASSEMBLAGGIO\n');
fprintf('==================================================================\n\n');

for i = 1:n_modelli
    fprintf('Macchina %s:\n', nomi_macchine{i});
    fprintf('  Tempo montaggio in linea: %.2f minuti\n', tempi_task(i));
    fprintf('  Tempo pre-assemblati: %.2f minuti\n', tempi_premontaggi(i));
    fprintf('  Incidenza pre-assemblati: %.2f%% (%s)\n', incidenza(i), classificazione(i));
    fprintf('  Produttività (in linea): %.2f pezzi/ora\n', prod_in_linea(i));
    fprintf('  Produttività (fuori linea): %.2f pezzi/ora\n', prod_fuori_linea(i));
    fprintf('  Miglioramento produttività: +%.2f%%\n\n', miglioramento(i));
end

%% RIEPILOGO FINALE
fprintf('==================================================================\n');
fprintf('RIEPILOGO MIGLIORAMENTI DI PRODUTTIVITÀ\n');
fprintf('==================================================================\n\n');

for i = 1:n_modelli
    fprintf('Macchina %s: +%.2f%%\n', nomi_macchine{i}, miglioramento(i));
end

fprintf('\nAnalisi completata con successo!\n');
