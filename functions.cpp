#include "functions.h"

int functions::assign_food(int terrain_type) {
    if (terrain_type == 0) { // plains
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

// hardcode buff given to each type of terrain
int functions::terrain_type_buff_calculator(int terrain) {
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
int functions::initialize_food_level(int food_type, int terrain_type) {
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

int functions::assign_water(int terrain_type) {
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

int functions::assign_food_regen(int food_type) {
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