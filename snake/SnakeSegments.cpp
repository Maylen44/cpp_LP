#include <SFML/Graphics.hpp>
#include "Snake.h"
#include "SnakeSegments.h"

SnakeSegments::SnakeSegments(const sf::RectangleShape& head)
	: m_segments()
	, m_head(head)
{
	m_segments.push_front(head);
}

SnakeSegments::~SnakeSegments(){}

void SnakeSegments::addSnakeSegment()
{
	sf::RectangleShape snakeTail(SNAKE_SIZE);
	snakeTail.setFillColor(SNAKE_FILL_COLOR);
	m_segments.push_back(snakeTail);
}

void SnakeSegments::resetProgress(const sf::RectangleShape& head)
{
	m_segments.clear();
	m_segments.push_front(head);
}

void SnakeSegments::updatePositions(const sf::RectangleShape& head)
{
	for (int i = m_segments.size() - 1; i > 0; --i)
	{
		m_segments[i].setPosition(m_segments[i - 1].getPosition());
	}
	m_segments.front().setPosition(head.getPosition());
}

const std::deque<sf::RectangleShape> SnakeSegments::getSegments()
{
	return m_segments;
}
