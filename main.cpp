#include "engine.h"
#include "sprites.h"
#include "events.h"

int main() {
    
    build();
    
    while(run){
        render();
        control();
    }
    return 0;
}

