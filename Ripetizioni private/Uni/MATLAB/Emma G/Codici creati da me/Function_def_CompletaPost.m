
function FunctionCompletaPost(termografia)
     
    %CREATEFIGURE1(termografia)
    axes1 = axes('Units','Centimeters','Parent',figure);
    hold(axes1,'on');
    surf(termografia,'Parent',axes1,'EdgeColor','none');
    view(axes1,[-180 90]);
    grid(axes1,'on');
    c=colorbar(axes1);
    c.Label.String='°C';

    %% createfigure2
    IR=rot90(termografia);
    createfigure(IR);
    title('Termografia');

    %% Estrazione valori
    %Creazione finestra dialogo di input (PRE INTERVENTO)
    prompt={'Enter minimum value on x-axes','Enter maximum value on x-axes','Enter minimum value on y-axes','Enter maximum value on y-axes'};
   
    %Titolo finestra dialogo
    dlgtitle='Input - Ranges - axes'; 
    
    %Dimensioni riquadro
    dims=[1 60]; 
    definput={'min x','max x','min y','max y'};
    answer=inputdlg(prompt,dlgtitle,dims,definput);
    
    %Converti i valori di input in numeri 
    xi=str2num(answer{1})+1;
    xf=str2num(answer{2});
    yi=str2num(answer{3})+1;
    yf=str2num(answer{4});

    [maxY, maxX] = size(IR);
    if xf > maxX || xi < 1 || yf > maxY || yi < 1
        error('Selected region is out of image bounds. Max X: %d, Max Y: %d', maxX, maxY);
    end

    %Ritaglio della termografia 
    subIR = IR(yi:yf, xi:xf);
    
    %Visualizza la termografia ritagliata
    createfigure(subIR);

    
    %% calibrazione 
    %Conversione da pixel in cm 
    prompt={'Enter distance in pixels','Enter distance in cm'};
    dlgtitle='Convert pixels to cm';
    dims=[1 60];
    definput={'pixels','cm'};
    answer=inputdlg(prompt,dlgtitle,dims,definput);
    distanceInPixel=str2num(answer{1});
    distanceInCm=str2num(answer{2});
    calibrationFactor=distanceInPixel/distanceInCm; 

    %% grafico temperatura profili verticali
    %Media verticale 
    V_AVG=mean(subIR);
    
    %deviazione standard verticale
    V_dev=std(subIR);
    sigmaV = mean(V_dev')
    fprintf('sigmaV (post): %.4f\n', sigmaV);

    %media totale sottomatrice
    Tot_AVG=mean(subIR,'all');

    sz=size(subIR);
    h_subIR=sz(1); 
    b_subIR=sz(2);

    %grafico profili verticali
    dH=linspace(0,(xf-xi)/calibrationFactor,b_subIR); 
    fig_vert_post = figure;
    plot(dH, V_AVG, 'g-', 'LineWidth', 1.0, 'DisplayName', 'μ post intervento');
    hold on;
    plot(dH, V_AVG+2*V_dev, 'k--', 'LineWidth', 0.7, 'DisplayName', 'μ+2σ');
    plot(dH, V_AVG-2*V_dev, 'k--', 'LineWidth', 0.7, 'DisplayName', 'μ−2σ');
   
    xlabel('Posizione X [cm]'); 
    ylabel('Temperatura media [°C]');
    title('Profili verticali: confronto pre/post intervento', 'FontWeight', 'bold');
    legend('Location', 'northeast');
    ytickformat('%.1f')

    % Salva il grafico dei profili verticali
    savefig(fig_vert_post, 'vert_post.fig')

    %% grafico temperatura profili orizzontali
    %media orizzontale
    tsubIR=subIR';
    H_AVG=mean(tsubIR);
    
    %deviazione standard orizzonale
    H_dev=std(tsubIR);
    sigmaH = mean(H_dev');
    fprintf('sigmaH (post): %.4f\n', sigmaH);

    dV=linspace(0,(yf-yi)/calibrationFactor,h_subIR);
    fig_orr_post = figure; 
    plot(dV,H_AVG,'g-', 'LineWidth', 1.0, 'DisplayName','μ post intervento');
    hold on
    plot(dV,H_AVG+2*H_dev,'k--','LineWidth', 0.7, 'DisplayName','μ+2σ');
    plot(dV,H_AVG-2*H_dev,'k--','LineWidth', 0.7, 'DisplayName','μ−2σ');
   
    xlabel('Posizione Y [cm]'); 
    ylabel('Temperatura media [°C]');
    title('Profili orizzontali: confronto pre/post intervento', 'FontWeight', 'bold');
    legend('Location', 'northeast');
    ytickformat('%.1f')
    
    savefig(fig_orr_post, 'orr_post.fig')

    %% temperatura normalizzata profili orizzontali 
    DH_AVG=H_AVG-Tot_AVG;
    fig_norm_post = figure; 
    plot(dV,DH_AVG,'g-', 'LineWidth', 1.0, 'DisplayName','μ post intervento');
    hold on
    plot(dV,DH_AVG+2*H_dev,'k--','LineWidth', 0.7, 'DisplayName','μ+2σ');
    plot(dV,DH_AVG-2*H_dev,'k--','LineWidth', 0.7, 'DisplayName','μ−2σ');
    
    xlabel('Posizione Y [cm]'); 
    ylabel('Temperatura normalizzata [°C]');
    title('Normalizzazione temperatura: confronto pre/post intervento', 'FontWeight', 'bold');
    legend('Location', 'northeast');
    ytickformat('%.1f')
    
    savefig(fig_norm_post, 'norm_post.fig')

    %% Interpolazione 
    %Interpolazione lineare dei dati 
    T_int=polyfit(dV,DH_AVG,1);
    m = T_int(1)
    q = T_int(2)
    fprintf('m (post): %.4f\n', m);
    fprintf('q (post): %.4f\n', q);
    r_int= T_int(2) + T_int(1) * dV; 
    fig_int_post = figure;
    plot(dV,r_int,'g-', 'LineWidth', 1.0, 'DisplayName','Interpolazione lineare post intervento');
    hold on
    plot(dV,DH_AVG,'g--', 'LineWidth', 0.7, 'DisplayName','μ post intervento');
   
    xlabel('Posizione Y [cm]'); 
    ylabel('Temperatura normalizzata [°C]');
    title('Interpolazione lineare: confronto pre/post intervento', 'FontWeight', 'bold');
    legend('Location', 'northeast');
    ytickformat('%.1f')
   
    savefig(fig_int_post, 'int_post.fig')

    %% Calcolo gradiente dei profili orizzontali
    dV=linspace(0,(yf-yi)/calibrationFactor,h_subIR);
    L=max(dV);
    max_DH=max(DH_AVG);
    min_DH=min(DH_AVG);
    grad_post = (max_DH-min_DH)/L
end
