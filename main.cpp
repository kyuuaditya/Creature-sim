#include <vector> 
#include <stdio.h>
#include <iostream>

using namespace std;

const int grid_x = 180;
const int grid_y = 100;
const int properties = 5;

const int creatureNo = 1000;

vector<vector<int>> creatures;
vector<vector<int>> creatures_next;

int map_grid[grid_x][grid_y][properties] = { 0 };

int main() {

    // Copy the updated array to the original array
    creatures = creatures_next;

    return 0;
}
