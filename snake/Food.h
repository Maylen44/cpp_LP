#ifndef FOOD_H
#define FOOD_H

class Food
{
public:
	Food();
	~Food() = default;

	void changePosition();
	const sf::RectangleShape& getShape();
	
private:
	const sf::Vector2f m_size;
	sf::RectangleShape m_shape;
	const sf::Color m_color;
};

#endif //FOOD_H