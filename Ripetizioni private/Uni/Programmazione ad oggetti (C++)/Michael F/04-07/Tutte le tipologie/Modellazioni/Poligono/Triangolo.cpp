#include "Triangolo.h"
#include <math.h>

Triangolo::Triangolo(const Punto* p): Poligono(3,p){}

//Area = (b*h)/2
double Triangolo::area() const{
	double per=perimetro()/2;	//Semiperimetro
	double a=Punto::Lung(p[0],p[1]), b=Punto::Lung(p[1],p[2]),  c=Punto::Lung(p[2],p[0]); //Lati
	return sqrt(per*(per-a)*(per-b)*(per-c));	//Formula di Erone --> A=√[p(p-a)(p-b)(p-c)]
}

Tri_Rettangolo::Tri_Rettangolo(const Punto* p): Triangolo(p){}

double Tri_Rettangolo::area() const{
	return (Punto::Lung(p[0],p[1]) * Punto::Lung(p[1],p[2]))/2;	//Area = (b*h)/2
}

Tri_Equi::Tri_Equi(const Punto* v): Triangolo(v){}

//Perimetro = Lato * 3
double Tri_Equi::perimetro()const{
	return (Punto::Lung(p[0],p[1]))*3;
}

double Tri_Equi::area() const{
	return ((Punto::Lung(p[0],p[1])/2)*sqrt(3) *Punto::Lung(p[0],p[1]))/2;	//Formula di Erone --> A=√[p(p-a)(p-b)(p-c)]
}


