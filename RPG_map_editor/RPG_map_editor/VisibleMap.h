#pragma once
#include"Map.h"
#include"iostream"
#include"Math.h"

class VisibleMap
{
private:
	sf::Texture m_mapTexture;
	std::vector<Map> m_wholeMaps;
	std::vector<sf::Sprite> m_wholeMapSprite;
	std::vector<sf::Sprite> m_displayMapSprite;
	int m[72] = { 128,129,130,131,132,133,
				152,153,154,155,156,157,
		
				111,1,2,3,4,5,
				24,25,26,27,27,29,
				48,49,50,51,52,53,

				72,73,74,75,76,77,
				96,97,98,99,100,101,
				78,79,80,81,82,83,
				102,103,104,105,106,107,

				216,217,218,220,221,222,
				240,241,242,244,245,246,
				264,265,266,268,269,270
				};
	sf::Vector2i map_size;
	sf::Vector2i size;
	sf::Vector2i m_cellSize;
	sf::Vector2i m_scale;
	sf::Vector2f m_position;
public:
	VisibleMap();
	VisibleMap(const sf::Vector2i cellSize,
				const sf::Vector2i scale,
				const sf::Vector2f position);
	~VisibleMap();

	void Initialization();
	void Load();
	void Update(float delta_time);
	sf::Sprite getSprite(sf::Vector2i mousePosition);
	void Draw(sf::RenderWindow& window);
};