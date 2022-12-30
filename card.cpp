/*#include "card.h"

//constructor,destructor
Card::Card()
{
    //member data
    m_color = 1;
    m_number = 0;
    m_owner = 10;
    m_card_x = 570;
    m_card_y = 600;
    m_card_angle = 0;

    //member object
}



//set function
void Card::setColor(unsigned int c)
{
    m_color = c;
}

void Card::setNumber(unsigned int n)
{
    m_number = n;
}

void Card::setOwner(unsigned int o)
{
    m_owner = o;
}

void Card::setCardX(float x)
{
    m_card_x = x;
}

void Card::setCardY(float y)
{
    m_card_y = y;
}

void Card::setCardAngle(int a)
{
    m_card_angle =a;
}

void Card::setPixmap()
{
 	m_card_shot.load("./images/Red0"); 
}



//get function
float Card::getCardX()
{
    return m_card_x;
}

float Card::getCardY()
{
    return m_card_y;
}

unsigned int Card::getColor()
{
    return m_color;
}

unsigned int Card::getNumber()
{
    return m_number;
}

unsigned int Card::getOwner()
{
    return m_owner;
}

int Card::getCardAngle()
{
    return m_card_angle;
}*/

#include "card.h"

//constructor,destructor
Card::Card()
{
    //member data
    m_color = 0;
    m_number = 0;
    m_owner = 10;
    m_card_x = 570;
    m_card_y = 550;
    m_card_angle = 0;

    //member object
}



//set function
void Card::setColor(unsigned int c)
{
    m_color = c;
}

void Card::setNumber(unsigned int n)
{
    m_number = n;
}

void Card::setOwner(unsigned int o)
{
    m_owner = o;
}

void Card::setCardX(float x)
{
    m_card_x = x;
}

void Card::setCardY(float y)
{
    m_card_y = y;
}

void Card::setCardAngle(int a)
{
    m_card_angle =a;
}

