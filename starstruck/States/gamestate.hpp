/*
 * menu.hpp
 *
 *  Created on: 9 de jun. de 2023
 *      Author: hayde
 */
#pragma once
#ifndef STATES_GAMESTATE_HPP_
#define STATES_GAMESTATE_HPP_
#include <Engine/gamedata.hpp>
#include <Entities/bullet.hpp>
#include <Engine/state.hpp>
#include <stdafx.hpp>
#include <Entities/player.hpp>
#include <Entities/map.hpp>
#include <Entities/score.hpp>

class GameState: public State {
public:
	GameState(GameDataRef data);
	void init();
	void update();
	void handleInput();
	void draw();

private:
	GameDataRef data;
	sf::SoundBuffer hitbuf, pewbuf;
	sf::Sound hitsound, pewsound;
	sf::Music gameMusic;
	Map map;
	Score score;
	int ast_points = 0, bilu_points = 0;
	float starCooldown = 0, rayCooldown = 0;
	std::vector<Player> players;
	std::vector<Bullet> stars;
	std::vector<Bullet> rays;
};

#endif /* STATES_GAMESTATE_HPP_ */
