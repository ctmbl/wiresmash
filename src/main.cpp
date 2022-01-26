#include <iostream>
using namespace std;

#include <SFML/Graphics.hpp>
#include <entity/strategies/controllable.h>
/*
#include "Conductor.h"
*/

void print(){
  std::cout << "TEST";
}

int main(){
  /*
  sf::RenderWindow window(sf::VideoMode(800, 450), "fil rouge!");
  window.setVerticalSyncEnabled(true);
  window.setFramerateLimit(60);
  */
  //Conductor conductor;

  Controllable c;

  std::array<unsigned short,256> test;

  std::function<void ()> f = [] () { std::cout << "Yay \n";};

  std::function<void ()> g = [] () { std::cout << "blblbll \n";};

  c.addCallBack(test, f);
  c.addCallBack(test, g);
  c.addCallBack(test,f);

  c.flush(test);

  /*
  while (window.isOpen()){
    sf::Event event;
    while (window.pollEvent(event)){
      switch (event.type){
        case sf::Event::Closed:
          window.close();
          break;
        case sf::Event::KeyReleased:
          // TODO
          break;
        default:
          break;
      }
    }

    // objects update.
   // conductor.flush()
    window.clear(sf::Color::Black);
    // TODO
    window.display();
  }
  */
  return 0;
}

