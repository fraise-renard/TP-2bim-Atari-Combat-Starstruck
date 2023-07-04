/*
 * gamestate.cpp
 *
 *  Created on: 14 de jun. de 2023
 *      Author: hayde
 */
#include <States/gameState.hpp>

GameState::GameState(GameDataRef data) {
	this->data = data;
}

void GameState::init() {
	gameMusic.openFromFile("assets/interstellar.wav");
	gameMusic.setVolume(17.f);
	gameMusic.setLoop(true);
	gameMusic.play();
	Player astronaut(data, "wasd", "assets/astronaut/"), bilu(data, "arrow",
			"assets/etbilu/");
	players.push_back(astronaut);
	players.push_back(bilu);
	players.at(0).init();
	players.at(1).init();
	pewbuf.loadFromFile("assets/pew.wav");
	hitbuf.loadFromFile("assets/hit.ogg");
	hitsound.setBuffer(hitbuf);
	pewsound.setBuffer(pewbuf);
	score.init();
	map.init(1);
	players.at(0).sprite.setPosition(ww / 2, wh / 2);
	players.at(1).sprite.setPosition(700, 500);

}
void GameState::update() {
	starCooldown += data->dt;
	rayCooldown += data->dt;
	for (int i = 0; i < stars.size(); i++) {
		stars[i].update(data->dt);
		if (stars[i].testCollision(players.at(1).sprite)) {
			stars.erase(std::next(stars.begin(), i));
			hitsound.play();
			ast_points++;
		}

	};
	for (int i = 0; i < rays.size(); i++) {
		rays[i].update(data->dt);
		if (rays[i].testCollision(players.at(0).sprite)) {
			rays.erase(std::next(rays.begin(), i));
			hitsound.play();
			bilu_points++;
		}
	};

	for (int i = 0; i < map.walls.size(); i++) {
		for (int j = 0; j < stars.size(); j++) {
			if (stars[j].testCollision(map.walls[i])) {
				stars.erase(std::next(stars.begin(), j));
				break;
			}
		}
		for (int j = 0; j < rays.size(); j++) {
			if (rays[j].testCollision(map.walls[i])) {
				rays.erase(std::next(rays.begin(), j));
				break;
			}
		}
	};

	for (int i = 0; i < map.walls.size(); i++) {
		if (players.at(1).testCollision(map.walls[i])
				|| players.at(0).testCollision(map.walls[i]))
			break;
	};

	players.at(0).testCollision(players.at(1).sprite);
	players.at(1).testCollision(players.at(0).sprite);
	players.at(0).update();
	players.at(1).update();
	score.update(ast_points, bilu_points);
}
void GameState::draw() {
	data->window.clear(sf::Color(157, 121, 188));
	for (int i = 0; i < map.walls.size(); i++) {
		data->window.draw(map.walls[i]);
	};
	for (int i = 0; i < stars.size(); i++) {
		stars[i].draw();
	};
	for (int i = 0; i < rays.size(); i++) {
		rays[i].draw();
	};
	players.at(0).draw();
	players.at(1).draw();
	for(int i = 0; i < 2; i++){
		data->window.draw(score.points[i]);
	}
	data->window.display();
}

void GameState::handleInput() {
	sf::Event event;
	while (data->window.pollEvent(event)) {
		if (event.type == sf::Event::Closed) {
			data->window.close();
		}
		if (event.type == sf::Event::KeyReleased
				&& event.key.code == sf::Keyboard::C) {
			players.at(0).rotate("left");
		}
		if (event.type == sf::Event::KeyReleased
				&& event.key.code == sf::Keyboard::V) {
			players.at(0).rotate("right");
		}
		if (event.type == sf::Event::KeyReleased
				&& event.key.code == sf::Keyboard::Comma) {
			players.at(1).rotate("left");
		}
		if (event.type == sf::Event::KeyReleased
				&& event.key.code == sf::Keyboard::Period) {
			players.at(1).rotate("right");
		}
		if (event.type == sf::Event::KeyPressed
				&& event.key.code == sf::Keyboard::B) {
			if (starCooldown >= 0.6) {
				starCooldown = 0;
				pewsound.play();
				Bullet b1(players.at(0).currentDir, players.at(0).sprite, data,
						"assets/star.png");
				b1.init();
				stars.push_back(b1);
			}
		}
		if (event.type == sf::Event::KeyPressed
				&& event.key.code == sf::Keyboard::RControl) {
			if (rayCooldown >= 0.6) {
				rayCooldown = 0;
				pewsound.play();
				Bullet b2(players.at(1).currentDir, players.at(1).sprite, data,
						"assets/ray.png");
				b2.init();
				rays.push_back(b2);
			}
		}
	}
}

