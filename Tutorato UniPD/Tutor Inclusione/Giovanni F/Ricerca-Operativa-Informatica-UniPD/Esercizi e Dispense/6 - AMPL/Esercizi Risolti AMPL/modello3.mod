set I; #linee
set J; #prodotti

param F{I}; #costi fissi linea
param C{I,J}; #costi orari linea/prodotto
param A{I,J}; #produttività oraria linea/prodotto
param B{J}; #richiesta minima linea
param D{I}; #capacità per linea

param M default 10000; #big-M constraint rispetto ai parametri D

var x{I, J} >=0 integer;
var y{I} binary;

minimize costo: sum{i in I, j in J}
	C[i,j]*x[i,j] + sum{i in I} F[i]*y[i]; 
s.t. produttivita{j in J}: sum{i in I} A[i,j]*x[i,j] >= B[j];
s.t. capacita{i in I}: sum{j in J} x[i,j] <= D[i];
s.t. viaggi{i in I}: sum{j in J} x[i,j] <= M*y[i];
