#include "MousePosition.h"
#include<iostream>

MousePosition::MousePosition() : x("x: "), y("y: ") , m_mouse_pos(0,0),
				tab("      ")
{
}

MousePosition::~MousePosition()
{
}

void MousePosition::Initialization()
{
}

void MousePosition::Load()
{
	if (font.loadFromFile("Assets/arial.ttf")) {
		printf("Mouse Position font Load\n");
		text.setFont(font);
		text.setString(x + std::to_string(m_mouse_pos.x) + tab+ 
						y + std::to_string(m_mouse_pos.y));
		text.setFillColor(sf::Color::Red);
		text.setPosition(sf::Vector2f(0, 40));
		
		std::cout << m_mouse_pos.x << std::endl;
		cordinate.setFont(font);
		
		std::cout << m_mouse_pos.x << std::endl; 
		cordinate.setString(x + std::to_string(m_mouse_pos.y / (16 * 3) + 1) + tab +
			y + std::to_string(m_mouse_pos.x / (16 * 3) + 1)
		);
		cordinate.setFillColor(sf::Color::Red);
		cordinate.setPosition(sf::Vector2f(0, 80));
		
		index.setFont(font);
		index.setString( "Index : " + 
			std::to_string(
				m_mouse_pos.x / (16 * 3) + (m_mouse_pos.y / (16 * 3))*24)
		);
		index.setFillColor(sf::Color::Red);
		index.setPosition(sf::Vector2f(0, 120));
	}
	else printf("Mouse Position font Not Load\n");
}

void MousePosition::Update(const sf::Vector2i& mouse_pos)
{
	m_mouse_pos = mouse_pos; 
	text.setString(x + std::to_string(m_mouse_pos.x) + tab +
		y + std::to_string(m_mouse_pos.y));

	
	sf::Vector2i p = Math::cordinateCalculate(
						m_mouse_pos,sf::Vector2i(16,16),
						sf::Vector2i(3,3),sf::Vector2f(0,0)
	);
	cordinate.setString(x + std::to_string(p.x) + tab +
		y + std::to_string(p.y) 
		);

	int in = Math::indexCalculation(m_mouse_pos, 
		sf::Vector2i(16, 16), 
		sf::Vector2i(3, 3),
		6, sf::Vector2f(0, 0));
	index.setString( "Index : " +
		std::to_string(in));
}

void MousePosition::Draw(sf::RenderWindow& window)
{
	window.draw(text);
	window.draw(cordinate);
	window.draw(index);
}
