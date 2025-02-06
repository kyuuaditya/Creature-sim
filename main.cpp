#include <sfml/Graphics.hpp>
#include <iostream>
#include <vector>

int main() {
    // Load the terrain map
    sf::Image terrain_map;
    if (terrain_map.loadFromFile("terrain_map.png")) {
        std::cerr << "terrain map loaded" << std::endl;
    }
    else {
        std::cerr << "failed to load terrain_map.png" << std::endl;
    }

    // Get the terrain map size
    sf::Vector2u terrain_map_size = terrain_map.getSize();

    // make the 3d terrain grid
    static const int grid_size_x = terrain_map_size.x;
    static const int grid_size_y = terrain_map_size.y;
    static const int grid_size_z = 4; // 0 = food type, 1 = water type, 2 = terrain type , 3 = food level
    int terrain[grid_size_x][grid_size_y][grid_size_z] = { 0 };

    // insert data in the terrain array
    for (unsigned int y = 0; y < terrain_map_size.y;y++) {
        for (unsigned int x = 0; x < terrain_map_size.x;x++) {
            sf::Color pixel = terrain_map.getPixel(x, y);
            if (pixel.r == 168 && pixel.g == 230 && pixel.b == 29) {
                terrain[x][y][2] = 0; // normal terrain
            }
            else if (pixel.r == 255 && pixel.g == 242 && pixel.b == 0) {
                terrain[x][y][2] = 1; // desert terrain
            }
            else if (pixel.r == 34 && pixel.g == 177 && pixel.b == 76) {
                terrain[x][y][2] = 2; // forest terrain
            }
            else if (pixel.r == 0 && pixel.g == 183 && pixel.b == 239) {
                terrain[x][y][2] = 3; // snow terrain
            }
            else if (pixel.r == 156 && pixel.g == 90 && pixel.b == 60) {
                terrain[x][y][2] = 4; // water terrain
            }
        }
    }

    // make the main array of creatures and their properties
    // x = creature number, 0 = x_cordinates, 2 = y_cordinates, 3 = food, 4 = water, 5 = health, 6 = age
    std::vector<std::vector<int>> creatures;

    int tile_size = 40;

    int window_size_x = grid_size_x * tile_size;
    int window_size_y = grid_size_y * tile_size;

    // display window setup
    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;
    sf::RenderWindow window(sf::VideoMode(window_size_x, window_size_y), "Creature Sim");
    window.setFramerateLimit(144); // set frame rate limit
    window.setVerticalSyncEnabled(true); // enable vertical sync


    // main loop
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
            if (event.type == sf::Event::KeyPressed) {
                if (event.key.code == sf::Keyboard::Escape) {
                    window.close();
                }
            }
        }
        window.clear();
        // displaying the terrain map
        for (unsigned int y = 0; y < terrain_map_size.y;y++) {
            for (unsigned int x = 0; x < terrain_map_size.x;x++) {
                sf::RectangleShape rectangle(sf::Vector2f(tile_size - 2, tile_size - 2));
                rectangle.setPosition(x * tile_size + 1, y * tile_size + 1);
                if (terrain[x][y][2] == 0) {
                    rectangle.setFillColor(sf::Color(168, 230, 29));
                }
                else if (terrain[x][y][2] == 1) {
                    rectangle.setFillColor(sf::Color(255, 242, 0));
                }
                else if (terrain[x][y][2] == 2) {
                    rectangle.setFillColor(sf::Color(34, 177, 76));
                }
                else if (terrain[x][y][2] == 3) {
                    rectangle.setFillColor(sf::Color(0, 183, 239));
                }
                else if (terrain[x][y][2] == 4) {
                    rectangle.setFillColor(sf::Color(156, 90, 60));
                }
                window.draw(rectangle);
            }
        }
        window.display();
    }
}