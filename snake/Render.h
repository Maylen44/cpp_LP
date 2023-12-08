#ifndef RENDER_H
#define RENDER_H

class Render
{
public:
	Render();
	virtual ~Render();

	void drawObject(const sf::Drawable& drawable);
	void renderGame(const std::vector<sf::Drawable> gameObjects);
	
protected:
	const sf::VideoMode m_windowMode;
	const std::string m_windowTitel;
	const sf::Uint64 m_windowStyle;
	sf::RenderWindow m_window;
};

#endif //RENDER_H