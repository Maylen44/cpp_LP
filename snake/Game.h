#ifndef GAME_H
#define GAME_H

const float GAME_WIDTH = 800.f;
const float GAME_HEIGHT = 600.f;
const int GAME_FPS_LIMIT = 60;

class Snake;
class SnakeSegments;
class Food;


class Game
{
public:

	Game();
	~Game();

	

	void runGame();

	void restartGame(Snake& s, Food& f, SnakeSegments& ss);
	void closeGame(sf::Event event);
	

private:
	bool m_isPlaying;
	sf::RenderWindow m_game;
};

#endif //GAME_H