#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>
#include <sstream>
#include <fstream>
#include"huffman.h"
#include"heap.h"
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

            cout << *buffer;
            ascii[(int)(*buffer)]++;
            buffer++;
        }

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
        if(ui->textEdit->toPlainText()!=NULL)
        {
            Huffman<int> **ax;
            for(int i=0;i<127;i++)
            {
                if(ascii[i]!=0)
                {

                }
            }
            Huffman<int> *tree=buildHuff(ax,127);
        }
    }
    else
    {

    }
}
