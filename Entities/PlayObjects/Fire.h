#pragma once
#include "Entities/Entity.h"
#include "Animation.h"
class Fire:public Entity,public Animation
{
private:
	//initializations 
	Sprite fireSprite;
	Texture fireTexture;
	IntRect rectSprite;
	Clock clock;
	void initTexture();
	Vector2f& pos,pos1;
public:
	Fire(Vector2f&);
	~Fire();
	void Animate();
	void update(const float& dt);
	void render(RenderTarget&);
};

