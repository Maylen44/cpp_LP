#ifndef SNAKE_H
#define SNAKE_H

const sf::Vector2f SNAKE_SIZE = sf::Vector2f(20.f, 20.f);
const sf::Color SNAKE_FILL_COLOR = sf::Color::Green;
const float SNAKE_DEFAULT_SPEED = 20.f;

class Snake
{
public:
	Snake();
	~Snake();

	void changeMoveDirection(sf::Event keyReleased);
	void move();
	void resetProgress();

	const sf::RectangleShape getSnake();
	const sf::Vector2f getPosition();
	const float getIngameSpeed();
	const float getSpeedModifier();

	void setIngameSnakeSpeed(float addedSpeed);

private:
	sf::RectangleShape m_snake;
	float m_ingameSpeed;
	float m_speedModifier;
	sf::Vector2f m_movementDirection;
	sf::Vector2f m_position;
};

#endif //SNAKE_H