function config = setupAmbienteAnalisi(nomeProgetto, dataAnalisi)
    % SETUPAMBIENTEANALISI - Crea la struttura di cartelle organizzata per l'analisi
    %
    % Sintassi: config = setupAmbienteAnalisi(nomeProgetto, dataAnalisi)
    %
    % Input:
    %   nomeProgetto - Nome del progetto (stringa)
    %   dataAnalisi  - Data dell'analisi in formato 'yyyy-mm-dd' (opzionale)
    %
    % Output:
    %   config - Struttura di configurazione con i percorsi delle cartelle
    %
    % Compatibilità: MATLAB e Octave
    
    % Gestione parametri opzionali
    if nargin < 2
        dataAnalisi = datestr(now, 'yyyy-mm-dd');
    end
    if nargin < 1
        nomeProgetto = 'AnalisiTermica';
    end
    
    % Creazione cartella principale del progetto
    cartellaP = fullfile(pwd, sprintf('%s_%s', nomeProgetto, dataAnalisi));
    
    % Compatibilità Octave/MATLAB per creazione cartelle
    if exist('OCTAVE_VERSION', 'builtin')
        % Octave
        if ~exist(cartellaP, 'dir')
            [status, msg] = mkdir(cartellaP);
            if ~status
                error('Impossibile creare la cartella: %s', msg);
            end
        end
    else
        % MATLAB
        if ~exist(cartellaP, 'dir')
            mkdir(cartellaP);
        end
    end
    
    % Definizione sottocartelle
    sottocartelle = {'termografie_grezze', 'grafici_elaborati', 'grafici_confronto', ...
                     'visualizzazioni_3d', 'dati_statistici', 'report'};
    
    % Creazione sottocartelle
    for i = 1:length(sottocartelle)
        sottoCartella = fullfile(cartellaP, sottocartelle{i});
        if exist('OCTAVE_VERSION', 'builtin')
            % Octave
            if ~exist(sottoCartella, 'dir')
                [status, msg] = mkdir(sottoCartella);
                if ~status
                    warning('Impossibile creare sottocartella %s: %s', sottocartelle{i}, msg);
                end
            end
        else
            % MATLAB
            if ~exist(sottoCartella, 'dir')
                mkdir(sottoCartella);
            end
        end
    end
    
    % Configurazione di output
    config.nomeProgetto = nomeProgetto;
    config.dataAnalisi = dataAnalisi;
    config.cartellaP = cartellaP;
    config.sottocartelle = sottocartelle;
    
    % Percorsi completi delle sottocartelle per facilità d'uso
    config.percorsi.termografie = fullfile(cartellaP, 'termografie_grezze');
    config.percorsi.grafici = fullfile(cartellaP, 'grafici_elaborati');
    config.percorsi.confronti = fullfile(cartellaP, 'grafici_confronto');
    config.percorsi.vis3d = fullfile(cartellaP, 'visualizzazioni_3d');
    config.percorsi.statistiche = fullfile(cartellaP, 'dati_statistici');
    config.percorsi.report = fullfile(cartellaP, 'report');
    
    % Salvataggio configurazione
    percorsoConfig = fullfile(cartellaP, 'configurazione_analisi.mat');
    if exist('OCTAVE_VERSION', 'builtin')
        % Octave usa save con sintassi diversa
        save(percorsoConfig, 'config');
    else
        % MATLAB
        save(percorsoConfig, 'config');
    end
    
    fprintf('Ambiente di analisi inizializzato: %s\n', cartellaP);
    fprintf('Cartelle create: %d\n', length(sottocartelle));
    
    % Mostra struttura creata
    fprintf('\nStruttura cartelle:\n');
    for i = 1:length(sottocartelle)
        fprintf('  - %s/\n', sottocartelle{i});
    end
end