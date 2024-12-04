set I; #prodotti (aranciata e concentrato)
set J; #risorse (acqua minerale e arance)

param B{J}; #risorsa disponibile
param R{I}; #ricavo unitario prodotto
param A{I,J}; #quantità "j" consumata per unità di prodotto "i"

var x{I} >= 0 integer; #quantità di prodotto da produrre

maximize ricavo: sum{i in I} R[i]*x[i];
s.t. soddisfazione{j in J}: sum {i in I} A[i,j]*x[i] <= B[j];
