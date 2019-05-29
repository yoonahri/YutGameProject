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

private slots:
    void on_throwButton_clicked();
    //전부 필요
    void on_Location0_clicked();
    void on_Location1_clicked();
    void on_Location2_clicked();

    void on_Location3_clicked();

    void on_Location4_clicked();

    void on_Location5_clicked();

    void on_Location6_clicked();

    void on_Location7_clicked();

    void on_Location8_clicked();

    void on_Location9_clicked();

    void on_Location10_clicked();

    void on_Location11_clicked();

    void on_Location12_clicked();

    void on_Location13_clicked();

    void on_Location14_clicked();

    void on_Location15_clicked();

    void on_Location16_clicked();

    void on_Location17_clicked();

    void on_Location18_clicked();

    void on_Location19_clicked();

    void on_Location20_clicked();

    void on_Location21_clicked();

    void on_Location22_clicked();

    void on_Location23_clicked();

    void on_Location24_clicked();

    void on_Location25_clicked();

    void on_Location26_clicked();

    void on_Location28_clicked();

    void on_Location29_clicked();

private:
    Ui::MainWindow *ui;
    int player_num;
    int piece_num;
    GameManager gamemanager;
};

#endif // MAINWINDOW_H
