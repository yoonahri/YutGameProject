#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "gamemanager.h"
#include <QVector>
#include <QPushButton>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    void setGameManager(int, int);
    void getBoardLocationNum();
    void highlightMovablePos(int, int);
    void movePiece(int);

    ~MainWindow();

private slots:
    void on_throwButton_clicked();

private:
    Ui::MainWindow *ui;
    int player_num;
    int piece_num;
    GameManager gamemanager;
    QVector <QPushButton *> buttonList;
};

#endif // MAINWINDOW_H
