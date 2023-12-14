#include <SFML/Graphics.hpp>
#include <vector>
#include <algorithm>
#include "Game.h"
#include "Snake.h"
#include "Food.h"
#include "Update.h"

static void moveSnake(Snake& snake, sf::Vector2f& movementDirection)
{
    std::vector<sf::RectangleShape>& segments = snake.getSegments();
    segments.back().setPosition(segments.front().getPosition() + movementDirection);
    std::rotate(segments.begin(), segments.end() - 1, segments.end());
}

Update::Update()
	: m_deltaTime()
    , m_timeProgressModifier(1.05f)
{
}

void const Update::updateGame(Snake& snake, Food& food, sf::Vector2f& movementDirection)
{
    float speedFactor = m_timeProgressModifier * snake.getSegments().size() / 2;
    sf::Time elapsed = m_deltaTime.getElapsedTime();

    if (elapsed > sf::seconds(0.35f) / speedFactor)
    {
        moveSnake(snake, movementDirection);
        m_deltaTime.restart();
    }
}

void Update::resetGame(Snake& snake, Food& food)
{
    snake.resetSnake();
    food.resetFood();
}

void Update::progressGame(Snake& snake, Food& food, sf::Vector2f& movementDirection)
{
    sf::RectangleShape newSegment(snake.getSize());
    newSegment.setFillColor(snake.getColor());
    newSegment.setPosition(snake.getSegments().back().getPosition() - movementDirection);
    snake.getSegments().push_back(newSegment);
    food.resetFood();
}