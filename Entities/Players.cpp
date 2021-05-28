#include "Players.h"


//player one


void Player::move(Direction direction)
{
	
	if (clock.getElapsedTime().asSeconds() >0.7f)
	{
		

		
		if (playerRect.left == playerRect.width && playerRect.top == playerRect.height)
		{
			playerRect.left = 0.f;
			playerRect.top = 0.f;
		}
		else if (playerRect.left == playerRect.width)
		{
			playerRect.top = playerRect.height;
			
		}
		else
			playerRect.left += playerRect.width;
		sprite.setTextureRect(playerRect);
		clock.restart();
	}
	
	switch (direction)
	{
	case RIGHT:


		break;
	case LEFT:


		break;
	case UP:


		break;
	case DOWN:


		break;

	}



}

void Player::initPlayerSprite()
{
}

void Player::getPlayer()
{
}

Player::Player(Texture& texture,Vector2f& position)
	:Entity(position),text(texture),pos(position)
{
	
	playerRect = IntRect(0.f, 0.f,( text.getSize().x)/2,(text.getSize().y)/2);
	sprite.setTexture(text);
	sprite.setPosition(pos);
	sprite.setTextureRect(playerRect);
	
}



void Player::update(const float& dt)
{
	
}

void Player::render(RenderTarget& target)
{
	//now drawing the shape in window that's it
	
	target.draw(sprite);

	
}

void Player::Animate()
{
	if (clock.getElapsedTime().asSeconds() > 0.7f)
	{



		if (playerRect.left == playerRect.width && playerRect.top == playerRect.height)
		{
			playerRect.left = 0.f;
			playerRect.top = 0.f;
		}
		else if (playerRect.left == playerRect.width)
		{
			playerRect.top = playerRect.height;

		}
		else
			playerRect.left += playerRect.width;
		sprite.setTextureRect(playerRect);
		clock.restart();
	}
}


