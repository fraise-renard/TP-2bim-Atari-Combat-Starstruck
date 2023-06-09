/*
 * statemachine.hpp
 *
 *  Created on: 3 de jun. de 2023
 *      Author: hayde
 */
#pragma once
#ifndef ENGINE_STATEMACHINE_HPP_
#define ENGINE_STATEMACHINE_HPP_
#include <Engine/state.hpp>
#include "stdafx.hpp"

class StateMachine{
public:

	void addState(State* newState, bool replace = true);
	void removeState();
	void doChanges();
	State* &getActualState();
private:
	std::stack<State*> states;
	State* newState;
	bool remove, replace, add;
};

#endif /* ENGINE_STATEMACHINE_HPP_ */
