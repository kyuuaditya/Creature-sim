#include <math.h>
#include <stdio.h>

#include <iostream>
using namespace std;

const int creatures_x = 180;
const int creatures_y = 100;

const int properties = 5;

int creatures[creatures_x][creatures_y][properties];
int creatures_next[creatures_x][creatures_y][properties];

int main() {
    // copy the updated array to the origianl array
    for (int x = 0; x < creatures_x; x++) {
        for (int y = 0; y < creatures_y; y++) {
            for (int p = 0; p < properties; p++) {
                creatures[x][y][p] = creatures_next[x][y][p];
            }
        }
    }
}
