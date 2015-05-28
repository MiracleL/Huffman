#ifndef HUFFMAN_H
#define HUFFMAN_H

#include"huffnode.h"
#include"leafnode.h"
#include"intnode.h"

template <typename E>

class Huffman
{
public:
    Huffnode<E> *root;
public:
    Huffman(E &val, int freq)
    {
        root=new leafnode<E>(val,freq);
    }
    Huffman(Huffman<E> *l,Huffman<E> *r)
    {
        root=new intnode<E>(l->root,r->root);
    }
    ~Huffman(){}

    Huffnode<E> *Root()
    {
        return root;   // 返回当前节点,小心重复定义
    }
    int weight()
    {
        return root->weight();
    }

};

#endif // HUFFMAN_H
