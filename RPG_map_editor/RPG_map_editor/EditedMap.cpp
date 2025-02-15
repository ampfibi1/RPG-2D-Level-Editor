#include "EditedMap.h"

EditedMap::EditedMap() : isTestSpriteExist(false) , onMainGrid(false)
{
}

EditedMap::~EditedMap()
{
}

void EditedMap::Initialization()
{
}

void EditedMap::Load()
{
}

void EditedMap::Update(float delta_time, sf::Vector2i mouse_pos, VisibleMap visibleMap)
{
	if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
		if (mouse_pos.x >= 1152 && mouse_pos.x <= 1440 &&
			mouse_pos.y >= 192 && mouse_pos.y <= 770) {
			std::cout << "Mouse in Visible Grid\n" << std::endl;
			m_sprite = visibleMap.getSprite(mouse_pos);
			m_sprite.setPosition(sf::Vector2f(0, 0));
			isTestSpriteExist = true;
		}
		else if (mouse_pos.x >= 0 && mouse_pos.x <= 1104 &&
			mouse_pos.y >= 0 && mouse_pos.y <= 770) {
			std::cout << "Mouse on Left Grid \n";
		}
		else
			std::cout << "Mouse in Notttt on Visible Grid\n" << std::endl;
	}
	if (mouse_pos.x >= 0 && mouse_pos.x <= 1104 &&
		mouse_pos.y >= 0 && mouse_pos.y <= 770) onMainGrid = true;
	else onMainGrid = false;
	if (isTestSpriteExist && onMainGrid) {
		int x = mouse_pos.x / (16 * 3);
		int y = mouse_pos.y / (16 * 3);
		int xx = x * (16 * 3);
		int yy = y * (16 * 3);
		m_sprite.setPosition(sf::Vector2f(xx, yy));

		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
				firstLayer.push_back(m_sprite);
	}
}

void EditedMap::Draw(sf::RenderWindow& window)
{
	for (auto& x : firstLayer) window.draw(x);
	if (onMainGrid) window.draw(m_sprite);
}
