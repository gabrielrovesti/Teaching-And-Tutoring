function dlp = DLP(x, d)
% DLP - Calcolo nodi di Leja approssimati (Algoritmo 1)
% Calcolo produttoria per ogni punto --> crescita quadratica
%
% Input:
%   x - vettore colonna di punti della mesh nell'intervallo [-1,1]
%   d - grado del polinomio interpolante (scalare intero positivo)
%
% Output:
%   dlp - vettore riga di d+1 nodi di Leja approssimati
%
% Algoritmo: ricerca iterativa del punto che massimizza la produttoria
% |x - ξ₀| * |x - ξ₁| * ... * |x - ξₛ₋₁|

    % Validazione input
    if ~isvector(x) || ~isscalar(d) || d < 0 || round(d) ~= d || length(x) < d+1
        error('Input non valido: x deve essere un vettore, d intero positivo, length(x) >= d+1');
    end
    
    % Assicura che x sia vettore colonna
    x = x(:);
    
    % Inizializzazione
    dlp = zeros(1, d+1);
    dlp(1) = x(1);  % Primo nodo: primo elemento della mesh
    
    % Selezione iterativa dei nodi successivi
    for s = 2:d+1
        % Calcola la produttoria |x - ξᵢ| per tutti i nodi già selezionati
        produttoria = prod(abs(x - dlp(1:s-1)), 2);
        % il valore 2 assicura che il prodotto sia un vettore colonna
        % contenente i prodotti di ciascuna riga
        
        % Trova il punto che massimizza la produttoria
        [~, idx_max] = max(produttoria);
        dlp(s) = x(idx_max);
    end
end