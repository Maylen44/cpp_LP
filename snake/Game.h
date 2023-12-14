#ifndef GAME_H
#define GAME_H

#include "EventHandler.h"
#include "Update.h"
#include "Render.h"
#include "Snake.h"
#include "Food.h"

const sf::Vector2f RESOLUTION(800.f, 600.f);

class Game : private Render, EventHandler, Update
{
public:
	Game();
	~Game() = default;
	void runGame();

private:
	bool m_isPlaying;
	
};

#endif //GAME_H