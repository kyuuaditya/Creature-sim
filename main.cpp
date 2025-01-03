#include <SFML/Graphics.hpp>
#include <random>
#include <iostream>

using namespace std;

int main() {

    // SFML window settings
    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;
    sf::RenderWindow window(sf::VideoMode(1280, 720), "Main menu", sf::Style::Default, settings);
    window.setFramerateLimit(144); // set frame rate limit
    window.setVerticalSyncEnabled(true); // enable vertical sync

    // initialize data
    int squareSize = 18;
    int padding = 1;
    int tileSize = squareSize + padding * 2;

    int xTiles = window.getSize().x / tileSize;
    int yTiles = window.getSize().y / tileSize;

    // Create the map with properties.
    int map[128][72][10];
    // x and y axis the first 2 and third one contains details about each tile.

    // set each tile on the map randomly to either water or land.
    for (int i = 0;i < xTiles;i++) {
        for (int j = 0;j < yTiles;j++) {
            map[i][j][0] = rand() % 16; // water or land
            map[i][j][1] = rand() % 3; // food
        }
    }

    // frames counter
    int nFrames = 0;

    // water color reducer
    int waterGradientConstant = 0; // upto 15

    while (window.isOpen()) {

        // frame counter
        nFrames++;

        // update water color every 144 frames
        if (nFrames == 144 * 1) {
            waterGradientConstant++;
        }

        // Event handling
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }

        // Draw the map
        window.clear(sf::Color::Black);

        for (int i = 0; i < xTiles; i++) {
            for (int j = 0; j < yTiles; j++) {
                // Draw the tile
                sf::RectangleShape tile(sf::Vector2f(squareSize, squareSize));
                tile.setPosition(i * tileSize + padding, j * tileSize + padding);
                // // water can dry and turn into land
                if (nFrames == 144 * 1 && map[i][j][0] < 15) {
                    map[i][j][0]++;
                }
                // if (map[x][y][0] == 0 && 1) {
                tile.setFillColor(sf::Color(map[i][j][0] * 17, 121 + map[i][j][0] * 4, 255 - (map[i][j][0] * 16)));
                // }
                // else {
                //     tile.setFillColor(sf::Color(255, 181, 15));
                // }

                window.draw(tile);
            }
        }

        for (int i = 0; i < xTiles; i++) {
            for (int j = 0;j < yTiles;j++) {
                // Draw the food
                if (map[i][j][1] == 1) {
                    sf::CircleShape food(3);
                    food.setFillColor(sf::Color::Green);
                    food.setPosition(i * tileSize + padding + 6, j * tileSize + padding + 6);
                    window.draw(food);
                }
            }
        }

        window.display();

        // reset frame counter
        if (nFrames == 144) {
            nFrames = 0;
        }
    }

    return 0;
}