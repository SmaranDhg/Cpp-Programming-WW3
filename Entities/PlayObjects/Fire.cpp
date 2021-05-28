#include "Fire.h"

void Fire::initTexture()
{
	pos1 = Vector2f(20,460);
	fireTexture.loadFromFile("Assets/sprites/fire.png");
	rectSprite = IntRect(0,0,150,130);
	fireSprite.setTexture(fireTexture);
	fireSprite.setPosition(pos1);
	//fireSprite.setOrigin(Vector2f());
	fireSprite.setTextureRect(rectSprite);
}

Fire::Fire(Vector2f& pos):Entity(pos),pos(pos)
{
	initTexture();
}

Fire::~Fire()
{
}

void Fire::Animate()
{

	if (clock.getElapsedTime().asSeconds() > 0.7f)
	{
	
	 if (rectSprite.left == rectSprite.width * 2 + 40 && rectSprite.top == rectSprite.height + 40)
	{
		rectSprite.left = 0.f;
		rectSprite.top = rectSprite.height * 2 + 40;
		/* rectSprite.top = 242.f;*/
	}

	
	   if (rectSprite.left == rectSprite.width*2-16)
	  {
		  rectSprite.left = 0.f;
		 // rectSprite.top = rectSprite.height+40;
		 // rectSprite.top = 132.f;

	  }
	else if (rectSprite.left == rectSprite.width * 2 + 40 && rectSprite.top == rectSprite.height * 2 + 80)
	{
		rectSprite.left = 0.f;
		rectSprite.top = 0.f;

	}
	
	 
		else
			rectSprite.left += rectSprite.width-8;
		fireSprite.setTextureRect(rectSprite);
		clock.restart(); 
	}
	
}

void Fire::update(const float& dt)
{
	//just updateing the dt of the animation super class
	
}

void Fire::render(RenderTarget& window)
{
	Animate();
	window.draw(fireSprite);
}
