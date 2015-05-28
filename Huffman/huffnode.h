#ifndef HUFFNODE_H
#define HUFFNODE_H
#include<QString>

template <typename E>
class Huffnode
{
public:
    virtual ~Huffnode(){}
    virtual int weight()=0;
    virtual bool isleaf()=0;
};

#endif // HUFFNODE_H
