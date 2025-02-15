#pragma once
#include<SFML/Graphics.hpp>
#include<iostream>

class Grid
{
private:
	std::vector<sf::RectangleShape> horizontal, vertical;
	sf::Vector2i m_total_cell; 
	sf::Vector2i m_scale; 
	sf::Vector2i m_cell_size; 
	float m_thickness; 
	sf::Vector2f m_position;
	sf::Color m_color; 
public:
	Grid(const sf::Vector2i total_cell,
		const sf::Vector2i scale,
		const sf::Vector2i cell_size,
		const float thickness,
		const sf::Vector2f position,
		const sf::Color color);
	~Grid();
	void Initialization();
	void Load();
	void Update(float delta_time);
	void Draw(sf::RenderWindow& window);
};

