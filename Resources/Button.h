#pragma once
#include "StaticContent.h"


/*
this class here is to define all the stuff
required for the a bottom that we gonna use in the menu state

*/
using namespace sf;
using namespace std;

enum ButtonState{BTN_IDL,BTN_HOVER,BTN_PRESSED};
class Button
{

	
private:
	// all the essentials for button
	RectangleShape shape;
	Font& font;
	Text text;
	float h, w;//for the reactangle around the text

	//
	bool btn_as_toggle = false;
	
	ButtonState btn_state;//that is enum of the state we made earlier
	
	//colors
	Color idleColor=Color(224, 255, 255);//lightcyan
	Color hoverColor= Color(0, 206, 209);//darkturquoise
	Color activeColor= Color(0, 255, 255);//cyan



public:
	 
	bool toggled=false;
	
	//all the necessary data will from the button
	Button(float x,float y,int fontSize,
		Font& ,string);
	~Button();
	void setText(string data);
	void setTextSize(int size);
	void setToggled(Color color = Color(0,255,255));

	//accesor
	const bool isPressed() const;
	const bool isHovered() const;

	//basic functions
	void render(RenderTarget& target);
	void update(const Vector2f& mousePos);


};

