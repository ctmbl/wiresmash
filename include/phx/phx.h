#ifndef PHX_PHX_H
#define PHX_PHX_H

#include <tuple>
#include <vector>
#include <iostream>
#include "entity/strategies/physical_entity.h"

// Constrain
// vitessePersoMax < longeurPersoMin

// dependencies
class Scene;

typedef std::pair<unsigned int, unsigned int> Vec;
typedef std::pair<int, int> Vel;

/** 
 * Update each Entity in the Scene
 */
void update(Scene);

Vel updateCinematics(PhysicalEntity const);
void updateCollision(Scene);

class Cinematics {
private:
    Vec m_pos;
    Vel m_vel;
};

class Hitbox {
private:
    std::vector<Vec> m_vertices;
};

enum Force {weight};

#endif
