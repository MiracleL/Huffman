#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include<QString>
#include<QFileDialog>
#include <QMainWindow>
#include<QMessageBox>
#include"huffman.h"
#include"heap.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    int ascii[127];
    template<typename E>
    Huffman<E> *buildHuff(Huffman<E> **array,int count)
    {
         heap<Huffman<E> *> *forest=new heap<Huffman<E> *>(array,count,count);
         Huffman<char> *temp1,*temp2,*temp3=NULL;
         while(forest->size()>1)
         {
             temp1=forest->removefirst();
             temp2=forest->removefirst();
             temp3=new Huffman<E>(temp1,temp2);
             forest->insert(temp3);
             delete temp1;
             delete temp2;
         }
         return temp3;
    }


private slots:
    void on_pushButton_4_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;


};

#endif // MAINWINDOW_H
