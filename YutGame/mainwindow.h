#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "gamemanager.h"
#include <QVector>
#include <QPushButton>
#include <QLabel>
#include <QMessageBox>
#include <QTextCodec>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    void setGameManager(int, int);
    void createScoreBoard();
    void createPiece();
    void getBoardLocationNum();
    void highlightMovablePos(int, int, bool);
    void movePiece(int, int);
    void showTurn();
    void showScore();
    void gameOver();
    ~MainWindow();

private slots:
    void on_throwButton_clicked();

    void on_testButton_clicked();

    void on_Location0_clicked();

private:
    Ui::MainWindow *ui;
    int player_num;
    int piece_num;
    GameManager gamemanager;
    QVector <QPushButton *> buttonList;
    int init_board;
};

#endif // MAINWINDOW_H
