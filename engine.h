#ifndef engine_h
#define engine_h

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <unistd.h>

using namespace std;

#define HEIGHT 13
#define WIDTH 39

short game[HEIGHT][WIDTH] = {};

short X = 3;
short Y = 10;

enum id {
    sky = -16,
    mario = 0,
    brick = 1,
    breakable_b = 2,
    question_b = 3,
    tube = 4
};

string level_1;

void build() {
    //Map generation
    ifstream map("level_1.txt", ios::in);

    stringstream ss;
    ss << map.rdbuf();
    level_1 = ss.str();
    level_1.erase(remove(level_1.begin(), level_1.end(), '\n'), level_1.end());
}

void action() {
    game[Y][X] = mario;
}
void gravity() {
    if(game[Y+1][X] == sky) Y++;
}

void render() {
    for (unsigned short i = 0, k = 0; i < HEIGHT; i++)
        for (unsigned short j = 0; j < WIDTH; j++)
            game[i][j] = level_1.at(k++) - 48;
    action();
    gravity();
    system("clear");
    cout << "\n\n\n\n\n";

    for (unsigned short i = 0; i < HEIGHT; i++) {
        cout << "\u001b[49m ";
        for (unsigned short j = 0; j < WIDTH; j++) {
            switch(game[i][j]) {
                case sky:
                    cout << "\u001b[46m   ";
                    break;
                case mario:
                    cout << "\u001b[46m👾 ";
                    break;
                case brick:
                    cout << "\u001b[30;41m / \u001b[0m";
                    break;
                case breakable_b:
                    cout << "\u001b[30;41m O \u001b[0m";
                    break;
                case question_b:
                    cout << "\u001b[31;40m ? \u001b[0m";
                    break;
                case tube:
                    cout << "\u001b[42m   \u001b[0m";
            }
        }cout << endl;
    }
}

#endif
