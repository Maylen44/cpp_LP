#include <SFML/Graphics.hpp>
#include "Game.h"

int main()
{
    Game g;
    g.runGame();






    ////some variables to work with
    ////const float GameWidth = 800.f;
    ////const float GameHeight = 600.f;
    ////const sf::Vector2f SnakeSize(20.f, 20.f);
    ////const sf::Vector2f FoodSize(20.f, 20.f);

    ////window rendering
    ////sf::RenderWindow window(sf::VideoMode(static_cast<unsigned int>(GameWidth), static_cast<unsigned int>(GameHeight), 32), "SNAKE", sf::Style::Titlebar | sf::Style::Close); //need to clarify Style and | operator
    ////window.setVerticalSyncEnabled(true); // need to clarify this point

    ////snake
    ////sf::RectangleShape snake;
    ////snake.setSize(SnakeSize - sf::Vector2f(3.f, 3.f));
    ////snake.setOutlineThickness(3.f);
    ////snake.setOutlineColor(sf::Color(sf::Color::White));
    ////snake.setFillColor(sf::Color::Green);
    ////float snakeDefaultSpeed = 10.f;
    ////float snakeIngameSpeed = snakeDefaultSpeed;
    ////sf::Vector2f snakeMovement(0.f, 0.f);
    
    ////snake segments
    ////std::deque<sf::RectangleShape> snakeSegments;
    ////snakeSegments.push_front(snake);

    ////food
    ////sf::RectangleShape food;
    ////food.setSize(FoodSize);
    ////food.setFillColor(sf::Color::Yellow);
    ////food.setPosition(Food::getRandomCoordinates(GameWidth, GameHeight, FoodSize));

    ////other properties/default settings
    ////sf::Clock clock;
    ////bool isPlaying = false;

    ////while (window.isOpen())
    ////{
        ////sf::Event event;
        ////float deltaTime = clock.restart().asSeconds();

        ////while (window.pollEvent(event))
        ////{
            //Closing or escaping the game
            ////if ((event.type == sf::Event::Closed) || ((event.type == sf::Event::KeyPressed) && (event.key.code == sf::Keyboard::Escape)))
            ////{
                ////window.close();
                ////break;
            ////}

            ////Starting the game
            ////if ((event.type == sf::Event::KeyPressed) && (event.key.code == sf::Keyboard::Space))
            ////{
                ////restarting the game
                ////if (!isPlaying)
                ////{
                    ////isPlaying = true;
                    ////clock.restart();

                    ////snake.setPosition(GameWidth / 2.f, GameHeight / 2.f);
                ////}
            ////}
        ////}
        ////if (isPlaying)
        ////{
            ////Move snake
            ////if (event.type == sf::Event::KeyReleased)
            ////{
                ////switch (event.key.code)
                ////{
                ////case sf::Keyboard::W:
                    ////if (snakeMovement != sf::Vector2f(0.f, 20.f))
                    ////{
                        ////snakeMovement = sf::Vector2f(0.f, -20.f);
                    ////}
                    ////break;
                ////case sf::Keyboard::S:
                ////if (snakeMovement != sf::Vector2f(0.f, -20.f))
                ////{
                    ////snakeMovement = sf::Vector2f(0.f, 20.f);
                ////}
                ////break;
                ////case sf::Keyboard::A:
                    ////if (snakeMovement != sf::Vector2f(20.f, 0.f))
                    ////{
                        ////snakeMovement = sf::Vector2f(-20.f, 0.f);
                    ////}
                    ////break;
                ////case sf::Keyboard::D:
                    ////if (snakeMovement != sf::Vector2f(-20.f, 0.f))
                    ////{
                        ////snakeMovement = sf::Vector2f(20.f, 0.f);
                    ////}
                    ////break;
                ////default:
                    ////snakeMovement;
                    ////break;
                ////}
                ////snake.setPosition(snake.getPosition() + snakeMovement * deltaTime * snakeIngameSpeed);
            ////}

            ////Check bounderies and restart snake progress
            ////sf::Vector2f snakePosition = snake.getPosition();
            ////if (snakePosition.x < 0.f || snakePosition.x > GameWidth || snakePosition.y < 0.f || snakePosition.y > GameHeight)
            ////{
                ////clock.restart();
                ////add restart as construct and deconstruct to game function.
                ////snake.setPosition(GameWidth / 2.f, GameHeight / 2.f);
                ////snakeIngameSpeed = snakeDefaultSpeed;
                ////
                ////food.setPosition(Food::getRandomCoordinates(GameWidth, GameHeight, FoodSize));
                ////snakeSegments.clear();
                ////snakeSegments.push_front(snake);
            ////}

            ////Collision check, resetting foods position and adding snakeSegment
            ////if (snake.getGlobalBounds().intersects(food.getGlobalBounds()))
            ////{
                ////food.setPosition(Food::getRandomCoordinates(GameWidth, GameHeight, FoodSize));
                ////snakeIngameSpeed += 0.25f;
                ////sf::RectangleShape snakeTail(SnakeSize - sf::Vector2f(3.f, 3.f));
                ////snakeTail.setOutlineThickness(3.f);
                ////snakeTail.setOutlineColor(sf::Color(sf::Color::White));
                ////snakeTail.setFillColor(sf::Color::Green);
                ////snakeSegments.push_back(snakeTail);
            ////}

            ////Updating position of segments
            ////for (int i = snakeSegments.size() - 1; i > 0; --i)
            ////{
                ////snakeSegments[i].setPosition(snakeSegments[i - 1].getPosition());
            ////}
            ////snakeSegments.front().setPosition(snake.getPosition());
        
        ////}
        
        ////clearing the window
        ////window.clear();

        ////Drawing menus and game
        ////if (isPlaying)
        ////{
            ////for (const auto& segment : snakeSegments)
            ////{
                ////window.draw(segment);
            ////}
            ////window.draw(snake);
            ////window.draw(food);

        ////}
        ////window.display();
    ////}

    return 0;
}