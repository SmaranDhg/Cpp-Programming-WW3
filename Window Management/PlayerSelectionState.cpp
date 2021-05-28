#include "PlayerSelectionState.h"

void PlayerSelectionState::initSound()
{
	selectionSound.loadFromFile(SOUND_MENU_SELECTED);
	playerSelectionSound.setBuffer(selectionSound);
}

void PlayerSelectionState::initTexture()
{
bgTexture.loadFromFile("Assets/sprites/ww1.jpg");
	bgSprite.setTexture(bgTexture);
	playerTexture1.loadFromFile(PLAYER_TEXTURE);
	playerTexture2.loadFromFile(PLAYER_TEXTURE_ONE);
	playerTexture3.loadFromFile(PLAYER_TEXTURE_TWO);
	playerTexture4.loadFromFile(PLAYER_TEXTURE_THREE);
}

void PlayerSelectionState::initText()
{
	font.loadFromFile(FONT_3D);
	
	//text1 for AXIS
	text1.setFont(font);
	text1.setString(" AXIS ");
	text1.setFillColor(Color::Black);
	text1.setCharacterSize(80);

	//text2 for ALLY
	text2.setFont(font);
	text2.setString(" ALLY ");
	text2.setFillColor(Color::Black);
	text2.setCharacterSize(80);

	//text5 for title
	text5.setFont(font);
	text5.setString("Player Selection");
	text5.setFillColor(Color::Black);
	text5.setCharacterSize(80);

	

}

void PlayerSelectionState::updateSelected()
{
	if (button2->toggled) playerIds.push(PlayerId::USA);
	if (button3->toggled) playerIds.push(PlayerId::FRANCE);
	if (button4->toggled) playerIds.push(PlayerId::IRAQ);
	if (button5->toggled) playerIds.push(PlayerId::SYRIA);

}

void PlayerSelectionState::updateText()//to update the line seperating axis and ally
{
	line.setFillColor(Color(274,255,0,100));
	line.setSize(Vector2f(15, 750));
	line.setPosition(x, 170);
	line1.setFillColor(Color::Black);
	line1.setSize(Vector2f(180, 10));
	line1.setPosition((text1.getPosition().x),190);	
	line2.setFillColor(Color::Black);
	line2.setSize(Vector2f(180,10));
	line2.setPosition((text2.getPosition().x), 190);
}

void PlayerSelectionState::buttonupdate()
{
	updateMousePosition();
	//just making sure that the stack is emty each time
	for (int i = 0; i < playerIds.size(); i++)
		playerIds.pop();
	button1->update(mousePosView);
	if (button1->isPressed())
	{
		states.pop();
		
	}
	if (button1->isHovered())
	{
		if (!Sound::Status::Playing == playerSelectionSound.getStatus())
			playerSelectionSound.play();
	}
	button2->update(mousePosView);
	if (button2->isPressed())
	{
		
		button2->setToggled(Color::Cyan);
		button3->toggled = false;
	}
	if (button2->isHovered())
	{
		if (!Sound::Status::Playing == playerSelectionSound.getStatus())
			playerSelectionSound.play();
	}

	button3->update( mousePosView);
	if (button3->isPressed())
	{
		
		button3->setToggled(Color::Cyan);
		button2->toggled = false;
	}
		
	if (button3->isHovered())
	{
		if (!Sound::Status::Playing == playerSelectionSound.getStatus())
			playerSelectionSound.play();
	}

	button4->update(mousePosView);
	if (button4->isPressed())
	{
		
		button4->setToggled(Color::Cyan);
		button5->toggled = false;
	}
		if (button4->isHovered())
		{
			if (!Sound::Status::Playing == playerSelectionSound.getStatus())
				playerSelectionSound.play();
		}

	button5->update(mousePosView);
	if (button5->isPressed())
	{
		
		button5->setToggled(Color::Cyan);
		button4->toggled = false;
	}
		if (button5->isHovered())
		{
			if (!Sound::Status::Playing == playerSelectionSound.getStatus())
				playerSelectionSound.play();
		}


		

   if ((button2->toggled == true || button3->toggled == true) && (button4->toggled == true || button5->toggled == true))
		{
	   //updateing the stack containing the selected players
	   updateSelected();
	  
			button6->update(mousePosView);
			if (button5->isHovered())
			{
				if (!Sound::Status::Playing == playerSelectionSound.getStatus())
					playerSelectionSound.play();
			}
			if(button6->isPressed())
			states.push(new AreaSelection(window, states, playerIds));
			a = true;
   }

   

}

PlayerSelectionState::PlayerSelectionState(RenderWindow& window, stack<State*>& states)
    :State(window,states)
{
	playerPos = Vector2f(200, 250);
	playerOnePos = Vector2f(200, 600);
	playerTwoPos = Vector2f(1350,250);
	playerThreePos = Vector2f(1350,600);
	initText();
	initTexture();
	initSound();
	button1 = new Button(200, 920, 70, font, " Return ");
	button2 = new Button(750, 300, 70, font, " USA ");
	button3 = new Button(750, 600, 70, font, " FRANCE");
	button4 = new Button(1100, 300, 70, font, " IRAQ");
	button5 = new Button(1100, 600, 70, font, " SYRIA");
	button6 = new Button(1500, 920, 70, font, " Play");

	player1 = new Player(playerTexture1, playerPos);
	player2 = new Player(playerTexture2, playerOnePos);
	player3 = new Player(playerTexture3, playerTwoPos);
	player4 = new Player(playerTexture4, playerThreePos);

}

PlayerSelectionState::~PlayerSelectionState()
{
}

void PlayerSelectionState::update(const float& dt)
{
	buttonupdate();
	checkForQuit();
	updateText();
	text1.setPosition(x-800, 100 + y);
	text2.setPosition(x+400, 100 + y);
	/*text3.setPosition(x-800 , 190 + y);
	text4.setPosition(x+400 , 190 + y);*/
	text5.setPosition(x - 200, y);
	player1->Animate();
	player2->Animate();
	player3->Animate();
	player4->Animate();
}

void PlayerSelectionState::render(RenderTarget& target)
{
	target.draw(bgSprite);
	target.draw(line);
	//underlline under axis and ally
	target.draw(line1);
	target.draw(line2);
	//button
	button1->render(target);
	button2->render(target);
	button3->render(target);
	button4->render(target);
	button5->render(target);
	if (a == b)
	{
		button6->render(target);
	}

	target.draw(text1);//for AXIS
	target.draw(text2);//for AllY
	target.draw(text5);//for title
	//player render for selection
	player1->render(target);
	player2->render(target);
	player3->render(target);
	player4->render(target);


}

void PlayerSelectionState::endState()
{
}

void PlayerSelectionState::updateInputs(const float& dt)
{
}

void PlayerSelectionState::checkForQuit()
{
}
