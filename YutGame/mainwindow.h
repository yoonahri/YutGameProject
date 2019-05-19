#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "gamemanager.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    void setGameManager(int, int);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    int player_num;
    int piece_num;
    GameManager gamemanager;
};

#endif // MAINWINDOW_H
