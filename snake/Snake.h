#ifndef SNAKE_H
#define SNAKE_H

class Snake
{
public:
	Snake();
	~Snake();

	void changeDirection(sf::Event keyReleased);
	void move();
	void reset();
	void increaseSpeed();
	void addSegment();

	const bool isTouching(const sf::Shape& food);
	const bool isTouchingBoundaried();

	const std::vector<sf::RectangleShape>& getSegments();

private:
	sf::Vector2f m_size;
	sf::RectangleShape m_shape;
	sf::Color m_color;
	const float m_defaultSpeed;
	float m_ingameSpeed;
	float m_speedModifier;
	sf::Vector2f m_movementDirection;
	std::vector<sf::RectangleShape> m_segments;
};

#endif //SNAKE_H