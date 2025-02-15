#include "Right_Side.h"

Right_Side::Right_Side()
{
	m_rightSlide = sf::RectangleShape(sf::Vector2f(1056, 770));
}

Right_Side::~Right_Side()
{
}

void Right_Side::Initialization()
{
}

void Right_Side::Load()
{
	m_rightSlide.setPosition(sf::Vector2f(1102, 0));
	m_rightSlide.setFillColor(sf::Color(220, 220, 220));
}

void Right_Side::Update(const sf::Vector2i& mouse_pos)
{
}

void Right_Side::Draw(sf::RenderWindow& window)
{
	window.draw(m_rightSlide);
}
