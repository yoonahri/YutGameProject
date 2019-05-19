#ifndef FIRSTSCREEN_H
#define FIRSTSCREEN_H

#include <QDialog>
#include "gamemanager.h"
#include "mainwindow.h"

namespace Ui {
class FirstScreen;
}

class FirstScreen : public QDialog
{
    Q_OBJECT

public:
    explicit FirstScreen(QWidget *parent = nullptr);
    ~FirstScreen();

private slots:
    void on_pushButton_start_clicked();

private:
    Ui::FirstScreen *ui;
    int player_num;
    int piece_num;
    GameManager main_game_manager;

};

#endif // FIRSTSCREEN_H
