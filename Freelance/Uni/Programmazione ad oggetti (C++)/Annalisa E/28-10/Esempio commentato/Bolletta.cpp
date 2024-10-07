#include <Bolletta.h>

Bolletta& Bolletta::operator=(const Bolletta& b){
    // Idea: copiare tutti i campi
    // info = b.info;
    // next = b.next

    // (1) Controllo che non ci sia interferenza

    if(*this != b){
        // (2) Pulire la memoria da interferenze ("aliasing" - puntatori nella stessa area di memoria che fanno casino)
        // delete p;
        distruggi(b.first);

        // (3) Copio tutti i campi e sottocampi
        first = copia(b.first);

        // (4) Ritorno il puntatore "al contesto"
        return *this;
    }


}