#ifndef SNAKE_H
#define SNAKE_H

class Snake
{
public:
	Snake();
	~Snake() = default;

	void changeDirection(sf::Event keyReleased); //enum Direction
	void move(); //update
	void reset(); //move to private
	void increaseSpeed(); //move to private
	void addSegment(); //move to private

	const bool isTouching(const sf::Shape& food); //update and move to privet
	const bool isTouchingBoundaried(); //update and move to privet

	const std::vector<sf::RectangleShape>& getSegments(); //delete

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