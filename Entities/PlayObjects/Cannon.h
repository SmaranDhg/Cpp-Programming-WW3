#pragma once
#include "Entities/Entity.h"
#include "Animation.h"
class Cannon :
	public Entity,public Animation
{
private:
	
public:
	void Animate();
	void update(const float& dt);
	void render(RenderTarget&);
};

