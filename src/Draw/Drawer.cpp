#include "Draw/Drawer.hpp"
#include "Draw/DrawStrategy.hpp"

std::map<int, DrawStrategy*> Drawer::drawStrategies = std::map<int, DrawStrategy*>();
int Drawer::idGen = 0;

int Drawer::addDrawStrategy(DrawStrategy* drawStrategy) {
    idGen++;
    drawStrategies.insert({idGen, drawStrategy});
    return idGen;
}

void Drawer::removeDrawStrategy(int id) {
    drawStrategies.erase(id);
}

void Drawer::flush(sf::RenderWindow& window) {
    for (std::pair<int, DrawStrategy*> element : drawStrategies) {
        element.second->draw(window);
    }
}