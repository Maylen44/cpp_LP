#ifndef SNAKE_SEGMENTS_H
#define SNAKE_SEGMENTS_H

#include <deque>

class SnakeSegments
{
public:
	SnakeSegments(const sf::RectangleShape& head);
	~SnakeSegments();
	void addSnakeSegment();
	void resetProgress(const sf::RectangleShape& head);
	void updatePositions(const sf::RectangleShape& head);

	const std::deque<sf::RectangleShape> getSegments();

private:
	std::deque<sf::RectangleShape> m_segments;
	sf::RectangleShape m_head;
};

#endif //SNAKE_SEGMENTS_H