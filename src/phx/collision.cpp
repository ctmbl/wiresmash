#include "phx/collision.h"
using namespace std;

pair<int, int> checkCollisionEntities(Entity* ett1, Entity* ett2){
    Hitbox hbx = ((PhysicalEntity*)(ett1->getStrategy(Entity::PHYSICAL)))->getHitbox();
    unsigned int minx1 = bx.getX();
    unsigned int maxx1 = minx1 + bx.getL();
    unsigned int miny1 = bx.getY();
    unsigned int maxy1 = miny1 + bx.getH();

    bx = ett2->hbx;
    unsigned int minx2 = bx.getX();
    unsigned int maxx2 = minx2 + bx.getL();
    unsigned int miny2 = bx.getY();
    unsigned int maxy2 = miny2 + bx.getH();

    int xcol = 0;
    int ycol = 0;

    if(maxx1>minx2 && maxx2 > minx1){
        xcol = -min(maxx2 - minx1, maxx1 - minx2);
    }
    if(maxy1>miny2 && maxy2 > miny1){
        ycol = -min(maxy2 - miny1, maxy1 - miny2);
    }

    return make_pair(xcol, ycol);
}

vector<Collider> checkCollision(std::vector<Entity*> collEtt){
    int nbEtt = collEtt.size();
    pair<int, int> colVect;
    Collider collider;
    vector<Collider> collColl = vector<Collider>();
    for(int i = 0; i < nbEtt - 1; i++){
        for(int j = i+1; i < nbEtt - 1; i++){
            colVect = checkCollisionEntities(collEtt.at(i), collEtt.at(j));
            if(colVect.first != 0 || colVect.second != 0){
                collider = Collider();
                collider.colVector = colVect;
                collider.ettColliding = &(collEtt.at(0));
                collider.ettInto = &(collEtt.at(1));
                collColl.push_back(collider);
            }
        }
    }
    return collColl;
}
