#ifndef EVENT_HANDLER_H
#define EVENT_HANDLER_H

enum KeyInputs
{
	ESC,
	UP,
	W,
	LEFT,
	A,
	DOWN,
	S,
	RIGHT,
	D
};

class EventHandler
{
public:
	EventHandler();
	~EventHandler() = default;
	bool checkingClossingGame(sf::Event& event);
	bool checkingCollisionWithFood(Snake& snake, Food& food);
	bool checkingCollisionWithBoundaries(Snake& snake);
	void const handleMovementInput(sf::Event& event);

protected:
	sf::Vector2f m_movementDirection;

};

#endif //EVENT_HANDLER_H