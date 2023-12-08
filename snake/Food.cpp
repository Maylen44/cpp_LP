#include <SFML/Graphics.hpp>
#include <cstdlib>
#include <ctime>
#include "Game.h"
#include "Food.h"

static int generateRandomNumber(int max) 
{
	return rand() % (max + 1);
}

static sf::Vector2f& getRandomCoordinates(const sf::Vector2f boundaries, const sf::Vector2f boundariesSizeStep) 
{
	std::srand(static_cast<unsigned int>(std::time(nullptr)));

	sf::Vector2f position;
	position.x = generateRandomNumber(static_cast<int>((boundaries.x - boundariesSizeStep.x) / boundariesSizeStep.x)) * boundariesSizeStep.x;
	position.y = generateRandomNumber(static_cast<int>((boundaries.y - boundariesSizeStep.y) / boundariesSizeStep.y)) * boundariesSizeStep.y;
	return position;
}

Food::Food()
	: m_size(sf::Vector2f(20.f, 20.f))
	, m_shape(m_size)
	, m_color(sf::Color::Yellow)
{
	m_shape.setFillColor(m_color);
	changePosition();
}



void Food::changePosition()
{
	m_shape.setPosition(getRandomCoordinates(RESOLUTION, m_size));
}

const sf::RectangleShape& Food::getShape()
{
	return m_shape;
}

