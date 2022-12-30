
#ifndef GAMECONTROLLER_H
#define GAMECONTROLLER_H

#include <QPixmap>
#include <vector>
#include "card.h"
#include "gamer.h"
#include "config.h"
#include "time.h"
#include "stdlib.h"
#include <QSound>
#include <iostream>

using namespace std;

class GameController
{
public:

    GameController();

    //initialization function
    void initialGame(unsigned int m,unsigned int p);
    void initialDeck(); // initial card deck and shuffle
    void initialPlayer(); // initial player status
    void initialDrawCard(); // initial player's card by drawCard
    void cleanCard();	


    //update function
    void update(); // call update function
    void updateCardPosition(); // update card position onhand
    void updateStage(); // update m_stage
    void updateResult(); // update the game result(who win)
    void updateBuff(); // update the m_buff
    void updateTurn(); // update the m_onturn
    void updateScore();
    void updateData();

    //card operating function
    void drawCard(); // draw card from deck
    void chooseCard(unsigned int c); // choose card to play
    void playCard(); // play card onto table
    void chooseKeepPlay(unsigned int k);
    void shuffle();
    void reloadDeck();

    //Buff
    void receiveBuff(); // exert buff on onturn player

    //computers
    void computerPlayer();

    //detector
    bool isPlayAvailable(); // decide whether on turn player can play
    bool isCardPlayAvailable(); //decide whether on turn player can play the choosed card
    bool isCardPlayAvailable2();
    unsigned int  isKeepPlaying();
    bool isUpdateOver();

    //set function
    void setIsDisplayCCS(bool d);
    void setIsDisplayCKPS(bool d);
    void setIsDisplayCES(bool d);
    void setIsDisplayGRS(bool d);
    void setChooseColor(unsigned int c);
    void setChooseExchange(unsigned int e);
    void setKeepPlay(unsigned int k);
    void setIsKeepPlay(bool k);
    void setissayuno(bool u);
    void setissaiduno(bool w);
    void setOver(bool o);

    //get function
    float getDeckX();
    float getDeckY();
    unsigned int getOnTurn();
    unsigned int getOnTableNum();
    unsigned int getStage();
    bool getIsDisplayCCS();
    bool getIsDisplayCKPS();
    bool getIsDisplayCES();
    bool getIsDisplayGRS();
    bool getissayuno();
    bool getIsResult();



    //member object
    QPixmap m_deck_pix;// pixmap for deck
    Gamer player_tmp; // player template to record modified player
    Card card_tmp; //card template to record modified card
    std::vector<Gamer> m_players; // 0~4
    std::vector<Card> m_ondeck; // cards in UNO deck
    std::vector<Card> m_ontable; //card's on table
    std::vector<bool>m_uno;



	

private:

    unsigned int m_onturn; // which player's turn
    unsigned int m_mode; // 1:playerVSplayer 2:playerVScomputer
    unsigned int m_person; // participants number
    unsigned int m_stage; // 1:preparation 2:choosing 3:execution
    unsigned int m_card_choose; // the card player choose to use
    unsigned int m_keep_play;
    float m_deck_x; // deck pixmap x position
    float m_deck_y; // deck pixmap y position
    unsigned int m_buff; // present buff
    bool m_play_available; //閰脩摰嗆?血隞亙??
    unsigned int m_order; //?拙振?箇??
    bool m_hold;
    bool m_isdisplayccs; //?臬憿舐內choosecolorscene
    bool m_isdisplayckps; //?臬憿舐內chooseKeepPlayScene
    bool m_isdisplayces; //?臬憿舐內chooseExchangeScene
    bool m_isdisplaygrs; //?臬憿舐內gameResultScene
    unsigned int m_choosecolor;
    unsigned int m_chooseexchange;
    unsigned int m_winner;
    unsigned int m_skip_counter;
    unsigned int m_reverse_counter;
    unsigned int m_drawcard_counter;
    unsigned int m_super0_counter = 0;
    unsigned int m_super7_counter;
    unsigned int m_hold_onturn;
    bool m_is_keep_play = false; //表示當前是否為連續出牌態
    bool unoflag;
    bool m_over;
    unsigned int m_choosecolor_counter;
    bool m_isresult;
   
};

#endif // GAMECONTROLLER_H
