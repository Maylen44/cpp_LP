#include <SFML/Graphics.hpp>
#include <iostream>
#include "Game.h"
#include "Snake.h"
#include "SnakeSegments.h"
#include "Food.h"




static sf::Vector2f getRandomCoordinates(const float windowWidth, const float windowHeight, const sf::Vector2f objectSize)
{
    sf::Vector2f position;

    position.x = rand() % int((windowWidth - objectSize.x) / objectSize.x + 1) * objectSize.x;
    position.y = rand() % int((windowHeight - objectSize.y) / objectSize.y + 1) * objectSize.y;

    return position;
}

Game::Game()
	: m_isPlaying(true)
    , m_game(sf::VideoMode(static_cast<unsigned int>(GAME_WIDTH), static_cast<unsigned int>(GAME_HEIGHT), 32), "SNAKE", sf::Style::Titlebar | sf::Style::Close)
{
    m_game.setFramerateLimit(GAME_FPS_LIMIT);
}

Game::~Game()
{

    
}

void Game::runGame()
{
    Snake s;
    SnakeSegments ss(s.getSnake());
    Food f;

    f.setFoodPosition(getRandomCoordinates(GAME_WIDTH, GAME_HEIGHT, FOOD_SIZE));
    sf::Event event;

    while (m_game.isOpen() && m_isPlaying)
    {
        //check for game start or exit
        while (m_game.pollEvent(event))
        {
            closeGame(event);
            std::cout << "Check done: close game?" << std::endl;
        }

        //checking for keypresses for direction change by snake
        if (event.type == sf::Event::KeyReleased)
        {
            s.changeMoveDirection(event);
            std::cout << "Check done: key pressed?" << std::endl;

        }
        s.move();
        
        //Collision check, resetting foods position and adding snakeSegment
        if (s.getSnake().getGlobalBounds().intersects(f.getFood().getGlobalBounds()))
        {
            f.setFoodPosition(getRandomCoordinates(GAME_WIDTH, GAME_HEIGHT, FOOD_SIZE));
            s.setIngameSnakeSpeed(s.getIngameSpeed() + s.getSpeedModifier());
            ss.addSnakeSegment();
            std::cout << "Check done: collison checked?" << std::endl;

        }
        
        //Updating position of segments
        ss.updatePositions(s.getSnake());
        std::cout << "Check done: updated segments?" << std::endl;

        
        //Check bounderies and restart snake progress
        if (s.getPosition().x < 0.f || s.getPosition().x > GAME_WIDTH || s.getPosition().y < 0.f || s.getPosition().y > GAME_HEIGHT)
        {
            restartGame(s, f, ss);
            std::cout << "Check done: restarted game?" << std::endl;

        }
        
        //Renderring visuals
        m_game.clear();
        if (m_isPlaying)
        {
            /*for (const auto& segment : ss.getSegments())
            {
                m_game.draw(segment);
            }*/
            m_game.draw(s.getSnake());
            std::cout << "Check done: draw snake?" << std::endl;

            m_game.draw(f.getFood());
            std::cout << "Check done: draw food?" << std::endl;

        }
        m_game.display();
    }
}

void Game::restartGame(Snake& s, Food& f, SnakeSegments& ss)
{
    s.resetProgress();
    f.setFoodPosition(getRandomCoordinates(GAME_WIDTH, GAME_HEIGHT, FOOD_SIZE));
    ss.resetProgress(s.getSnake());
}

void Game::closeGame(sf::Event event)
{
    if ((event.type == sf::Event::Closed) || ((event.type == sf::Event::KeyReleased) && (event.key.code == sf::Keyboard::Escape)))
    {
        m_isPlaying = false;
        m_game.close();
    }
}





//check if snake ate itself
/*for (int i = 1; i < snakeSegments.size(); ++i)
            {
                if (snake.getGlobalBounds().intersects(snakeSegments[i].getGlobalBounds()))
                {
                    food.setPosition(getRandomCoordinates(gameWidth, gameHeight, foodSize));
                    snakeIngameSpeed += 1.f;
                    sf::RectangleShape snakeTail(snakeSize - sf::Vector2f(3.f, 3.f));
                    snakeTail.setOutlineThickness(3.f);
                    snakeTail.setOutlineColor(sf::Color(sf::Color::White));
                    snakeTail.setFillColor(sf::Color::Green);
                    snakeTail.setPosition(snakeSegments.back().getPosition() - snakeMovement * snakeSize.x);
                    snakeSegments.push_back(snakeTail);
                }
            }*/