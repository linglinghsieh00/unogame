#ifndef GAMER_H
#define GAMER_H

#include <QPixmap>
#include <vector>
#include "card.h"
#include "config.h"



class Gamer
{
public:

    Gamer();

    //set function
    void setPlayerName(unsigned int n);
    void setIsComputer(bool c);
    void setScore(unsigned int s);
	void setHX(float x);
    void setHY(float y);
	void setLX(float x);
    void setLY(float y);




	

    //get function
    float getHX(); //get m_head_shot_x
    float getHY(); //get m_head_shot_y
    float getLX(); //get m_left_card_shot_x
    float getLY(); //get m_left_card_shot_y
    unsigned int getLeftCardNum();
    bool getIsComputer();
    unsigned int getScore();

    //member object
    QPixmap m_head_shot; //pixmap for head shot
QPixmap m_head_shot_2;
QPixmap m_head_shot_3;
QPixmap m_head_shot_4;
QPixmap m_head_shot_5;
    QPixmap m_left_card_shot; // pixmap for head shot
    std::vector<Card> m_cards; // cards on player's hand
std::vector<float>m_pos;

private:

    unsigned int m_left_card_num; // number of the player's left card
    unsigned int player_name; // belong to which player(player's name)
    float m_head_shot_x; // head shot's pixmap x
    float m_head_shot_y; // head shot's pixmap y
    float m_left_card_shot_x; // left card shot's pixmap x
    float m_left_card_shot_y; // left card shot's pixmap y
    bool m_computer;//是否為電腦
    unsigned int m_score;//玩家分數



};

#endif // GAMER_H