void Card::setPixmap()
{
    if (m_color == 0 && m_number == 0)//RedCard=0
    {
        m_card_shot.load(RED0);
    }
    else if(m_color == 0 && m_number == 1)
    {
        m_card_shot.load(RED1);
    }
    else if (m_color == 0 && m_number == 2)
    {
        m_card_shot.load(RED2);
    }
    else if (m_color == 0 && m_number == 3)
    {
        m_card_shot.load(RED3);
    }
    else if (m_color == 0 && m_number == 4)
    {
        m_card_shot.load(RED4);
    }
    else if (m_color == 0 && m_number == 5)
    {
        m_card_shot.load(RED5);
    }
    else if (m_color == 0 && m_number == 6)
    {
        m_card_shot.load(RED6);
    }
    else if (m_color == 0 && m_number == 7)
    {
        m_card_shot.load(RED7);
    }
    else if (m_color == 0 && m_number == 8)
    {
        m_card_shot.load(RED8);
    }
    else if (m_color == 0 && m_number == 9)
    {
        m_card_shot.load(RED9);
    }
    else if (m_color == 0 && m_number == 10)
    {
        m_card_shot.load(REDSKIP);
    }
    else if (m_color == 0 && m_number == 11)
    {
        m_card_shot.load(REDREVERSE);
    }
    else if (m_color == 0 && m_number == 12)
    {
        m_card_shot.load(REDDRAWTWO);
    }
    else if (m_color == 1 && m_number == 0)//YellowCard=1
    {
        m_card_shot.load(YELLOW0);
    }
    else if (m_color == 1 && m_number == 1)
    {
        m_card_shot.load(YELLOW1);
    }
    else if (m_color == 1 && m_number == 2)
    {
        m_card_shot.load(YELLOW2);
    }
    else if (m_color == 1 && m_number == 3)
    {
        m_card_shot.load(YELLOW3);
    }
    else if (m_color == 1 && m_number == 4)
    {
        m_card_shot.load(YELLOW4);
    }
    else if (m_color == 1 && m_number == 5)
    {
        m_card_shot.load(YELLOW5);
    }
    else if (m_color == 1 && m_number == 6)
    {
        m_card_shot.load(YELLOW6);
    }
    else if (m_color == 1 && m_number == 7)
    {
        m_card_shot.load(YELLOW7);
    }
    else if (m_color == 1 && m_number == 8)
    {
        m_card_shot.load(YELLOW8);
    }
    else if (m_color == 1 && m_number == 9)
    {
        m_card_shot.load(YELLOW9);
    }
    else if (m_color == 1 && m_number == 10)
    {
        m_card_shot.load(YELLOWSKIP);
    }
    else if (m_color == 1 && m_number == 11)
    {
        m_card_shot.load(YELLOWREVERSE);
    }
    else if (m_color == 1 && m_number == 12)
    {
        m_card_shot.load(YELLOWDRAWTWO);
    }
    else if (m_color == 2 && m_number == 0)//GreenCard=2
    {
    m_card_shot.load(GREEN0);
    }
    else if (m_color == 2 && m_number == 1)
    {
    m_card_shot.load(GREEN1);
    }
    else if (m_color == 2 && m_number == 2)
    {
    m_card_shot.load(GREEN2);
    }
    else if (m_color == 2 && m_number == 3)
    {
    m_card_shot.load(GREEN3);
    }
    else if (m_color == 2 && m_number == 4)
    {
    m_card_shot.load(GREEN4);
    }
    else if (m_color == 2 && m_number == 5)
    {
    m_card_shot.load(GREEN5);
    }
    else if (m_color == 2 && m_number == 6)
    {
    m_card_shot.load(GREEN6);
    }
    else if (m_color == 2 && m_number == 7)
    {
    m_card_shot.load(GREEN7);
    }
    else if (m_color == 2 && m_number == 8)
    {
    m_card_shot.load(GREEN8);
    }
    else if (m_color == 2 && m_number == 9)
    {
    m_card_shot.load(GREEN9);
    }
    else if (m_color == 2 && m_number == 10)
    {
    m_card_shot.load(GREENSKIP);
    }
    else if (m_color == 2 && m_number == 11)
    {
    m_card_shot.load(GREENREVERSE);
    }
    else if (m_color == 2 && m_number == 12)
    {
    m_card_shot.load(GREENDRAWTWO);
    }
    else if (m_color == 3 && m_number == 0)//BlueCard=3
    {
    m_card_shot.load(BLUE0);
    }
    else if (m_color == 3 && m_number == 1)
    {
    m_card_shot.load(BLUE1);
    }
    else if (m_color == 3 && m_number == 2)
    {
    m_card_shot.load(BLUE2);
    }
    else if (m_color == 3 && m_number == 3)
    {
    m_card_shot.load(BLUE3);
    }
    else if (m_color == 3 && m_number == 4)
    {
    m_card_shot.load(BLUE4);
    }
    else if (m_color == 3 && m_number == 5)
    {
    m_card_shot.load(BLUE5);
    }
    else if (m_color == 3 && m_number == 6)
    {
    m_card_shot.load(BLUE6);
    }
    else if (m_color == 3 && m_number == 7)
    {
    m_card_shot.load(BLUE7);
    }
    else if (m_color == 3 && m_number == 8)
    {
    m_card_shot.load(BLUE8);
    }
    else if (m_color == 3 && m_number == 9)
    {
    m_card_shot.load(BLUE9);
    }
    else if (m_color == 3 && m_number == 10)
    {
    m_card_shot.load(BLUESKIP);
    }
    else if (m_color == 3 && m_number == 11)
    {
    m_card_shot.load(BLUEREVERSE);
    }
    else if (m_color == 3 && m_number == 12)
    {
    m_card_shot.load(BLUEDRAWTWO);
    }
    else if (m_color == 4 && m_number == 13)//BlackCard=4
    {
    m_card_shot.load(WILD);
    }
    else if (m_color == 4 && m_number == 14)
    {
    m_card_shot.load(DRAWFOUR);
    }
    
}



//get function
float Card::getCardX()
{
    return m_card_x;
}

float Card::getCardY()
{
    return m_card_y;
}

unsigned int Card::getColor()
{
    return m_color;
}

unsigned int Card::getNumber()
{
    return m_number;
}

unsigned int Card::getOwner()
{
    return m_owner;
}

int Card::getCardAngle()
{
    return m_card_angle;
}

