#ifndef SNAKE_H
#define SNAKE_H

class Snake
{
public:
	Snake();
	~Snake() = default;
	void resetSnake();
	std::vector<sf::RectangleShape>& getSegments();
	sf::Vector2f& getSize();
	sf::Color& getColor();

private:
	sf::Vector2f m_size;
	sf::RectangleShape m_shape;
	sf::Color m_color;
	std::vector<sf::RectangleShape> m_segments;
};

#endif //SNAKE_H