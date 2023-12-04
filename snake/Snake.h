#ifndef SNAKE_H
#define SNAKE_H

const float GameWidth = 800.f;
const float gameHeight = 600.f;
const sf::Vector2f snakeSize(20.f, 20.f);
const sf::Vector2f foodSize(20.f, 20.f);



//void restartGame();

sf::Vector2f getRandomCoordinates(const float windowWidth, const float windowHeight, const sf::Vector2f objectSize);

#endif //SNAKE_H