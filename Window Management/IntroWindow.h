#pragma once
#include "windows.h"


class Game
{
private:
	
	RenderWindow window;
	Event event;
	Clock dtclock;

	float dt;// delta time is the time between one render call or one update call
	stack<State*> states;///note state is the main function so you only make the refrence of the state
                           //you cant create the refrence  of the abstract state

	//textures 
	Texture temp1, temp2;


	//initializations
	 void initialize();
	 void initState();//now we like use this function to initialize the data
	 void initVariable();//its just for safetly of uninitlized warning and stuff
	
	 //some special vedio mode like full screen and stuff
	 vector<VideoMode>  videoModes;
	 ContextSettings windowSettings;//this is just the settings to maintaint the antialiasing and all other 3d shit in opengl for now cool and chill
	 bool fullscreen;//just to give the toggle for the full screen

public:
	 //updates
	void updateSFMLEvent();
	void update();
	void updatedt();

	//render
	void render();

	//run
	void run();


	//game component
	void endApplication();
	Game();
	~Game();

	
	
	
};