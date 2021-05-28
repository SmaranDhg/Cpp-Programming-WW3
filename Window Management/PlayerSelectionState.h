#pragma once
#include "State.h"
#include "Entities/Players.h"
#include "Resources/Button.h"
#include "MenuState.h"
#include"AreaSelection.h"

class PlayerSelectionState :
	public State
{
private:


	Button* button1;Button* button2;Button* button3;Button* button4;Button* button5;Button* button6;

	//playerid
	stack<PlayerId> playerIds;

	Text text1, text2,text3,text4,text5;
	Font font;
	RectangleShape line,line1,line2;//to divide axix and ally
	Event event;
	bool a;
	bool b = true;
	String playerString1,playerString2,s;
	Sprite bgSprite;

	Texture bgTexture;
	Texture playerTexture2, playerTexture1,playerTexture3,playerTexture4;

	SoundBuffer selectionSound;
	Sound playerSelectionSound;

	Player* player1;
	Player* player2;
	Player* player3;
	Player* player4;
	Vector2f playerOnePos, playerTwoPos,playerThreePos,playerPos;
	Vector2i select;
	//member functions
	void initSound();
	void initTexture();
	void initText();

	void updateSelected();
	void updateText();
	void buttonupdate();
	int x = window.getSize().x / 2;
	int y = 5;

	public:

		PlayerSelectionState(RenderWindow&, stack<State*>&);

		~PlayerSelectionState();


		void update(const float& dt);
		void render(RenderTarget& target);//render target is just the base class for renderwindwo and render texture
		void endState();
	   void updateInputs(const float& dt);//that ever child class has to define the 
		
		void checkForQuit();


};

