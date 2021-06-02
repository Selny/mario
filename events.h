#ifndef events_h
#define events_h

#include "engine.h"
#include "InputReader.h"

auto collusion = [](auto Y, auto X) {
    return ((Y <= HEIGHT && X <= WIDTH && Y >= 0 && X >= 0)
            && (game[Y][X] == sky || (game[Y][X] > 4 && game[Y][X] != ladder)));
};

void control() {
    char key;
    key = getch();
    switch(key){
        case ' ': case 'w':
            for (unsigned short i = 0; i < 5; i++){
                if (collusion(Y-1, X)) Y-=1;
                usleep(100000);
                render(true);
                if (key == 'w' && i == 2) {
                    while(collusion(Y+1, X)){
                        usleep(80000);
                        Y++;
                        render();
                    }
                    break;
                }
            }
            break;
        case 's':
            if (stage == 1  && (X == 7 || X == 8) && Y == 6) {
                stage = 5;
                X = 8; Y = 0;
                render(true);
                while(collusion(Y+1, X)){
                    usleep(80000);
                    Y++;
                    render();
                }
            }
            else if(collusion(Y+1, X)) Y++;
            break;
        case 'a':
            if (X-2 < 0 && stage > 0) {
                --stage;
                X = WIDTH-1;
                render(true);
            }
            else if(collusion(Y, X-1)) X--;
            break;
        case 'd':
            if (X+2 > WIDTH && stage < stages-1) {
                ++stage;
                X = 0;
                render(true);
            }
            else if (stage == 5 && X == 18 && Y == 8) {
                stage = 3;
                X = 36; Y = 8;
                render(true);
            }
            else if (stage == 4 && X == 31 && Y > 10) {
                for (unsigned short x = 31; x != 9; x--) {
                    game[2][x] = sky;
                    game[2][x-1] = flag;
                    render();
                }
            }
            else if(collusion(Y, X+1)) X++;
            break;
    }
    if (stage == 4 && (X == 36|| X ==37) && (Y == 9 || Y == 10)) --run;
}

#endif
