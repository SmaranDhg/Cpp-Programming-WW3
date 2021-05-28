#pragma once
#include "Entities/Entity.h"
#include "Animation.h"
#include "Entities/Players.h"
#include "Window Management/GameState.h"

class Mortar :
	public Entity,public Animation
{
private:
	Sprite ballfiresprite;
	Texture text;
	//initializations 
	Vector2f pos;
public:
	Mortar(Vector2f&);
	void animate();

	void render(RenderTarget&);
	void update(const float&);
};

