#include <SFML/Graphics.hpp>
#include "Game.h"
#include "Shape.h"
#include "Shape.h"
#include "Snake.h"
#include "Food.h"
#include "Update.h"

static void moveSnake(Snake& snake, sf::Vector2f& movementDirection, float ingameSpeed)
{
    if (snake.getSegments().size() > 1)
    {
        for (int i = snake.getSegments().size() - 1; i > 0; --i)
        {
            sf::Vector2f direction = snake.getSegments()[i - 1].getPosition() - snake.getSegments()[i].getPosition();
            snake.getSegments()[i].setPosition(snake.getSegments()[i].getPosition() + direction * ingameSpeed);
        }
    }
    snake.getSegments().front().setPosition(snake.getSegments().front().getPosition() + movementDirection * ingameSpeed);
}

Update::Update()
	: m_deltaTime()
    , m_defaultSpeed(20.0f)
    , m_ingameSpeed(m_defaultSpeed)
    , m_speedModifier(1.10f)
{
}

void const Update::updateGame(Snake& snake, Food& food, sf::Vector2f& movementDirection)
{
    moveSnake(snake, movementDirection, m_ingameSpeed);
}

void Update::resetGame(Snake& snake, Food& food)
{
    snake.resetSnake();
    m_ingameSpeed = m_defaultSpeed;
    food.resetFood();
}

void Update::progressGame(Snake& snake, Food& food, sf::Vector2f& movementDirection)
{
    m_ingameSpeed *= m_speedModifier;
    sf::RectangleShape newSegment(m_size);
    newSegment.setFillColor(m_color);
    newSegment.setPosition(snake.getSegments().back().getPosition() - movementDirection);
    snake.getSegments().push_back(newSegment);

}

//Collision check with food and adding game progress
if (snake.isTouching(food.getShape()))
{
    snake.increaseSpeed();
    snake.addSegment();
    food.changePosition();
}


void Snake::addSegment()
{
    
}