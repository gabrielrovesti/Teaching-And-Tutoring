function utilitaCompatibilita()
    % UTILITACOMPATIBILITA - Raccolta di funzioni per compatibilità MATLAB/Octave
    %
    % Questo file contiene funzioni utility per garantire la compatibilità
    % tra MATLAB e GNU Octave per il sistema di analisi termografica.
    %
    % Funzioni disponibili:
    %   - isOctave()          - Verifica se si sta usando Octave
    %   - getTimestamp()      - Ottiene timestamp compatibile
    %   - saveCompatible()    - Salvataggio file compatibile
    %   - loadCompatible()    - Caricamento file compatibile
    %   - inputDialog()       - Dialog input compatibile
    %   - createDirectory()   - Creazione cartelle compatibile
    %   - printFigure()       - Stampa figure compatibile
    %   - setColormap()       - Impostazione colormap compatibile
    %   - calculateStats()    - Statistiche compatibili
    %   - validateInput()     - Validazione input
    %
    % Compatibilità: MATLAB e Octave
    
    fprintf('Utilità di compatibilità MATLAB/Octave caricate\n');
    fprintf('Versione: 1.0\n');
    
    if isOctave()
        fprintf('Sistema rilevato: GNU Octave %s\n', version);
    else
        fprintf('Sistema rilevato: MATLAB %s\n', version);
    end
end

function result = isOctave()
    % ISOCTAVE - Verifica se il codice è in esecuzione su Octave
    %
    % Output:
    %   result - true se Octave, false se MATLAB
    
    result = exist('OCTAVE_VERSION', 'builtin') ~= 0;
end

function timestamp = getTimestamp(formato)
    % GETTIMESTAMP - Ottiene timestamp in formato compatibile
    %
    % Input:
    %   formato - Formato timestamp ('completo', 'file', 'breve')
    %
    % Output:
    %   timestamp - Stringa timestamp
    
    if nargin < 1
        formato = 'completo';
    end
    
    switch lower(formato)
        case 'completo'
            if isOctave()
                timestamp = strftime('%Y-%m-%d %H:%M:%S', localtime(time));
            else
                timestamp = datestr(now, 'yyyy-mm-dd HH:MM:SS');
            end
            
        case 'file'
            if isOctave()
                timestamp = strftime('%Y-%m-%d_%H-%M', localtime(time));
            else
                timestamp = datestr(now, 'yyyy-mm-dd_HH-MM');
            end
            
        case 'breve'
            if isOctave()
                timestamp = strftime('%H-%M-%S', localtime(time));
            else
                timestamp = datestr(now, 'HH-MM-SS');
            end
            
        otherwise
            error('Formato timestamp non riconosciuto: %s', formato);
    end
end

function success = saveCompatible(filename, varargin)
    % SAVECOMPATIBLE - Salvataggio variabili compatibile MATLAB/Octave
    %
    % Input:
    %   filename - Nome file di destinazione
    %   varargin - Variabili da salvare
    %
    % Output:
    %   success - true se salvataggio riuscito
    
    try
        if isOctave()
            % Octave - sintassi semplificata
            if nargin == 2
                save(filename, varargin{1});
            else
                save(filename, varargin{:});
            end
        else
            % MATLAB - sintassi standard
            if nargin == 2
                save(filename, varargin{1});
            else
                save(filename, varargin{:});
            end
        end
        success = true;
    catch ME
        warning('Errore nel salvataggio: %s', ME.message);
        success = false;
    end
end

function [data, success] = loadCompatible(filename, varname)
    % LOADCOMPATIBLE - Caricamento file compatibile MATLAB/Octave
    %
    % Input:
    %   filename - Nome file da caricare
    %   varname  - Nome variabile specifica (opzionale)
    %
    % Output:
    %   data     - Dati caricati (struct se varname non specificato)
    %   success  - true se caricamento riuscito
    
    try
        if nargin < 2
            % Carica tutto il file
            data = load(filename);
        else
            % Carica variabile specifica
            if isOctave()
                temp = load(filename, varname);
                data = temp.(varname);
            else
                temp = load(filename, varname);
                data = temp.(varname);
            end
        end
        success = true;
    catch ME
        warning('Errore nel caricamento: %s', ME.message);
        data = [];
        success = false;
    end
