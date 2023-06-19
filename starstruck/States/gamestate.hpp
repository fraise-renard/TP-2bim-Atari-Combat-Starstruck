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
#include <Engine/state.hpp>
#include <stdafx.hpp>
#include <Entities/player.hpp>


class GameState: public State {
public:
	GameState(GameDataRef data);
	void init();
	void update();
	void handleInput();
	void draw();
	//void handleInput();
	//void update(const float dt);
	//void handleInput();

private:
	GameDataRef data;
	std::vector<Player> players;
};

#endif /* STATES_GAMESTATE_HPP_ */
