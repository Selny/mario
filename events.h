#ifndef events_h
#define events_h

#include "engine.h"
#include "InputReader.h"

void control() {
    char key;
    key = getch();
    switch(key){
        case 'w':
            if (game[Y-3][X] == sky) Y--;
            break;
        case 's':
            if(game[Y+1][X] == sky) Y++;
            break;
        case 'a':
            if(game[Y][X-1] == sky) X--;
            break;
        case 'd':
            if(game[Y][X+1] == sky) X++;
            break;
    }
}



#endif
