#ifndef HEAP_H
#define HEAP_H
#include"qdebug.h"
#include<assert.h>

template<typename E>
class heap
{
public:
    E *HeapArray;
    int maxsize;  //Maximum size of the heap
    int n;
    void siftdown(int pos) {
      while (!isleaf(pos)) { // Stop if pos is a leaf
        int j = leftchild(pos);  int rc = rightchild(pos);
        if ((rc < n) && prior(HeapArray[rc], HeapArray[j]))
          j = rc;            // Set j to greater child's value
        if (prior(HeapArray[pos], HeapArray[j])) return; // Done
        swap(HeapArray, pos, j);
        pos = j;             // Move down
      }
    }

public:
    heap(E *h,int number,int max)
    {
        HeapArray=h;
        n=number;
        maxsize=max;
        buildHeap();
    }
    bool prior(E x,E y)
    {
        return x<y;
    }

    void swap(E *HeapA,int pos,int j)
    {
        E x=HeapA[pos];
        HeapA[pos]=HeapA[j];
        HeapA[j]=x;
    }

    int size()
    {
        return n;
    }
    bool isleaf(int pos)
    {
        return (pos>=n/2)&&(pos<n);
    }
    int leftchild(int pos)
    {
        return 2*pos+1;
    }
    int rightchild(int pos)
    {
        return 2*pos+2;
    }
    int parent(int pos)
    {
        return (pos-1)/2;
    }
    void buildHeap()
    {
        for(int i=n/2-1;i>=0;i--)
            siftdown(i);
    }
    void insert(E &it)
    {
        if(n>maxsize)
            qDebug()<<"The Heap is full";
        int curr=n++;
        HeapArray[curr]=it;
        while((curr!=0)&&prior(HeapArray[curr],HeapArray[parent(curr)]))
        {
            swap(HeapArray,curr,parent(curr));
            curr=parent(curr);
        }
    }

    E removefirst()
    {
      if(n<=0)
          qDebug()<<"Heap is empty";
      swap(HeapArray, 0, --n);       // Swap first with last value
      if (n != 0) siftdown(0);  // Siftdown new root val
      return HeapArray[n];             // Return deleted value
    }

    E remove(int pos)
    {
      if (pos == (n-1)) n--; // Last element, no work to do
      else
      {
        swap(HeapArray, pos, --n);          // Swap with last value
        while ((pos != 0) &&
               (prior(HeapArray[pos], HeapArray[parent(pos)]))) {
          swap(HeapArray, pos, parent(pos)); // Push up large key
          pos = parent(pos);
        }
        if (n != 0) siftdown(pos);     // Push down small key
      }
      return HeapArray[n];
    }

};

#endif // HEAP_H
