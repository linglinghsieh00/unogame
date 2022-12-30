#include "gamecontroller.h"
#include<algorithm>

#include <QApplication>
#include <QLabel>

//constructor,destructor
GameController::GameController()
{
    m_deck_pix.load(UNO_DECK_PATH);
    m_ondeck.reserve(108);
    m_ontable.reserve(108);

    //member data
    m_onturn = 0;
    m_mode = 1;
    m_person = 3;
    m_stage = 1;
    m_card_choose = INITIAL_CHOOSE_CARD;
    m_keep_play = INITIAL_KEEP_PLAY;
    m_deck_x = 570;
    m_deck_y = 50;
    m_over = false;
    m_buff = INITIAL_BUFF;
    m_play_available = true;
    m_order = 1; //出牌順序預設為順時針
    m_hold = false;
    m_isdisplayccs = false;
    m_isdisplayckps = false;
    m_isdisplayces = false;
    m_isdisplaygrs = false;
    m_isresult = false;
    m_choosecolor = INITIAL_CHOOSE_COLOR;
    m_chooseexchange = INITIAL_CHOOSE_EXCHANGE;
    m_winner = INITIAL_WINNER; //等於87表示此時沒有贏家
    m_skip_counter = 0; //禁止牌疊加
    m_reverse_counter = 0; //迴轉牌疊加
    m_drawcard_counter = 0; //+2牌疊加
    m_super0_counter = 0;  //super0疊加
    m_super7_counter = 0; //super7疊加
    m_hold_onturn = INITIAL_HOLD_ONTURN;

    unoflag=false;
    m_uno={false};

    //function
    srand(time(NULL));
}



//initialization function
void GameController::initialGame(unsigned int m,unsigned int p)
{
    m_mode = m;
    m_person = p;
    initialDeck();
    shuffle();
    initialPlayer();
    initialDrawCard();
}

void GameController::initialDeck()
{
		
	for(unsigned int k = 0;k < 4;k++){ //1~12
        for(unsigned int i = 0;i < 2;i++){
            for(unsigned int j = 1;j <= 12;j++){
                card_tmp.setColor(k);
                card_tmp.setNumber(j);
                card_tmp.setOwner(10);
		card_tmp.setPixmap();
                m_ondeck.push_back(card_tmp);
            }
        }
    }
    for(unsigned int i = 0;i < 4;i++){ //0
        card_tmp.setColor(i);
        card_tmp.setNumber(0);
        card_tmp.setOwner(10);
	card_tmp.setPixmap();
        m_ondeck.push_back(card_tmp);
    }
    for(unsigned int i = 13;i <= 14;i++){ //黑卡
        for(unsigned int j =0;j < 4;j++){
            card_tmp.setColor(4);
            card_tmp.setNumber(i);
            card_tmp.setOwner(10);
	    card_tmp.setPixmap();
            m_ondeck.push_back(card_tmp);
        }
    }
    card_tmp.setColor(rand()%4);
    card_tmp.setNumber(rand()%10);
    card_tmp.setOwner(10);
    card_tmp.setPixmap();
    card_tmp.setCardX(0);
    card_tmp.setCardY(0);
    m_ontable.push_back(card_tmp);
}

void GameController::cleanCard(){
	for(unsigned int i =0;i< m_person;i++){
		m_players.at(i).m_cards.clear();
	}
	m_ondeck.clear();
	m_ontable.clear();
}

