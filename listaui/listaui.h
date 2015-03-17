#ifndef LISTAUI_H
#define LISTAUI_H

#include <QMainWindow>

namespace Ui {
class listaui;
}

class listaui : public QMainWindow
{
    Q_OBJECT

public:
    explicit listaui(QWidget *parent = 0);
    ~listaui();



private slots:
    void on_radiob_posic_clicked();

    void on_radiob_inicio_clicked();

    void on_btn_insert_clicked();

private:
    Ui::listaui *ui;


};

#endif // LISTAUI_H
