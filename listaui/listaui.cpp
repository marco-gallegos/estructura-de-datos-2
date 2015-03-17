#include "listaui.h"
#include "ui_listaui.h"

#include<listasimple.h>
#include<QDebug>

listasimple lista;

listaui::listaui(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::listaui)
{
    ui->setupUi(this);

    ui->box_posicion->hide();
}

listaui::~listaui()
{
    delete ui;
}



void listaui::on_radiob_posic_clicked()
{
    if(ui->box_posicion->isEnabled())
    {
        ui->box_posicion->show();
    }
}

void listaui::on_radiob_inicio_clicked()
{
    ui->box_posicion->hide();

    ui->box_posicion->clear();
}

void listaui::on_btn_insert_clicked()
{

    if(ui->lineEdit->text().isEmpty())
    {
        qDebug()<<"no puede estar el campo dato vacio"<<endl;
        return;
    }

}
