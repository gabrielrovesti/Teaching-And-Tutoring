function dlp2 = DLP2(x, d)
% DLP2 - Calcolo nodi di Leja approssimati (Algoritmo 2)
%
% Input:
%   x - vettore colonna di punti della mesh nell'intervallo [-1,1]
%   d - grado del polinomio interpolante (scalare intero positivo)
%
% Output:
%   dlp2 - vettore riga di d+1 nodi di Leja approssimati
%
% Algoritmo: fattorizzazione LU con pivoting della matrice di Vandermonde
% costruita con i polinomi di Chebyshev

    % Validazione input
    if ~isvector(x) || ~isscalar(d) || d < 0 || round(d) ~= d || length(x) < d+1
        error('Input non valido: x deve essere un vettore, d intero positivo, length(x) >= d+1');
    end
    
    % Assicura che x sia vettore colonna
    x = x(:);
    
    % Costruisce la matrice di Vandermonde con base di Chebyshev
    % V(i,j) = T_{j-1}(x_i) = cos((j-1) * arccos(x_i))
    % dove T_k è il k-esimo polinomio di Chebyshev
    V = cos((0:d)' * acos(x'));  % Matrice (d+1) x length(x)
    
    % Fattorizzazione LU con pivoting: P*V = L*U
    % P contiene la permutazione che ordina i punti secondo i criteri di Leja
    [~, ~, P] = lu(V, 'vector');
    
    % I primi d+1 elementi della permutazione sono i nodi di Leja
    dlp2 = x(P(1:d+1))';  % Restituisce vettore riga
end