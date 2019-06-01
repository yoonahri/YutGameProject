#ifndef EXITSCREEN_H
#define EXITSCREEN_H

#include <QDialog>

namespace Ui {
class Exitscreen;
}

class Exitscreen : public QDialog
{
    Q_OBJECT

public:
    explicit Exitscreen(QWidget *parent = nullptr);
    explicit Exitscreen(QWidget *parent = nullptr, int = NULL);
    ~Exitscreen();

private slots:
    void on_ExitButton_clicked();

    void on_restartButton_clicked();

private:
    Ui::Exitscreen *ui;
};

#endif // EXITSCREEN_H
