////this is the central library  for all the static content and includes
#pragma once

#include<iostream>
#include<SFML/Window.hpp>
#include<SFML/Graphics.hpp>
#include<SFML/OpenGL.hpp>
#include<iostream>
#include<SFML/Audio.hpp>
#include<SFML/Graphics.hpp>
#include<SFML/System.hpp>
#include<SFML/Window.hpp>
#include<SFML/Network.hpp>
#include<fstream>
#include<istream>
#include<vector>
#include<map>
#include<stack>
#include<math.h>
#include<ostream>
using namespace sf;
using  namespace std;


//enums
enum  Direction { LEFT, RIGHT, UP, DOWN };
enum class PlayerId {SYRIA,USA,FRANCE,IRAQ};
enum class BattleGround {AELEPO,BAGHDAD,MOSUL};
//here we create the names pace in order to distinguih between the all the static contains
//this is for the window operation
namespace winfo {

	
	static const string soundFolder = "Assets/Sounds/";

	static const string fontFolder = "Assets/fonts/";

	static const string spriteFolder = "Assets/sprites/";

	static const string samePlayTtl = "WorldWar3";
	static const string introTtl = "Select Your Aliance";
	static const Vector2u windowSize(VideoMode::getDesktopMode().width, VideoMode::getDesktopMode().height);
	static const Vector2f displayCenter(windowSize.x/ 2,windowSize.y/2);
	//mainmenu option
	static const string MM_NEW_GAME = "New Game";
	static const string MM_SOLO = "Solo Play";
	static const string MM_EXIT = "Exit";
	//textures keys
	static const string BG_MENU_TEXTURE = "MBG";
	static const string BG_END_TEXTURE = "EBG";
	static const string BG_GAMEPLAY_TEXTURE = spriteFolder+"Background.png";
	static const string PLAYER_TEXTURE = spriteFolder+"usWright.png";
	static const string PLAYER_TEXTURE_ONE = spriteFolder + "NavyWright.png";
	static const string PLAYER_TEXTURE_TWO = spriteFolder + "IraqWleft.png";
	static const string PLAYER_TEXTURE_THREE = spriteFolder + "syriaWleft.png";
	//sound keys
	static const string SOUND_MENU_BG = soundFolder + "BackGroundScore.wav";
	static const string SOUND_MENU_SELECTED = soundFolder + "MenuSelectSound.wav";
	static const string SOUND_AIR_RAID_SIREN = soundFolder + "Air Raid Siren.wav";
	static const string SOUND_CANNON_FIRE = soundFolder + "Connon Fire.wav";
	static const string FONT_3D = "Assets/fonts/3D.ttf";

	//
	

}

//information about the projectiles
namespace pinfo
{
	//x Position of bullet
	static vector<int> xCoords = { 1,24,57,95,134,179,224,275,332,389,451,516 };//this the x coordinate of bulltets in sprite sheet
	static Vector2i yCoords(182, 260);
}




//all the printing funtion for debuging

namespace dbg
{

	static void getVoid()
	{

	}
	static void clear()
	{
		system("cls");
	}
	
	static void print(const string& a, bool line = true)
	{
		line ? cout << a << endl : cout << a;
	}
	static void print(const float& a, bool line = true)
	{
		line ? cout << a << endl : cout << a;
	}
	static void print(const int& a, bool line = true)
	{
		line ? cout << a << endl : cout << a;
	}
	
	static void print(unsigned a, bool line = true)
	{
		line ? cout << a << endl : cout << a;
	}
	static void print(RenderWindow* a, bool line = true)
	{
		line ? cout << a << endl : cout << a;
	}
	static void print(Texture * a, bool line = true)
	{
		line ? cout << a << endl : cout << a;
	}
	static void print(Sprite* a, bool line = true)
	{
		line ? cout << a << endl : cout << a;
	}
	static void print(BattleGround a,bool line = true)
	{
		line ? cout << int(a) << endl : cout << int(a);
	}
	static void print(Vector2f a, bool line = true)
	{
		line ? cout <<"("<< a.x <<","<<a.y<<")"<< endl : cout << "(" << a.x << "," << a.y << ")";
	}
	static void print(Vector2u a, bool line = true)
	{
		line ? cout << "(" << a.x << "," << a.y << ")" << endl : cout << "(" << a.x << "," << a.y << ")";
	}
	static void print(Vector2i a, bool line = true)
	{
		line ? cout << "(" << a.x << "," << a.y << ")" << endl : cout << "(" << a.x << "," << a.y << ")";
	}

	
	
}