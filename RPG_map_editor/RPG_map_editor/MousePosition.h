#pragma once
#include"Math.h"

class MousePosition
{
private:
	sf::Font font;
	sf::Text text,cordinate,index;
	sf::Clock clock;
	const std::string x , y , tab ;
	sf::Vector2i m_mouse_pos; 

public:
	MousePosition();
	~MousePosition();
	void Initialization();
	void Load();
	void Update(const sf::Vector2i& mouse_pos);
	void Draw(sf::RenderWindow& window);
};

