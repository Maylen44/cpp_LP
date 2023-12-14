#include <SFML/Graphics.hpp>
#include <vector>
#include "Game.h"
#include "Snake.h"

Snake::Snake()
    : m_size(sf::Vector2f(20.f, 20.f))
    , m_shape(m_size)
    , m_color(sf::Color::Green)
    , m_segments()
{
    m_shape.setFillColor(m_color);
    m_shape.setPosition(RESOLUTION.x/ 2.f, RESOLUTION.y / 2.f);
    m_segments.push_back(m_shape);
}

void Snake::resetSnake()
{
    m_segments.clear();
    m_segments.push_back(m_shape);
    m_shape.setPosition(RESOLUTION.x / 2.f, RESOLUTION.y / 2.f);
}

std::vector<sf::RectangleShape>& Snake::getSegments()
{
    return m_segments;
}

sf::Vector2f& Snake::getSize()
{
    return m_size;
}

sf::Color& Snake::getColor()
{
    return m_color;
}
