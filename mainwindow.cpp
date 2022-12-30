#include "mainwindow.h"


//constructor,destructor,I/O
MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent)
{ 
    //mainwindow parameter
    setFixedSize(HOMESCENE_WIDTH,HOMESCENE_HEIGHT);
    setMouseTracking(true);

    //mainwindow member data
    stage = HOMEPAGE;
    mode = PVP;
    person = 3;
    startflag = false;
    score.load(SCORE);

    //pushbutton
    h1=new QPushButton;
    h1->setParent(this);
    h1->setText("start");
    h1->move(200,100);
    h1->setStyleSheet("QPushButton{font:20px;}");
    h1->resize(200,75);
    s1=new QPushButton;
    s1->setParent(this);
    s1->setText("3 player");
    s1->move(200,100);
    s1->setStyleSheet("QPushButton{font:20px;}");
    s1->resize(200,75);
    s2=new QPushButton;
    s2->setParent(this);
    s2->setText("4 player");
    s2->move(200,200);
    s2->setStyleSheet("QPushButton{font:20px;}");
    s2->resize(200,75);
    s3=new QPushButton;
    s3->setParent(this);
    s3->setText("5 player");
    s3->move(200,300);
    s3->setStyleSheet("QPushButton{font:20px;}");
    s3->resize(200,75);
    s4=new QPushButton;
    s4->setParent(this);
    s4->setText("player v.s. player");
    s4->move(200,400);
    s4->setStyleSheet("QPushButton{font:20px;}");
    s4->resize(200,75);
    s5=new QPushButton;
    s5->setParent(this);
    s5->setText("player v.s. computer");
    s5->move(200,500);
    s5->setStyleSheet("QPushButton{font:20px;}");
    s5->resize(200,75);
    s6=new QPushButton;
    s6->setParent(this);
    s6->setText("start playing");
    s6->move(900,500);
    s6->setStyleSheet("QPushButton{font:20px;}");
    s6->resize(200,75);
    c0=new QPushButton;
    c0->setParent(this);
    c0->setText("red");
    c0->move(0,50);
    c0->setStyleSheet("QPushButton{font:20px;}");
    c0->resize(500,50);
    c1=new QPushButton;
    c1->setParent(this);
    c1->setText("1");
    c1->move(0,100);
    c1->setStyleSheet("QPushButton{font:20px;}");
    c1->resize(500,50);
    c2=new QPushButton;
    c2->setParent(this);
    c2->setText("2");
    c2->move(0,150);
    c2->setStyleSheet("QPushButton{font:20px;}");
    c2->resize(500,50);
    c3=new QPushButton;
    c3->setParent(this);
    c3->setText("3");
    c3->move(0,200);
    c3->setStyleSheet("QPushButton{font:20px;}");
    c3->resize(500,50);
    k1=new QPushButton;
    k1->setParent(this);
    k1->setText("keep play");
    k1->move(0,250);
    k1->setStyleSheet("QPushButton{font:20px;}");
    k1->resize(500,50);
    k2=new QPushButton;
    k2->setParent(this);
    k2->setText("no");
    k2->move(0,300);
    k2->setStyleSheet("QPushButton{font:20px;}");
    k2->resize(500,50);
    e0=new QPushButton;
    e0->setParent(this);
    e0->setText("e0");
    e0->move(0,350);
    e0->setStyleSheet("QPushButton{font:20px;}");
    e0->resize(500,50);
    e1=new QPushButton;
    e1->setParent(this);
    e1->setText("e1");
    e1->move(0,400);
    e1->setStyleSheet("QPushButton{font:20px;}");
    e1->resize(500,50);
    e2=new QPushButton;
    e2->setParent(this);
    e2->setText("e2");
    e2->move(0,450);
    e2->setStyleSheet("QPushButton{font:20px;}");
    e2->resize(500,50);
    e3=new QPushButton;
    e3->setParent(this);
    e3->setText("e3");
    e3->move(0,500);
    e3->setStyleSheet("QPushButton{font:20px;}");
    e3->resize(500,50);
    e4=new QPushButton;
    e4->setParent(this);
    e4->setText("e4");
    e4->move(0,550);
    e4->setStyleSheet("QPushButton{font:20px;}");
    e4->resize(500,50);
    r1=new QPushButton;
    r1->setParent(this);
    r1->setText("r1");
    r1->move(0,600);
    r1->setStyleSheet("QPushButton{font:20px;}");
    r1->resize(500,50);
    sayuno=new QPushButton;
    sayuno->setText("UNO");
    sayuno->move(0,600);
    sayuno->setStyleSheet("QPushButton{font:100px;}");
    sayuno->resize(500,500);



    //-------------------------------------------------------
    connect(h1,&QPushButton::clicked,this,&MainWindow::h1ConnectedFunction);
    connect(s1,&QPushButton::clicked,this,&MainWindow::s1ConnectedFunction);
    connect(s2,&QPushButton::clicked,this,&MainWindow::s2ConnectedFunction);
    connect(s3,&QPushButton::clicked,this,&MainWindow::s3ConnectedFunction);
    connect(s4,&QPushButton::clicked,this,&MainWindow::s4ConnectedFunction);
    connect(s5,&QPushButton::clicked,this,&MainWindow::s5ConnectedFunction);
    connect(s6,&QPushButton::clicked,this,&MainWindow::s6ConnectedFunction);
    connect(c0,&QPushButton::clicked,this,&MainWindow::c0ConnectedFunction);
    connect(c1,&QPushButton::clicked,this,&MainWindow::c1ConnectedFunction);
    connect(c2,&QPushButton::clicked,this,&MainWindow::c2ConnectedFunction);
    connect(c3,&QPushButton::clicked,this,&MainWindow::c3ConnectedFunction);
    connect(e0,&QPushButton::clicked,this,&MainWindow::e0ConnectedFunction);
    connect(e1,&QPushButton::clicked,this,&MainWindow::e1ConnectedFunction);
    connect(e2,&QPushButton::clicked,this,&MainWindow::e2ConnectedFunction);
    connect(e3,&QPushButton::clicked,this,&MainWindow::e3ConnectedFunction);
    connect(e4,&QPushButton::clicked,this,&MainWindow::e4ConnectedFunction);
    connect(k1,&QPushButton::clicked,this,&MainWindow::k1ConnectedFunction);
    connect(k2,&QPushButton::clicked,this,&MainWindow::k2ConnectedFunction);
    connect(r1,&QPushButton::clicked,this,&MainWindow::r1ConnectedFunction);
    connect(sayuno,&QPushButton::clicked,this,&MainWindow::sayunoConnectedFunction);




    //function call
    homeScene();
}

