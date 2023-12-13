#ifndef RENDER_H
#define RENDER_H

class Snake;
class Food;

class Render
{
public:
	Render();
	~Render() = default;

	void const renderGame(Snake& snake, Food& food);
	void const closeWindow();
	
private:
	const sf::VideoMode m_windowMode;
	const std::string m_windowTitel;
	const sf::Uint64 m_windowStyle;
	
protected:
	sf::RenderWindow m_window;
};

#endif //RENDER_H