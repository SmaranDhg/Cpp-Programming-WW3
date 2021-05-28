#include "AreaSelection.h"

void AreaSelection::initText()
{
	font.loadFromFile(fontFolder + "3D.ttf");

	text1.setFont(font);
	text1.setFillColor(Color::Black);
	text1.setString(" AREA SELECTION ");
	text1.setCharacterSize(100);
	text1.setPosition(x - 350, 20);

	text2.setFont(font);
	text2.setFillColor(Color::Cyan);
	text2.setString(" AELEPO ");
	text2.setCharacterSize(100);
	text2.setPosition(x + xpadding + 25, y + 30);

	text3.setFont(font);
	text3.setFillColor(Color::Cyan);
	text3.setString(" BAGHDAD ");
	text3.setCharacterSize(100);
	text3.setPosition(x - xpadding - width + 25, y + 30);

	text4.setFont(font);
	text4.setFillColor(Color::Cyan);
	text4.setString(" MOSUL ");
	text4.setCharacterSize(100);
	text4.setPosition(x - width / 2 + 25, rect2.getPosition().y + ypadding + height + 30);
}

void AreaSelection::initTexture()
{
	bgTexture.loadFromFile("Assets/sprites/ww1.jpg");
	bgsprite.setTexture(bgTexture);

	placeTexture1.loadFromFile("Assets/sprites/Background.png");
	placeSprite1.setTexture(placeTexture1);
	placeSprite1.setPosition(x + xpadding+25, y+30);
	placeSprite1.setScale(0.31f, 0.32f);
	
	placeTexture2.loadFromFile("Assets/sprites/snow.png");
	placeSprite2.setTexture(placeTexture2);
	placeSprite2.setPosition(x - xpadding - width+25, y + 30);
	placeSprite2.setScale(0.12f, 0.209f);

	placeTexture3.loadFromFile("Assets/sprites/Background.png");
	placeSprite3.setTexture(placeTexture3);
	placeSprite3.setPosition(x - width / 2+25, rect2.getPosition().y + ypadding + height + 30);
	placeSprite3.setScale(0.31f, 0.32f);

}

void AreaSelection::initRect()
{
	
	rect1.setFillColor(Color::Cyan);
	rect1.setPosition(x+xpadding, y);
	rect1.setSize(Vector2f(width, height));

	rect2.setFillColor(Color::Cyan);
	rect2.setPosition(x - xpadding-width, y );
	rect2.setSize(Vector2f(width, height));

	rect3.setFillColor(Color::Cyan);
	rect3.setPosition(x -width/2, rect2.getPosition().y+ypadding+height);
	rect3.setSize(Vector2f(width, height));


	
}

void AreaSelection::isPressCheck()
{
	updateMousePosition();
	if ( rect1.getGlobalBounds().contains(mousePosView))
	{
		playSound();
		if (Mouse::isButtonPressed(Mouse::Left))
		{
			battle_grd = BattleGround::AELEPO;
			reset();
			rect1.setFillColor(Color::Blue);
		}
	}

	if  (rect2.getGlobalBounds().contains(mousePosView))
	{
		playSound();
		if(Mouse::isButtonPressed(Mouse::Left))
		{
			battle_grd =BattleGround::BAGHDAD;
			reset();
			rect2.setFillColor(Color::Blue);
		
		}
	}

	if (rect3.getGlobalBounds().contains(mousePosView))
	{
		playSound();
		if (Mouse::isButtonPressed(Mouse::Left))
		{
			battle_grd = BattleGround::MOSUL;
			reset();
			rect3.setFillColor(Color::Blue);
			
		}
	}
	
}

void AreaSelection::buttonUpdate()
{
	updateMousePosition();
	button1->update(mousePosView);
	button2->update(mousePosView);
	if (button1->isHovered() || button2->isHovered())
	{
		playSound();
	}
	if (button1->isPressed())
		states.pop();
	if (button2->isPressed())
		states.push(new GameState(window, states,playerIds,battle_grd));

}

void AreaSelection::initSound()
{
	buffer.loadFromFile(SOUND_MENU_SELECTED);
	buttonSound.setBuffer(buffer);
}

void AreaSelection::reset()
{
	rect1.setFillColor(Color::Cyan);
	rect2.setFillColor(Color::Cyan);
	rect3.setFillColor(Color::Cyan);
	
}

void AreaSelection::playSound()
{

	if (!Sound::Status::Playing == buttonSound.getStatus())
		buttonSound.play();
}

AreaSelection::AreaSelection(RenderWindow& window, stack<State*>& states,stack<PlayerId>& playerids)
	:State(window,states),playerIds(playerids)
{
	//print(int(playerIds.size()));
	initSound();
	initRect();
	initTexture();
	initText();
	
	button1 = new Button(220, 900, 80, font, " Return ");
	button2 = new Button(1700, 900, 80, font, " Play ");
}

AreaSelection::~AreaSelection()
{
	if (button1) delete button1;
    if(button2) delete button2;
}

void AreaSelection::checkForQuit()
{
}

void AreaSelection::endState()
{
}

void AreaSelection::update(const float& dt)
{
	isPressCheck();
	buttonUpdate();
	

}

void AreaSelection::render(RenderTarget& target)
{
	target.draw(bgsprite);

	target.draw(rect1);
	target.draw(rect2);
	target.draw(rect3);
	target.draw(placeSprite1);
	target.draw(placeSprite2);
	target.draw(placeSprite3);

	target.draw(text4);
	target.draw(text2);
	target.draw(text3);
	target.draw(text1);

	button1->render(target);
	button2->render(target);
}

void AreaSelection::updateInputs(const float& dt)
{
}

