#include "mainwindow.h"
#include <QApplication>
#include"heap.h"
#include"qdebug.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    int array[10]={1,2,3,4,5,6,7,8,9,10};
    heap<int> *k=new heap<int>(array,10,20);
    k->removefirst();
\
    for(int i=0;i<10;i++)
        qDebug()<<k->HeapArray[i];
    w.show();

    return a.exec();
}
