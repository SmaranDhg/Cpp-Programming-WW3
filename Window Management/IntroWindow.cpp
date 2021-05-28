#include "IntroWindow.h"

//all initialization and loading stuff
void Game::initialize()
{
	//now all the essential component can be configur from the .ini file
	//or know as configuration file 
	ifstream wConfig("Config/window.ini");
	string ttl = "WW3";
	unsigned frameRate = 60;
	if (wConfig.is_open())
	{
		//reading the configuration
		wConfig >> ttl;
		wConfig >> frameRate;


	}
	wConfig.close();



	window.create(VideoMode(windowSize.x / 2, windowSize.y / 2), introTtl);

	
	//now cheing if full screen
    fullscreen?
    window.create(VideoMode(windowSize.x , windowSize.y ), introTtl,Style::Fullscreen,windowSettings):
	window.create(VideoMode(windowSize.x , windowSize.y ), introTtl, Style::Titlebar| Style::Close, windowSettings) ;

	window.setFramerateLimit(frameRate);
	window.setVerticalSyncEnabled(false);
}

void Game::initState()
{
	//states.push(new State);

	/*now here we just push the game state
		creating it dynamically*/


	

	//hya state initial 
	states.push(new GameState(window, states));

}




void Game::initVariable()
{
	
	dt = 0.f;
	fullscreen = false;

}








//game components
void Game::endApplication()
{
	//here doing all the saving saving things we need for the game

}

Game::Game()
{
	
	initialize();
	initState();
	initVariable();

}

Game::~Game()
{
	
	//just deleting the texture later on
	
	/*
	here we just pop the top level states
	and delete the state data dynamically
	*/



	while (!this->states.empty())
	{
		delete this->states.top();//it deletes the data
		this->states.pop();//and it deletes the actual pointer

	}
}





//functions

void Game::updateSFMLEvent()
{
	while (window.pollEvent(event))
	{
		if (event.type == Event::Closed)
		{
			window.close();
		}
	}

}


void Game::updatedt()
{
	//basically it gives the time between two render and updates of the game loop
	//or simple the time it takes to render and update one frame
	dt = dtclock.restart().asSeconds();

}

void Game::update()
{
	//updateing the events first
	updateSFMLEvent();
	updatedt();


	/*now for updating the state we just
	 update the state from the stack*/

	if (!states.empty())
	{
		states.top()->update(dt);
		states.top()->getQuit() ?//if the state says quit you just start the deletion procedure
			states.top()->endState(),
			delete states.top(),
			states.pop() : getVoid();
	}
	else
	{
		endApplication();
		window.close();
	}

}

void Game::render()
{
	window.clear(Color::Blue);
	/*now for render the state we
	*we basically render the top state
	that is the top configuration that we have for the game

	*/

	!states.empty() ? states.top()->render(window) : getVoid();




	

	window.display();

}

void Game::run()
{
	while (window.isOpen())
	{

		//updatedt();
		update();
		render();
	}
}

