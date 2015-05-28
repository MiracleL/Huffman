#ifndef INTNODE_H
#define INTNODE_H
#include"huffnode.h"
template <typename E>
class intnode:public Huffnode<E>
{
public:
    Huffnode<E> *lc;
    Huffnode<E> *rc;
    int wgt;
public:

    intnode(Huffnode<E> *l,Huffnode<E> *r)
    {
        wgt=l->weight()+r->weight();
        lc=l;
        rc=r;
    }
    int weight()
    {
        return wgt;
    }
    bool isleaf()
    {
        return false;
    }
    Huffnode<E> *left()
    {
        return lc;
    }
    Huffnode<E> *right()
    {
        return rc;
    }
    void setRight(Huffnode<E> *b)
    {
        rc=b;
    }
};
#endif // INTNODE_H
