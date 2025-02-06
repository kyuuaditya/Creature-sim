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

    sf::Texture plains_bushes;
    sf::Texture desert_bushes;
    sf::Texture jungle_bushes;

    sf::Texture plains_bushes_fruits;
    sf::Texture desert_bushes_fruits;
    sf::Texture jungle_bushes_fruits;
    sf::Texture hilly_bushes_fruits;

    int size_64 = 64;
    int size_32 = 32;

public:
    sf::Sprite plains_tree_sprite;
    sf::Sprite jungle_tree_sprite;
    sf::Sprite snow_tree_sprite;
    sf::Sprite hilly_tree_sprite;

    sf::Sprite plains_tree_sprite_fruits;
    sf::Sprite jungle_tree_sprite_fruits;
    sf::Sprite snow_tree_sprite_fruits;
    sf::Sprite hilly_tree_sprite_fruits;

    sf::Sprite plains_bushes_sprite;
    sf::Sprite desert_bushes_sprite;
    sf::Sprite jungle_bushes_sprite;

    sf::Sprite plains_bushes_sprite_fruits;
    sf::Sprite desert_bushes_sprite_fruits;
    sf::Sprite jungle_bushes_sprite_fruits;
    sf::Sprite hilly_bushes_sprite_fruits;

public:
    void Load();
    void Draw(sf::RenderWindow& window, int terrain_type, int food_type, int i, int j);
};