void GameController::initialPlayer()
{
    if(m_mode == 1){
        for(unsigned int i = 0;i < m_person;i++){
            player_tmp.setPlayerName(i);
            m_players.push_back(player_tmp);
        }
    }
    if(m_mode == 2){
        for(unsigned int i = 0;i < m_person;i++){
            if(i == 0){
                player_tmp.setPlayerName(i);
                player_tmp.setIsComputer(false);
                m_players.push_back(player_tmp);
            }
            else{
                player_tmp.setPlayerName(i);
                player_tmp.setIsComputer(true);
                m_players.push_back(player_tmp);
            }
        }
    }
    if(m_person==3){
	    m_players.at(0).m_head_shot.load(HEAD_SHOT_1);
	    m_players.at(1).m_head_shot.load(HEAD_SHOT_2);
	    m_players.at(2).m_head_shot.load(HEAD_SHOT_3);
    		if(m_onturn==2){
			m_players.at(0).setHX(1000);
		    	m_players.at(0).setHY(0);
		    	m_players.at(0).setLX(1000);
		    	m_players.at(0).setLY(120);
			//中間
		    	m_players.at(2).setHX(800);
		    	m_players.at(2).setHY(345);
		    	m_players.at(2).setLX(800);
		    	m_players.at(2).setLY(445);
	    		//左
			m_players.at(1).setHX(0);
		    	m_players.at(1).setHY(0);
		    	m_players.at(1).setLX(0);
		   	m_players.at(1).setLY(120);
		}
		else if(m_onturn==1){
			m_players.at(2).setHX(1000);
		    		m_players.at(2).setHY(0);
		    		m_players.at(2).setLX(1000);
		    		m_players.at(2).setLY(120);
				m_players.at(1).setHX(800);
		    		m_players.at(1).setHY(345);
		    		m_players.at(1).setLX(800);
		    		m_players.at(1).setLY(445);
				m_players.at(0).setHX(0);
		    		m_players.at(0).setHY(0);
		    		m_players.at(0).setLX(0);
		    		m_players.at(0).setLY(120);
		}
		else if(m_onturn==0){
			m_players.at(1).setHX(1000);
		    		m_players.at(1).setHY(0);
		    		m_players.at(1).setLX(1000);
		    		m_players.at(1).setLY(120);
				m_players.at(0).setHX(800);
		    		m_players.at(0).setHY(345);
		    		m_players.at(0).setLX(800);
		    		m_players.at(0).setLY(445);
				m_players.at(2).setHX(0);
		    		m_players.at(2).setHY(0);
		    		m_players.at(2).setLX(0);
		    		m_players.at(2).setLY(120);
		}
    }
	else if(m_person==4){
	    	m_players.at(0).m_head_shot.load(HEAD_SHOT_1);
	    	m_players.at(1).m_head_shot.load(HEAD_SHOT_2);
	    	m_players.at(2).m_head_shot.load(HEAD_SHOT_3);
		m_players.at(3).m_head_shot.load(HEAD_SHOT_4);
		if(m_onturn==3){
			//右邊
			m_players.at(0).setHX(1000);
		    	m_players.at(0).setHY(0);
		    	m_players.at(0).setLX(1000);
		    	m_players.at(0).setLY(120);
			//中間
		    	m_players.at(3).setHX(800);
		    	m_players.at(3).setHY(345);
		    	m_players.at(3).setLX(800);
		    	m_players.at(3).setLY(445);
	    		//上面
			m_players.at(1).setHX(800);
		    	m_players.at(1).setHY(0);
		    	m_players.at(1).setLX(800);
		   	m_players.at(1).setLY(120);
			//左邊
			m_players.at(2).setHX(0);
		    	m_players.at(2).setHY(0);
		    	m_players.at(2).setLX(0);
		    	m_players.at(2).setLY(120);
		}
		if(m_onturn==0){
			m_players.at(1).setHX(1000);
		    	m_players.at(1).setHY(0);
		    	m_players.at(1).setLX(1000);
		    	m_players.at(1).setLY(120);
			
		    	m_players.at(0).setHX(800);
		    	m_players.at(0).setHY(345);
		    	m_players.at(0).setLX(800);
		    	m_players.at(0).setLY(445);
	    		
			m_players.at(2).setHX(800);
		    	m_players.at(2).setHY(0);
		    	m_players.at(2).setLX(800);
		   	m_players.at(2).setLY(120);
			
			m_players.at(3).setHX(0);
		    	m_players.at(3).setHY(0);
		    	m_players.at(3).setLX(0);
		    	m_players.at(3).setLY(120);

		}
		if(m_onturn==1){
			
			m_players.at(2).setHX(1000);
		    	m_players.at(2).setHY(0);
		    	m_players.at(2).setLX(1000);
		    	m_players.at(2).setLY(120);
			
		    	m_players.at(1).setHX(800);
		    	m_players.at(1).setHY(345);
		    	m_players.at(1).setLX(800);
		    	m_players.at(1).setLY(445);
	    		
			m_players.at(3).setHX(800);
		    	m_players.at(3).setHY(0);
		    	m_players.at(3).setLX(800);
		   	m_players.at(3).setLY(120);
			
			m_players.at(0).setHX(0);
		    	m_players.at(0).setHY(0);
		    	m_players.at(0).setLX(0);
		    	m_players.at(0).setLY(120);

		}
		if(m_onturn==2){
			
			m_players.at(3).setHX(1000);
		    	m_players.at(3).setHY(0);
		    	m_players.at(3).setLX(1000);
		    	m_players.at(3).setLY(120);
			
		    	m_players.at(2).setHX(800);
		    	m_players.at(2).setHY(345);
		    	m_players.at(2).setLX(800);
		    	m_players.at(2).setLY(445);
	    		
			m_players.at(0).setHX(800);
		    	m_players.at(0).setHY(0);
		    	m_players.at(0).setLX(800);
		   	m_players.at(0).setLY(120);

			m_players.at(1).setHX(0);
		    	m_players.at(1).setHY(0);
		    	m_players.at(1).setLX(0);
		    	m_players.at(1).setLY(120);
		}	
	}
	else if(m_person==5){
	    	m_players.at(0).m_head_shot.load(HEAD_SHOT_1);
	    	m_players.at(1).m_head_shot.load(HEAD_SHOT_2);
	    	m_players.at(2).m_head_shot.load(HEAD_SHOT_3);
		m_players.at(3).m_head_shot.load(HEAD_SHOT_4);
		m_players.at(4).m_head_shot.load(HEAD_SHOT_5);
		if(m_onturn==4){
			m_players.at(0).setHX(1000);
		    	m_players.at(0).setHY(0);
		    	m_players.at(0).setLX(1000);
		    	m_players.at(0).setLY(120);
			m_players.at(4).setHX(800);
		    	m_players.at(4).setHY(345);
		    	m_players.at(4).setLX(800);
		    	m_players.at(4).setLY(445);
			m_players.at(1).setHX(800);
		    	m_players.at(1).setHY(0);
		    	m_players.at(1).setLX(800);
		   	m_players.at(1).setLY(120);
			m_players.at(2).setHX(200);
		    	m_players.at(2).setHY(0);
		    	m_players.at(2).setLX(200);
		    	m_players.at(2).setLY(120);
			m_players.at(3).setHX(0);
		    	m_players.at(3).setHY(200);
		    	m_players.at(3).setLX(0);
		    	m_players.at(3).setLY(300);
		}if(m_onturn==0){
			m_players.at(1).setHX(1000);
		    	m_players.at(1).setHY(0);
		    	m_players.at(1).setLX(1000);
		    	m_players.at(1).setLY(120);
			m_players.at(0).setHX(800);
		    	m_players.at(0).setHY(345);
		    	m_players.at(0).setLX(800);
		    	m_players.at(0).setLY(445);
			m_players.at(2).setHX(800);
		    	m_players.at(2).setHY(0);
		    	m_players.at(2).setLX(800);
		   	m_players.at(2).setLY(120);
			m_players.at(3).setHX(200);
		    	m_players.at(3).setHY(0);
		    	m_players.at(3).setLX(200);
		    	m_players.at(3).setLY(120);
			m_players.at(4).setHX(0);
		    	m_players.at(4).setHY(200);
		    	m_players.at(4).setLX(0);
		    	m_players.at(4).setLY(300);
		}if(m_onturn==1){
			m_players.at(2).setHX(1000);
		    	m_players.at(2).setHY(0);
		    	m_players.at(2).setLX(1000);
		    	m_players.at(2).setLY(120);
			m_players.at(1).setHX(800);
		    	m_players.at(1).setHY(345);
		    	m_players.at(1).setLX(800);
		    	m_players.at(1).setLY(445);
			m_players.at(3).setHX(800);
		    	m_players.at(3).setHY(0);
		    	m_players.at(3).setLX(800);
		   	m_players.at(3).setLY(120);
			m_players.at(4).setHX(200);
		    	m_players.at(4).setHY(0);
		    	m_players.at(4).setLX(200);
		    	m_players.at(4).setLY(120);
			m_players.at(0).setHX(0);
		    	m_players.at(0).setHY(200);
		    	m_players.at(0).setLX(0);
		    	m_players.at(0).setLY(300);
		}if(m_onturn==2){
			m_players.at(3).setHX(1000);
		    	m_players.at(3).setHY(0);
		    	m_players.at(3).setLX(1000);
		    	m_players.at(3).setLY(120);
			m_players.at(2).setHX(800);
		    	m_players.at(2).setHY(345);
		    	m_players.at(2).setLX(800);
		    	m_players.at(2).setLY(445);
			m_players.at(4).setHX(800);
		    	m_players.at(4).setHY(0);
		    	m_players.at(4).setLX(800);
		   	m_players.at(4).setLY(120);
			m_players.at(0).setHX(200);
		    	m_players.at(0).setHY(0);
		    	m_players.at(0).setLX(200);
		    	m_players.at(0).setLY(120);
			m_players.at(1).setHX(0);
		    	m_players.at(1).setHY(200);
		    	m_players.at(1).setLX(0);
		    	m_players.at(1).setLY(300);
		}if(m_onturn==3){
			m_players.at(4).setHX(1000);
		    	m_players.at(4).setHY(0);
		    	m_players.at(4).setLX(1000);
		    	m_players.at(4).setLY(120);
			m_players.at(3).setHX(800);
		    	m_players.at(3).setHY(345);
		    	m_players.at(3).setLX(800);
		    	m_players.at(3).setLY(445);
			m_players.at(0).setHX(800);
		    	m_players.at(0).setHY(0);
		    	m_players.at(0).setLX(800);
		   	m_players.at(0).setLY(120);
			m_players.at(1).setHX(200);
		    	m_players.at(1).setHY(0);
		    	m_players.at(1).setLX(200);
		    	m_players.at(1).setLY(120);
			m_players.at(2).setHX(0);
		    	m_players.at(2).setHY(200);
		    	m_players.at(2).setLX(0);
		    	m_players.at(2).setLY(300);
		}

	}

}

