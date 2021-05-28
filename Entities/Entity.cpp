#include "Entity.h"



//just for setting but not that necessasr
void Entity::setPositon(Vector2f& pos)
{
	this->position = pos;
	sprite.setPosition(pos);
}





//just the function to set the texture  to the sprite
//and to scale it by 50% scaling can control throw arguments
void Entity::initSprite(Texture& texture,bool setPosition,bool scale,float scaleVal )
{
	if(setPosition)sprite.setPosition(position);
	if(scale) sprite.setScale(scaleVal, scaleVal);
	sprite.setTexture(texture);


}

Entity::Entity(Vector2f& postion)
	:position(postion)
{
	


	
	
	
}

Entity::~Entity()
{
	//clearing the srpite and all that shit here after the use
	
}

Vector2i Entity::getPostion()
{
	return Vector2i(sprite.getPosition());
}







