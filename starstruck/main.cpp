/*
 * main.cpp
 *
 *  Created on: 25 de mai de 2023
 *      Author: user
 */
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "menu/menu.hpp"

int main() {

	sf::VideoMode vm(sf::VideoMode::getDesktopMode().width, sf::VideoMode::getDesktopMode().height);

	sf::RenderWindow window(vm, "SFML works!", sf::Style::Fullscreen);

	sf::CircleShape shape(100.f);
	    shape.setFillColor(sf::Color::Green);

	Menu menu_state(vm.width, vm.height);

	while (window.isOpen()) {
		sf::Event event;
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed) {
				window.close();
			}
			if (event.type == sf::Event::KeyPressed) {
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
					window.close();
				}
			}
			menu_state.key_manager(menu_state, event);
		}

		window.clear(sf::Color::White); //branco :)
		menu_state.draw(window); ///teste legal
		window.display(); //nubia linda cheirosa
		//melzita eh top

		//aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa
		//funciona plss <3 :D
		//triste vida
		//fieiguegeifwifwij
	}

	return 0;
}

