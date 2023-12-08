#ifndef GAME_H
#define GAME_H

#include "Render.h"

const sf::Vector2f RESOLUTION(800.f, 600.f); //make members
const int FPS_LIMIT = 60; //make members

class Render;

class Game
{
public:
	Game();
	~Game() = default;
	void runGame();
	void closeGame(sf::Event event);

private:
	bool m_isPlaying;
	Render m_render;
	
};

#endif //GAME_H