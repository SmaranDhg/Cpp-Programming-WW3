#include "MenuState.h"


void MenuState::initFonts()
{
	//all the fonts
	isFontsLoaded= halo.loadFromFile(fontFolder + "Halo3.ttf") &&
	invasion.loadFromFile(fontFolder + "invasion.ttf");

	if (!isFontsLoaded) throw("Could not load the font and stuff");
}

void MenuState::initButtons()
{
	int x = window.getSize().x/2;
		int y=300, verticalPadding=75;
	
   btns[MM_NEW_GAME] = new Button(x, y, 75, halo, " New Game ");
   btns[MM_SOLO] = new Button( x, y+75*2.23*1 , 75,invasion, "    Solo    ");
   btns[MM_EXIT] = new Button(x, y + 75 * 2.23*2, 75, halo, "   Exit   ");
}

void MenuState::initBackGround()
{
	
	/*here the loading all the shit happesn special the backgroud*/
	temp.loadFromFile(spriteFolder + "war.jpg");
	background.setSize(Vector2f(static_cast<float>(window.getSize().x), static_cast<float>(window.getSize().y)));
	
	background.setTexture(&temp);
}

void MenuState::initSounds()
{

	
	isSdBgLoaded=bg_buffer.loadFromFile(SOUND_MENU_BG);
	isSdMSelectedLoaded = select_buffer.loadFromFile(SOUND_MENU_SELECTED);
	bgScore.setBuffer(bg_buffer);
	menuSelect.setBuffer(select_buffer);
	
	
}



MenuState::MenuState(RenderWindow& wind , stack<State*>& states)

	:State(wind,states)
{
	//all the initialization stuff for this state
	initFonts();
	initBackGround();
	initButtons();
	initSounds();
	//bgScore.play();
	//setting for reactangle shape



	
	
}

MenuState::~MenuState()
{
	print("deleting");
	delete btns[MM_NEW_GAME];
	delete btns[MM_SOLO];
	delete btns[MM_EXIT];

}



//functions


void MenuState::update(const float& dt)
{
	updateInputs(dt);
	updateMousePosition();
	updateButtons();
	


}
void MenuState::updateInputs(const float& dt)
{
	//that is for every update to the gamestate it will check for quit
	checkForQuit();//this function is defined in base class so becool





}
void MenuState::updateButtons()
{
	btns[MM_NEW_GAME]->update(mousePosView);
	btns[MM_SOLO]->update(mousePosView);
	btns[MM_EXIT]->update(mousePosView);
	bgScore.Playing;
     
	//here playing sound if the mouse is hovering the button and stuff
	btns[MM_NEW_GAME]->isHovered() || btns[MM_SOLO]->isHovered() || btns[MM_EXIT]->isHovered()
		? 
	  	   menuSelect.getStatus()==Sound::Playing?
		         getVoid()
		         :menuSelect.play(), 
		  (bgScore.getStatus()==Sound::Playing?
			bgScore.stop()
			:bgScore.play())
		:getVoid();
	
	if (btns[MM_SOLO]->isPressed())
	{
		
	}

	if (btns[MM_EXIT]->isPressed())
	{
		bgScore.stop();
		quit = true;
		
	}
	if (btns[MM_NEW_GAME]->isPressed())
	{

		print("new Game");
	    bgScore.stop();
        states.push(new PlayerSelectionState(window, states));
		
	}

}


void MenuState::render(RenderTarget& wind)
{
	wind.draw(background);
	renderButtons(wind);
	
	
	
}
void MenuState::renderButtons(RenderTarget& wind)
{
	btns[MM_NEW_GAME]->render(wind);
	btns[MM_SOLO]->render(wind);
	btns[MM_EXIT]->render(wind);
}






void MenuState::endState()
{
	print("Ending the game");

}

