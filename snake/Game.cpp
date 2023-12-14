#include <SFML/Graphics.hpp>
#include "Game.h"

Game::Game()
    : m_isPlaying(false)
{
    runGame();
}

void Game::runGame()
{
    Snake snake;
    Food food;

    m_isPlaying = true;
    while (m_isPlaying)
    {
        sf::Event event;

        while (m_window.pollEvent(event))
        {
            if (checkingClossingGame(event))
            {
                m_isPlaying = false;
                closeWindow();
            }
        }
        if (m_isPlaying)
        {
            handleMovementInput(event);
            if (checkingCollisionWithBoundaries(snake))
            {
                resetGame(snake, food);
            }
            else if (checkingCollisionWithFood(snake, food))
            {
                progressGame(snake, food, m_movementDirection);
            }
            updateGame(snake, food, m_movementDirection);
        }
        renderGame(snake, food);
    }
}