void MainWindow::mouseMoveEvent(QMouseEvent *event)
{
    if(stage == GAMESTAGE && gc.getStage() == 2){
        m_mouseX = event -> x();
        m_mouseY = event -> y();

    }
}

void MainWindow::mousePressEvent(QMouseEvent *event)
{
    if(stage == GAMESTAGE && gc.getStage() == 2){
        if(event -> button() == Qt::LeftButton)
        {
            for(unsigned int i = 0;i < gc.m_players.at(gc.getOnTurn()).getLeftCardNum();i++)
            {
                if(m_mouseX > gc.m_players.at(gc.getOnTurn()).m_cards.at(i).getCardX()
                    && m_mouseX < gc.m_players.at(gc.getOnTurn()).m_cards.at(i).getCardX()+CARD_WIDTH
                    && m_mouseY > gc.m_players.at(gc.getOnTurn()).m_cards.at(i).getCardY()
                    && m_mouseY < gc.m_players.at(gc.getOnTurn()).m_cards.at(i).getCardY()+CARD_HEIGHT)
                {
                    gc.chooseCard(i);
                    continue;

                }
            }
            if(m_mouseX > gc.getDeckX() && m_mouseX < gc.getDeckX()+ DECK_WIDTH
                && m_mouseY > gc.getDeckY() && m_mouseY < gc.getDeckY()+ DECK_HEIGHT)
            {
                gc.chooseCard(CHOOSE_DRAW_CARD);
            }
        }
    }
}

void MainWindow::timerEvent(QTimerEvent *event)
{
    if(event ->timerId()== timerID && timerID != 0 && startflag == true){
        if(stage == SETSTAGE){

        }else if(stage == GAMESTAGE){
            gc.update();
	    if(gc.getIsDisplayCCS() == true){ //是否要顯示CCS
                chooseColorScene();
                gc.setIsDisplayCCS(false);
            }
            if(gc.getIsDisplayCKPS() == true){ //是否要顯示CKPS
                chooseKeepPlayScene();
                gc.setIsDisplayCKPS(false);
            }
            if(gc.getIsDisplayCES() == true){ //是否要顯示CES
                chooseExchangeScene();
                gc.setIsDisplayCES(false);
            }
            if(gc.getIsResult() == true){ //是否要顯示GRS
                gameResultScene();
		stage = RESULTSTAGE;
	    }
	    if(gc.getissayuno() == true){//uno
		    unoscene();
		    gc.setissayuno(false);
	    }
        }
	else if(stage == RESULTSTAGE){


	
	}
        update();
    }
}

