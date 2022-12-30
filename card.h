#ifndef CARD_H
#define CARD_H

#include <QPixmap>
#include "config.h"

class Card
{
public:
    Card();

    //set function
    void setColor(unsigned int c);
    void setNumber(unsigned int n);
    void setOwner(unsigned int o);
    void setCardX(float x);
    void setCardY(float y);
    void setCardAngle(int a);
    void setPixmap();

    //getfunction
    float getCardX();
    float getCardY();
    int getCardAngle();
    unsigned int getColor();
    unsigned int getNumber();
    unsigned int getOwner();

    //member object
    QPixmap m_card_shot; // pixmap for card shot

private:
    //member data
    unsigned int m_color; // 紅(0)黃(1)綠(2)藍(3)黑(4)
    unsigned int m_number; // 品叡數字用數值表示。禁止(10)，迴轉(11)，+2(12)，轉色(13)，+4轉色(14)
    unsigned int m_owner; // player:0~4 gamcontroller:10
    float m_card_x; // card's pixmap y
    float m_card_y; // card's pixmap y
    int m_card_angle; //card's display angle
};

#endif // CARD_H