void GameController::initialDrawCard()
{
    for(unsigned int i =0;i < m_person;i++)
    {
        for(unsigned int j = 0;j < INITIAL_DRAW_CARD_NUM;j++)
        {
            m_onturn =i;
            drawCard();
        }
    }
    m_isresult = false;
    m_stage = 1;
}

		


//update function
void GameController::update()
{
    updateCardPosition();
    updateStage();
    updateData();
    if(m_ondeck.size() < 5){
	    reloadDeck();
    }
}

void GameController::updateCardPosition()
{
    for(unsigned int i =0;i < m_person;i++)
    {
        float gap = (float)HOMESCENE_WIDTH/(float)(m_players.at(i).getLeftCardNum()+1);
        float offset = gap;
        for(unsigned int j = 0;j < m_players.at(i).getLeftCardNum();j++)
        {
            m_players.at(i).m_cards.at(j).setCardX(offset-(float)CARD_WIDTH/2);
	    m_players.at(i).m_cards.at(j).setCardY(570);
            offset+=gap;
        }
    }

}

void GameController::updateStage()
{
    if(m_stage == 1){ //preparation
	    cout << "stage1" << endl;
        receiveBuff();
	
        if(isPlayAvailable() == true)
        {
            m_stage = 2;
        }
        else{
            m_stage = 4;
        }
    }

    else if(m_stage == 2){ //decision
	 cout << "stage2 " << endl;
        if(m_players.at(m_onturn).getIsComputer() == true){
            computerPlayer();
        }
        if(isCardPlayAvailable() == true)
        {
		m_stage = 3;
        }
        else{
            m_stage = 2;
        }
    }

    else if(m_stage == 3){ //keep_playing
	    cout << "stage 3" << endl;
	    unsigned int k = isKeepPlaying();
	if(k == 0){
        	m_stage = 3;
	}
        else if(k == 1){
		m_stage = 2;
	}
	else if(k == 2){
		m_stage = 4;
	}


    }
    else if(m_stage == 4){ //execution
	cout << "stage4" << endl;
        updateBuff();
        //updateTurn();
	//updateData();
	m_is_keep_play = false;
	//if(isUpdateOver() == true){  //選色前的m_stage會維持4，選色後的一瞬間會被timer呼叫(此時m_stage仍然是4)，因此會略過一個人(updateTurn)，暫時刪去。
		m_stage = 5;
	//}
    }
    else if(m_stage == 5){
	    if(m_over == true){
		    m_over = false;
		    updateTurn();
		    updateData();
		    m_stage = 1;
            }
    }
}

void GameController::updateBuff()
{
    if(m_ontable.at(m_ontable.size()-1).getNumber() == 10 && m_skip_counter != 0){ //禁止
        m_buff = 2;
	m_over = true;
    }
    else if(m_ontable.at(m_ontable.size()-1).getNumber() == 11){ //迴轉
        m_buff = 3;
	m_over = true;
    }
    else if(m_ontable.at(m_ontable.size()-1).getNumber() == 12 && m_drawcard_counter != 0){ //+2 (當上一位玩家帶著仍有效力的+2牌時才生效)
        m_buff = 4;
	m_over = true;
    }
    else if(m_ontable.at(m_ontable.size()-1).getNumber() == 13 && m_choosecolor_counter != 0){ //轉色 (有效轉色牌才生效)
        m_buff = 5;
        m_isdisplayccs = true;  //顯示選色對話框
	
    }
    else if(m_ontable.at(m_ontable.size()-1).getNumber() == 14 && m_drawcard_counter != 0){ //+4轉色 (當上一位玩家帶著仍有效力的+4牌才生效)
        m_buff = 6;
        m_isdisplayccs = true;  //顯示選色對話框
    }
    else if(m_ontable.at(m_ontable.size()-1).getNumber() == 0 && m_super0_counter != 0){ //super0
        m_buff = 7;
	m_isdisplayces = true;
    }
    else if(m_ontable.at(m_ontable.size()-1).getNumber() == 7){ //super7
        m_buff = 8;
	m_over = true;
    }
    else{ //1,2,3,4,5,6,8,9
        m_buff = 1;
	m_over = true;
    }
    m_play_available = true;
}

