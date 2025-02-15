#pragma once
#include<SFML/Graphics.hpp>

struct Map {
	int id = -1;
	sf::Texture* texture = nullptr;
	sf::Vector2f position;
};