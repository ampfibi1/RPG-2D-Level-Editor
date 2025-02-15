#include "FPS.h"
#include<iostream>

FPS::FPS() : max_time(.5f) , fps_text("FPS : ") , fps(0)
{
}

FPS::~FPS()
{
}

void FPS::Initialization()
{
}

void FPS::Load()
{
	if (font.loadFromFile("Assets/arial.ttf")) {
		printf("Fps font Load\n");
		text.setFont(font);
		text.setString(fps_text+std::to_string(fps));
		text.setFillColor(sf::Color::Red);
	}
	else printf("Not Load\n");
}

void FPS::Update(float delta_time)
{
	if (clock.getElapsedTime().asSeconds() >= max_time) {
		fps = 1 / delta_time; 
		text.setString(fps_text + std::to_string(fps));
		clock.restart();
	}
}

void FPS::Draw(sf::RenderWindow& window)
{
	window.draw(text);
}
