#pragma once

#include "Entity.h"



using namespace std;
using namespace sf;


class Player: public Entity
{

	//
	void move(Direction);
	Clock clock;
	float width = 160.f,heigth=240.f;
	Sprite sprite;
	Texture text;
	Vector2f pos;
	//int
	IntRect playerRect;



	//initializer functions
	void initPlayerSprite();
	void getPlayer();

	

public:
	Player(Texture&,Vector2f&);

	void update(const float& dt);
	void render(RenderTarget& target);
	void Animate();
	
	
	

};




