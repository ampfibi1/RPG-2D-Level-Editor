#pragma once
#include<SFML/Graphics.hpp>
#include<iostream>

class FPS
{
private:
	sf::Font font; 
	sf::Text text;
	sf::Clock clock;
	const float max_time; 
	const std::string fps_text; 
	int fps;
public:
	FPS(); 
	~FPS(); 
	void Initialization(); 
	void Load();
	void Update(float delta_time);
	void Draw(sf::RenderWindow& window);
};