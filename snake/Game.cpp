#include <SFML/Graphics.hpp>
#include "Game.h"
#include "Snake.h"
#include "Food.h"

Game::Game()
	: m_isPlaying(true)
    , m_window(sf::VideoMode(RESOLUTION.x, RESOLUTION.y), 
               "SNAKE", 
               sf::Style::Titlebar | sf::Style::Resize | sf::Style::Close)
{
    m_window.setFramerateLimit(FPS_LIMIT);
    runGame();
}

Game::~Game()
{
}

void Game::runGame()
{
    Snake snake;
    Food food;
    sf::Event event;

    while (m_window.isOpen() && m_isPlaying)
    {
        //Closing input check
        while (m_window.pollEvent(event))
        {
            closeGame(event);
        }

        //Keyboard input check and snake movement
        if (event.type == sf::Event::KeyReleased)
        {
            snake.changeDirection(event);
        }
        snake.move();
        
        //Collision check with food and adding game progress
        if (snake.isTouching(food.getShape()))
        {
            snake.increaseSpeed();
            snake.addSegment();
            food.changePosition();
        }

        //Collision check with boundaries or itself and game progress resset
        if (snake.isTouchingBoundaried())
        {
            snake.reset();
            food.changePosition();
        }

        //Window render process
        m_window.clear();
        if (m_isPlaying)
        {
            for (const auto& segment : snake.getSegments())
            {
                m_window.draw(segment);
            }
            m_window.draw(food.getShape());
        }
        m_window.display();
    }
}

void Game::closeGame(sf::Event event)
{
    if ((event.type == sf::Event::Closed) || 
       ((event.type == sf::Event::KeyReleased) && (event.key.code == sf::Keyboard::Escape)))
    {
        m_isPlaying = false;
        m_window.close();
    }
}
