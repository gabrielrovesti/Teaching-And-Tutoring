function L = leb_con(z, x)
% LEB_CON - Calcolo della costante di Lebesgue
% Termometro della stabilità di interpolazione stabilendo qualità dei nodi;
% L'errore di interpolazione è al massimo \Lambda volte l'errore di
% approssimazione; fuori dall'intervallo possibile esplosione
% Input:
%   z - vettore riga dei nodi di interpolazione
%   x - vettore colonna di punti su cui valutare la funzione di Lebesgue
%
% Output:
%   L - costante di Lebesgue (scalare)
%
% La costante di Lebesgue è definita come:
% L = max_x Σᵢ |ℓᵢ(x)|
% dove ℓᵢ(x) sono i polinomi di Lagrange 
% -> l_i(x) = prod_(j = 0, j \neq i)^(n) (x - x_j) / (x_i - x_j)

    % Validazione input
    if isempty(z) || isempty(x)
        error('Input non valido: z e x non possono essere vuoti');
    end
    
    % Assicura formato corretto
    z = z(:)';  % vettore riga
    x = x(:);   % vettore colonna
    
    n = length(z);
    
    % Inizializza il vettore per i valori della funzione di Lebesgue
    lebesgue_vals = zeros(size(x));
    
    % Calcola la somma dei valori assoluti dei polinomi di Lagrange
    for i = 1:n
        % Calcola il polinomio di Lagrange ℓᵢ(x)
        % ℓᵢ(x) = ∏_{j≠i} (x - zⱼ)/(zᵢ - zⱼ)
        
        % Indici di tutti i nodi tranne il corrente
        altri_nodi = [1:i-1, i+1:n];
        
        % Calcola la produttoria del polinomio di Lagrange
        lagrange_poly = prod((x - z(altri_nodi)) ./ (z(i) - z(altri_nodi)), 2);
        
        % Accumula il valore assoluto
        lebesgue_vals = lebesgue_vals + abs(lagrange_poly);
    end
    
    % La costante di Lebesgue è il massimo della funzione di Lebesgue
    L = max(lebesgue_vals);
end