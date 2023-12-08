#include <SFML/Graphics.hpp>
#include "Render.h"

Render::Render()
	: m_windowMode(800, 600)
	, m_windowTitel("SNAKE")
	, m_windowStyle(sf::Style::Titlebar | sf::Style::Resize | sf::Style::Close)
	, m_window(m_windowMode, m_windowTitel, m_windowStyle)
{
}

Render::~Render()
{
}

void Render::drawObject(const sf::Drawable& drawable)
{
    m_window.draw(drawable);
}

void Render::renderGame(const std::vector<sf::Drawable> gameObjects)
{
	m_window.clear();
	for (const auto& object : gameObjects)
	{
		drawObject(object);
	}
	m_window.display();
}