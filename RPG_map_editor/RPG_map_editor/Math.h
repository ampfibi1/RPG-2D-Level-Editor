#pragma once
#include<SFML/Graphics.hpp>

class Math
{
public:
	static sf::Vector2i cordinateCalculate(const sf::Vector2i mousePos,
		const sf::Vector2i cellSize,const sf::Vector2i scale,
		const sf::Vector2f position);

	static int indexCalculation(const sf::Vector2i mousePos,
		sf::Vector2i cellSize, sf::Vector2i scale, int column,
		const sf::Vector2f position);
};

