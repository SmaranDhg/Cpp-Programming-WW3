#pragma once
#include "State.h"
#include "Entities/Players.h"
#include"Entities/PlayObjects/Fire.h"


class GameState :public State
{
private:
	
	



	Player* player;
	RectangleShape backgroud;
	Texture bg_texture,playerOneTexture,playerTwoRefrence;
	Sprite sprit;

	//gameInfos
	stack<PlayerId> playerIds;
	BattleGround btl_grnd;
	Fire* fire1;
	Vector2f pos;
	//intitializer function
	void initPlayers();
	void initbackground();
	void initTextures();
	



public:
	GameState(RenderWindow& ,stack<State*>&,stack<PlayerId>& playerIds,BattleGround battle_grnd );
	GameState(RenderWindow&, stack<State*>&);
	~GameState();
	//all the abstract functions
	void update(const float& dt);
	void render( RenderTarget& target);
    void updateInputs(const float& dt);
	void endState();

};

