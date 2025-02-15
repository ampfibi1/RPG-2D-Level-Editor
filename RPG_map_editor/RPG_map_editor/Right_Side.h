#pragma once
#include<SFML/Graphics.hpp>

class Right_Side
{
private:
	sf::RectangleShape m_rightSlide; 
public:
	Right_Side();
	~Right_Side();
	void Initialization();
	void Load();
	void Update(const sf::Vector2i& mouse_pos);
	void Draw(sf::RenderWindow& window);
};

