#include "Math.h"

sf::Vector2i Math::cordinateCalculate(const sf::Vector2i mousePos, const sf::Vector2i cellSize, const sf::Vector2i scale, const sf::Vector2f position)
{
	int x = mousePos.x - (position.x * cellSize.x * scale.x);
	int y = mousePos.y - (position.y * cellSize.y * scale.y);
	sf::Vector2i ans = sf::Vector2i(x/(cellSize.x*scale.x), y / (cellSize.y * scale.y));
	return sf::Vector2i(ans.y,ans.x);
}

int Math::indexCalculation(const sf::Vector2i mousePos, sf::Vector2i cellSize, sf::Vector2i scale, int column, const sf::Vector2f position)
{
	int x = mousePos.x - (position.x * cellSize.x * scale.x);
	int y = mousePos.y - (position.y * cellSize.y * scale.y);
	return x / (cellSize.x * scale.x)
		+ (y/ (cellSize.y * scale.y) * 6);
}