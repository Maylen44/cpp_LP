#include <SFML/Graphics.hpp>
#include "Snake.h"

/*void restartGame()
{
	clock.restart();
	snake.setPosition(GameWidth / 2.f, gameHeight / 2.f);
	snakeIngameSpeed = snakeDefaultSpeed;
	food.setPosition(getRandomCoordinates(GameWidth, gameHeight, foodSize));
	snakeSegments.clear();
	snakeSegments.push_front(snake);
}*/

sf::Vector2f getRandomCoordinates(const float windowWidth, const float windowHeight, const sf::Vector2f objectSize)
{
	sf::Vector2f position;

	position.x = rand() % int((windowWidth - objectSize.x) / objectSize.x + 1) * objectSize.x;
	position.y = rand() % int((windowHeight - objectSize.y) / objectSize.y + 1) * objectSize.y;

	return position;
}