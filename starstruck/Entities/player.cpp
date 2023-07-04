/*
 * player.cpp
 *
 *  Created on: 19 de jun. de 2023
 *      Author: hayde
 */

#include <Entities/player.hpp>
Player::Player(GameDataRef data, std::string keyset, std::string texPath) :
		data(data), keyset(keyset), texPath(texPath) {
}
void Player::init() {
	int dirframes[9] = { 0, 6, 12, 17, 23, 29, 35, 40, 23};
	int directions[9] = { south, southwest, west, northwest, north, northeast, east, southeast, 8};
	for (int i = 0; i < 9; i++) {
		std::stringstream path;
		path << texPath << dirframes[i] << ".png";
		facing[directions[i]].loadFromFile(path.str());
	}
	sprite.setTexture(facing[south]);
	sprite.setOrigin(sprite.getGlobalBounds().width/2, sprite.getGlobalBounds().height/2);
	sprite.setScale(1.125, 1.125);
	currentDir = south;
	if (keyset == "arrow") {
		keyUp = sf::Keyboard::Up;
		keyDown = sf::Keyboard::Down;
		keyLeft = sf::Keyboard::Left;
		keyRight = sf::Keyboard::Right;
	}
	if (keyset == "wasd") {
		keyUp = sf::Keyboard::W;
		keyDown = sf::Keyboard::S;
		keyLeft = sf::Keyboard::A;
		keyRight = sf::Keyboard::D;
	}
}
void Player::move() {
	dir = (sf::Vector2f(0, 0));
	if (sf::Keyboard::isKeyPressed(keyUp)) {
		dir.y = -1;
		if (velocity.y > -maxVelocity) {
			velocity.y += acc * dir.y;
		}
	} else if (sf::Keyboard::isKeyPressed(keyDown)) {
		dir.y = 1;
		if (velocity.y < maxVelocity) {
			velocity.y += acc * dir.y;
		}
	}
	if (sf::Keyboard::isKeyPressed(keyLeft)) {
		dir.x = -1;
		if (velocity.x > -maxVelocity) {
			velocity.x += acc * dir.x;
		}
	} else if (sf::Keyboard::isKeyPressed(keyRight)) {
		dir.x = 1;
		if (velocity.x < maxVelocity) {
			velocity.x += acc * dir.x;
		}
	}

}
void Player::friction() {
	//Up
	if (velocity.y < 0) {

		velocity.y += drag;

		if (velocity.y > 0) {
			velocity.y = 0;
		}
	}
	//Down
	if (velocity.y > 0) {

		velocity.y -= drag;

		if (velocity.y < 0) {
			velocity.y = 0;
		}
	}
	//Left
	if (velocity.x < 0) {

		velocity.x += drag;

		if (velocity.y > 0) {
			velocity.y = 0;
		}
	}
	//Right
	if (velocity.x > 0) {

		velocity.x -= drag;

		if (velocity.x < 0) {
			velocity.x = 0;
		}
	}

}

void Player::rotate(std::string dir) {
	if (dir == "left") {
		currentDir++;
		if (currentDir >= 8)
			currentDir = 0;
	} else if (dir == "right") {
		currentDir--;
		if (currentDir <= 0)
			currentDir = 8;
	}
}
void Player::testCollision(sf::Sprite object) {
	if (sprite.getGlobalBounds().intersects(object.getGlobalBounds())) {
		playerCollision = true;
	} else {
		playerCollision = false;
	}
}

bool Player::testCollision(sf::RectangleShape wall) {
	if (sprite.getGlobalBounds().intersects(wall.getGlobalBounds())) {
		wallCollision = true;
	} else {
		wallCollision = false;
	}
	return wallCollision;
}
void Player::draw() {
	data->window.draw(sprite);
}
void Player::update() {
	move();
	friction();
	if (playerCollision || wallCollision) {
		velocity.x = -velocity.x*1.25;
		velocity.y = -velocity.y*1.25;
	}
	sprite.setTexture(facing[currentDir]);
	sprite.move(velocity.x * data->dt * multiplier,
			velocity.y * data->dt * multiplier);
}

