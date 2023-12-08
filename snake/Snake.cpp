#include <SFML/Graphics.hpp>
#include <vector>
#include "Game.h"
#include "Snake.h"
#include "Food.h"

Snake::Snake()
    : m_size(sf::Vector2f(20.f, 20.f))
    , m_shape(m_size)
    , m_color(sf::Color::Green)
    , m_defaultSpeed(4.0f / FPS_LIMIT)
    , m_ingameSpeed(m_defaultSpeed)
    , m_speedModifier(1.10f)
    , m_movementDirection(sf::Vector2f(0.f, 0.f))
    , m_segments()
{
    m_shape.setFillColor(m_color);
    m_shape.setPosition( RESOLUTION.x/ 2.f, RESOLUTION.y / 2.f);
    m_segments.push_back(m_shape);
}

void Snake::changeDirection(sf::Event keyReleased)
{
    const sf::Vector2f up(0.f, -20.f);
    const sf::Vector2f down(0.f, 20.f);
    const sf::Vector2f left(-20.f, 0.f);
    const sf::Vector2f right(20.f, 0.f);

    switch (keyReleased.key.code)
    {
    case sf::Keyboard::W:
        if (m_movementDirection != down)
        {
            m_movementDirection = up;
        }
        break;
    case sf::Keyboard::S:
        if (m_movementDirection != up)
        {
            m_movementDirection = down;
        }
        break;
    case sf::Keyboard::A:
        if (m_movementDirection != right)
        {
            m_movementDirection = left;
        }
        break;
    case sf::Keyboard::D:
        if (m_movementDirection != left)
        {
            m_movementDirection = right;
        }
        break;
    default:
        m_movementDirection;
        break;
    }
}

void Snake::move()
{
    if (m_segments.size() > 1)
    {
        for (int i = m_segments.size() - 1; i > 0; --i)
        {
            sf::Vector2f direction = m_segments[i - 1].getPosition() - m_segments[i].getPosition();
            m_segments[i].setPosition(m_segments[i].getPosition() + direction * m_ingameSpeed);
        }
    }
    m_segments.front().setPosition(m_segments.front().getPosition() + m_movementDirection * m_ingameSpeed);
}

void Snake::reset()
{
    m_segments.clear();
    m_segments.push_back(m_shape);
    m_shape.setPosition(RESOLUTION.x / 2.f, RESOLUTION.y / 2.f); //m_resetPosition
    m_ingameSpeed = m_defaultSpeed;
}

void Snake::increaseSpeed()
{
    m_ingameSpeed *= m_speedModifier;
}

void Snake::addSegment()
{
    sf::RectangleShape newSegment(m_size);
    newSegment.setFillColor(m_color);
    newSegment.setPosition(m_segments.back().getPosition() - m_movementDirection);
    m_segments.push_back(newSegment);
}

const bool Snake::isTouching(const sf::Shape& object)
{
    return m_segments.front().getGlobalBounds().intersects(object.getGlobalBounds());
}

const bool Snake::isTouchingBoundaried()
{
    sf::Vector2f position = m_segments.front().getPosition();
    if (position.x < 0.f || position.x > RESOLUTION.x || 
        position.y < 0.f || position.y > RESOLUTION.y)
    {
        return true;
    }
    for (int i = 3; i < m_segments.size(); ++i)
    {
        if (m_segments.front().getGlobalBounds().intersects(m_segments[i].getGlobalBounds()))
        {
            return true;
        }
    }
    return false;
}

const std::vector<sf::RectangleShape>& Snake::getSegments()
{
    return m_segments;
}