void GameController::updateTurn()
{
    if(m_buff == 3 && m_reverse_counter % 2 == 1){  //疊加次數為奇數時等於迴轉一次
        if(m_order == 1){
            m_order = 2;
	}
	else if(m_order == 2){
	    m_order = 1;
	}
    }
    if(m_buff == 3){  //吃到buff後要將疊加與buff歸零
        m_buff = 0;
	m_reverse_counter = 0;
    }
    if(m_order == 1){  //順時針
        m_onturn++;
        if(m_onturn > m_person - 1){
            m_onturn = 0;
        }
    }
    else if(m_order == 2){  //逆時針
        if(m_onturn == 0){
	    m_onturn = m_person - 1;
	}
	else{
	    m_onturn--;
	}
    }
}

void GameController::updateResult()
{
    if(m_isresult == false){
	for(unsigned int i = 0;i < m_person;i++){  //該輪勝者才可加分
        if(m_players.at(i).getLeftCardNum() != 0){
                continue;
        }
        else if(m_players.at(i).getLeftCardNum() == 0){ //呼叫計算分數的函式
                m_isresult = true;
		cout << "result" << endl;
		updateScore();
            for(unsigned int j = 0;j < m_person;j++){
                if(m_players.at(j).getScore() >= 500){
                    m_winner = j;
                }
            }
        }
    }}
    

}

void GameController::updateScore(){  //計算分數
    for(unsigned int i = 0;i < m_person;i++){
        for(unsigned int j = 0;j < m_players.at(i).getLeftCardNum();j++){
            if(m_players.at(i).m_cards.at(j).getNumber() >= 1 && m_players.at(i).m_cards.at(j).getNumber() <= 9){ //1~9則+1~9分
                m_players.at(i).setScore(m_players.at(i).m_cards.at(j).getNumber());
            }
            else if(m_players.at(i).m_cards.at(j).getNumber() == 10){ //禁止牌+20分
                m_players.at(i).setScore(20);
            }
            else if(m_players.at(i).m_cards.at(j).getNumber() == 11){ //迴轉牌+20分
                m_players.at(i).setScore(20);
            }
            else if(m_players.at(i).m_cards.at(j).getNumber() == 12){ //+2牌+20分
                m_players.at(i).setScore(20);
            }
            else if(m_players.at(i).m_cards.at(j).getNumber() == 13){ //轉色牌+30分
                m_players.at(i).setScore(30);
            }
            else if(m_players.at(i).m_cards.at(j).getNumber() == 14){ //+4轉色+50分
                m_players.at(i).setScore(50);
            }
        }
    }
}

