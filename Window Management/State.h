#pragma once
#include "StaticContent.h"





//all the windows and stuff will extends the state class and 
//all it doees is provide the interface for all windows

using namespace sf;
using namespace std;
class State
{

protected:

	//resourses
	RenderWindow& window;
	bool  quit;//this just need to end the 

	
	//map of states it self
	stack<State*>& states;

	
	//vectors for mouse and stuff
	Vector2i  mousePosScreen;
	Vector2i mousePosWindow;
	Vector2f mousePosView;
public:
	State(RenderWindow& , stack<State*>&);
	const bool& getQuit() const;//reason its constant function bececause we dont wanna change the valye value of quit latter on after return from the function




	/*also every window/state has capacity to dismiss it self 
	so we create a pure virtual function to destroy it self*/
	virtual void checkForQuit();
	virtual void endState() = 0;//for deleting the state /saving data and stuff before deletion
	virtual void update(const float& dt) = 0;
	virtual void render(RenderTarget& target) = 0;//render target is just the base class for renderwindwo and render texture
    virtual void updateInputs(const float& dt) = 0;//that ever child class has to define the 
	void updateMousePosition();
};