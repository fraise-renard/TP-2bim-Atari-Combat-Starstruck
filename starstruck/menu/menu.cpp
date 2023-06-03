/*
 * menu.cpp
 *
 *  Created on: 26 de mai. de 2023
 *      Author: hayde
 */
#include <iostream>
#include "screen/screen.hpp"
#include "Menu.hpp"
#include <iostream>

//Fornece altura e largura da janela e incializa os textos do menu
Menu::Menu(float width, float height){

	this -> width = width;
	this -> height = height;

	font.loadFromFile("assets/ARIAL.ttf");
	//Error catch
	if (!font.loadFromFile("assets/ARIAL.ttf")) {
		std::cout << "Error loading font";
	}

	sf::FloatRect textRect; //limites do texto

	//Definicao de opcoes do menu
	menu[0].setString("Play");
	menu[1].setString("Options");
	menu[2].setString("Exit");

	for (int i = 0; i < 3; i++) {
		menu[i].setCharacterSize(56);
		menu[i].setFont(font);
		menu[i].setFillColor(sf::Color::Black);
		textRect = menu[i].getLocalBounds();
		menu[i].setOrigin(textRect.width / 2, textRect.height / 2); //origem no meio do texto
	}

}

//Desenha os textos
void Menu::draw(sf::RenderWindow &window) {

	if(inScreen){
		int pos = -100; //para as opcoes ficarem embaixo da outra

			for (int i = 0; i < 3; i++) {
				menu[i].setPosition(width / 2, (height / 2)+pos);
				pos += 100;
				window.draw(menu[i]);
			}
	}

}

/*void key_manager(Menu menu, sf::Event event) {
	switch (event.type) {
	case sf::Event::KeyReleased:
		switch (event.key.code) {
		case sf::Keyboard::Up:
			menu.move_up();
			break;
		case sf::Keyboard::Down:
			menu.move_down();
			break;
		}
		break;
	}
*/

void Menu::move_up() {
	if (selected_index - 1 >= 0) { //só move pra cima se opcao 1, 2 ou 3 tiverem selecionadas
		menu[selected_index].setFillColor(sf::Color::Black); //desseleciona index atual
		selected_index--; //sobe o vetor de opcoes, min = 0
		menu[selected_index].setFillColor(sf::Color::Red); //seleciona o novo index
	}
}

void Menu::move_down() {
	if (selected_index + 1 <= 3) { //só move pra baixo se opcao 0, 1 ou 2 tiverem selecionadas
		menu[selected_index].setFillColor(sf::Color::Black); //desseleciona index atual
		selected_index++; //desce o vetor de opcoes, max = 3
		menu[selected_index].setFillColor(sf::Color::Red); //seleciona o novo index
	}
}
