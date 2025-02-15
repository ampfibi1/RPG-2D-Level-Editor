#include "VisibleMap.h"

VisibleMap::VisibleMap()
{
}

VisibleMap::VisibleMap(const sf::Vector2i cellSize,
			const sf::Vector2i scale, const sf::Vector2f position)
{
	this->m_cellSize = cellSize;
	this->m_scale = scale;
	this->m_position = position;
}

VisibleMap::~VisibleMap()
{
}

void VisibleMap::Initialization()
{
}

void VisibleMap::Load()
{
	if (m_mapTexture.loadFromFile("Assets/Dungeon_tileset.png")) {
		printf("Visible Map Load\n");
		map_size.x = m_mapTexture.getSize().x;
		map_size.y = m_mapTexture.getSize().y;
		size.x = map_size.x / m_cellSize.x;
		size.y = map_size.y / m_cellSize.y;
		printf("%d ,, %d\n", size.x, size.y);
		
		for (int y = 0; y < size.y; y++) {
			for (int x = 0; x < size.x; x++) {
				int index = x + y * size.x;//index or id whatever
				Map map;
				map.id = index;
				map.position = sf::Vector2f(x*m_cellSize.x, y* m_cellSize.y);
				map.texture = &m_mapTexture;
				m_wholeMaps.push_back(map);
				printf("%d  ", index);
			}
		}
		/*for (int y = 0; y < size.y; y++) {
			for (int x = 0; x < size.x; x++) {
				int index = x + y * size.x;
				sf::Sprite msp;
				msp.setTexture(*m_wholeMaps[index].texture);
				msp.setTextureRect(sf::IntRect(x * 16, y * 16,16,16));
				msp.setPosition(m_wholeMaps[index].position.x * m_scale.x
					,m_wholeMaps[index].position.y * m_scale.y);
				msp.setScale(sf::Vector2f(3, 3));
				m_wholeMapSprite.push_back(msp);
			}
		}*/
		m_position.x *= m_scale.x;
		m_position.y *= m_scale.y;
		
		for (int y = 0; y < 12; y++) {
			for (int x = 0; x < 6; x++) {
				int i = x + y * 6; 
				int index = m[i];

				sf::Sprite msp;
				msp.setTexture(*m_wholeMaps[index].texture);
				msp.setTextureRect(sf::IntRect(
					m_wholeMaps[index].position.x,
					m_wholeMaps[index].position.y,
					m_cellSize.x, m_cellSize.y));
				
				msp.setPosition(m_position+
							sf::Vector2f(x* m_cellSize.x *m_scale.x,
							y* m_cellSize.y * m_scale.y));
				msp.setScale(sf::Vector2f(m_scale));
			
				std::cout << i << " : " << msp.getPosition().x << " "
					<< msp.getPosition().y << std::endl;

				m_displayMapSprite.push_back(msp);
			}
		}
	}
	else printf("Visible Map not Load\n");
}

void VisibleMap::Update(float delta_time)
{
}

sf::Sprite VisibleMap::getSprite(sf::Vector2i mousePosition)
{
	//identify cordinate and then index 
	//return that index sprite on m_displayMapSprite[index]
	int index = Math::indexCalculation(mousePosition,
		sf::Vector2i(16, 16),
		sf::Vector2i(3, 3),
		6, sf::Vector2f(24, 4));
	
	return m_displayMapSprite[index];
}

void VisibleMap::Draw(sf::RenderWindow& window)
{
	for (auto& x : m_displayMapSprite) window.draw(x);
	/*window.draw(m_wholeMapSprite[1]);
	window.draw(m_wholeMapSprite[2]);
	window.draw(m_wholeMapSprite[3]);
	window.draw(m_wholeMapSprite[24]);
	window.draw(m_wholeMapSprite[48]);
	window.draw(m_wholeMapSprite[49]);*/
	//for (auto& x : m_wholeMapSprite) window.draw(x);
}