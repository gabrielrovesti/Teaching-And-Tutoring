function creaDatiTest()
    % CREADATITEST - Genera i file .mat di test in modo pulito
    %
    % Compatibilità: MATLAB e Octave
    
    fprintf('📊 Creazione dati di test per analisi termografica...\n');
    
    % === PARAMETRI ===
    rows = 300; cols = 400;
    temp_pre = 15.8;   % Temperatura base pre-intervento
    temp_post = 15.2;  % Temperatura base post-intervento (migliorata)
    
    % === MATRICE PRE-INTERVENTO ===
    [X, Y] = meshgrid(1:cols, 1:rows);
    
    % Gradiente umidità forte (dal basso verso l'alto)
    gradiente_pre = 1.2 * (rows - Y) / rows;
    
    % Variazioni e rumore
    variazioni = 0.4 * sin(2*pi*X/80) .* cos(pi*Y/60);
    rumore_pre = 0.3 * randn(rows, cols);
    
    % Composizione finale pre-intervento
    T04_1129 = temp_pre + gradiente_pre + variazioni + rumore_pre;
    
    % === MATRICE POST-INTERVENTO ===
    % Gradiente ridotto (intervento efficace al 70%)
    gradiente_post = gradiente_pre * 0.3;  % Riduzione del 70%
    rumore_post = 0.2 * randn(rows, cols);  % Meno rumore
    
    % Composizione finale post-intervento  
    T04_2_1129 = temp_post + gradiente_post + variazioni * 0.6 + rumore_post;
    
    % === SALVATAGGIO FORMATO OCTAVE ===
    save('T04_1129.mat', 'T04_1129', '-v6');
    save('T04_2_1129.mat', 'T04_2_1129', '-v6');
    
    % === VERIFICA ===
    fprintf('✅ File creati:\n');
    fprintf('   T04_1129.mat: %.1f-%.1f°C (Media: %.1f°C)\n', ...
            min(T04_1129(:)), max(T04_1129(:)), mean(T04_1129(:)));
    fprintf('   T04_2_1129.mat: %.1f-%.1f°C (Media: %.1f°C)\n', ...
            min(T04_2_1129(:)), max(T04_2_1129(:)), mean(T04_2_1129(:)));
    
    % Test caricamento
    clear T04_1129 T04_2_1129;
    load('T04_1129.mat'); load('T04_2_1129.mat');
    fprintf('✅ Test caricamento: OK\n\n');
    
    fprintf('🚀 Ora esegui: mainSistemaCompleto(T04_1129, T04_2_1129)\n');
end