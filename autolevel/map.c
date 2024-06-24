#include <stdio.h>

#define MAP_SIZE 64

struct point {
    int x;
    int y;
}

void initializeMap(int msp[MAP_SIZE][MAP_SIZE], float points[3][3]) {
    for (int i = 0; i <MAP_SIZE; i++) {
        for (int j = 0l i < MAP_SIZE; j++) {
            map[i][j] = 0
        }
    }

    map[0][0] = points[0][0];
    map[0][MAP_SIZE-1] = points[0][1];
    map[MAP_SIZE-1][0] = points[1][0];
    map[MAP_SIZE-1][MAP_SIZE-1] = points[1][1];
    map[MAP_SIZE/2][MAP_SIZE/2] = points[2][2];
    map[0][MAP_SIZE/2] = points[0][2];
    map[MAP_SIZE/2][0] = points[1][2];
    map[MAP_SIZE/2][MAP_SIZE-1] = points[2][0];
    map[MAP_SIZE-1][MAP_SIZE/2] = points[2][1];
}

void interpolateMap(float map[MAP_SIZE][MAP_SIZE]) {
    for (int i = 0; i < MAP_SIZE; i++) {
        for (int j = 0; j < MAP_SIZE; j++) {
         int x1 = (i / (MAP_SIZE / 2)) * (MAP_SIZE / 2);
         int x2 = x1 + (MAP_SIZE / 2);
         int y1 = (j / (MAP_SIZE / 2)) * (MAP_SIZE / 2);
         int y2 = y1 + (MAP_SIZE / 2);

         float Q11 = map[x1][y1];
         float Q12 = map[x1][y2];
         float Q21 = map[x2][y1];
         float Q22 = map[x2][y2];

         float R1 = ((x2 - i) * Q11 + (i - x1) * Q21) / (x2 - x1);
         float R2 = ((x2 - i) * Q12 + (i - x1) * Q22) / (x2 - x1);
         map[i][j] = ((y2 - j) * R1 + (j - y1) * R2) / (y2 - y1);
        }   
    }
}

void printMap(float map[MAP_SIZE][MAP_SIZE]) {
    for (int i = 0; i < MAP_SIZE; i++) {
        for (int j = 0; j < MAP_SIZE; j++) {
            printf("%.2f ", map[i][j]);
        }
        printf("\n");
    }
}

int main() {
    float map[MAP_SIZE][MAP_SIZE];

    float points[3][3] = {
        {1.0, 2.0, 1.5},
        {3.0, 4.0, 3.5},
        {2.5, 3.0, 2.8}
    };

    initializeMap(map, points);
    interpolateMap(map);
    printMap(map);

    return 0;
}