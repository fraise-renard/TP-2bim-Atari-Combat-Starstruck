/*c
 * game.cpp
 *
 *  Created on: 3 de jun. de 2023
 *      Author: hayde
 */
#include <Engine/game.hpp>
Game::Game(int width, int height) {
	game_data->window.create(sf::VideoMode(width, height), "Starstruck",
			sf::Style::Fullscreen);
	game_data->window.setFramerateLimit(60);
	game_data->machine.addState(new MenuState(game_data));
	Run();
}
void Game::Run() {
	while (game_data->window.isOpen()) {
		while (game_data->window.pollEvent(event)) {
			if (event.type == sf::Event::KeyPressed &&
					event.key.code == sf::Keyboard::Escape){
				game_data->window.close();
			}
		}
		game_data->machine.doChanges();
		game_data->machine.getActualState()->handleInput();
		game_data->machine.getActualState()->update(dt);
		game_data->machine.getActualState()->draw(dt);
	}
}

