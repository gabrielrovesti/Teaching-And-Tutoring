function p_eval = interp_chebyshev(x_nodes, f_nodes, x_eval)
% INTERP_CHEBYSHEV - Interpolazione polinomiale con base di Chebyshev
%
% Input:
%   x_nodes - nodi di interpolazione (vettore)
%   f_nodes - valori della funzione nei nodi (vettore)
%   x_eval  - punti di valutazione (vettore)
%
% Output:
%   p_eval - valori del polinomio interpolante in x_eval
%
% Metodo: risolve il sistema lineare V*c = f dove V è la matrice
% di Vandermonde costruita con i polinomi di Chebyshev

    % Validazione input
    if length(x_nodes) ~= length(f_nodes)
        error('x_nodes e f_nodes devono avere la stessa lunghezza');
    end
    
    % Assicura formato colonna
    x_nodes = x_nodes(:);
    f_nodes = f_nodes(:);
    x_eval = x_eval(:);
    
    n = length(x_nodes);
    
    % Costruisce la matrice di Vandermonde con base di Chebyshev
    % V(i,j) = T_{j-1}(x_nodes(i)) = cos((j-1) * arccos(x_nodes(i)))
    V = cos((0:n-1)' * acos(x_nodes'));
    
    % Risolve il sistema lineare V*c = f_nodes per trovare i coefficienti
    c = V \ f_nodes;
    
    % Valuta il polinomio nei punti x_eval
    V_eval = cos((0:n-1)' * acos(x_eval'));
    p_eval = V_eval' * c;
    
    % Assicura formato colonna per l'output
    p_eval = p_eval(:);
end