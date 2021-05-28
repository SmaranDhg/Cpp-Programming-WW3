#include "EndGameState.h"




void EndGameState::initSound()
{
	btnsndbuffer.loadFromFile(SOUND_MENU_SELECTED);
	btnsound.setBuffer(btnsndbuffer);
}

void EndGameState::buttonupdate()
{
	updateMousePosition();
	button1->update(mousePosView);
	if (button1->isHovered())
	{
		if (!Sound::Status::Playing == btnsound.getStatus())
			btnsound.play();

	}
	if (button1->isPressed())
	{

		states.push(new MenuState(window, states));
	}
	button2->update(mousePosView);
	if (button2->isHovered())
	{
		if (!Sound::Status::Playing == btnsound.getStatus())
			btnsound.play();
	}
	if (button2->isPressed())
		exit(true);

}

void EndGameState::initTexture()
{

	bgTexture.loadFromFile("Assets/sprites/war.jpg");
    bgSprite.setTexture(bgTexture);
	playerOnePos = Vector2f(600, 500);
	playerTwoPos = Vector2f(1200, 500);
	if (playerOneTexture.loadFromFile(PLAYER_TEXTURE))
	{
		p1 = new Player( playerOneTexture, playerOnePos);
	}
	if (playerTwoTexture.loadFromFile(PLAYER_TEXTURE_ONE))
	{
		p2 = new Player(playerTwoTexture, playerTwoPos);
	}
	


}

void EndGameState::initText()
{
	int a = 30, b = 55;
	//text1 for score
	text1.setFont(font);
	text1.setString("Score");
	text1.setFillColor(Color::Black);
	
	text1.setCharacterSize(100);
	//text1 for player 1
	text2.setFont(font);
	text2.setString("Player 1");
	text2.setFillColor(Color::Black);

	text2.setCharacterSize(100);
	//text2 for player 2
	text3.setFont(font);
	text3.setString("Player 2");
	text3.setFillColor(Color::Black);

	text3.setCharacterSize(100);
	//text3 for player1 score
	text4.setFont(font);
	text4.setString(to_string(a));
	text4.setFillColor(Color::Black);

	text4.setCharacterSize(80);
	//text4 for player 2 score
	text5.setFont(font);
	text5.setString(to_string(b));
	text5.setFillColor(Color::Black);

	text5.setCharacterSize(80);
	//text5 for header
	text6.setFont(font);
	text6.setString("World War 3");
	text6.setFillColor(Color::Black);

	text6.setCharacterSize(150);
	
}

EndGameState::EndGameState(RenderWindow& window, stack<State*>& states)
	:State(window , states)
{


	font.loadFromFile(FONT_3D);
	button1 = new  Button(x-500, 900, 75, font, " Restart ");
	button2 = new  Button(x + 500, 900, 75, font, " Exit ");
	initSound();
	initTexture();
	initText();
}



EndGameState::~EndGameState()
{
	//cleaniing data
	delete button1;
	delete button2;
	delete p1;
	delete p2;
}




//
void EndGameState::endState()
{
	//quit = true;
}

void EndGameState::update(const float& dt)
{
	/*print("window at intor:", false);
	print(&window);*/
	buttonupdate();

}


//draw garna parne kura haru
void EndGameState::render(RenderTarget& target)
{
	
	target.draw(bgSprite);
	button1->render(target);
	button2->render(target);
	text1.setPosition(x-50, 25 + y);
	text2.setPosition(x - text3.getGlobalBounds().width -60, 125 + y);
	text3.setPosition(x + text3.getGlobalBounds().width -60, 125 + y);
	text4.setPosition(x - text3.getGlobalBounds().width - 60, 225 + y);
	text5.setPosition(x + text3.getGlobalBounds().width - 60, 225 + y);
	text6.setPosition(x - 300, 0);
	target.draw(text1);//for score
	target.draw(text2);//for player 1
	target.draw(text3);//for player2
	target.draw(text4);//for player1 score
	target.draw(text5);//for player2 score
	target.draw(text6);//for header
p1->render(target);
p2->render(target);
}

void EndGameState::updateInputs(const float& dt)
{
}
