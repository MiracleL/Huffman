#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>
#include <sstream>
#include <fstream>

using namespace std;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::on_pushButton_4_clicked()
{
    QString path = QFileDialog::getOpenFileName(this,tr("Open File"),
                                                   ".",tr("Text Files(*.txt)"));
    if(!path.isEmpty())
    {
        for(int i=0;i<127;i++)
            ascii[i]=0;
        QByteArray ba=path.toLatin1();
        char*p=ba.data();
        std::ifstream t;


        long length;
        t.open(p);      // open input file
        t.seekg(0, std::ios::end);    // go to the end
        length = t.tellg();           // report location (this is the length)
        t.seekg(0, std::ios::beg);    // go back to the beginning
        char* buffer = new char[length];    // allocate memory for a buffer of appropriate dimension
        t.read(buffer, length);       // read the whole file into the buffer
        t.close();                    // close file handle
        while(*buffer != '\0')
        {
            ascii[(int)(*buffer)]++;
            buffer++;
        }
        delete p;

    }
    else
    {
        QMessageBox::warning(this,tr("Warining"),tr("You don't select any file"));
    }
}

void MainWindow::on_pushButton_3_clicked()
{
    QString path = QFileDialog::getOpenFileName(this,tr("Open File"),
                                             ".",tr("Text Files(*.txt)"));
    if(!path.isEmpty())
    {

    }
    else
    {
        QMessageBox::warning(this,tr("Warining"),tr("You don't select any file"));
    }
}

void MainWindow::on_pushButton_clicked()
{
    if(ui->radioButton->isChecked()==true)
    {
       // if(ui->textEdit->toPlainText()!=NULL)
        {
            Huffman<char> **ax=NULL;
            QString bm="";
            char v;
            int j=0,level=0;
            int count=127;
            ax=new Huffman<char> *[count];
            for(int i=0;i<count;i++)
            {
                if(ascii[i]!=0)
                {
                   v=i;
                   ax[j]=new Huffman<char>(v,ascii[i]);
                   j++;
                }
            }
            tree=buildHuff(ax,j);
            trevisit(tree->Root(),bm,level);

        }



    }
    else if(ui->radioButton_2->isCheckable()==true)
    {

    }


}
