
#pragma once
#include "StaticContent.h"


using namespace sf;
using namespace std;
using namespace winfo;

class Bullet
{
private:
	float currVelocity;
	Texture bTexture;
	Sprite bSprite;
	bool isbTextLoaded = false;

	//bullet animation counters and stuff
	int xPos, dt;//dt==delta time or simply update the sprite every 10 frame
	
	
	
public:
	
	Bullet(float currVelocity=5.f,int winPosX=0,int winPosY=0);
	void shoot(RenderWindow& window,int& counter);

};


