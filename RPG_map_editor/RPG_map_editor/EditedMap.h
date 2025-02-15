#pragma once
#include<SFML/Graphics.hpp>
#include"VisibleMap.h"

class EditedMap
{
private:
	sf::Sprite m_sprite;
	bool isTestSpriteExist; 
	bool onMainGrid;
	std::vector<sf::Sprite> firstLayer;
public:
	EditedMap();
	~EditedMap();

	void Initialization();
	void Load();
	void Update(float delta_time,sf::Vector2i mouse_pos,VisibleMap visibleMap);
	void Draw(sf::RenderWindow& window);
};

