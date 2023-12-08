#ifndef UPDATE_H
#define UPDATE_H

class Update
{
public:
	Update();
	~Update();

	void const updateGame();

private:
	sf::Clock m_deltaTime;
	
};

#endif //UPDATE_H