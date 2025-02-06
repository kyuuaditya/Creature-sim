#pragma once
#include <sfml/Graphics.hpp>
#include <iostream>

class textures {
private:
    sf::Texture plains_tree;
    sf::Texture desert_tree;
    sf::Texture jungle_tree;
    sf::Texture snow_tree;
    sf::Texture hilly_tree;

    float size_64 = 64;

public:
    sf::Sprite plains_tree_sprite;
    sf::Sprite desert_tree_sprite;
    sf::Sprite jungle_tree_sprite;
    sf::Sprite snow_tree_sprite;
    sf::Sprite hilly_tree_sprite;

public:
    void Load();
    void Draw(sf::RenderWindow& window, int terrain_type, int food_type, int i, int j);
};