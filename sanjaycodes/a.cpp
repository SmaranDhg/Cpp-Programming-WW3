#include "SFML/Graphics.hpp"
#include <iostream>
#include <vector>
#include "bullet.h"
using namespace sf;
int main()
{
	sf::RenderWindow window(sf::VideoMode(600, 600), "SFML WORK!");
	window.setFramerateLimit(60);
	window.setKeyRepeatEnabled(true);

	//Background
	Texture texturebg;
	texturebg.loadFromFile("city.png");
	Sprite spritebg(texturebg);
	spritebg.setPosition(0, 0);
	spritebg.setScale(Vector2f(0.32, 0.55));

	//Player1
	Texture texturep1;
	texturep1.loadFromFile("p1a.png");
	Sprite spritep1(texturep1);
	spritep1.setPosition(60, 435);
	spritep1.setScale(Vector2f(0.06, 0.1));

	//player2
	Texture texturep2;
	texturep2.loadFromFile("p2a.png");
	Sprite spritep2(texturep2);
	spritep2.setPosition(531, 435);
	spritep2.setScale(Vector2f(0.06, 0.1));
	//bullet
	/*Texture texturebullet;
	texturebullet.loadFromFile("bullet.png");
	Sprite spritebullet(texturebullet);
	spritebullet.setPosition(24,44);
	spritep2.setScale(Vector2f(0.06, 0.1));
	*/
	
	//movement
	const float speed = 15.f;
	
	Clock clock;
	while (window.isOpen())
	{


		sf::Event event;

		while (window.pollEvent(event))
		{
			switch (event.type)
			{
			case sf::Event::KeyPressed:
				switch (event.key.code)
				{
				case sf::Keyboard::Up:
					break;

				case sf::Keyboard::Right:
					if ((600 - spritep2.getPosition().x)< 55 ) {
						spritep2.move(0, 0);
					}
					else {
						spritep2.move(speed, 0);
					}
					break;

				case sf::Keyboard::Left:
					
					if ((spritep2.getPosition().x - spritep1.getPosition().x) < 15) {
						printf(" colliosion \n");
						spritep2.move(speed, 0);
					}
					else {
						printf("no collision \n");
						spritep2.move(-speed, 0);
					}


					break;

				case sf::Keyboard::A:
					if (spritep1.getPosition().x == 0) {
						spritep1.move(0, 0);
					}
					else {
						spritep1.move(-speed, 0);
					}
					break;
				case sf::Keyboard::D:
					
					if ((spritep2.getPosition().x - spritep1.getPosition().x) < 15) {
						printf(" colliosion \n");
						spritep1.move(-speed, 0);
					}
					else {
						printf("no collision \n");
						spritep1.move(speed, 0);
					}
					break;
				case sf::Keyboard::W:

					break;

				}
				break;
				case Event::MouseMoved:
					std::cout<<"x="<<event.mouseMove.x<<"y="<<event.mouseMove.y;
					break;
			case sf::Event::Closed:
				window.close();

				break;

			}
		}

		window.clear();

	
			

		window.draw(spritebg);
		window.draw(spritep1);
		window.draw(spritep2);


		window.display();
	}
}