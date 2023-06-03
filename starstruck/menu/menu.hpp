/*
 * screen.hpp
 *
 *  Created on: 25 de mai de 2023
 *      Author: user
 */

#ifndef MENU_MENU_HPP_
#define MENU_MENU_HPP_
#include <SFML/Graphics.hpp>

class Menu {
public:

	Menu(float width, float height);
	void draw(sf::RenderWindow &window);
	void key_manager(sf::Event event);
	void move_up();
	void move_down();
	int selected_index = 0;
	float height, width;
	sf::Font font;
	sf::Text menu[3];

};

#endif /* MENU_MENU_HPP_ */
