#include <SFML/Graphics.hpp>
#include "Game.h"
#include "Food.h"


Food::Food()
	: m_food(FOOD_SIZE)
	, m_position(sf::Vector2f(GAME_WIDTH / 2.f, GAME_HEIGHT / 2.f))
{
	m_food.setFillColor(FOOD_FILL_COLOR);
}

Food::~Food() {}

const sf::RectangleShape Food::getFood()
{
	return m_food;
}

const sf::Vector2f Food::getFoodPosition()
{
	return m_position;
}

void Food::setFoodPosition(const sf::Vector2f destination)
{
	m_position = destination;
}