#ifndef LEAFNODE_H
#define LEAFNODE_H
#include"huffnode.h"
template <typename E>
class leafnode:public Huffnode<E>
{
private:
    E it;              //value
    int wgt;        //Weight
public:

    leafnode(E &val,int freq)
    {
        it=val;
        wgt=freq;
    }

    int weight()
    {
        return wgt;
    }

    E val()
    {
        return it;
    }
    bool isleaf()
    {
        return true;
    }
};
#endif // LEAFNODE_H
