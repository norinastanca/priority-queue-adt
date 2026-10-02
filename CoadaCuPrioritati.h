#ifndef CoadaCuPrioritati_h
#define CoadaCuPrioritati_h
#include <functional>
#include "IteratorCP.h"
#include <queue>
#include <utility>
#include <vector>
typedef int TElem;
typedef int TPrioritate;

typedef std::pair<TElem, TPrioritate> Element;

typedef bool(*Relatie)(TPrioritate, TPrioritate);

struct Nod {
    Element el;
    int urm;
    int pre;
};

class CP {
    friend class IteratorCP;
private:
    Nod* elem;
    int capacitate;
    int prim;
    int ultim;
    int primulLiber;
    int dim;// dimensiunea cuenta
    Relatie rel;

    void redimensioneaza();
public:
    //constructorul implicit
    CP(Relatie r);

    //adauga un element in CP, avand o anumita pioritate
    void adauga(TElem e, TPrioritate p);

    //acceseaza elementul cel mai prioritar in raport cu relatia de ordine
    //arunca exceptie daca CP e vida
    Element element()  const;

    //sterge elementul cel mai prioritar si il returneaza
    //arunca exceptie daca CP e vida
    Element sterge();

    //verifica daca CP e vida;
    bool vida() const;

    IteratorCP iterator() const;

    // destructorul cozii
    ~CP();
};
#endif