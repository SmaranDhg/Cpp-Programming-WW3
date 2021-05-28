#pragma once
#include "State.h"
#include "StaticContent.h"
#include "Resources/Button.h"
#include "PlayerSelectionState.h"


using namespace sf;
using namespace std;
using namespace winfo;
using namespace dbg;
using namespace pinfo;


class MenuState :public State
{
private:
	//variables
	RectangleShape background;
	Font halo,invasion;
	
    Texture temp;

	//bools
	bool isFontsLoaded = false,isSdBgLoaded=false,isSdMSelectedLoaded=false;
	SoundBuffer bg_buffer, select_buffer;
	Sound bgScore,menuSelect;

	//now keybinds for this state and other initialization
    void initFonts();
	void initButtons();
	void initBackGround();
	void initSounds();

	//creating the buttons 
	map<string,Button*> btns;
	


	

public:
	MenuState(RenderWindow&, stack<State*>&);

	~MenuState();

	//all the abstract functions
	void update(const float& dt);
	void render(RenderTarget& target);
	void updateInputs(const float& dt);
	void endState();

	//buttons
	void updateButtons();
	void renderButtons(RenderTarget& wind);

};

