#include "textures.h"


void textures::Load() {
    // textures for trees
    if (plains_tree.loadFromFile("assets/trees/plains_tree.png")) { // plains tree
        plains_tree_sprite.setTexture(plains_tree);
        plains_tree_sprite.setTextureRect(sf::IntRect(0, 0, size_64, size_64));
        std::cout << "plains_tree texture loaded!" << std::endl;
    }
    else {
        std::cout << "plains_tree texture failed to loaded!" << std::endl;
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

    // textures for trees with fruits
    if (plains_tree_fruits.loadFromFile("assets/trees/plains_tree_fruits.png")) { // plains tree with fruits
        plains_tree_sprite_fruits.setTexture(plains_tree_fruits);
        plains_tree_sprite_fruits.setTextureRect(sf::IntRect(0, 0, 80, 80));
        std::cout << "plains_tree_fruits texture loaded!" << std::endl;
        plains_tree_sprite_fruits.setScale(0.8, 0.8);
    }
    else {
        std::cout << "plains_tree_fruits texture failed to loaded!" << std::endl;
    }
    if (jungle_tree_fruits.loadFromFile("assets/trees/jungle_tree_fruits.png")) { // jungle tree with fruits
        jungle_tree_sprite_fruits.setTexture(jungle_tree_fruits);
        jungle_tree_sprite_fruits.setTextureRect(sf::IntRect(0, 0, size_64, size_64));
        std::cout << "jungle_tree_fruits texture loaded!" << std::endl;
    }
    else {
        std::cout << "jungle_tree_fruits texture failed to loaded!" << std::endl;
    }
    if (snow_tree_fruits.loadFromFile("assets/trees/snow_tree_fruits.png")) { // snow tree with fruits
        snow_tree_sprite_fruits.setTexture(snow_tree_fruits);
        snow_tree_sprite_fruits.setTextureRect(sf::IntRect(0, 0, size_64, size_64));
        std::cout << "snow_tree_fruits texture loaded!" << std::endl;
    }
    else {
        std::cout << "snow_tree_fruits texture failed to loaded!" << std::endl;
    }
    if (hilly_tree_fruits.loadFromFile("assets/trees/hilly_tree_fruits.png")) { // hilly tree with fruits
        hilly_tree_sprite_fruits.setTexture(hilly_tree_fruits);
        hilly_tree_sprite_fruits.setTextureRect(sf::IntRect(0, 0, size_64, size_64));
        std::cout << "hilly_tree_fruits texture loaded!" << std::endl;
    }
    else {
        std::cout << "hilly_tree_fruits texture failed to loaded!" << std::endl;
    }

    // textures for bushes
    if (plains_bushes.loadFromFile("assets/bushes/plains_bushes.png")) { // plains bushes with fruits
        plains_bushes_sprite.setTexture(plains_bushes);
        plains_bushes_sprite.setTextureRect(sf::IntRect(0, 0, size_32, size_32));
        std::cout << "plains_bushes texture loaded!" << std::endl;
    }
    else {
        std::cout << "plains_bushes texture failed to loaded!" << std::endl;
    }
    if (desert_bushes.loadFromFile("assets/bushes/desert_bushes.png")) { // desert bushes
        desert_bushes_sprite.setTexture(desert_bushes);
        desert_bushes_sprite.setTextureRect(sf::IntRect(0, 0, size_32, size_32));
        std::cout << "desert_bushes texture loaded!" << std::endl;
    }
    else {
        std::cout << "desert_bushes texture failed to loaded!" << std::endl;
    }
    if (jungle_bushes.loadFromFile("assets/bushes/jungle_bushes.png")) { // jungle bushes
        jungle_bushes_sprite.setTexture(jungle_bushes);
        jungle_bushes_sprite.setTextureRect(sf::IntRect(0, 0, size_32, size_32));
        std::cout << "jungle_bushes texture loaded!" << std::endl;
    }
    else {
        std::cout << "jungle_bushes texture failed to loaded!" << std::endl;
    }

    // textures for bushes with fruits
    if (plains_bushes_fruits.loadFromFile("assets/bushes/plains_bushes_fruits.png")) { // plains bushes with fruits
        plains_bushes_sprite_fruits.setTexture(plains_bushes_fruits);
        plains_bushes_sprite_fruits.setTextureRect(sf::IntRect(0, 0, size_32, size_32));
        std::cout << "plains_bushes_fruits texture loaded!" << std::endl;
    }
    else {
        std::cout << "plains_bushes_fruits texture failed to loaded!" << std::endl;
    }
    if (desert_bushes_fruits.loadFromFile("assets/bushes/desert_bushes_fruits.png")) { // desert bushes
        desert_bushes_sprite_fruits.setTexture(desert_bushes_fruits);
        desert_bushes_sprite_fruits.setTextureRect(sf::IntRect(0, 0, size_32, size_32));
        std::cout << "desert_bushes_fruits texture loaded!" << std::endl;
    }
    else {
        std::cout << "desert_bushes_fruits texture failed to loaded!" << std::endl;
    }
    if (jungle_bushes_fruits.loadFromFile("assets/bushes/jungle_bushes_fruits.png")) { // jungle bushes
        jungle_bushes_sprite_fruits.setTexture(jungle_bushes_fruits);
        jungle_bushes_sprite_fruits.setTextureRect(sf::IntRect(0, 0, size_32, size_32));
        std::cout << "jungle_bushes_fruits texture loaded!" << std::endl;
    }
    else {
        std::cout << "jungle_bushes_fruits texture failed to loaded!" << std::endl;
    }
    if (hilly_bushes_fruits.loadFromFile("assets/bushes/hilly_bushes_fruits.png")) { // jungle bushes
        hilly_bushes_sprite_fruits.setTexture(hilly_bushes_fruits);
        hilly_bushes_sprite_fruits.setTextureRect(sf::IntRect(0, 0, size_32, size_32));
        std::cout << "hilly_bushes_fruits texture loaded!" << std::endl;
    }
    else {
        std::cout << "hilly_bushes_fruits texture failed to loaded!" << std::endl;
    }
}

void textures::Draw(sf::RenderWindow& window, int terrain_type, int food_type, int i, int j) {
    if (terrain_type == 0) { // plains
        if (food_type == 0) { // tree
            plains_tree_sprite.setPosition(sf::Vector2f(i * 64, j * 64));
            window.draw(plains_tree_sprite);
        }
        if (food_type == 1) { // tree with fruits
            plains_tree_sprite_fruits.setPosition(sf::Vector2f(i * 64, j * 64));
            window.draw(plains_tree_sprite_fruits);
        }
        if (food_type == 2) { // bush
            plains_bushes_sprite.setPosition(sf::Vector2f(i * 64 + 16, j * 64 + 16));
            window.draw(plains_bushes_sprite);
        }
        if (food_type == 3) { // bush with fruits
            plains_bushes_sprite_fruits.setPosition(sf::Vector2f(i * 64 + 16, j * 64 + 16));
            window.draw(plains_bushes_sprite_fruits);
        }
    }
    if (terrain_type == 1) { // desert
        if (food_type == 2) { // bush
            desert_bushes_sprite.setPosition(sf::Vector2f(i * 64 + 16, j * 64 + 16));
            window.draw(desert_bushes_sprite);
        }
        if (food_type == 3) { // bush with fruits
            desert_bushes_sprite_fruits.setPosition(sf::Vector2f(i * 64 + 16, j * 64 + 16));
            window.draw(desert_bushes_sprite_fruits);
        }
    }
    if (terrain_type == 2) { // jungle
        if (food_type == 0) { // tree
            jungle_tree_sprite.setPosition(sf::Vector2f(i * 64, j * 64));
            window.draw(jungle_tree_sprite);
        }
        if (food_type == 1) { // tree with fruits
            jungle_tree_sprite_fruits.setPosition(sf::Vector2f(i * 64, j * 64));
            window.draw(jungle_tree_sprite_fruits);
        }
        if (food_type == 2) { // bush
            jungle_bushes_sprite.setPosition(sf::Vector2f(i * 64 + 16, j * 64 + 16));
            window.draw(jungle_bushes_sprite);
        }
        if (food_type == 3) { // bush with fruits
            jungle_bushes_sprite_fruits.setPosition(sf::Vector2f(i * 64 + 16, j * 64 + 16));
            window.draw(jungle_bushes_sprite_fruits);
        }
    }
    if (terrain_type == 3) { // snow
        if (food_type == 0) { // tree
            snow_tree_sprite.setPosition(sf::Vector2f(i * 64, j * 64));
            window.draw(snow_tree_sprite);
        }
        if (food_type == 1) { // tree with fruits
            snow_tree_sprite_fruits.setPosition(sf::Vector2f(i * 64, j * 64));
            window.draw(snow_tree_sprite_fruits);
        }
    }
    if (terrain_type == 4) { // hilly
        if (food_type == 0) { // tree
            hilly_tree_sprite.setPosition(sf::Vector2f(i * 64, j * 64));
            window.draw(hilly_tree_sprite);
        }
        if (food_type == 1) { // tree with fruits
            hilly_tree_sprite_fruits.setPosition(sf::Vector2f(i * 64, j * 64));
            window.draw(hilly_tree_sprite_fruits);
        }
        if (food_type == 3) { // bush with fruits
            hilly_bushes_sprite_fruits.setPosition(sf::Vector2f(i * 64 + 16, j * 64 + 16));
            window.draw(hilly_bushes_sprite_fruits);
        }
    }
    // window.draw(plains_tree_sprite);
}