void GameController::updateData()
{
	
	if(m_players.at(m_onturn).getLeftCardNum()==1&&m_uno[m_onturn]==false)
	{
		setissayuno(1);
	
	}
	else if(m_players.at(m_onturn).getLeftCardNum()>1&&m_uno[m_onturn]==true){
		setissaiduno(false);
	}
	
	if(m_person==3){
		if(m_onturn==2){
			//右
			m_players.at(0).setHX(1000);
		    	m_players.at(0).setHY(0);
		    	m_players.at(0).setLX(1000);
		    	m_players.at(0).setLY(120);
			//中間
		    	m_players.at(2).setHX(800);
		    	m_players.at(2).setHY(345);
		    	m_players.at(2).setLX(800);
		    	m_players.at(2).setLY(445);
	    		//左
			m_players.at(1).setHX(0);
		    	m_players.at(1).setHY(0);
		    	m_players.at(1).setLX(0);
		   	m_players.at(1).setLY(120);
		}
		else if(m_onturn==1){
			m_players.at(2).setHX(1000);
		    	m_players.at(2).setHY(0);
		    	m_players.at(2).setLX(1000);
		    	m_players.at(2).setLY(120);
			m_players.at(1).setHX(800);
		    	m_players.at(1).setHY(345);
		    	m_players.at(1).setLX(800);
		    	m_players.at(1).setLY(445);
			m_players.at(0).setHX(0);
		   	m_players.at(0).setHY(0);
		    	m_players.at(0).setLX(0);
		    	m_players.at(0).setLY(120);
		}
		else if(m_onturn==0){
			m_players.at(1).setHX(1000);
		    	m_players.at(1).setHY(0);
		    	m_players.at(1).setLX(1000);
		    	m_players.at(1).setLY(120);
			m_players.at(0).setHX(800);
		    	m_players.at(0).setHY(345);
		    	m_players.at(0).setLX(800);
		    	m_players.at(0).setLY(445);
			m_players.at(2).setHX(0);
		    	m_players.at(2).setHY(0);
		    	m_players.at(2).setLX(0);
		    	m_players.at(2).setLY(120);
		}
	}
	else if(m_person==4){
		if(m_onturn==3){
			
			m_players.at(0).setHX(1000);
		    	m_players.at(0).setHY(0);
		    	m_players.at(0).setLX(1000);
		    	m_players.at(0).setLY(120);
			
		    	m_players.at(3).setHX(800);
		    	m_players.at(3).setHY(345);
		    	m_players.at(3).setLX(800);
		    	m_players.at(3).setLY(445);
	    		
			m_players.at(1).setHX(800);
		    	m_players.at(1).setHY(0);
		    	m_players.at(1).setLX(800);
		   	m_players.at(1).setLY(120);
			
			m_players.at(2).setHX(0);
		    	m_players.at(2).setHY(0);
		    	m_players.at(2).setLX(0);
		    	m_players.at(2).setLY(120);
		}
		if(m_onturn==0){
			m_players.at(1).setHX(1000);
		    	m_players.at(1).setHY(0);
		    	m_players.at(1).setLX(1000);
		    	m_players.at(1).setLY(120);

		    	m_players.at(0).setHX(800);
		    	m_players.at(0).setHY(345);
		    	m_players.at(0).setLX(800);
		    	m_players.at(0).setLY(445);

			m_players.at(2).setHX(800);
		    	m_players.at(2).setHY(0);
		    	m_players.at(2).setLX(800);
		   	m_players.at(2).setLY(120);

			m_players.at(3).setHX(0);
		    	m_players.at(3).setHY(0);
		    	m_players.at(3).setLX(0);
		    	m_players.at(3).setLY(120);

		}
		if(m_onturn==1){

			m_players.at(2).setHX(1000);
		    	m_players.at(2).setHY(0);
		    	m_players.at(2).setLX(1000);
		    	m_players.at(2).setLY(120);

		    	m_players.at(1).setHX(800);
		    	m_players.at(1).setHY(345);
		    	m_players.at(1).setLX(800);
		    	m_players.at(1).setLY(445);

			m_players.at(3).setHX(800);
		    	m_players.at(3).setHY(0);
		    	m_players.at(3).setLX(800);
		   	m_players.at(3).setLY(120);

			m_players.at(0).setHX(0);
		    	m_players.at(0).setHY(0);
		    	m_players.at(0).setLX(0);
		    	m_players.at(0).setLY(120);

		}
		if(m_onturn==2){

			m_players.at(3).setHX(1000);
		    	m_players.at(3).setHY(0);
		    	m_players.at(3).setLX(1000);
		    	m_players.at(3).setLY(120);

		    	m_players.at(2).setHX(800);
		    	m_players.at(2).setHY(345);
		    	m_players.at(2).setLX(800);
		    	m_players.at(2).setLY(445);

			m_players.at(0).setHX(800);
		    	m_players.at(0).setHY(0);
		    	m_players.at(0).setLX(800);
		   	m_players.at(0).setLY(120);

			m_players.at(1).setHX(0);
		    	m_players.at(1).setHY(0);
		    	m_players.at(1).setLX(0);
		    	m_players.at(1).setLY(120);
		}
	}
	else if(m_person==5){
		if(m_onturn==4){
			m_players.at(0).setHX(1000);
		    	m_players.at(0).setHY(0);
		    	m_players.at(0).setLX(1000);
		    	m_players.at(0).setLY(120);
			m_players.at(4).setHX(800);
		    	m_players.at(4).setHY(345);
		    	m_players.at(4).setLX(800);
		    	m_players.at(4).setLY(445);
			m_players.at(1).setHX(800);
		    	m_players.at(1).setHY(0);
		    	m_players.at(1).setLX(800);
		   	m_players.at(1).setLY(120);
			m_players.at(2).setHX(200);
		    	m_players.at(2).setHY(0);
		    	m_players.at(2).setLX(200);
		    	m_players.at(2).setLY(120);
			m_players.at(3).setHX(0);
		    	m_players.at(3).setHY(200);
		    	m_players.at(3).setLX(0);
		    	m_players.at(3).setLY(300);
		}if(m_onturn==0){
			m_players.at(1).setHX(1000);
		    	m_players.at(1).setHY(0);
		    	m_players.at(1).setLX(1000);
		    	m_players.at(1).setLY(120);
			m_players.at(0).setHX(800);
		    	m_players.at(0).setHY(345);
		    	m_players.at(0).setLX(800);
		    	m_players.at(0).setLY(445);
			m_players.at(2).setHX(800);
		    	m_players.at(2).setHY(0);
		    	m_players.at(2).setLX(800);
		   	m_players.at(2).setLY(120);
			m_players.at(3).setHX(200);
		    	m_players.at(3).setHY(0);
		    	m_players.at(3).setLX(200);
		    	m_players.at(3).setLY(120);
			m_players.at(4).setHX(0);
		    	m_players.at(4).setHY(200);
		    	m_players.at(4).setLX(0);
		    	m_players.at(4).setLY(300);
		}if(m_onturn==1){
			m_players.at(2).setHX(1000);
		    	m_players.at(2).setHY(0);
		    	m_players.at(2).setLX(1000);
		    	m_players.at(2).setLY(120);
			m_players.at(1).setHX(800);
		    	m_players.at(1).setHY(345);
		    	m_players.at(1).setLX(800);
		    	m_players.at(1).setLY(445);
			m_players.at(3).setHX(800);
		    	m_players.at(3).setHY(0);
		    	m_players.at(3).setLX(800);
		   	m_players.at(3).setLY(120);
			m_players.at(4).setHX(200);
		    	m_players.at(4).setHY(0);
		    	m_players.at(4).setLX(200);
		    	m_players.at(4).setLY(120);
			m_players.at(0).setHX(0);
		    	m_players.at(0).setHY(200);
		    	m_players.at(0).setLX(0);
		    	m_players.at(0).setLY(300);
		}if(m_onturn==2){
			m_players.at(3).setHX(1000);
		    	m_players.at(3).setHY(0);
		    	m_players.at(3).setLX(1000);
		    	m_players.at(3).setLY(120);
			m_players.at(2).setHX(800);
		    	m_players.at(2).setHY(345);
		    	m_players.at(2).setLX(800);
		    	m_players.at(2).setLY(445);
			m_players.at(4).setHX(800);
		    	m_players.at(4).setHY(0);
		    	m_players.at(4).setLX(800);
		   	m_players.at(4).setLY(120);
			m_players.at(0).setHX(200);
		    	m_players.at(0).setHY(0);
		    	m_players.at(0).setLX(200);
		    	m_players.at(0).setLY(120);
			m_players.at(1).setHX(0);
		    	m_players.at(1).setHY(200);
		    	m_players.at(1).setLX(0);
		    	m_players.at(1).setLY(300);
		}if(m_onturn==3){
			m_players.at(4).setHX(1000);
		    	m_players.at(4).setHY(0);
		    	m_players.at(4).setLX(1000);
		    	m_players.at(4).setLY(120);
			m_players.at(3).setHX(800);
		    	m_players.at(3).setHY(345);
		    	m_players.at(3).setLX(800);
		    	m_players.at(3).setLY(445);
			m_players.at(0).setHX(800);
		    	m_players.at(0).setHY(0);
		    	m_players.at(0).setLX(800);
		   	m_players.at(0).setLY(120);
			m_players.at(1).setHX(200);
		    	m_players.at(1).setHY(0);
		    	m_players.at(1).setLX(200);
		    	m_players.at(1).setLY(120);
			m_players.at(2).setHX(0);
		    	m_players.at(2).setHY(200);
		    	m_players.at(2).setLX(0);
		    	m_players.at(2).setLY(300);
		}

	}
		
}