void MainWindow::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    QPainter drawer(this);
    QPointF center((float)(HOMESCENE_WIDTH)/2,(float)(HOMESCENE_HEIGHT)/2);

    if(stage == SETSTAGE){
        QFont ft;
        ft.setPointSize(15);
        painter.setFont(ft);
        painter.setPen(Qt::red);
        painter.drawText(800,150,tr("mode"));
        painter.drawText(850,200,tr((mode == 1)?"PVP":"PVC"));
        painter.drawText(800,250,tr("person"));
        painter.drawText(850,300,QString::number(person));
    }else if(stage == GAMESTAGE){
	painter.drawText(350,100,QString::number(gc.getOnTurn()));

        painter.drawPixmap(gc.getDeckX(),gc.getDeckY(),DECK_WIDTH,DECK_HEIGHT,gc.m_deck_pix); //paint UNO deck
        for(unsigned int i = 0;i<person;i++) //paint players' head shot and left card
        {
            painter.drawPixmap(gc.m_players.at(i).getHX(),gc.m_players.at(i).getHY(),HEADSHOT_WIDTH,HEADSHOT_HEIGHT,gc.m_players.at(i).m_head_shot);
            painter.drawText(gc.m_players.at(i).getLX(),gc.m_players.at(i).getLY(),QString::number(gc.m_players.at(i).getLeftCardNum()));
        }
        for(unsigned int i = 0;i<gc.m_players.at(gc.getOnTurn()).getLeftCardNum();i++) //paint the on-turn player's card
        {
	    gc.m_players.at(gc.getOnTurn()).m_cards.at(i).setPixmap();
            painter.drawPixmap(gc.m_players.at(gc.getOnTurn()).m_cards.at(i).getCardX(),gc.m_players.at(gc.getOnTurn()).m_cards.at(i).getCardY(),CARD_WIDTH,CARD_HEIGHT,gc.m_players.at(gc.getOnTurn()).m_cards.at(i).m_card_shot);
        }
        drawer.translate(center);
        for(unsigned int i = 0;i<gc.getOnTableNum();i++) //paint cards on table
        {
            drawer.rotate(gc.m_ontable.at(i).getCardAngle());
            drawer.drawPixmap(gc.m_ontable.at(i).getCardX(),gc.m_ontable.at(i).getCardY(),CARD_WIDTH,CARD_HEIGHT,gc.m_ontable.at(i).m_card_shot);
        }
    }else if(stage == RESULTSTAGE){
	drawer.drawPixmap(300,0,100,50,score);
	    int k=100;
	    for(unsigned int i=0;i<person;i++)
	    {
		    
		    drawer.drawText(300,k,QString::number(i));
		    drawer.drawText(400,k,QString::number(gc.m_players.at(i).getScore()));
		    k=k+100;
	    }
    
    }
	

}



//scene initialization
void MainWindow::homeScene()
{
    startflag = false;
    h1->show();
    s1->hide();
    s2->hide();
    s3->hide();
    s4->hide();
    s5->hide();
    s6->hide();
    c0->hide();
    c1->hide();
    c2->hide();
    c3->hide();
    k1->hide();
    k2->hide();
    e0->hide();
    e1->hide();
    e2->hide();
    e3->hide();
    e4->hide();
    r1->hide();
    sayuno->hide();
}

void MainWindow::setScene()
{
    h1->hide();
    s1->show();
    s2->show();
    s3->show();
    s4->show();
    s5->show();
    s6->show();

}

void MainWindow::gameScene()
{
    
    h1->hide();
    s1->hide();
    s2->hide();
    s3->hide();
    s4->hide();
    s5->hide();
    s6->hide();
    c0->hide();
    c1->hide();
    c2->hide();
    c3->hide();
    k1->hide();
    k2->hide();
    e0->hide();
    e1->hide();
    e2->hide();
    e3->hide();
    e4->hide();
    r1->hide();
    sayuno->hide();
    startflag = true;
}

void MainWindow::chooseColorScene(){
    startflag = false;
    c0->show();
    c1->show();
    c2->show();
    c3->show();
    k1->hide();
    k2->hide();
    e0->hide();
    e1->hide();
    e2->hide();
    e3->hide();
    e4->hide();
    r1->hide();
    sayuno->hide();

    if(gc.m_players.at(gc.getOnTurn()).getIsComputer() == true){
    	int a = rand() % 4;
	if(a == 0){
		c0ConnectedFunction();
	}
	else if(a == 1){
                c1ConnectedFunction();
        }
	else if(a == 2){
                c2ConnectedFunction();
        }
	else if(a == 3){
                c3ConnectedFunction();
        }	
    }
}

