#include <math.h>
#include <vector> 
#include <stdio.h>
#include <iostream>

using namespace std;

const int grid_x = 180;
const int grid_y = 100;
const int properties = 1;

const int creatureNo = 1000;

vector<vector<int>> creatures;
vector<vector<int>> creatures_next;

int map_grid[grid_x][grid_y][properties] = { 0 };

double perlinNoise(double x, double y) {
    return (sin(x) + cos(y)) / 2.0;
}

void generateTerrain(int seed) {
    srand(seed);
    for (int x = 0;x < grid_x;++x) {
        for (int y = 0;grid_y;++y) {
            double nx = (double)x / grid_x - 0.5, ny = (double)y / grid_y - 0.5;
            map_grid[x][y][0] = (int)(perlinNoise(nx, ny) * 100);
        }
    }
}

int main() {
    int seed = 69;

    // generates terrain based on seed
    generateTerrain(seed);

    // Copy the updated array to the original array
    creatures = creatures_next;

    return 0;

}