end

function [valori, cancellato] = inputDialog(prompt, titolo, valore_default)
    % INPUTDIALOG - Dialog di input compatibile MATLAB/Octave
    %
    % Input:
    %   prompt         - Cell array con i prompt
    %   titolo         - Titolo del dialog
    %   valore_default - Valori default (opzionale)
    %
    % Output:
    %   valori     - Cell array con i valori inseriti
    %   cancellato - true se l'utente ha annullato
    
    if nargin < 3
        valore_default = {};
    end
    
    if nargin < 2
        titolo = 'Input';
    end
    
    if isOctave()
        % Octave - input da console
        fprintf('\n=== %s ===\n', titolo);
        valori = cell(size(prompt));
        cancellato = false;
        
        for i = 1:length(prompt)
            if i <= length(valore_default) && ~isempty(valore_default{i})
                risposta = input(sprintf('%s [default: %s]: ', prompt{i}, valore_default{i}), 's');
                if isempty(risposta)
                    valori{i} = valore_default{i};
                else
                    valori{i} = risposta;
                end
            else
                valori{i} = input(sprintf('%s: ', prompt{i}), 's');
            end
            
            % Controlla cancellazione (invio vuoto per tutti)
            if isempty(valori{i}) && (i > length(valore_default) || isempty(valore_default{i}))
                risposta_conferma = input('Vuoi annullare l''operazione? (s/n): ', 's');
                if strcmpi(risposta_conferma, 's')
                    cancellato = true;
                    valori = {};
                    return;
                end
            end
        end
    else
        % MATLAB - dialog grafico
        try
            dims = [1 60];
            answer = inputdlg(prompt, titolo, dims, valore_default);
            
            if isempty(answer)
                cancellato = true;
                valori = {};
            else
                cancellato = false;
                valori = answer;
            end
        catch
            % Fallback a input console anche su MATLAB
            fprintf('\n=== %s ===\n', titolo);
            valori = cell(size(prompt));
            cancellato = false;
            
            for i = 1:length(prompt)
                if i <= length(valore_default) && ~isempty(valore_default{i})
                    risposta = input(sprintf('%s [default: %s]: ', prompt{i}, valore_default{i}), 's');
                    if isempty(risposta)
                        valori{i} = valore_default{i};
                    else
                        valori{i} = risposta;
                    end
                else
                    valori{i} = input(sprintf('%s: ', prompt{i}), 's');
                end
            end
        end
    end
end

function success = createDirectory(percorso)
    % CREATEDIRECTORY - Creazione cartelle compatibile MATLAB/Octave
    %
    % Input:
    %   percorso - Percorso della cartella da creare
    %
    % Output:
    %   success - true se creazione riuscita
    
    try
        if isOctave()
            % Octave
            if ~exist(percorso, 'dir')
                [status, msg] = mkdir(percorso);
                if ~status
                    error('Mkdir fallito: %s', msg);
                end
            end
        else
            % MATLAB
            if ~exist(percorso, 'dir')
                mkdir(percorso);
            end
        end
        success = true;
    catch ME
        warning('Impossibile creare cartella %s: %s', percorso, ME.message);
        success = false;
    end
end

function success = printFigure(fig_handle, filename, formato)
    % PRINTFIGURE - Stampa/salvataggio figure compatibile
    %
    % Input:
    %   fig_handle - Handle della figura
    %   filename   - Nome file di destinazione
    %   formato    - Formato file ('fig', 'png', 'eps', ecc.)
    %
    % Output:
    %   success - true se salvataggio riuscito
    
    if nargin < 3
        formato = 'fig';
    end
    
    try
        if isOctave()
            % Octave - usa print
            switch lower(formato)
                case 'fig'
                    print(fig_handle, '-dfig', filename);
                case 'png'
                    print(fig_handle, '-dpng', filename);
                case 'eps'
                    print(fig_handle, '-deps', filename);
                case 'pdf'
                    print(fig_handle, '-dpdf', filename);
                otherwise
                    print(fig_handle, ['-d' formato], filename);
            end
        else
            % MATLAB - usa savefig o saveas
            switch lower(formato)
                case 'fig'
                    savefig(fig_handle, filename);
                otherwise
                    saveas(fig_handle, filename, formato);
            end
        end
        success = true;
    catch ME
        warning('Errore nel salvataggio figura: %s', ME.message);
        success = false;
    end