//card operating function
void GameController::drawCard()
{
    card_tmp.setColor(m_ondeck.at(m_ondeck.size()-1).getColor());
    card_tmp.setNumber(m_ondeck.at(m_ondeck.size()-1).getNumber());
    card_tmp.setOwner(m_onturn);
    card_tmp.setPixmap();
    m_ondeck.pop_back();
    m_players.at(m_onturn).m_cards.push_back(card_tmp);
    //m_card_choose = INITIAL_CHOOSE_CARD;  //避免手動抽卡後開始瘋狂抽卡，每次抽卡後就初始化選卡變數
    if (m_ondeck.size() == 0) {
	    Card topCard = m_ontable.back();
	    m_ontable.pop_back();             // shuffle and use discard pile as deck to draw from
	    int numCards = m_ontable.size();
	    for (int i = 0; i < numCards ; ++i) {
		    int index = rand() % m_ontable.size();
		    m_ondeck.push_back(m_ontable.at(index));
		    m_ontable.erase(m_ontable.begin() + index);
	    }
		// discard pile should now be empty, except the top card we kept
			m_ontable.push_back(topCard);
     }
}

void GameController::playCard()
{
    card_tmp.setColor(m_players.at(m_onturn).m_cards.at(m_card_choose).getColor());
    card_tmp.setNumber(m_players.at(m_onturn).m_cards.at(m_card_choose).getNumber());
    if(m_players.at(m_onturn).m_cards.at(m_card_choose).getNumber() == 10){  //聲音系統與疊加系統
        QSound::play("./sounds/skip.wav");
        m_skip_counter++;
    }
    else if(m_players.at(m_onturn).m_cards.at(m_card_choose).getNumber() == 11){
        QSound::play("./sounds/reverse.wav");
        m_reverse_counter++;
    }
    else if(m_players.at(m_onturn).m_cards.at(m_card_choose).getNumber() == 12){
        QSound::play("./sounds/draw_two.wav");
        m_drawcard_counter++;
    }
    else if(m_players.at(m_onturn).m_cards.at(m_card_choose).getNumber() == 13){
        QSound::play("./sounds/wild.wav");
	m_choosecolor_counter++;
    }
    else if(m_players.at(m_onturn).m_cards.at(m_card_choose).getNumber() == 14){
        QSound::play("./sounds/wild_four.wav");
        m_drawcard_counter++;
    }
    else if(m_players.at(m_onturn).m_cards.at(m_card_choose).getNumber() == 0){
        QSound::play("./sounds/super0.wav");
        m_super0_counter++;
        m_hold_onturn = m_onturn;  //出牌時直接記下出牌者，方便換牌
    }
    else if(m_players.at(m_onturn).m_cards.at(m_card_choose).getNumber() == 7){
        QSound::play("./sounds/super7.wav");
        m_super7_counter++;
    }
    else{
        QSound::play("./sounds/normal.wav");
    }
    card_tmp.setOwner(10);
    card_tmp.setCardX((m_players.at(m_onturn).m_cards.at(m_card_choose).getCardX()-570)/7);
    card_tmp.setCardY(0);
    card_tmp.setCardAngle(rand()%360+110);
    card_tmp.setPixmap();
    m_players.at(m_onturn).m_cards.erase(m_players.at(m_onturn).m_cards.begin()+m_card_choose);
    m_ontable.push_back(card_tmp);
    m_is_keep_play = true; //出完牌後會預設為連續出牌態，進入stage4後改為false
    updateResult();
}

void GameController::chooseCard(unsigned int c)
{
    m_card_choose =c;
}
void GameController::chooseKeepPlay(unsigned int k)
{
    m_keep_play = k;
}

void GameController::reloadDeck(){
                for(int i = m_ontable.size()-2;i>=0;i--){
                        card_tmp = m_ontable.at(i);
                        m_ontable.erase(m_ontable.begin()+i);
                        m_ondeck.push_back(card_tmp);
                }
                shuffle();

}

//computers
void GameController::computerPlayer(){ //電腦出牌
    for(unsigned int i = 0;i < m_players.at(m_onturn).getLeftCardNum();i++){
        chooseCard(i);
        if(isCardPlayAvailable2() == true){
            break;
        }
        if(i == m_players.at(m_onturn).getLeftCardNum() - 1){
            m_card_choose = CHOOSE_DRAW_CARD;
        }
    }
}


