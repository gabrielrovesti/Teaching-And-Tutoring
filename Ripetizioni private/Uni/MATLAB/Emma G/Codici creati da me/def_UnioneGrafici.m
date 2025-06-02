
function UnioneGrafici(grafico_pre, grafico_post)
    percorso_pre = fullfile(pwd, grafico_pre);
    percorso_post = fullfile(pwd, grafico_post);    

    fig1 = openfig(grafico_pre, 'invisible');
    fig2 = openfig(grafico_post, 'invisible');

    ax1 = findobj(fig1, 'type', 'axes');
    lines1 = findobj(ax1, 'type', 'line');

    ax2 = findobj(fig2, 'type', 'axes');
    lines2 = findobj(ax2, 'type', 'line');

    figure;
    hold on;

    for i = 1:length(lines1)
        plot(lines1(i).XData, lines1(i).YData, ...
             'Color', lines1(i).Color, ...
             'LineStyle', lines1(i).LineStyle, ...
             'LineWidth', lines1(i).LineWidth, ...
             'DisplayName', lines1(i).DisplayName);
    end

    for i = 1:length(lines2)
        plot(lines2(i).XData, lines2(i).YData, ...
             'Color', lines2(i).Color, ...
             'LineStyle', lines2(i).LineStyle, ...
             'LineWidth', lines2(i).LineWidth, ...
             'DisplayName', lines2(i).DisplayName);
    end

    legend show;
    grid on;
    box on;
end
