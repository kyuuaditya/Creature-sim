#include <sfml/Graphics.hpp>
#include <iostream>
#include <vector>

int assign_food(int terrain_type) {
    if (terrain_type == 0) { // plains
        int roullete = rand() % 100;
        if (roullete < 5) {
            return 0; // Tree
        }
        else if (roullete < 8) {
            return 1; // Tree with fruits
        }
        else if (roullete < 23) {
            return 2; // Bush
        }
        else if (roullete < 33) {
            return 3; // Bush with fruits
        }
        else if (roullete < 35) {
            return 4; // Plants
        }
        else if (roullete < 36) {
            return 5; // Plants with fruits
        }
        else {
            return 6; // Nothing
        }
    }
    else if (terrain_type == 1) { // desert
        int roullete = rand() % 100;
        if (roullete < 10) {
            return 2; // bush
        }
        else {
            return 6; // nothing
        }
    }
    else if (terrain_type == 2) { // jungle
        int roullete = rand() % 100;
        if (roullete < 20) {
            return 0; // Tree
        }
        else if (roullete < 35) {
            return 1; // Tree with fruits
        }
        else if (roullete < 55) {
            return 2; // Bush
        }
        else if (roullete < 75) {
            return 3; // Bush with fruits
        }
        else {
            return 6; // Nothing
        }
    }
    else if (terrain_type == 3) { // snow
        int roullete = rand() % 100;
        if (roullete < 7) {
            return 0; // Tree
        }
        else if (roullete < 12) {
            return 1; // Tree with fruits
        }
        else {
            return 6; // Nothing
        }
    }
    else if (terrain_type == 4) { // hilly
        int roullete = rand() % 100;
        if (roullete < 10) {
            return 0; // Tree
        }
        else if (roullete < 30) {
            return 1; // Tree with fruits
        }
        else if (roullete < 42) {
            return 2; // Bush
        }
        else {
            return 6; // Nothing
        }
    }
    else {
        std::cout << "error in assign_food" << std::endl;
    }
    return 6;
}

int assign_water(int terrain_type) {
    int roullete = rand() % 100;
    if (terrain_type == 0) { // plains
        if (roullete < 10) {
            return 0; // water logged
        }
        else if (roullete < 85) {
            return 1; // humid
        }
        else {
            return 2; // dry
        }
    }
    else if (terrain_type == 1) {
        if (roullete < 5) {
            return 0; // water logged
        }
        else if (roullete < 15) {
            return 1; // humid
        }
        else {
            return 2; // dry
        }
    }
    else if (terrain_type == 2) {
        if (roullete < 10) {
            return 0; // water logged
        }
        else if (roullete < 95) {
            return 1; // humid
        }
        else {
            return 2; // dry
        }
    }
    else if (terrain_type == 3) {
        if (roullete < 30) {
            return 0; // water logged
        }
        else if (roullete < 40) {
            return 1; // humid
        }
        else {
            return 3; // ice
        }
    }
    else if (terrain_type == 4) {
        if (roullete < 5) {
            return 0; // water logged
        }
        else if (roullete < 95) {
            return 1; // humid
        }
        else {
            return 3; // ice
        }
    }
    else {
        std::cout << "error in assign_water" << std::endl;
    }
    return 1;
}

int main() {
    srand(time(0));
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
                terrain[x][y][0] = assign_food(0);
                terrain[x][y][1] = assign_water(0);
                terrain[x][y][2] = 0; // normal terrain
            }
            else if (pixel.r == 255 && pixel.g == 242 && pixel.b == 0) {
                terrain[x][y][0] = assign_food(1);
                terrain[x][y][1] = assign_water(1);
                terrain[x][y][2] = 1; // desert terrain
            }
            else if (pixel.r == 34 && pixel.g == 177 && pixel.b == 76) {
                terrain[x][y][0] = assign_food(2);
                terrain[x][y][1] = assign_water(2);
                terrain[x][y][2] = 2; // forest terrain
            }
            else if (pixel.r == 0 && pixel.g == 183 && pixel.b == 239) {
                terrain[x][y][0] = assign_food(3);
                terrain[x][y][1] = assign_water(3);
                terrain[x][y][2] = 3; // snow terrain
            }
            else if (pixel.r == 156 && pixel.g == 90 && pixel.b == 60) {
                terrain[x][y][0] = assign_food(4);
                terrain[x][y][1] = assign_water(4);
                terrain[x][y][2] = 4; // water terrain
            }
            else {
                std::cout << "miss-colored pixel at: " << x << ", " << y << std::endl;
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

    sf::sleep(sf::milliseconds(100));
    unsigned long long int clock = 0;
    // main loop
    while (window.isOpen()) {
        // sf::sleep(sf::milliseconds(10));
        // clock++;
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

        // displaying the foods
        for (unsigned int y = 0; y < terrain_map_size.y;y++) {
            for (unsigned int x = 0; x < terrain_map_size.x;x++) {
                sf::RectangleShape rectangle(sf::Vector2f(tile_size / 5, tile_size / 5)); // outline of food
                sf::RectangleShape food(sf::Vector2f(tile_size / 5 - 2, tile_size / 5 - 2)); // food
                rectangle.setPosition(x * tile_size + 1, y * tile_size + 1);
                food.setPosition(x * tile_size + 2, y * tile_size + 2);
                rectangle.setFillColor(sf::Color(255, 255, 255));
                if (terrain[x][y][0] == 0) {
                    food.setFillColor(sf::Color(127, 0, 127));
                }
                else if (terrain[x][y][0] == 1) {
                    food.setFillColor(sf::Color(255, 0, 0));
                }
                else if (terrain[x][y][0] == 2) {
                    food.setFillColor(sf::Color(255, 63, 0));
                }
                else if (terrain[x][y][0] == 3) {
                    food.setFillColor(sf::Color(255, 127, 0));
                }
                else if (terrain[x][y][0] == 4) {
                    food.setFillColor(sf::Color(255, 127, 255));
                }
                else if (terrain[x][y][0] == 5) {
                    food.setFillColor(sf::Color(127, 127, 127));
                }
                else if (terrain[x][y][0] == 6) {
                    food.setFillColor(sf::Color(255, 255, 255));
                }
                window.draw(rectangle);
                window.draw(food);
            }
        }
        // displaying the foods
        for (unsigned int y = 0; y < terrain_map_size.y;y++) {
            for (unsigned int x = 0; x < terrain_map_size.x;x++) {
                sf::RectangleShape rectangle(sf::Vector2f(tile_size / 5 - 1, tile_size - 2)); // outline of food
                rectangle.setPosition(x * tile_size + (tile_size - tile_size / 5), y * tile_size + 1);
                sf::RectangleShape water(sf::Vector2f(tile_size / 5 - 3, tile_size - 4)); // food
                water.setPosition(x * tile_size + (tile_size - tile_size / 5) + 1, y * tile_size + 2);
                rectangle.setFillColor(sf::Color(255, 255, 255));
                if (terrain[x][y][1] == 0) {
                    water.setFillColor(sf::Color(0, 112, 255));
                }
                else if (terrain[x][y][1] == 1) {
                    water.setFillColor(sf::Color(0, 215, 139));
                }
                else if (terrain[x][y][1] == 2) {
                    water.setFillColor(sf::Color(255, 255, 102));
                }
                else {
                    water.setFillColor(sf::Color(103, 248, 252));
                }
                window.draw(rectangle);
                window.draw(water);
            }
        }
        window.display();
    }
}