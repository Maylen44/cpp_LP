#include <SFML/Graphics.hpp>
#include <unordered_map>
#include "Snake.h"
#include "Food.h"
#include "EventHandler.h"
#include "Game.h"

static const sf::Vector2f up(0.f, -20.f);
static const sf::Vector2f down(0.f, 20.f);
static const sf::Vector2f left(-20.f, 0.f);
static const sf::Vector2f right(20.f, 0.f);

EventHandler::EventHandler()
    :m_movementDirection(sf::Vector2f(0.f, 0.f))
{}

bool EventHandler::checkingClossingGame(sf::Event& event)
{
    if ((event.type == sf::Event::Closed) ||
        ((event.type == sf::Event::KeyReleased) && (event.key.code == sf::Keyboard::Escape)))
    {
        return true;
    }
    return false;
}

bool EventHandler::checkingCollisionWithFood(Snake& snake, Food& food)
{
    return snake.getSegments().front().getGlobalBounds().intersects(food.getShape().getGlobalBounds());
}

bool EventHandler::checkingCollisionWithBoundaries(Snake& snake)
{
    sf::Vector2f position = snake.getSegments().front().getPosition();
    if (position.x < 0.f || position.x > RESOLUTION.x ||
        position.y < 0.f || position.y > RESOLUTION.y)
    {
        return true;
    }
    for (int i = 3; i < snake.getSegments().size(); ++i)
    {
        if (snake.getSegments().front().getGlobalBounds().intersects(snake.getSegments()[i].getGlobalBounds()))
        {
            return true;
        }
    }
    return false;
}

void const EventHandler::handleMovementInput(sf::Event& event)
{
    if (event.type == sf::Event::KeyReleased)
    {
        switch (event.key.code)
        {
        case sf::Keyboard::Up:
            if (m_movementDirection != down)
            {
                m_movementDirection = up;
            }
            break;
        case sf::Keyboard::W:
            if (m_movementDirection != down)
            {
                m_movementDirection = up;
            }
            break;
        case sf::Keyboard::Down:
            if (m_movementDirection != up)
            {
                m_movementDirection = down;
            }
            break;
        case sf::Keyboard::S:
            if (m_movementDirection != up)
            {
                m_movementDirection = down;
            }
            break;
        case sf::Keyboard::Left:
            if (m_movementDirection != right)
            {
                m_movementDirection = left;
            }
            break;
        case sf::Keyboard::A:
            if (m_movementDirection != right)
            {
                m_movementDirection = left;
            }
            break;
        case sf::Keyboard::Right:
            if (m_movementDirection != left)
            {
                m_movementDirection = right;
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
}
