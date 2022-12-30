#include "gamer.h"

//constructor,destructor
Gamer::Gamer()
{
    //member data
    m_left_card_num = 2;
    player_name = 0;
    m_head_shot_x = 0;
    m_head_shot_y = 0;
    m_left_card_shot_x = 60;
    m_left_card_shot_y = 60;
    m_computer = false;
    m_score =0;


    //member object
    m_head_shot.load(HEAD_SHOT_1);
    m_left_card_shot.load(NUMBER_TEST);
    m_cards.reserve(30);
}



//set function
void Gamer::setPlayerName(unsigned int n)
{
    player_name = n;
}

void Gamer::setIsComputer(bool c){
    m_computer = c;
}

void Gamer::setScore(unsigned int s){
    m_score = m_score + s;
}
void Gamer::setHX(float x){
	m_head_shot_x= x;
}

void Gamer::setHY(float y){
	m_head_shot_y = y;
}
void Gamer::setLX(float x){
	m_left_card_shot_x = x;
}
void Gamer::setLY(float y){
	m_left_card_shot_y = y;
}









//get function
float Gamer::getHX()
{
    return m_head_shot_x;
}

float Gamer::getHY()
{
    return m_head_shot_y;
}

float Gamer::getLX()
{
    return m_left_card_shot_x;
}

float Gamer::getLY()
{
    return m_left_card_shot_y;
}

unsigned int Gamer::getLeftCardNum()
{
    return (unsigned int)m_cards.size();
}

bool Gamer::getIsComputer(){
    return m_computer;
}

unsigned int Gamer::getScore(){
    return m_score;
}





