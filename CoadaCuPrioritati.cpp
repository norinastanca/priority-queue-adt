#include "CoadaCuPrioritati.h"
#include <exception>


using namespace std;

CP::CP(Relatie r) {
    //BC=Theta(capacitate)
    //WC=Theta(capaictate)
    //AC=Theta(capaictate)
    //General=Theta(capaictate)
    this->rel = r;
    this->capacitate=10;
    this->elem = new Nod[capacitate];
    this->prim = -1;
    this->ultim= -1;
    this->dim= 0;

    for(int i=0;i<capacitate-1;i++) {
        elem[i].urm = i+1;
    }
    elem[capacitate-1].urm = -1;
    this->primulLiber=0;
}
void CP::redimensioneaza() {
    //BC=Theta(n)
    //WC=Theta(n)
    //AC=Theta(n)
    //General=O(n)
    int nouaCapacitate = capacitate*2;
    Nod* noiElemente = new Nod[nouaCapacitate];

    //copiem elem existente
    for(int i=0;i<capacitate;i++) {
        noiElemente[i]=elem[i];
    }

    for (int i=capacitate;i<nouaCapacitate-1;i++)
        noiElemente[i].urm = i+1;

    noiElemente[nouaCapacitate-1].urm = -1;

    this->primulLiber = capacitate;
    delete[] elem;
    this->elem = noiElemente;
    this->capacitate = nouaCapacitate;

}

void CP::adauga(TElem e,TPrioritate p) {
    //BC=Theta(1)//daca coada este goala sau daca elem nou e mai prioritar decat primul
    //WC=Theta(n)// il punem la final, e cel mai putin prioritar
    //AC=Theta(n)//
    //General=O(n)
    if (primulLiber==-1) {
        redimensioneaza();
    }

    int nou = primulLiber;//gaseste locul din vector unde sa puna noul element
    primulLiber = elem[primulLiber].urm;// actualizeaza primulLiber  cu urm casuta goala

    elem[nou].el = make_pair(e,p);//il pune in vector pe elem

    // parcurgem vectorul pana cand gasim un element mai mare decat elem nostru
    int curent = prim;
    while (curent != -1 && rel(elem[curent].el.second, p)) {
        curent = elem[curent].urm;
    }

    if (dim == 0) { // Cazul listei vide
        prim = ultim = nou;
        elem[nou].urm = -1;
        elem[nou].pre = -1;

    } else if (curent == prim) { // Inserare la inceput
        elem[nou].urm = prim;
        elem[nou].pre = -1;
        elem[prim].pre = nou;
        prim = nou;
    } else if (curent == -1) { // Inserare la sfarșit
        elem[nou].urm = -1;
        elem[nou].pre = ultim;
        elem[ultim].urm = nou;
        ultim = nou;
    } else { // Inserare în interior
        int anterior = elem[curent].pre;
        elem[nou].urm = curent;
        elem[nou].pre = anterior;
        elem[anterior].urm = nou;
        elem[curent].pre = nou;
    }
    dim++;
}

// Accesează elementul cel mai prioritar
Element CP::element() const {
    //BC=WC=AC=General=O(1)
    if (vida()) {
        throw exception();
    }
    return elem[prim].el;
}

// Șterge și returnează elementul cel mai prioritar
Element CP::sterge() {
    //BC=WC=AC=General=O(1)
    if (vida()) {
        throw exception();
    }

    int deSters = prim;
    Element extras = elem[deSters].el;

    // Actualizăm legăturile LDI
    prim = elem[prim].urm;// Noul prim devine al doilea element
    if (prim != -1) {
        elem[prim].pre = -1;// Daca mai exista elemente, noul prim nu mai are nimic în fata
    } else {
        ultim = -1;// Daca lista a devenit goala, actualizam și ultim
    }

    // Returnam nodul în lista de spații libere
    elem[deSters].urm = primulLiber;
    primulLiber = deSters;

    dim--;
    return extras;
}

// Verifica daca coada este vida
bool CP::vida() const {
    //BC=WC=AC=General=O(1)
    return dim == 0;
}

// Destructor
CP::~CP() {
    //BC=WC=AC=General=O(1)
    delete[] elem;
}
