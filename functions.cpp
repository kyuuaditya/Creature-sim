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