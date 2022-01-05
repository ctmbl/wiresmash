#ifndef DRAWER_HPP
#define DRAWER_HPP

#include <vector>
#include <SFML/Graphics.hpp>

class DrawStrategy;

class Drawer
{
private:
    static std::vector<DrawStrategy*> drawStrategies;
public:
    int static addDrawStrategy(DrawStrategy* drawStrategy);
    void static removeDrawStrategy(int id);

    static void flush(sf::RenderWindow& window);
};
#endif