#include "Button.h"


Button::Button(float x, float y, int fontSize,
	Font& font, string data = "nothing")
:font(font)
{
	

	//initaillys setting the button state to the idl
	btn_state = BTN_IDL;
	
	text.setFont(font);
	text.setString(data);
	
	text.setFillColor(Color::Black);
	text.setCharacterSize(fontSize);
	/*
	now for centering the txt we
	first get the center of the shape
	and then the global bound of the text box
	*/
	
	text.setPosition(Vector2f(x, y));
	
	shape.setPosition(Vector2f(x,y));
	


	//
	shape.setFillColor(idleColor);
}

Button::~Button()
{
}

void Button::setText(string data)
{
	text.setString(data);
}

void Button::setTextSize(int size)
{
	text.setCharacterSize(size);
}

void Button::setToggled(Color color)
{
	//here we set the btn color as the toggle button
	if (!btn_as_toggle)
	{
		btn_as_toggle = !btn_as_toggle;
	}
	toggled =! toggled;
	
}



const bool Button::isPressed() const
{
	if (btn_state == BTN_PRESSED)
		return true;
	return false;
}

const bool Button::isHovered() const
{
	
	return btn_state==BTN_HOVER;
}

void Button::render(RenderTarget& target)
{
	//dbg::print(text.getString()+" width:", false);
	//dbg::print(text.getGlobalBounds().width);
	//dbg::print(text.getString() + " height:", false);
	//dbg::print(text.getGlobalBounds().height);
	

	//the text global bound is accesible after loop only so
	w = text.getGlobalBounds().width*1.05;//just adjusting the width of box around the text
	h = text.getGlobalBounds().height*2.2;//around the height
	text.setOrigin(Vector2f(text.getGlobalBounds().width/2, text.getGlobalBounds().height /2));
	shape.setOrigin(text.getOrigin());
	shape.setSize(Vector2f(w, h));
	shape.setPosition(text.getPosition());
	target.draw(this->shape);
	target.draw(text);
	
}

void Button::update(const Vector2f& mousePos)
{
	/*here update the booleans for the hover and pressed*/
	
	//now for the hover and stuff

	

	//hover
	if (shape.getGlobalBounds().contains(mousePos))
	{
		this->btn_state = BTN_HOVER;
		

		//pressed vaye pachi
		if (Mouse::isButtonPressed(Mouse::Left))
		{
			
			btn_state = BTN_PRESSED;
		}

	}
	else {
		
		btn_state = BTN_IDL;
	}


	//now changing the behavior of the btn with new condition
	if (!btn_as_toggle )
	{
		switch (btn_state)
		{
		case BTN_IDL:
			shape.setFillColor(idleColor);
			break;
		case BTN_HOVER:
			shape.setFillColor(hoverColor);
			break;
		case BTN_PRESSED:
			shape.setFillColor(activeColor);
			break;
		default:
			shape.setFillColor(idleColor);
			break;
		}
	}
	 if(toggled)
	{
		shape.setFillColor(activeColor);
	}
	else if(btn_as_toggle)
	{
		shape.setFillColor(idleColor);
	}

}
