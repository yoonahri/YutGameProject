#include "exitscreen.h"
#include "ui_exitscreen.h"
#include <firstscreen.h>
#include "qprocess.h"

Exitscreen::Exitscreen(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Exitscreen)
{
    ui->setupUi(this);
}

Exitscreen::Exitscreen(QWidget *parent, int winner) :
    QDialog(parent),
    ui(new Ui::Exitscreen)
{
    ui->setupUi(this);
    this->ui->winnerLabel->setNum(winner+1);
    this->ui->fire_image->setStyleSheet("border-image: url(:firecracker.png);");
}

Exitscreen::~Exitscreen()
{
    delete ui;
}

void Exitscreen::on_ExitButton_clicked()
{
    qApp->quit();
}

void Exitscreen::on_restartButton_clicked()
{
    qApp->quit();
    QProcess::startDetached(qApp->arguments()[0], qApp->arguments());
}
