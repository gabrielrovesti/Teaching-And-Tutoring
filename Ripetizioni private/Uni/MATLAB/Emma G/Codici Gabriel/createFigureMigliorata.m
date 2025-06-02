function fig_handle = createFigureMigliorata(termografia, titolo, opzioni)
    % CREATEFIGUREMIGLIORATA - Visualizzazione termografia con compatibilità MATLAB/Octave
    %
    % Sintassi: fig_handle = createFigureMigliorata(termografia, titolo, opzioni)
    %
    % Input:
    %   termografia - Matrice numerica della termografia
    %   titolo      - Titolo del grafico (opzionale)
    %   opzioni     - Struttura con opzioni di visualizzazione (opzionale)
    %
    % Output:
    %   fig_handle  - Handle della figura creata
    %
    % Opzioni disponibili:
    %   opzioni.colormap    - Mappa colori ('hot', 'jet', 'cool', ecc.)
    %   opzioni.colorbar    - Mostra colorbar (true/false)
    %   opzioni.grid        - Mostra griglia (true/false)
    %   opzioni.view        - Angolo di vista [az, el]
    %   opzioni.unita       - Unità di misura per colorbar
    %   opzioni.range       - Range temperatura [min, max]
    %   opzioni.salva       - Percorso salvataggio (stringa)
    %
    % Compatibilità: MATLAB e Octave
    %
    % Esempi:
    %   % Uso base
    %   createFigureMigliorata(termografia);
    %   
    %   % Con titolo
    %   createFigureMigliorata(termografia, 'Termografia Pre-intervento');
    %   
    %   % Con opzioni complete
    %   opz.colormap = 'hot';
    %   opz.colorbar = true;
    %   opz.unita = '°C';
    %   createFigureMigliorata(termografia, 'Termografia', opz);
    
    % === GESTIONE PARAMETRI INPUT ===
    if nargin < 1
        error('È necessario fornire almeno la matrice termografia');
    end
    
    if nargin < 2 || isempty(titolo)
        titolo = 'Termografia';
    end
    
    if nargin < 3
        opzioni = struct();
    end
    
    % === OPZIONI DEFAULT ===
    default_options.colormap = 'hot';
    default_options.colorbar = true;
    default_options.grid = true;
    default_options.view = [-180, 90];
    default_options.unita = '°C';
    default_options.range = [];
    default_options.salva = '';
    default_options.edge_color = 'none';
    default_options.font_size = 12;
    default_options.title_size = 14;
    
    % Merge opzioni utente con default
    nomi_campi = fieldnames(default_options);
    for i = 1:length(nomi_campi)
        if ~isfield(opzioni, nomi_campi{i})
            opzioni.(nomi_campi{i}) = default_options.(nomi_campi{i});
        end
    end
    
    % === VALIDAZIONE INPUT ===
    if isempty(termografia) || ~isnumeric(termografia)
        error('La termografia deve essere una matrice numerica non vuota');
    end
    
    if size(termografia, 1) < 2 || size(termografia, 2) < 2
        error('La termografia deve avere dimensioni almeno 2x2');
    end
    
    % Rimozione valori NaN e Inf
    if any(isnan(termografia(:))) || any(isinf(termografia(:)))
        warning('Rilevati valori NaN o Inf nella termografia - verranno sostituiti');
        termografia(isnan(termografia)) = mean(termografia(:), 'omitnan');
        termografia(isinf(termografia)) = mean(termografia(:), 'omitnan');
    end
    
    % === CREAZIONE FIGURA ===
    fig_handle = figure();
    
    % Configurazione figura compatibile MATLAB/Octave
    if ~exist('OCTAVE_VERSION', 'builtin')
        % MATLAB - configurazione avanzata
        set(fig_handle, 'Name', titolo, 'NumberTitle', 'off');
        set(fig_handle, 'Color', 'white');
        
        % Posizione e dimensioni ottimali
        screen_size = get(0, 'ScreenSize');
        fig_width = min(800, screen_size(3) * 0.6);
        fig_height = min(600, screen_size(4) * 0.6);
        fig_x = (screen_size(3) - fig_width) / 2;
        fig_y = (screen_size(4) - fig_height) / 2;
        set(fig_handle, 'Position', [fig_x, fig_y, fig_width, fig_height]);
    else
        % Octave - configurazione semplificata
        set(fig_handle, 'Name', titolo);
    end
    
    % === CREAZIONE ASSI ===
    if ~exist('OCTAVE_VERSION', 'builtin')
        % MATLAB
        axes_handle = axes('Parent', fig_handle, 'Units', 'normalized');
    else
        % Octave
        axes_handle = axes();
    end
    
    hold(axes_handle, 'on');
    
    % === VISUALIZZAZIONE SUPERFICIE ===
    try
        % Creazione superficie 3D
        surf_handle = surf(termografia, 'Parent', axes_handle, ...
                          'EdgeColor', opzioni.edge_color, ...
                          'FaceColor', 'interp');
        
        % Impostazione vista
        view(axes_handle, opzioni.view);
        
        % Materiale e illuminazione (solo MATLAB)
        if ~exist('OCTAVE_VERSION', 'builtin')
            try
                material(axes_handle, 'dull');
                lighting(axes_handle, 'gouraud');
            catch
                % Ignora errori di materiale/illuminazione
            end
        end
        
    catch ME
        % Fallback per sistemi con problemi surf
        warning('Impossibile creare superficie 3D, usando imagesc: %s', ME.message);
        
        % Visualizzazione 2D alternativa
        imagesc(termografia, 'Parent', axes_handle);
        set(axes_handle, 'YDir', 'normal');
    end
    
    % === CONFIGURAZIONE ASSI ===
    
    % Griglia
    if opzioni.grid
        grid(axes_handle, 'on');
    else
        grid(axes_handle, 'off');
    end
    
    % Box
    box(axes_handle, 'on');
    
    % Etichette assi
    xlabel(axes_handle, 'Posizione X [pixel]', 'FontSize', opzioni.font_size, 'FontWeight', 'bold');
    ylabel(axes_handle, 'Posizione Y [pixel]', 'FontSize', opzioni.font_size, 'FontWeight', 'bold');
    
    % Solo per vista 3D
    if length(opzioni.view) == 2 && opzioni.view(2) ~= 90
        zlabel(axes_handle, sprintf('Temperatura [%s]', opzioni.unita), ...
               'FontSize', opzioni.font_size, 'FontWeight', 'bold');
    end
    
    % Titolo
    title(axes_handle, titolo, 'FontSize', opzioni.title_size, 'FontWeight', 'bold');
    
    % === COLORMAP E COLORBAR ===
    
    % Impostazione colormap
    try
        if exist('OCTAVE_VERSION', 'builtin')
            % Octave - colormap globale
            colormap(opzioni.colormap);
        else
            % MATLAB - colormap locale
            colormap(axes_handle, opzioni.colormap);
        end
    catch
        warning('Colormap %s non disponibile, usando default', opzioni.colormap);
        if exist('OCTAVE_VERSION', 'builtin')
            colormap('hot');
        else
            colormap(axes_handle, 'hot');
        end
    end
    
    % Range colori
    if ~isempty(opzioni.range) && length(opzioni.range) == 2
        caxis(axes_handle, opzioni.range);
    else
        % Range automatico con esclusione outlier
        dati_validi = termografia(~isnan(termografia) & ~isinf(termografia));
        if ~isempty(dati_validi)
            q1 = prctile(dati_validi(:), 5);
            q99 = prctile(dati_validi(:), 95);
            if q99 > q1
                caxis(axes_handle, [q1, q99]);
            end
        end
    end
    
    % Colorbar
    if opzioni.colorbar
        try
            if exist('OCTAVE_VERSION', 'builtin')
                % Octave
                c = colorbar();
                if isfield(opzioni, 'unita') && ~isempty(opzioni.unita)
                    ylabel(c, sprintf('Temperatura [%s]', opzioni.unita), ...
                           'FontSize', opzioni.font_size, 'FontWeight', 'bold');
                end
            else
                % MATLAB
                c = colorbar(axes_handle);
                c.Label.String = sprintf('Temperatura [%s]', opzioni.unita);
                c.Label.FontSize = opzioni.font_size;
                c.Label.FontWeight = 'bold';
                
                % Formattazione tick colorbar
                if ~isempty(opzioni.range)
                    c.Limits = opzioni.range;
                end
                
                % Tick personalizzati se range definito
                if ~isempty(opzioni.range) && diff(opzioni.range) > 0
                    num_ticks = 6;
                    tick_values = linspace(opzioni.range(1), opzioni.range(2), num_ticks);
                    c.Ticks = tick_values;
                    tick_labels = cell(size(tick_values));
                    for i = 1:length(tick_values)
                        tick_labels{i} = sprintf('%.1f', tick_values(i));
                    end
                    c.TickLabels = tick_labels;
                end
            end
        catch ME
            warning('Impossibile creare colorbar: %s', ME.message);
        end
    end
    
    % === CONFIGURAZIONI AVANZATE (solo MATLAB) ===
    if ~exist('OCTAVE_VERSION', 'builtin')
        try
            % Anti-aliasing
            set(fig_handle, 'Renderer', 'opengl');
            
            % Toolbar personalizzata
            set(fig_handle, 'MenuBar', 'figure');
            set(fig_handle, 'ToolBar', 'figure');
            
            % Callback per resize
            set(fig_handle, 'ResizeFcn', @(src, evt) resizeCallback(axes_handle));
            
        catch
            % Ignora errori di configurazione avanzata
        end
    end
    
    % === STATISTICHE TERMOGRAFIA ===
    
    % Calcolo statistiche di base
    temp_media = mean(termografia(:), 'omitnan');
    temp_std = std(termografia(:), 'omitnan');
    temp_min = min(termografia(:));
    temp_max = max(termografia(:));
    
    % Aggiunta testo informativo (opzionale)
    if ~exist('OCTAVE_VERSION', 'builtin')
        try
            % Posiziona testo statistiche nell'angolo
            text_x = 0.02;
            text_y = 0.98;
            
            stats_text = sprintf('Media: %.2f%s\nStd: %.2f%s\nRange: %.2f-%.2f%s', ...
                               temp_media, opzioni.unita, temp_std, opzioni.unita, ...
                               temp_min, temp_max, opzioni.unita);
            
            annotation('textbox', [text_x, text_y-0.15, 0.2, 0.15], ...
                      'String', stats_text, ...
                      'FontSize', 10, ...
                      'BackgroundColor', 'white', ...
                      'EdgeColor', 'black', ...
                      'FitBoxToText', 'on', ...
                      'VerticalAlignment', 'top');
        catch
            % Ignora errori di annotazione
        end
    end
    
    % === SALVATAGGIO ===
    if ~isempty(opzioni.salva)
        try
            if exist('OCTAVE_VERSION', 'builtin')
                % Octave
                print(fig_handle, '-dfig', opzioni.salva);
            else
                % MATLAB
                savefig(fig_handle, opzioni.salva);
                
                % Salva anche come PNG per compatibilità
                [path, name, ~] = fileparts(opzioni.salva);
                png_path = fullfile(path, [name, '.png']);
                saveas(fig_handle, png_path, 'png');
            end
            
            fprintf('Termografia salvata: %s\n', opzioni.salva);
            
        catch ME
            warning('Impossibile salvare la figura: %s', ME.message);
        end
    end
    
    % === OUTPUT INFORMAZIONI ===
    fprintf('\n=== INFORMAZIONI TERMOGRAFIA ===\n');
    fprintf('Dimensioni: %dx%d pixel\n', size(termografia, 1), size(termografia, 2));
    fprintf('Temperatura media: %.3f %s\n', temp_media, opzioni.unita);
    fprintf('Deviazione standard: %.3f %s\n', temp_std, opzioni.unita);
    fprintf('Range: %.3f - %.3f %s\n', temp_min, temp_max, opzioni.unita);
    fprintf('Colormap: %s\n', opzioni.colormap);
    fprintf('Vista: [%.0f, %.0f]\n', opzioni.view(1), opzioni.view(2));
    
end

% === FUNZIONI CALLBACK ===

function resizeCallback(axes_handle)
    % Callback per ridimensionamento figura (solo MATLAB)
    try
        % Mantieni proporzioni assi durante resize
        axis(axes_handle, 'equal');
        drawnow;
    catch
        % Ignora errori di callback
    end
end

% === FUNZIONE COMPATIBILITÀ LEGACY ===

function createfigure(termografia)
    % CREATEFIGURE - Funzione compatibilità con codice esistente
    % Wrapper per createFigureMigliorata con impostazioni legacy
    
    opzioni.colormap = 'hot';
    opzioni.colorbar = true;
    opzioni.grid = true;
    opzioni.view = [-180, 90];
    opzioni.unita = '°C';
    
    createFigureMigliorata(termografia, 'Termografia', opzioni);
end