#pragma once
#include <sfml/Graphics.hpp>
#include <iostream>

class textures {
private:
    sf::Texture plains_tree;
    sf::Texture jungle_tree;
    sf::Texture snow_tree;
    sf::Texture hilly_tree;

    sf::Texture plains_tree_fruits;
    sf::Texture jungle_tree_fruits;
    sf::Texture snow_tree_fruits;
    sf::Texture hilly_tree_fruits;

    float size_64 = 64;

public:
    sf::Sprite plains_tree_sprite;
    sf::Sprite jungle_tree_sprite;
    sf::Sprite snow_tree_sprite;
    sf::Sprite hilly_tree_sprite;

    sf::Sprite plains_tree_sprite_fruits;
    sf::Sprite jungle_tree_sprite_fruits;
    sf::Sprite snow_tree_sprite_fruits;
    sf::Sprite hilly_tree_sprite_fruits;

public:
    void Load();
    void Draw(sf::RenderWindow& window, int terrain_type, int food_type, int i, int j);
};