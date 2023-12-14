#ifndef UPDATE_H
#define UPDATE_H

class Snake;
class Food;

class Update
{
public:
	Update();
	~Update() = default;

	void const updateGame(Snake& snake, Food& food, sf::Vector2f& movementDirection);
	void resetGame(Snake& snake, Food& food);
	void progressGame(Snake& snake, Food& food, sf::Vector2f& movementDirection);

private:
	sf::Clock m_deltaTime;
	float m_timeProgressModifier;
};

#endif //UPDATE_H