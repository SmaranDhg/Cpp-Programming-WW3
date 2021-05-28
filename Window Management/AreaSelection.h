#pragma once
#include"state.h"
#include"Resources/Button.h"
#include"GameState.h"
#include"PlayerSelectionState.h"
using namespace winfo;
class AreaSelection :
	public State
{
protected:
	Text text1,text2,text3,text4;
	Font font;
	Texture bgTexture,placeTexture1,placeTexture2,placeTexture3;
	Sprite bgsprite,placeSprite1,placeSprite2,placeSprite3;
	Button* button1;
	Button* button2;
	Sound buttonSound;
	SoundBuffer buffer;
	
	int width = 550, height = 350;
	int xpadding = 200, ypadding = 100;
	//gameinfos
	stack<PlayerId>& playerIds;
	BattleGround battle_grd;

	RectangleShape rect1, rect2, rect3;
	int x = window.getSize().x / 2;
	int y = 150;

	void initText();
	void initTexture();
	void initRect();
	void isPressCheck();
	void buttonUpdate();
	void initSound();
	void reset();
	void playSound();
public:
	AreaSelection(RenderWindow&, stack<State*>&,stack<PlayerId>&);
	//AreaSelection(RenderWindow&,);
	~AreaSelection();
	
	void checkForQuit();
	void endState();
	void update(const float& dt);
	void render(RenderTarget& traget);
	void updateInputs(const float& dt);
	
	
};

