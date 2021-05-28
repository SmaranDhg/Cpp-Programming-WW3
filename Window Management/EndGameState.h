#pragma once
#include<Resources/Button.h>
#include "Entities/Players.h"
#include "MenuState.h"
#include "State.h"
class EndGameState : public State
{
protected:
	Text text1, text2, text3, text4, text5, text6;
	Font font;
	Player* p1;
	Player* p2;
	Texture  playerOneTexture, playerTwoTexture;
	Vector2f playerOnePos, playerTwoPos;
	

	Button* button1;
	Button* button2;
	Sound btnsound;
	SoundBuffer btnsndbuffer;
	int x = window.getSize().x / 2;
	int y = 150;
	Sprite bgSprite;
	Texture bgTexture;
	//initialization
	void initSound();
	void buttonupdate();
	void initTexture();
	void initText();

	//std::ostringstream store1 ;//for astoring variable

public:

	EndGameState(RenderWindow&,stack<State*>&);
	
	~EndGameState();


	 void endState();//for deleting the state /saving data and stuff before deletion
	 void update(const float& dt);
	 void render(RenderTarget& target);//render target is just the base class for renderwindwo and render texture
	 void updateInputs(const float& dt);//that ever child class has to define the 

};



