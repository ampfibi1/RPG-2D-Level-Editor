#include "Grid.h"

Grid::Grid(const sf::Vector2i total_cell, const sf::Vector2i scale,
		const sf::Vector2i cell_size,const float thickness, 
		const sf::Vector2f position, const sf::Color color)
{
	this->m_total_cell = total_cell;
	this->m_scale = scale;
	this->m_cell_size = cell_size;
	this->m_thickness = thickness;
	this->m_position = position;
	this->m_color = color;
}

Grid::~Grid()
{
}

void Grid::Initialization()
{
}

void Grid::Load()
{
	int hLineWeight = m_total_cell.x* m_cell_size.x * m_scale.x ; 
	int vLineWeight = m_total_cell.y* m_cell_size.y * m_scale.y ;

	for (int i = 0; i < m_total_cell.y+1; i++) {
		sf::RectangleShape line(sf::Vector2f(hLineWeight,m_thickness));
		line.setPosition(m_position+sf::Vector2f(0, i*m_cell_size.x*m_scale.x));
		line.setFillColor(m_color); 
		horizontal.push_back(line);
	}

	for (int i = 0; i < m_total_cell.x+1; i++) {
		sf::RectangleShape line(sf::Vector2f(vLineWeight,m_thickness));
		line.setPosition(m_position+sf::Vector2f(i*m_cell_size.y*m_scale.y, 0));
		line.setRotation(90);
		line.setFillColor(m_color);
		vertical.push_back(line);
	}
}

void Grid::Update(float delta_time)
{
}

void Grid::Draw(sf::RenderWindow& window)
{
	for (auto& x : horizontal) window.draw(x);
	for (auto& x : vertical) window.draw(x);
}