void MainWindow::chooseKeepPlayScene()
{
    startflag = false;
    k1->show();
    k2->show();
    c0->hide();
    c1->hide();
    c2->hide();
    c3->hide();
    e0->hide();
    e1->hide();
    e2->hide();
    e3->hide();
    e4->hide();
    r1->hide();
    sayuno->hide();

    if(gc.m_players.at(gc.getOnTurn()).getIsComputer() == true){
    	k1ConnectedFunction();
    }
}



void MainWindow::chooseExchangeScene(){
    startflag = false;
    if(gc.getOnTurn()!=0){e0->show();}
    if(gc.getOnTurn()!=1){e1->show();}
    if(gc.getOnTurn()!=2){e2->show();}
    if(person >= 4 && gc.getOnTurn()!=4){e3->show();}
    if(person >= 5 && gc.getOnTurn()!=5){e4->show();}
    c0->hide();
    c1->hide();
    c2->hide();
    c3->hide();
    k1->hide();
    k2->hide();
    r1->hide();
    sayuno->hide();
	if(gc.m_players.at(gc.getOnTurn()).getIsComputer() == true){
        int a = rand() % person;
	if(a == gc.getOnTurn()){
		a = (a + 1) % person;
	}
        if(a == 0){
                e0ConnectedFunction();
        }
        if(a == 1){
                e1ConnectedFunction();
        }
        if(a == 2){
                e2ConnectedFunction();
        }
        if(a == 3){
                e3ConnectedFunction();
        }
        if(a == 4){
                e4ConnectedFunction();
        }
	}
}

void MainWindow::unoscene(){
	startflag=false;
	sayuno->show();
	c0->hide();
    c1->hide();
    c2->hide();
    c3->hide();
    k1->hide();
    k2->hide();
    e0->hide();
    e1->hide();
    e2->hide();
    e3->hide();
    e4->hide();
    r1->hide();
	
}

void MainWindow::gameResultScene(){
    r1->show();
    k1->hide();
    k2->hide();
    e0->hide();
    e1->hide();
    e2->hide();
    e3->hide();
    e4->hide();
}


//pushbutton-connected funcction
void MainWindow::h1ConnectedFunction()
{
    setScene();
    stage = SETSTAGE;
    startflag = true;
    timerID = startTimer(UPDATE_RATE);
}

void MainWindow::s1ConnectedFunction()
{
    person = 3;
}

void MainWindow::s2ConnectedFunction()
{
    person = 4;
}

void MainWindow::s3ConnectedFunction()
{
    person = 5;
}

void MainWindow::s4ConnectedFunction()
{
    mode = PVP;
}

void MainWindow::s5ConnectedFunction()
{
    mode = PVC;
}

void MainWindow::s6ConnectedFunction()
{
    gameScene();
    stage = GAMESTAGE;
    gc.initialGame(mode,person);
}

void MainWindow::c0ConnectedFunction(){
    gc.setChooseColor(0);
    gameScene();
    gc.setOver(true);
}

void MainWindow::c1ConnectedFunction(){
    gc.setChooseColor(1);
    gameScene();
    gc.setOver(true);
}

void MainWindow::c2ConnectedFunction(){
    gc.setChooseColor(2);
    gameScene();
    gc.setOver(true);
}

void MainWindow::c3ConnectedFunction(){
    gc.setChooseColor(3);
    gameScene();
    gc.setOver(true);
}

void MainWindow::e0ConnectedFunction(){
    gc.setChooseExchange(0);
    gameScene();
gc.setOver(true);
}

void MainWindow::e1ConnectedFunction(){
    gc.setChooseExchange(1);
    gameScene();
    gc.setOver(true);
}

void MainWindow::e2ConnectedFunction(){
    gc.setChooseExchange(2);
    gameScene();
    gc.setOver(true);
}

void MainWindow::e3ConnectedFunction(){
    gc.setChooseExchange(3);
    gameScene();
    gc.setOver(true);
}

void MainWindow::e4ConnectedFunction(){
    gc.setChooseExchange(4);
    gameScene();
    gc.setOver(true);
}

void MainWindow::k1ConnectedFunction()
{
    gc.setKeepPlay(1); //set  m_keep_play參數為繼續出牌
    gameScene();
}

void MainWindow::k2ConnectedFunction()
{
    gc.setKeepPlay(2);
    gameScene();
}

void MainWindow::r1ConnectedFunction()
{
    gameScene();
    stage = GAMESTAGE;
    gc.cleanCard();
    gc.initialDeck();
    gc.shuffle();
    gc.initialDrawCard();
}


void MainWindow::sayunoConnectedFunction()
{
	gc.setissayuno(0);
	gc.setissaiduno(true);
	gameScene();
}

