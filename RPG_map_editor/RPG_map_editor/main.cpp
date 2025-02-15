#include"FPS.h"
#include"MousePosition.h"
#include"Grid.h"
#include"Right_Side.h"
#include"EditedMap.h"

int main() {
	//-------------------------initialization-----------------------
	sf::RenderWindow window(sf::VideoMode(1440, 770), "RPG 2D Map");
	sf::Clock clock;
	sf::Time time;
	float delta_time;
	sf::Vector2i mouse_pos; 

	Right_Side right_side;
	FPS fps;
	MousePosition mousePosition;
	Grid grid(sf::Vector2i(50, 100),// column , row
		sf::Vector2i(3, 3),			//scale
		sf::Vector2i(16, 16),		//cellsize
		.75f,						//thickness
		sf::Vector2f(0, 0),			//position
		sf::Color(150,150,150));	//Color
	
	Grid right_grid(sf::Vector2i(6, 12),// column , row
		sf::Vector2i(3, 3),			//scale
		sf::Vector2i(16, 16),		//cellsize
		.75f,						//thickness
		sf::Vector2f(1152, 192),			//position
		sf::Color::Green);	//Color
	
	
	VisibleMap visibleMap(sf::Vector2i(16, 16),//cellsize
							sf::Vector2i(3,3),//scale			
							sf::Vector2f(384,64));//position

	sf::Sprite testSprite;
	bool isTestSpriteExist = false;
	bool onMainGrid = false;

	EditedMap editeMap;

	visibleMap.Initialization();
	fps.Initialization();
	mousePosition.Initialization();
	grid.Initialization();
	right_grid.Initialization();
	right_side.Initialization();
	editeMap.Initialization();
	//-------------------------initialization-----------------------
	//-------------------------Load-----------------------
	fps.Load();
	mousePosition.Load();
	grid.Load();
	right_grid.Load();
	visibleMap.Load();
	right_side.Load();
	editeMap.Load();
	//-------------------------Load-----------------------
	while (window.isOpen()) {
		time = clock.restart();
		delta_time = time.asSeconds();
		//-------------------------Update-----------------------
		sf::Event event;
		while (window.pollEvent(event))if (event.type == sf::Event::Closed) window.close(); 
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) window.close();
		
		mouse_pos = sf::Mouse::getPosition(window);
		
		editeMap.Update(delta_time,mouse_pos,visibleMap);
		fps.Update(delta_time);
		mousePosition.Update(mouse_pos);
		grid.Update(delta_time);
		visibleMap.Update(delta_time);
		right_side.Update(mouse_pos);
		right_grid.Update(delta_time);
		//-------------------------Update-----------------------
		//-------------------------Draw-----------------------
		window.clear(sf::Color::Black);
		
		grid.Draw(window);
		right_side.Draw(window);
		visibleMap.Draw(window);
		right_grid.Draw(window);
		editeMap.Draw(window);
		fps.Draw(window);
		mousePosition.Draw(window);
		window.display();
		//-------------------------Draw-----------------------
	}
}