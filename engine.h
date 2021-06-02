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

unsigned short run = 2;

short X = 3;
short Y = 10;

enum id {
    sky = -16,
    mario = 0,
    brick = 1,
    breakable_b = 2,
    question_b = 3,
    tube = 4,
    cloud = 5,
    turtle = 6,
    goomba = 7,
    mushroom = 8,
    ladder = 9,
    door = 52,
    flag = 54,
    gold = 55,
    line = 57,
    win = 71
};

const unsigned short stages = 6;
unsigned short stage = 0;
string maps[stages] = {};

void build() {
    //Map generation
    ifstream map_1("maps/level_1_1.txt", ios::in);
    ifstream map_2("maps/level_1_2.txt", ios::in);
    ifstream map_3("maps/level_1_3.txt", ios::in);
    ifstream map_4("maps/level_1_4.txt", ios::in);
    ifstream map_5("maps/level_1_5.txt", ios::in);
    ifstream map_s("maps/secret_level.txt", ios::in);

    //Loading maps
    stringstream ss;
    ss << map_1.rdbuf(); maps[0] = ss.str(); ss.str("");
    ss << map_2.rdbuf(); maps[1] = ss.str(); ss.str("");
    ss << map_3.rdbuf(); maps[2] = ss.str(); ss.str("");
    ss << map_4.rdbuf(); maps[3] = ss.str(); ss.str("");
    ss << map_5.rdbuf(); maps[4] = ss.str(); ss.str("");
    ss << map_s.rdbuf(); maps[5] = ss.str(); ss.str("");
    
    for (unsigned short i = 0; i < stages; i++)
    maps[i].erase(remove(maps[i].begin(), maps[i].end(), '\n'), maps[i].end());
    
}

void action() {
    game[Y][X] = mario;
}

void gravity() {
        if(game[Y+1][X] == sky) Y++;
}

void render(bool jump = false) {
    for (unsigned short i = 0, k = 0; i < HEIGHT; i++)
        for (unsigned short j = 0; j < WIDTH; j++)
            game[i][j] = maps[stage].at(k++) - 48;
    action();
    if(!jump) gravity();
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
                    cout << "\u001b[46m👽 ";
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
                    cout << "\u001b[33;42m | \u001b[0m";
                    break;
                case cloud:
                    cout << " ☁️ ";
                    break;
                case turtle:
                    cout << "🐢 ";
                    break;
                case goomba:
                    cout << "👾 ";
                    break;
                case mushroom:
                    cout << "🍄 ";
                    break;
                case ladder:
                    cout << "\u001b[30;41m o \u001b[0m";
                    break;
                case door:
                    cout << "\u001b[41m🚪 \u001b[0m";
                    break;
                case line:
                    cout << "\u001b[37;46m ⎸ ";
                    break;
                case flag:
                    cout << " 🏳 ";
                    break;
                case gold:
                    cout << " ⭐️ ";
                    break;
                case win:
                    if (run == 2) cout << "   ";
                    else cout << " 🏆";
            }
        }cout << endl;
    }
}

#endif
