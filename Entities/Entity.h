#pragma once
#include "StaticContent.h"
using namespace dbg;
using namespace winfo;
using namespace pinfo;


//basically  entity are the object like the
//its  the base class for all the object in the game
class Entity
{
private:
protected:


	Sprite sprite;//so that all the player and other stuff hava flexiblity while using them
    
	//position of the entity
	Vector2f position;
	void setPositon(Vector2f&);//now we just set position of the entity


	
	

	//initialization
protected:
	void initSprite(Texture& texture, bool setPosition = true, bool scale = true, float scaleVal = 0.5f);




	
	
public:
	Entity(Vector2f&);

	~Entity();

	//getters 
	Vector2i getPostion();
	
	//functions
	virtual void update(const float& dt) = 0;
	virtual void render(RenderTarget&) = 0;
};

