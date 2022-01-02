#include "phx/phx.h"

Vel updateCinematics(PhysicalEntity const ett) {
  Vel correction (0,0); 
  Vel ett.getVelocity();

  // TODO: get fps here for integration ?
  // Must be a integer ??
  int time(1);
  int g = 10;

  correction.second += g*time;

  return correction; 
}

