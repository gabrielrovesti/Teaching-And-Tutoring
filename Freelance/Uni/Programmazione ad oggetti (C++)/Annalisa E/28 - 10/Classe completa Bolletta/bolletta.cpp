#include "bolletta.h"


bolletta::nodo::nodo(): riferimenti(0) {}      //COSTRUTTORE DEFAULT

bolletta::nodo::nodo(const telefonata& t, const smartp& p): info(t), next(p), riferimenti(0) {}     //COSTRUTTORE DI NODO

bolletta::bolletta(const bolletta& b) : first(b.first) {if(first->next!=0) first->riferimenti++;}

bool bolletta::Vuota() const {return first==0;}     //CONTROLLA SE VUOTA

void bolletta::Aggiungi_Telefonata(telefonata t)    //AGGIUNGE UNA TEL ALLA BOLLETTA
{
    first=new nodo(t, first);
}

void bolletta::Togli_Telefonata(telefonata t)   //TOGLIE DALLA BOLLETTA UNA TELEFONATA T
{
    smartp p=first, prec, q;
    smartp original=first;
    first=0;
    while(p!=0 && !(p->info==t))
    {
        q=new nodo(p->info, p->next);
        if(prec==0) first=q;
        else prec->next=q;
        prec=q; p=p->next;
     }

        if(p==0) {first=original;}

        else if (prec==0) first=p->next;
        else prec->next=p->next;
}

void bolletta::Sostituisci(const telefonata& t1, const telefonata& t2)
{
    smartp p=first, prec, q;
    smartp original=first;
    first=0;
    while(p!=0 && !(p->info==t1))
    {
        q=new nodo(p->info, p->next);
        if(prec==0) first=q;
        else prec->next=q;
        prec=q; p=p->next;
    }
    if(p==0) {first=original;}
    else if(prec==0) first->info=t2;
    else p->info=t2;
}

void bolletta::Sostituisci_Tutte(const telefonata& t1, const telefonata& t2) {
    smartp p = first, prec, q;
    smartp original = first;
    first = 0;
    bool found = false;
    while (p != 0) {
        if (p->info == t1) {
            q = new nodo(t2, p->next);
            if (prec == 0) first = q;
            else prec->next = q;
            prec = q;
            found = true;
            p = p->next;
        } else {
            q = new nodo(p->info, p->next);
            if (prec == 0) first = q;
            else prec->next = q;
            prec = q;
            p = p->next;
        }
    }
    if (!found) { // if t1 is not found, restore original list
        first = original;
    }
}

ostream& operator<<(ostream& os, const bolletta& b)
{
    if(b.Vuota()) os<<"BOLLETTA VUOTA"<<endl;
    else
    {
        os<<"TELEFONATE IN BOLLETTA"<<endl;
        bolletta::smartp p=b.first;
        int i=1;
        while(p!=0)
        {
            os<<i++<<") "<<p->info<<endl;
            p=p->next;
        }
    }
    return os;
}

telefonata bolletta::Estrai_Una()       //ESTRAE UNA TELEFONATA DALLA BOLLETTA
{
    telefonata aux=first->info;
    first=first->next;
    return aux;
}

bolletta& bolletta::operator=(const bolletta& b)    //OPERATORE =
{
    if(this!=&b)
        first.~smartp();
    first = b.first;
    return *this;
}

