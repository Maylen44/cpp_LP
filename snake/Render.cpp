#include <SFML/Graphics.hpp>
#include "Game.h"
#include "Snake.h"
#include "Food.h"
#include "Render.h"

Render::Render()
	: m_windowMode(RESOLUTION.x, RESOLUTION.y)
	, m_windowTitel("SNAKE")
	, m_windowStyle(sf::Style::Titlebar | sf::Style::Resize | sf::Style::Close)
	, m_window(m_windowMode, m_windowTitel, m_windowStyle)
{
}

void const Render::renderGame(Snake& snake, Food& food)
{
	m_window.clear();
	for (const auto& object : snake.getSegments())
	{
		m_window.draw(object);
	}
	m_window.draw(food.getShape());
	m_window.display();
}

void const Render::closeWindow()
{
	m_window.close();
}