end

function success = setColormap(axes_handle, mappa_colori)
    % SETCOLORMAP - Impostazione colormap compatibile
    %
    % Input:
    %   axes_handle  - Handle degli assi (opzionale)
    %   mappa_colori - Nome della mappa colori
    %
    % Output:
    %   success - true se impostazione riuscita
    
    if nargin < 2
        mappa_colori = axes_handle;
        axes_handle = gca;
    end
    
    try
        if isOctave()
            % Octave - colormap globale
            colormap(mappa_colori);
        else
            % MATLAB - colormap locale se supportato
            if ~isempty(axes_handle)
                colormap(axes_handle, mappa_colori);
            else
                colormap(mappa_colori);
            end
        end
        success = true;
    catch ME
        warning('Impossibile impostare colormap %s: %s', mappa_colori, ME.message);
        success = false;
    end
end

function stats = calculateStats(dati, opzioni)
    % CALCULATESTATS - Calcolo statistiche compatibile
    %
    % Input:
    %   dati     - Array di dati numerici
    %   opzioni  - Struttura con opzioni (opzionale)
    %
    % Output:
    %   stats - Struttura con statistiche calcolate
    
    if nargin < 2
        opzioni = struct();
    end
    
    % Opzioni default
    if ~isfield(opzioni, 'includi_nan')
        opzioni.includi_nan = false;
    end
    
    if ~isfield(opzioni, 'percentili')
        opzioni.percentili = [5, 25, 50, 75, 95];
    end
    
    % Rimozione NaN se richiesto
    if ~opzioni.includi_nan
        dati = dati(~isnan(dati));
    end
    
    % Calcolo statistiche di base
    stats.n = length(dati);
    stats.media = mean(dati);
    stats.mediana = median(dati);
    stats.deviazione_std = std(dati);
    stats.varianza = var(dati);
    stats.minimo = min(dati);
    stats.massimo = max(dati);
    stats.range = stats.massimo - stats.minimo;
    
    % Percentili
    if isOctave()
        % Octave - calcolo manuale percentili
        dati_ordinati = sort(dati);
        stats.percentili = struct();
        for i = 1:length(opzioni.percentili)
            p = opzioni.percentili(i);
            idx = round(p/100 * length(dati_ordinati));
            idx = max(1, min(idx, length(dati_ordinati)));
            stats.percentili.(sprintf('p%d', p)) = dati_ordinati(idx);
        end
    else
        % MATLAB - funzione prctile
        stats.percentili = struct();
        try
            valori_perc = prctile(dati, opzioni.percentili);
            for i = 1:length(opzioni.percentili)
                p = opzioni.percentili(i);
                stats.percentili.(sprintf('p%d', p)) = valori_perc(i);
            end
        catch
            % Fallback calcolo manuale
            dati_ordinati = sort(dati);
            for i = 1:length(opzioni.percentili)
                p = opzioni.percentili(i);
                idx = round(p/100 * length(dati_ordinati));
                idx = max(1, min(idx, length(dati_ordinati)));
                stats.percentili.(sprintf('p%d', p)) = dati_ordinati(idx);
            end
        end
    end
    
    % Statistiche avanzate se i dati lo permettono
    if stats.n > 1
        try
            if isOctave()
                % Octave - calcolo manuale skewness e kurtosis
                dati_centrati = dati - stats.media;
                stats.asimmetria = mean(dati_centrati.^3) / (stats.deviazione_std^3);
                stats.curtosi = mean(dati_centrati.^4) / (stats.deviazione_std^4) - 3;
            else
                % MATLAB - funzioni built-in se disponibili
                try
                    stats.asimmetria = skewness(dati);
                    stats.curtosi = kurtosis(dati) - 3;
                catch
                    % Fallback calcolo manuale
                    dati_centrati = dati - stats.media;
                    stats.asimmetria = mean(dati_centrati.^3) / (stats.deviazione_std^3);
                    stats.curtosi = mean(dati_centrati.^4) / (stats.deviazione_std^4) - 3;
                end
            end
        catch
            stats.asimmetria = NaN;
            stats.curtosi = NaN;
        end
    else
        stats.asimmetria = NaN;
        stats.curtosi = NaN;
    end