//Buff
void GameController::receiveBuff()
{
    if(m_buff == 2){  //禁止
        m_skip_counter--; //觸發一次就把疊加次數減少一次
        m_play_available = false;
    }
    else if(m_buff == 4){  //+2
        for(unsigned int i = 0;i < 2*m_drawcard_counter;i++){  //該玩家抽卡的次數為2乘以疊加次數
            drawCard();
        }
	m_play_available = false;
        m_drawcard_counter = 0;  //抽完卡後要將疊加次數歸零
    }
    else if(m_buff == 5){  //轉色
        if(m_choosecolor == 0){  //把桌上的黑卡變成指定的顏色
            m_ontable.at(m_ontable.size()-1).setColor(0);
        }
        else if(m_choosecolor == 1){
            m_ontable.at(m_ontable.size()-1).setColor(1);
        }
        else if(m_choosecolor == 2){
            m_ontable.at(m_ontable.size()-1).setColor(2);
        }
        else if(m_choosecolor == 3){
            m_ontable.at(m_ontable.size()-1).setColor(3);
        }
        m_play_available = true;
	m_choosecolor_counter = 0;  //效果結束後歸零(這比較特別一點)
    }
    else if(m_buff == 6){  //+4轉色
        for(unsigned int i = 0;i < 4*m_drawcard_counter;i++){  //該玩家的抽卡次數為4乘以疊加次數
            drawCard();
        }
        if(m_choosecolor == 0){  //把桌上的黑卡變成指定的顏色
            m_ontable.at(m_ontable.size()-1).setColor(0);
        }
        else if(m_choosecolor == 1){
            m_ontable.at(m_ontable.size()-1).setColor(1);
        }
        else if(m_choosecolor == 2){
            m_ontable.at(m_ontable.size()-1).setColor(2);
        }
        else if(m_choosecolor == 3){
            m_ontable.at(m_ontable.size()-1).setColor(3);
        }
        m_play_available = false;
        m_drawcard_counter = 0;  //效果結束後把疊加歸零
    }
    else if(m_buff == 7){  //super0，將雙方手牌對調
        std::vector<Card> hold;
	hold = m_players.at(m_hold_onturn).m_cards;
        m_players.at(m_hold_onturn).m_cards = m_players.at(m_chooseexchange).m_cards;
        m_players.at(m_chooseexchange).m_cards = hold;
        m_play_available = true;
	m_super0_counter--;
    }
    else if(m_buff == 8){  //super7，所有玩家將手牌給下一位玩家
        for(unsigned int i = 0;i < m_super7_counter;i++){  //換牌次數為疊加次數
            if(m_person == 3){
                std::vector<Card> hold0,hold1,hold2;
		hold0 = m_players.at(0).m_cards;  //暫存
                hold1 = m_players.at(1).m_cards;
                hold2 = m_players.at(2).m_cards;

                m_players.at(0).m_cards = hold2;  //開始與下一位交換
                m_players.at(1).m_cards = hold0;
                m_players.at(2).m_cards = hold1;
            }
            if(m_person == 4){
                std::vector<Card> hold0,hold1,hold2,hold3;
		hold0 = m_players.at(0).m_cards;  //暫存
                hold1 = m_players.at(1).m_cards;
                hold2 = m_players.at(2).m_cards;
                hold3 = m_players.at(3).m_cards;

                m_players.at(0).m_cards = hold3;  //開始與下一位交換
                m_players.at(1).m_cards = hold0;
                m_players.at(2).m_cards = hold1;
                m_players.at(3).m_cards = hold2;
            }
            if(m_person == 5){
                std::vector<Card> hold0,hold1,hold2,hold3,hold4;
		hold0 = m_players.at(0).m_cards;  //暫存
                hold1 = m_players.at(1).m_cards;
                hold2 = m_players.at(2).m_cards;
                hold3 = m_players.at(3).m_cards;
                hold4 = m_players.at(4).m_cards;

                m_players.at(0).m_cards = hold4;  //開始與下一位交換
                m_players.at(1).m_cards = hold0;
                m_players.at(2).m_cards = hold1;
                m_players.at(3).m_cards = hold2;
                m_players.at(4).m_cards = hold3;
            }
        }
        m_play_available = true;
        m_super7_counter = 0;  //效果結束時疊加歸零
    }
    else if(m_buff == 1){  //一般牌的疊加沒有特殊效果
        m_play_available = true;
    }
        m_buff = 0;  //清除所記錄的buff項目
}



//detector
bool GameController::isPlayAvailable()
{
    return m_play_available;
}

bool GameController::isCardPlayAvailable()
{
  
    	if(m_card_choose == INITIAL_CHOOSE_CARD){
		return false;
	}


    else if(m_card_choose == CHOOSE_DRAW_CARD){
        if(m_stage == 2){
            drawCard();
        }
        
        return true;
    }


	if(m_players.at(m_onturn).m_cards.at(m_card_choose).getColor() == 4 && m_ontable.at(m_ontable.size()-1).getColor() != 4 && m_is_keep_play == false){ //黑牌在除了場上是黑牌且不是連續出牌態以外都可以出
        if(m_stage == 2){
            playCard();
        }
        m_card_choose = INITIAL_CHOOSE_CARD;
        return true;
        }
    else if(m_players.at(m_onturn).m_cards.at(m_card_choose).getColor() == 4 && m_ontable.at(m_ontable.size()-1).getColor() == 4 && m_players.at(m_onturn).m_cards.at(m_card_choose).getNumber() == m_ontable.at(m_ontable.size()-1).getNumber()){ //黑牌對黑牌且同樣功能的牌才可以出
	    if(m_stage == 2){
                playCard();
            }
            m_card_choose = INITIAL_CHOOSE_CARD;
            return true;
        }
    else if(m_players.at(m_onturn).m_cards.at(m_card_choose).getColor() == m_ontable.at(m_ontable.size()-1).getColor() && m_players.at(m_onturn).m_cards.at(m_card_choose).getColor() != 4 && m_ontable.at(m_ontable.size()-1).getColor() != 4 && m_is_keep_play == false){  //同色卡且不是黑卡且在非連續出牌態時可出
        if(m_stage == 2){
            playCard();
        }
        m_card_choose = INITIAL_CHOOSE_CARD;
        return true;
    }
    else if(m_players.at(m_onturn).m_cards.at(m_card_choose).getNumber() == m_ontable.at(m_ontable.size()-1).getNumber()){  //同數值卡可出
        if(m_stage == 2){
            playCard();
        }
        m_card_choose = INITIAL_CHOOSE_CARD;
        return true;
    }
    else {
        if(m_stage == 2){
            if(m_players.at(m_onturn).getIsComputer() == false){  //僅玩家會觸發錯誤聲音
                QSound::play("./sounds/illegal_move.wav");
            }
        }
        m_card_choose = INITIAL_CHOOSE_CARD;
	
        return false;
    }
}

