#ifndef ITERATOR_H
#define ITERATOR_H

class CP;

typedef int TElem;
typedef int TPrioritate;
typedef std::pair<TElem, TPrioritate> Element;

class IteratorCP {
    friend class CP;
private:
    const CP& cp;
    int curent;

    IteratorCP(const CP& c);

public:
    void prim();
    void urmator();
    bool valid() const;
    Element element() const;
};

#endif