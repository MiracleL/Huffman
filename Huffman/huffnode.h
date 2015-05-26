#ifndef HUFFNODE_H
#define HUFFNODE_H

template <typename E>
class Huffnode
{
public:
    Huffnode();
    virtual ~Huffnode(){}
    virtual int weight()=0;
    virtual bool isleaf()=0;
};

#endif // HUFFNODE_H
