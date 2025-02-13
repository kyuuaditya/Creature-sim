#include <sfml/Graphics.hpp>
#include <iostream>
#include <vector>
#include "textures.h"

int debugging = 0;

int assign_food(int terrain_type) {
    if (terrain_type == 0) { // plains
        if (debugging)
            std::cout << "assigned plains" << std::endl;
        int roullete = rand() % 100;
        if (roullete < 5) {
            return 0; // Tree
        }
        else if (roullete < 10) {
            return 1; // Tree with fruits
        }
        else if (roullete < 25) {
            return 2; // Bush
        }
        else if (roullete < 35) {
            return 3; // Bush with fruits
        }
        else {
            return 6; // Nothing
        }
    }
    else if (terrain_type == 1) { // desert
        if (debugging)
            std::cout << "assigned desert" << std::endl;
        int roullete = rand() % 100;
        if (roullete < 10) {
            return 2; // bush
        }
        else if (roullete < 20) {
            return 3; // bush with fruits (cactus)
        }
        else {
            return 6; // nothing
        }
    }
    else if (terrain_type == 2) { // jungle
        if (debugging)
            std::cout << "assigned jungle" << std::endl;
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
        if (debugging)
            std::cout << "assigned snow" << std::endl;
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
        if (debugging)
            std::cout << "assigned hilly" << std::endl;
        int roullete = rand() % 100;
        if (roullete < 10) {
            return 0; // Tree
        }
        else if (roullete < 30) {
            return 1; // Tree with fruits
        }
        else if (roullete < 42) {
            return 3; // Bush with fruits
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

// hardcode buff given to each type of terrain
int terrain_type_buff_calculator(int terrain) {
    if (terrain == 0) {
        return 0;
    }
    else if (terrain == 1) {
        return -1;
    }
    else if (terrain == 2) {
        return 1;
    }
    else if (terrain == 3) {
        return -2;
    }
    else if (terrain == 4) {
        return 1;
    }
    else {
        return 0;
    }
}

// initialize food level based on terrain and food type
int initialize_food_level(int food_type, int terrain_type) {
    if (food_type == 0) {
        return 8 + terrain_type_buff_calculator(terrain_type);
    }
    else if (food_type == 1) {
        return 5 + terrain_type_buff_calculator(terrain_type);
    }
    else if (food_type == 2) {
        return 3 + terrain_type_buff_calculator(terrain_type);
    }
    else if (food_type == 3) {
        return 2 + terrain_type_buff_calculator(terrain_type);
    }
    else {
        return 0;
    }
}

int assign_food_regen(int food_type) {
    if (food_type == 0) {
        return 1;
    }
    else if (food_type == 1) {
        return 1;
    }
    else if (food_type == 2) {
        return 2;
    }
    else if (food_type == 3) {
        return 2;
    }
    else {
        return 0;
    }
}


int main() {
    // for randomization
    srand(time(0));

    // Load the terrain map
    sf::Image terrain_map;
    if (terrain_map.loadFromFile("terrain_map.png")) {
        std::cerr << "terrain map loaded" << std::endl;
    }
    else {
        std::cerr << "failed to load terrain_map.png" << std::endl;
    }
    class textures textures;
    textures.Load();

    // Get the terrain map size
    sf::Vector2u terrain_map_size = terrain_map.getSize();

    // make the 3d terrain grid
    static const int grid_size_x = terrain_map_size.x;
    static const int grid_size_y = terrain_map_size.y;
    static const int grid_size_z = 5; // 0 = food type, 1 = water type, 2 = terrain type , 3 = food level, 4 = food regen counter
    int terrain[grid_size_x][grid_size_y][grid_size_z] = { { { 0 } } };

    int terrain_type = -1;
    int food_type = -1;
    // insert data in the terrain array
    for (unsigned int x = 0; x < terrain_map_size.x;x++) {
        for (unsigned int y = 0; y < terrain_map_size.y;y++) {
            sf::Color pixel = terrain_map.getPixel(x, y);
            if (pixel.r == 168 && pixel.g == 230 && pixel.b == 29) {
                terrain_type = 0;
            }
            else if (pixel.r == 255 && pixel.g == 242 && pixel.b == 0) {
                terrain_type = 1;
            }
            else if (pixel.r == 34 && pixel.g == 177 && pixel.b == 76) {
                terrain_type = 2;
            }
            else if (pixel.r == 0 && pixel.g == 183 && pixel.b == 239) {
                terrain_type = 3;
            }
            else if (pixel.r == 156 && pixel.g == 90 && pixel.b == 60) {
                terrain_type = 4;
            }
            else {
                std::cout << "miss-colored pixel at: " << x << ", " << y << std::endl;
            }
            terrain[x][y][2] = terrain_type; // desert terrain
            terrain[x][y][0] = assign_food(terrain_type);
            terrain[x][y][1] = assign_water(terrain_type);
            food_type = terrain[x][y][0];
            terrain[x][y][3] = initialize_food_level(food_type, terrain_type);
            terrain[x][y][4] = assign_food_regen(food_type); // food regen counter
            // std::cout << "After assignment: terrain[" << x << "][" << y << "][0] = " << terrain[x][y][0] << std::endl;
        }
        // for (unsigned int x = 0; x < terrain_map_size.x;x++) {
        //     std::cout << terrain[x][0][0] << terrain[x][0][2] << terrain[x][0][3] << terrain[x][0][4] << " ";
        // }
        // std::cout << std::endl;
    }

    // printing the holy data
    // if (go_next_itr == 1) {
    // std::cout << "food_level " << "max_food_level " << "food_type " << "terrain_type " << std::endl;
    // for (unsigned int i = 0;i < terrain_map_size.x;i++) {
    //     for (unsigned int j = 0;j < terrain_map_size.y;j++) {
    //         std::cout << terrain[i][j][0] << terrain[i][j][2] << terrain[i][j][3] << terrain[i][j][4] << " ";
    //     }
    //     std::cout << std::endl;
    // }
    // std::cout << std::endl;
    // }

    // make the main array of creatures and their properties
    // x = creature number, 0 = x_cordinates, 2 = y_cordinates, 3 = food, 4 = water, 5 = health, 6 = age
    std::vector<std::vector<int>> creatures;

    int tile_size = 64;

    int window_size_x = grid_size_x * tile_size;
    int window_size_y = grid_size_y * tile_size;

    // display window setup
    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;
    sf::RenderWindow window(sf::VideoMode(1920, 1080), "Creature Sim", sf::Style::Fullscreen, settings);
    window.setFramerateLimit(60); // set frame rate limit
    window.setVerticalSyncEnabled(true); // enable vertical sync

    sf::sleep(sf::milliseconds(100));
    int ticks = 0;
    sf::Clock clock;
    sf::Time elapsedTime;

    // Font and text for the stat bar
    sf::Font font;
    if (!font.loadFromFile("assets/fonts/comicsans.ttf")) {
        std::cerr << "Failed to load font" << std::endl;
        return -1;
    }

    sf::Text statBar;
    statBar.setFont(font);
    statBar.setCharacterSize(24);
    statBar.setFillColor(sf::Color::White);
    statBar.setPosition(10, window.getSize().y - 30);

    int go_next_itr = 0;
    int food_reduction_counter = 0; // to be reset every 3 ticks
    int tree_fruit_counter = 0; // to be reset every 1 ticks
    int bush_fruit_counter = 0; // to be reset every 2 ticks

    // main loop
    while (window.isOpen()) {
        elapsedTime += clock.restart();
        float tick_length = 1.0f;
        if (elapsedTime.asSeconds() >= tick_length) {
            go_next_itr = 1;
            ticks++;
            elapsedTime -= sf::seconds(tick_length);
            // std::cout << "clock: " << seconds << std::endl;

            // Update stat bar text
            statBar.setString("Tick: " + std::to_string(ticks));
        }
        else {
            go_next_itr = 0;
        }

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

        // update the enviournment

        // reduce food level every 3 ticks
        if (go_next_itr == 1) {
            food_reduction_counter++;
            if (food_reduction_counter == 1) {
                for (unsigned int i = 0;i < terrain_map_size.x;i++) {
                    for (unsigned int j = 0;j < terrain_map_size.y;j++) {
                        if (terrain[i][j][3] > 0) {
                            terrain[i][j][3] -= 1;
                        }
                    }
                }
            }
            food_reduction_counter = 0;
        }

        // increase food level based on food type
        if (go_next_itr == 1) {
            tree_fruit_counter++;
            bush_fruit_counter++;
            for (unsigned int i = 0;i < terrain_map_size.x;i++) {
                for (unsigned int j = 0;j < terrain_map_size.y;j++) {
                    if (tree_fruit_counter == 1 && (terrain[i][j][0] == 0 || terrain[i][j][0] == 1)) {
                        if (terrain[i][j][3] < initialize_food_level(terrain[i][j][0], terrain[i][j][2])) {
                            terrain[i][j][3] += 1;
                        }
                    }
                    if (bush_fruit_counter == 2 && (terrain[i][j][0] == 2 || terrain[i][j][0] == 3)) {
                        if (terrain[i][j][3] < initialize_food_level(terrain[i][j][0], terrain[i][j][2])) {
                            terrain[i][j][3] += 1;
                        }
                    }
                }
            }
            if (tree_fruit_counter == 1)
                tree_fruit_counter = 0;
            if (bush_fruit_counter == 2)
                bush_fruit_counter = 0;
        }

        window.clear();
        // displaying the terrain map
        for (unsigned int x = 0; x < terrain_map_size.x;x++) {
            for (unsigned int y = 0; y < terrain_map_size.y;y++) {
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
                    rectangle.setFillColor(sf::Color(176, 110, 80));
                }
                window.draw(rectangle);
            }
        }

        // displaying the water
        for (unsigned int x = 0; x < terrain_map_size.x;x++) {
            for (unsigned int y = 0; y < terrain_map_size.y;y++) {
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

        // display food levels
        for (unsigned int i = 0;i < terrain_map_size.x;i++) {
            for (unsigned int j = 0;j < terrain_map_size.y;j++) {
                if (terrain[i][j][3] > 0) {
                    // std::cout << ((float)terrain[i][j][3] / (float)initialize_food_level(terrain[i][j][0], terrain[i][j][2])) << std::endl;
                    sf::RectangleShape border(sf::Vector2f(tile_size - 2, tile_size / 8)); // food
                    border.setPosition(i * tile_size + 1, j * tile_size + tile_size - tile_size / 8 - 1);
                    sf::RectangleShape food(sf::Vector2f((float)(tile_size - 4) * (float)((float)terrain[i][j][3] / (float)initialize_food_level(terrain[i][j][0], terrain[i][j][2])), tile_size / 8 - 3)); // food
                    food.setPosition(i * tile_size + 2, j * tile_size + tile_size - tile_size / 8);
                    border.setFillColor(sf::Color(255, 255, 255));
                    food.setFillColor(sf::Color(255, 0, 0));
                    window.draw(border);
                    window.draw(food);
                }
            }
        }


        // display the food_types
        for (unsigned int i = 0;i < terrain_map_size.x;i++) {
            for (unsigned int j = 0;j < terrain_map_size.y;j++) {
                textures.Draw(window, terrain[i][j][2], terrain[i][j][0], i, j);
            }
        }

        window.draw(statBar);
        window.display();
    }
}