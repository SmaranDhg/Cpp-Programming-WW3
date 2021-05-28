 
#include "State.h"



State::State(RenderWindow& wind, stack<State*>& states)

:quit(false), window(wind),states(states)

{
}

const bool& State::getQuit() const
{
	
	return this->quit;
	
}

void State::checkForQuit()
{
	
  quit=Keyboard::isKeyPressed(Keyboard::Escape) ? true : false;
  //!quit ? dbg::print("running..") :dbg:: print("quiting!");
}

void State::updateMousePosition()
{
	
	mousePosScreen = Mouse::getPosition();
	mousePosWindow = Mouse::getPosition(window);
	mousePosView = window.mapPixelToCoords(Mouse::getPosition(window));//now it give the position of the coordinates of a view inside the window no the scree
	

}
