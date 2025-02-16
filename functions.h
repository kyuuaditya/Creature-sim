#pragma once
#include <iostream>

class functions {
public:
    int assign_food(int terrain_type);
    int assign_water(int terrain_type);
    int terrain_type_buff_calculator(int terrain);
    int initialize_food_level(int food_type, int terrain_type);
    int assign_food_regen(int food_type);
};