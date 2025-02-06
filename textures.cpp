#include "textures.h"


void textures::Load() {
    if (plains_tree.loadFromFile("assets/trees/plains_tree.png")) { // plains tree
        plains_tree_sprite.setTexture(plains_tree);
        plains_tree_sprite.setTextureRect(sf::IntRect(0, 0, size_64, size_64));
        std::cout << "plains_tree texture loaded!" << std::endl;
    }
    else {
        std::cout << "plains_tree texture failed to loaded!" << std::endl;
    }
    if (desert_tree.loadFromFile("assets/trees/desert_tree.png")) { // desert tree
        desert_tree_sprite.setTexture(desert_tree);
        desert_tree_sprite.setTextureRect(sf::IntRect(0, 0, size_64, size_64));
        std::cout << "desert_tree texture loaded!" << std::endl;
    }
    else {
        std::cout << "desert_tree texture failed to loaded!" << std::endl;
    }
    if (jungle_tree.loadFromFile("assets/trees/jungle_tree.png")) { // jungle tree
        jungle_tree_sprite.setTexture(jungle_tree);
        jungle_tree_sprite.setTextureRect(sf::IntRect(0, 0, size_64, size_64));
        std::cout << "jungle_tree texture loaded!" << std::endl;
    }
    else {
        std::cout << "jungle_tree texture failed to loaded!" << std::endl;
    }
    if (snow_tree.loadFromFile("assets/trees/snow_tree.png")) { // snow tree
        snow_tree_sprite.setTexture(snow_tree);
        snow_tree_sprite.setTextureRect(sf::IntRect(0, 0, size_64, size_64));
        std::cout << "snow_tree texture loaded!" << std::endl;
    }
    else {
        std::cout << "snow_tree texture failed to loaded!" << std::endl;
    }
    if (hilly_tree.loadFromFile("assets/trees/hilly_tree.png")) { // hilly tree
        hilly_tree_sprite.setTexture(hilly_tree);
        hilly_tree_sprite.setTextureRect(sf::IntRect(0, 0, size_64, size_64));
        std::cout << "hilly_tree texture loaded!" << std::endl;
    }
    else {
        std::cout << "hilly_tree texture failed to loaded!" << std::endl;
    }
}

void textures::Draw(sf::RenderWindow& window, int terrain_type, int food_type, int i, int j) {
    if (terrain_type == 0) { // plains
        if (food_type == 0) { // tree
            plains_tree_sprite.setPosition(sf::Vector2f(i * 64, j * 64));
            window.draw(plains_tree_sprite);
        }
    }
    if (terrain_type == 1) { // desert
        if (food_type == 0) { // tree
            desert_tree_sprite.setPosition(sf::Vector2f(i * 64, j * 64));
            window.draw(desert_tree_sprite);
        }
    }
    if (terrain_type == 2) { // jungle
        if (food_type == 0) { // tree
            jungle_tree_sprite.setPosition(sf::Vector2f(i * 64, j * 64));
            window.draw(jungle_tree_sprite);
        }
    }
    if (terrain_type == 3) { // snow
        if (food_type == 0) { // tree
            snow_tree_sprite.setPosition(sf::Vector2f(i * 64, j * 64));
            window.draw(snow_tree_sprite);
        }
    }
    if (terrain_type == 4) { // hilly
        if (food_type == 0) { // tree
            hilly_tree_sprite.setPosition(sf::Vector2f(i * 64, j * 64));
            window.draw(hilly_tree_sprite);
        }
    }
    // window.draw(plains_tree_sprite);
}