end

function [valido, messaggio] = validateInput(valore, tipo, constraints)
    % VALIDATEINPUT - Validazione input con messaggi di errore
    %
    % Input:
    %   valore      - Valore da validare
    %   tipo        - Tipo atteso ('numeric', 'string', 'matrix', ecc.)
    %   constraints - Struttura con vincoli (opzionale)
    %
    % Output:
    %   valido    - true se input valido
    %   messaggio - Messaggio di errore se non valido
    
    valido = true;
    messaggio = '';
    
    if nargin < 3
        constraints = struct();
    end
    
    switch lower(tipo)
        case 'numeric'
            if ~isnumeric(valore)
                valido = false;
                messaggio = 'Il valore deve essere numerico';
                return;
            end
            
            if isfield(constraints, 'min') && any(valore < constraints.min)
                valido = false;
                messaggio = sprintf('Il valore deve essere >= %g', constraints.min);
                return;
            end
            
            if isfield(constraints, 'max') && any(valore > constraints.max)
                valido = false;
                messaggio = sprintf('Il valore deve essere <= %g', constraints.max);
                return;
            end
            
            if isfield(constraints, 'positive') && constraints.positive && any(valore <= 0)
                valido = false;
                messaggio = 'Il valore deve essere positivo';
                return;
            end
            
        case 'string'
            if ~ischar(valore)
                valido = false;
                messaggio = 'Il valore deve essere una stringa';
                return;
            end
            
            if isfield(constraints, 'min_length') && length(valore) < constraints.min_length
                valido = false;
                messaggio = sprintf('La stringa deve avere almeno %d caratteri', constraints.min_length);
                return;
            end
            
        case 'matrix'
            if ~isnumeric(valore) || ~ismatrix(valore)
                valido = false;
                messaggio = 'Il valore deve essere una matrice numerica';
                return;
            end
            
            if isfield(constraints, 'min_size')
                min_size = constraints.min_size;
                if size(valore, 1) < min_size(1) || size(valore, 2) < min_size(2)
                    valido = false;
                    messaggio = sprintf('La matrice deve avere dimensioni almeno %dx%d', min_size(1), min_size(2));
                    return;
                end
            end
            
        case 'file'
            if ~ischar(valore) || ~exist(valore, 'file')
                valido = false;
                messaggio = 'Il file specificato non esiste';
                return;
            end
            
        otherwise
            warning('Tipo di validazione non riconosciuto: %s', tipo);
    end
end

function info = getSystemInfo()
    % GETSYSTEMINFO - Ottiene informazioni di sistema
    %
    % Output:
    %   info - Struttura con informazioni di sistema
    
    info = struct();
    
    % Software
    if isOctave()
        info.software = 'GNU Octave';
        info.versione = version;
    else
        info.software = 'MATLAB';
        info.versione = version;
    end
    
    % Sistema operativo
    info.os = computer;
    
    % Data e ora
    info.timestamp = getTimestamp('completo');
    
    % Memoria disponibile (se possibile)
    try
        if isOctave()
            % Octave - informazioni limitate
            info.memoria_disponibile = 'Non disponibile';
        else
            % MATLAB - informazioni di memoria
            mem_info = memory;
            info.memoria_disponibile = mem_info.MemAvailableAllArrays;
            info.memoria_totale = mem_info.MemUsedMATLAB;
        end
    catch
        info.memoria_disponibile = 'Non disponibile';
    end
    
    % Path MATLAB/Octave
    info.path_corrente = pwd;
    
    % Versione utilità compatibilità
    info.versione_utilita = '1.0';
end