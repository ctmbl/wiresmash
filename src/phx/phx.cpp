#include "phx/phx.h"
#include <vector>



Vel updateCinematics(PhysicalEntity const ett) {
  Vel correction (0,0); 
  Vel ett.getVelocity();
  std::vector<Strength> strengths = ett.getStrength(); 

  // TODO: get fps here for integration ?
  // Must be a integer ??
  int sigma = 0;
  for (auto strength: strengths) {
    switch(strength) {
      case weight:
        sigma += -10;
        break;

      default:
        break;
    }
  } 

  return correction; 
}

