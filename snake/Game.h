#ifndef GAME_H
#define GAME_H

const sf::Vector2f RESOLUTION(800.f, 600.f);
const int FPS_LIMIT = 60;

class Snake;
class Food;

class Game
{
public:
	Game();
	~Game();
	void runGame();
	void closeGame(sf::Event event);

private:
	bool m_isPlaying;
	sf::RenderWindow m_window;
};

#endif //GAME_H