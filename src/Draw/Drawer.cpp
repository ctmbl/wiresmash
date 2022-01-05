#include "Draw/Drawer.hpp"
#include "Draw/DrawStrategy.hpp"

std::vector<DrawStrategy*> Drawer::drawStrategies = std::vector<DrawStrategy*>();

int Drawer::addDrawStrategy(DrawStrategy* drawStrategy) {
    drawStrategies.push_back(drawStrategy);
    return drawStrategies.size()-1;
}

void Drawer::removeDrawStrategy(int id) {
    //TODO
}

void Drawer::flush(sf::RenderWindow& window) {
    for (DrawStrategy* drawStrategy : drawStrategies) {
        drawStrategy->draw(window);
    }
}