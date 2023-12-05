#include <SFML/Graphics.hpp>
#include "Game.h"
#include "Snake.h"

Snake::Snake()
	: m_snake(SNAKE_SIZE)
	, m_ingameSpeed(SNAKE_DEFAULT_SPEED)
    , m_speedModifier(5.f)
	, m_movementDirection(sf::Vector2f(0.f, 0.f))
	, m_position(sf::Vector2f(GAME_WIDTH/2.f, GAME_HEIGHT/2.f))
{
    m_snake.setFillColor(SNAKE_FILL_COLOR);
}

Snake::~Snake(){}

void Snake::changeMoveDirection(sf::Event keyReleased)
{
    switch (keyReleased.key.code)
    {
    case sf::Keyboard::W:
        if (m_movementDirection != sf::Vector2f(0.f, 20.f))
        {
            m_movementDirection = sf::Vector2f(0.f, -20.f);
        }
        break;
    case sf::Keyboard::S:
        if (m_movementDirection != sf::Vector2f(0.f, -20.f))
        {
            m_movementDirection = sf::Vector2f(0.f, 20.f);
        }
        break;
    case sf::Keyboard::A:
        if (m_movementDirection != sf::Vector2f(20.f, 0.f))
        {
            m_movementDirection = sf::Vector2f(-20.f, 0.f);
        }
        break;
    case sf::Keyboard::D:
        if (m_movementDirection != sf::Vector2f(-20.f, 0.f))
        {
            m_movementDirection = sf::Vector2f(20.f, 0.f);
        }
        break;
    default:
        m_movementDirection;
        break;
    }
}

void Snake::move()
{
    m_snake.setPosition(m_snake.getPosition() + m_movementDirection * m_ingameSpeed * static_cast<float>(GAME_FPS_LIMIT));
}

void Snake::resetProgress()
{
    m_snake.setPosition(GAME_WIDTH / 2.f, GAME_HEIGHT / 2.f);
    m_ingameSpeed = SNAKE_DEFAULT_SPEED;
}

const sf::RectangleShape Snake::getSnake()
{
    return m_snake;
}

const sf::Vector2f Snake::getPosition()
{
    return m_position;
}

const float Snake::getIngameSpeed()
{
    return m_ingameSpeed;
}

const float Snake::getSpeedModifier()
{
    return m_speedModifier;
}

void Snake::setIngameSnakeSpeed(float addedSpeed)
{
    m_ingameSpeed += addedSpeed;
}