#ifndef SHAPE_H
#define SHAPE_H

class Shape
{
public:
	Shape();
	~Shape() = default;


protected:
	sf::Vector2f m_size;
	sf::RectangleShape shape;
};

#endif //SHAPE_H