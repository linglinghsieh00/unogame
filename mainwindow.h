#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMainWindow>
#include <QMouseEvent>
#include <QKeyEvent>
#include <QPainter>
#include <QTimer>
#include <QPushButton>
#include <QLabel>
#include <iostream>
#include "config.h"
#include "gamecontroller.h"

using namespace std;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:

    //constructor,destructor,I/O
    MainWindow(QWidget *parent = nullptr);
    void mouseMoveEvent(QMouseEvent *event);
    void mousePressEvent(QMouseEvent *event);
    void paintEvent(QPaintEvent *event);
    void timerEvent(QTimerEvent *event);


    //scene initialization
    void homeScene(); // initialize homepage scene
    void setScene(); // initialize set_mode scene
    void gameScene(); // initialize game_mode scene
    void chooseColorScene();
    void chooseKeepPlayScene();
    void chooseExchangeScene();
    void gameResultScene();
    void unoscene();


    //pushbutton connected funcction
    void h1ConnectedFunction(); // slot function for h1
    void s1ConnectedFunction(); // slot function for s1
    void s2ConnectedFunction(); // slot function for s2
    void s3ConnectedFunction(); // slot function for s3
    void s4ConnectedFunction(); // slot function for s4
    void s5ConnectedFunction(); // slot function for s5
    void s6ConnectedFunction(); // slot function for s6
    void c0ConnectedFunction();
    void c1ConnectedFunction();
    void c2ConnectedFunction();
    void c3ConnectedFunction();
    void k1ConnectedFunction();
    void k2ConnectedFunction();
    void e0ConnectedFunction();
    void e1ConnectedFunction();
    void e2ConnectedFunction();
    void e3ConnectedFunction();
    void e4ConnectedFunction();
    void r1ConnectedFunction();
    void sayunoConnectedFunction();


private:

    //mainwindow parameter
    int timerID; // timer period
    float m_mouseX; // mouse position's x
    float m_mouseY; // mouse position's y
    bool startflag; // whether game update
    unsigned int person; // participants number
    unsigned int stage; // 1:homepage 2:setstage 3:gamestage
    unsigned int mode; // 1:playerVSplayer 2:playerVScomputer


    //pushbutton
    QPushButton *h1; // homepage start setting
    QPushButton *s1; // choose 3p
    QPushButton *s2; // choose 4p
    QPushButton *s3; // choose 5p
    QPushButton *s4; // choose player v.s. player
    QPushButton *s5; // choose player v.s. computer
    QPushButton *s6; // start game
    QPushButton *c0; //選紅
    QPushButton *c1; //選黃
    QPushButton *c2; //選綠
    QPushButton *c3; //選藍
    QPushButton *k1; //繼續玩
    QPushButton *k2; //不繼續玩
    QPushButton *e0; //和玩家0換牌
    QPushButton *e1; //和玩家1換牌
    QPushButton *e2; //和玩家2換牌
    QPushButton *e3; //和玩家3換牌
    QPushButton *e4; //和玩家4換牌
    QPushButton *r1; //homepage
    QPushButton *sayuno;

    QPixmap score;



    //member object
    GameController gc; // gamecontroller for uno
};
#endif // MAINWINDOW_H
