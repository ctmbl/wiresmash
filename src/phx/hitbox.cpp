#include "./../../include/phx/hitbox.h"

// size default value is 2
Hitbox::Hitbox(unsigned int size){
    s = size;
    tl = br = {0, -1};
}

// size default value is 2
Hitbox::Hitbox(unsigned int H[][2], unsigned int size){
    s = size;
    tl = { H[0][0], -1-H[0][1] };
    br = { H[1][0], -1-H[1][1] };
}

void Hitbox::setPoint(unsigned int i, unsigned int x, unsigned int y){
    if (i == 0){
        tl = {x, -1-y};
    } else {
        br = {x, -1-y};
    }
}