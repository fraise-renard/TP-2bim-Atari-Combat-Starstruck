/*
 * mapa.cpp
 *
 *  Created on: 11 de jun. de 2023
 *      Author: Karina
 */

#include <SFML/Graphics.hpp>

int main()
{
    // Janela do SFML
    sf::RenderWindow window(sf::VideoMode(800, 600), "Mapa com Tilesets");

    // Carregar tileset
    sf::Texture tileset;
    if (!tileset.loadFromFile("tileset.png")) {
        return -1; // Retornar erro se não conseguir carregar o tileset
    }

    // Criar sprite do tileset
    sf::Sprite sprite;
    sprite.setTexture(tileset);

    // Definir tamanho dos tiles
    int tileSize = 32;

    // Definir mapa de exemplo (representado por uma matriz)
    int mapWidth = 10;
    int mapHeight = 8;
    int map[8][10] = {
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
        {1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
        {1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
        {1, 0, 0, 1, 1, 1, 1, 0, 0, 1},
        {1, 0, 0, 1, 1, 1, 1, 0, 0, 1},
        {1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
        {1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 1}
    };

    // Loop principal
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        // Limpar a janela
        window.clear();

        // Desenhar o mapa usando o tileset
        for (int y = 0; y < mapHeight; y++) {
            for (int x = 0; x < mapWidth; x++) {
                // Calcular a posição do sprite do tile atual
                sprite.setPosition(x * tileSize, y * tileSize);

                // Definir a região do tileset que será desenhada
                int tileID = map[y][x];
                int tilesetColumns = tileset.getSize().x / tileSize;
                int tilesetRow = tileID / tilesetColumns;
                int tilesetCol = tileID % tilesetColumns;
                sf::IntRect tileRect(tilesetCol * tileSize, tilesetRow * tileSize, tileSize, tileSize);
                sprite.setTextureRect(tileRect);

                // Desenhar o sprite na janela
                window.draw(sprite);
            }
        }

        // Exibir a janela
        window.display();
    }

    return 0;
}



