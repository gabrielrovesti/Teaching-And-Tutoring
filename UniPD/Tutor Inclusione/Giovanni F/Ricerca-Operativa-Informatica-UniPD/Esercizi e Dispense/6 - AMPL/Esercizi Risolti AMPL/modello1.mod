set I; #insieme dei prodotti
set J; #insieme delle materie prime

param C{I}; #costo di produzione
param P{I}; #profitto unitario
param F{I}; #costo fisso
param B{J};	#materia prima disponibile
param A{I, J};
param W; #budget
param M default W; #costante

var x{I} >=0 integer;
var y{I} binary;

maximize costo: sum{i in I} P[i]*x[i];
s.t. materiaprima{j in J}: sum{i in I} A[i,j]*x[i] <= B[j];
s.t. costo_fisso: sum{i in I} (C[i]*x[i] + F[i]*y[i]) <= W;
s.t. bigM {i in I}: x[i] <= M*y[i];
