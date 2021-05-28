#include "GameState.h"





void GameState::initPlayers()
{
	Vector2f pos(32, 32);
	if (playerOneTexture.loadFromFile(PLAYER_TEXTURE))
	player = new Player(playerOneTexture,pos);
	else print("player one texture not loaded");
}

void GameState::initbackground()
{
	backgroud.setSize(Vector2f(window.getSize().x,window.getSize().y));
	if(bg_texture.loadFromFile(BG_GAMEPLAY_TEXTURE))
	backgroud.setTexture(&bg_texture);
	else {
		print("Not loaded");
	}
}

void GameState::initTextures()
{

}


GameState::GameState(RenderWindow& wind, stack<State*>& states, stack<PlayerId>& playerIds, BattleGround battle_grnd)
	:State(wind, states),playerIds(playerIds),btl_grnd(battle_grnd)
{
	initbackground();
	initPlayers();
	print(btl_grnd);
	pos = Vector2f(0, 0);
	fire1 = new Fire(pos);
}
GameState::GameState(RenderWindow& wind, stack<State*>& states)
	:State(wind, states)
{
	initbackground();
	initPlayers();
	print(btl_grnd);
	pos = Vector2f(0, 0);
	fire1 = new Fire(pos);
}
GameState::~GameState()
{
	if (player)
		delete &player;
	delete fire1;
}



//functions
void GameState::update(const float& dt)
{
	updateInputs(dt);
	updateMousePosition();
	print(mousePosView);
	clear();
	player?player->update(dt):getVoid();
}

void GameState::render( RenderTarget& wind)
{

	wind.draw(backgroud);
	fire1 ? fire1->render(wind) : getVoid();
	//player?player->render(wind):getVoid();

}

void GameState::updateInputs(const float& dt)
{ 
	//that is for every update to the gamestate it will check for quit
	checkForQuit();//this function is defined in base class so becool
	





}

void GameState::endState()
{
	quit = true;


}
