/*
 * main.cpp
 *
 *  Created on: 25 de mai de 2023
 *      Author: user
 */
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "screen/screen.hpp"
#include "menu/menu.hpp"

int main() {

	sf::VideoMode vm(sf::VideoMode::getDesktopMode().width, sf::VideoMode::getDesktopMode().height);

	sf::RenderWindow window(vm, "SFML works!", sf::Style::Fullscreen);

	Menu menu_state(vm.width, vm.height);
	//primeira tela: menu
	menu_state.inScreen = true;

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
			//menu_state.key_manager(menu_state, event);
		}

		window.clear(sf::Color::White);
		menu_state.draw(window); //só desenha se true
		window.display();
	}

	return 0;
}