unsigned int GameController::isKeepPlaying(){  //檢查該玩家是否還有牌可以出並詢問是否繼續出牌
	if(m_card_choose == CHOOSE_DRAW_CARD){
		m_card_choose = INITIAL_CHOOSE_CARD;
		return 2;
	}
	else{
                if(m_keep_play == 1 && m_hold == true){  //有可用的牌並選擇繼續出牌
                        m_keep_play = 0;
			m_hold = false;
			return 1;
                }
                else if(m_keep_play == 2 && m_hold == true){  //有可用的牌但選擇不繼續出牌
                        m_keep_play = 0;
			m_hold =false;
			return 2;
                }
		else if(m_players.at(m_onturn).getIsComputer() == false && m_hold == false && m_keep_play == INITIAL_KEEP_PLAY){
        		for(unsigned int i = 0;i < m_players.at(m_onturn).getLeftCardNum();i++){  //檢查該玩家手牌
        		    m_card_choose = i;  //迴圈選牌
        		    m_hold = isCardPlayAvailable();
        		    if(m_hold == true){  //只要找到一張可用的牌就詢問是否繼續出牌
				m_isdisplayckps = true;
				return 0;  //找到一張可用的牌就停止繼續找
			    }
        		}
			if(m_hold == false){ //沒有可用的牌就回傳false
				return 2;
			}
        	}
	}
	


}


//set function
void GameController::setIsDisplayCCS(bool d){
    m_isdisplayccs = d;
}

void GameController::setIsDisplayCKPS(bool d){
    m_isdisplayckps = d;
}

void GameController::setIsDisplayCES(bool d){
    m_isdisplayces = d;
}

void GameController::setIsDisplayGRS(bool d){
    m_isdisplaygrs = d;
}

void GameController::setChooseColor(unsigned int c){
    m_choosecolor = c;
}

void GameController::setChooseExchange(unsigned int e){
    m_chooseexchange = e;
}

void GameController::setKeepPlay(unsigned int k){
	m_keep_play = k;
}

void GameController::setIsKeepPlay(bool k){
	m_is_keep_play = k;
}
void GameController::setissayuno(bool u){
	unoflag=u;
}
void GameController::setissaiduno(bool w){
	m_uno[m_onturn]=w;
}
void GameController::setOver(bool o){
	m_over = o;
}
//get function
float GameController::getDeckX()
{
    return m_deck_x;
}

float GameController::getDeckY()
{
    return m_deck_y;
}

unsigned int GameController::getOnTurn()
{
    return m_onturn;
}

unsigned int GameController::getOnTableNum()
{
    return (unsigned int)m_ontable.size();
}

unsigned int GameController::getStage()
{
    return m_stage;
}
bool GameController::getIsDisplayCCS(){
    return m_isdisplayccs;
}

bool GameController::getIsDisplayCKPS(){
    return m_isdisplayckps;
}

bool GameController::getIsDisplayCES(){
    return m_isdisplayces;
}

bool GameController::getIsDisplayGRS(){
    return m_isdisplaygrs;
}
bool GameController::getissayuno(){
	return unoflag;
}
bool GameController::getIsResult(){
	return m_isresult;
}
 






void GameController::shuffle()
{
	//vector<Card> shuffled;// warning: if there are less than 108 cards, this does not work.  initDeck function will reset the deck.

	for (int i = 0; i < 1000; i++) {
			int index = rand() % m_ondeck.size();  // Get a random card from the deck (program component: random number generator)
                        card_tmp = m_ondeck.at(index);
			//shuffled.push_back(m_ondeck.at(index));
			m_ondeck.erase(m_ondeck.begin() + index); // remove the card from the deck once it's been chosen by erasing card from deck
			m_ondeck.push_back(card_tmp);
		}
		//m_ondeck = shuffled;   // set cards vector equal to shuffled deck vector
}



/*void GameController::sayuno(){
	if(m_players.at(m_onturn).m_cards.size()==2){
		{
			unoflag=true;
		}
	}
}*/

bool GameController::isCardPlayAvailable2()
{
        if(m_card_choose == INITIAL_CHOOSE_CARD){
                return false;
        }
        if(m_players.at(m_onturn).m_cards.at(m_card_choose).getColor() == 4 && m_ontable.at(m_ontable.size()-1).getColor() != 4 && m_is_keep_play == false){ //黑牌在除了場上是黑牌且不是連續出牌態以外都可以出
        return true;
        }
    else if(m_players.at(m_onturn).m_cards.at(m_card_choose).getColor() == 4 && m_ontable.at(m_ontable.size()-1).getColor() == 4 && m_players.at(m_onturn).m_cards.at(m_card_choose).getNumber() == m_ontable.at(m_ontable.size()-1).getNumber()){ //黑牌對黑牌且同樣功能的牌才可以出
            return true;
        }
    else if(m_players.at(m_onturn).m_cards.at(m_card_choose).getColor() == m_ontable.at(m_ontable.size()-1).getColor() && m_players.at(m_onturn).m_cards.at(m_card_choose).getColor() != 4 && m_ontable.at(m_ontable.size()-1).getColor() != 4 && m_is_keep_play == false){  //同色卡且不是黑卡且在非連續出牌態時可出
        return true;
    }
    else if(m_players.at(m_onturn).m_cards.at(m_card_choose).getNumber() == m_ontable.at(m_ontable.size()-1).getNumber()){  //同數值卡可出
        return true;
    }
    else {
        return false;
    }
}

	











