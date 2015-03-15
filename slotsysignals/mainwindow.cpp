#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
//#include<QFile>
#include<fstream>
#include<iostream>

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

void MainWindow::on_pushButton_clicked()
{

    qDebug()<<ui->lineEdit->text()<<endl
              <<ui->lineEdit_2->text()<<endl
              <<ui->lineEdit_3->text()<<endl;
    ui->boxx->setPlainText(
                ui->lineEdit->text() + "\n"+
                ui->lineEdit_2->text() + "\n"+
                ui->lineEdit_3->text() + "\n");

fstream archivo("librosqt.txt",ios::out|ios::app);
if(archivo.is_open())
{
    archivo<<ui->lineEdit->text().toStdString() << "|" <<
             ui->lineEdit_2->text().toStdString() << "|"<<
             ui->lineEdit_3->text().toStdString() << "|";
}

archivo.close();
}

void MainWindow::on_guardar2_clicked()
{
    QFile file("guardar2.txt");
    file.open(QIODevice::WriteOnly|QIODevice::Text);
    QTextStream out(&file);

    out<<ui->lineEdit->text()<<"|"<<
         ui->lineEdit_2->text()<<"|"<<
         ui->lineEdit_3->text()<<"|";
}
