#include "CoadaCuPrioritati.h"
#include <exception>

using namespace std;

// Constructorul iteratorului: pornește de la 'prim' (cel mai prioritar)
IteratorCP::IteratorCP(const CP& c) : cp(c) {
    //BC=WC=AC=General=O(1)
    this->curent = c.prim;
}

// Resetarea iteratorului la începutul listei
void IteratorCP::prim() {
    //BC=WC=AC=General=O(1)
    this->curent = cp.prim;
}

// Trecerea la următorul element în ordinea priorității
void IteratorCP::urmator() {
    //BC=WC=AC=General=O(1)
    if (!valid()) {
        throw exception();
    }
    // Folosim campul 'urm' din tabloul de noduri al cozii
    this->curent = cp.elem[curent].urm;
}

// Verifică dacă iteratorul mai are elemente de vizitat
bool IteratorCP::valid() const {
    //BC=WC=AC=General=O(1)
    return this->curent != -1;
}

// Returnează elementul curent vizitat de iterator
Element IteratorCP::element() const {
    //BC=WC=AC=General=O(1)
    if (!valid()) {
        throw exception();
    }
    return cp.elem[curent].el;
}

// Metoda din clasa CP care creează un iterator nou
IteratorCP CP::iterator() const {
    //BC=WC=AC=General=O(1)
    return IteratorCP(*this);
}