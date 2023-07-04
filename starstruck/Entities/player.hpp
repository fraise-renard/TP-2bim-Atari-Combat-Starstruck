/*
 * Player.hpp
 *
 *  Created on: 19 de jun. de 2023
 *      Author: hayde
 */

#ifndef ENTITIES_PLAYER_HPP_
#define ENTITIES_PLAYER_HPP_
#include <Entities/entity.hpp>
#include <Engine/gamedata.hpp>
class Player : Entity{
public:
	Player(GameDataRef data, std::string keyset, std::string texPath);
	void init();
	void update();
	void draw();
	void move();
	void rotate(std::string dir);
	void friction();
	void animate(){};
	void testCollision(sf::Sprite object);
	bool testCollision(sf::RectangleShape wall);
	sf::Sprite sprite;
	int currentDir;
private:
	GameDataRef data;
	std::string keyset, texPath;
	sf::Keyboard::Key keyUp, keyDown, keyLeft, keyRight;
	sf::Texture facing[9];
	sf::Vector2f velocity, dir;
	float acc = 1, maxVelocity = 3, drag = 0.5, multiplier = 60;
	bool playerCollision = false, wallCollision = false;

};



#endif /* ENTITIES_PLAYER_HPP_ */
