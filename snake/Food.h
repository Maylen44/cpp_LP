#ifndef FOOD_H
#define FOOD_H

const sf::Vector2f FOOD_SIZE = sf::Vector2f(20.f, 20.f);
const sf::Color FOOD_FILL_COLOR = sf::Color::Green;

class Food
{
public:
	Food();
	~Food();

	const sf::RectangleShape getFood();
	const sf::Vector2f getFoodPosition();
	void setFoodPosition(const sf::Vector2f destination);


	//
	//NOTE: Check if sf::RenderWindow without * creates new window or better use *
	//same in class food and snake
	//
	
private:
	sf::RectangleShape m_food;
    sf::Vector2f m_position;
};

#endif //FOOD_H