#include "engine.h"
#include "sprites.h"
#include "events.h"
#include <iostream>

using namespace std;

int main() {
    
    build();
    
    while(1){
        render();
        control();
    }
    return 0;
}

