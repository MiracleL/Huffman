#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include<QString>
#include<QFileDialog>
#include <QMainWindow>
#include<QMessageBox>
#include"huffman.h"
#include"heap.h"
#include"huffnode.h"
#include"qdebug.h"
#include"string"
using namespace std;
namespace Ui {
class MainWindow;
}

class a
{
public:
    static bool prior(Huffman<char>* x, Huffman<char>* y)
    { return x->weight() < y->weight(); }
};

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    int ascii[127]={0};
    Huffman<char> *tree=NULL;

    template<typename E>
    Huffman<E> *buildHuff(Huffman<E> **array,int count)
    {
         heap<Huffman<E> *,a> *forest=new heap<Huffman<E> *,a>(array,count,128);
         Huffman<char> *temp1,*temp2,*temp3=NULL;

 /**        for(int i=0;i<count;i++)
         {
            // Huffman<char> *j=forest->HeapArray[i];
              Huffman<char> *j1=array[i];
            // Huffnode<char> *k=j->Root();
              Huffnode<char> *k1=j1->Root();
              qDebug()<<((leafnode<char> *)k1)->val()
                     << " "<<((leafnode<char> *)k1)->weight()<<" ";
         }**/


         while(forest->size()>1)
         {
             temp1=forest->removefirst();
             temp2=forest->removefirst();
             temp3=new Huffman<E>(temp1,temp2);
             forest->insert(temp3);
             delete temp1;
             delete temp2;
         }
         delete forest;
         return temp3;
    }

    void trevisit(Huffnode<char> *root,QString bm,int level)
    {
        Huffnode<char> *currnode=root;

        if(currnode==NULL)
            qDebug()<<"The tree is empty";
        if(!currnode->isleaf())
        {
            bm+='0';
            trevisit(((intnode<char>*)currnode)->left(),bm,level+1);
            bm.replace(bm.length()-1,1,'1');
            trevisit(((intnode<char> *)currnode)->right(),bm,level+1);

        }
        else
        {
            qDebug()<<((leafnode<char> *)currnode)->val()<<" "
                   <<((leafnode<char> *)currnode)->weight()<<" "<<bm;
        }
    }



private slots:
    void on_pushButton_4_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;


};

#endif // MAINWINDOW_H
