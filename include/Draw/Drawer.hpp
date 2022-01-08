#ifndef DRAWER_HPP
#define DRAWER_HPP

#include <map>
#include <SFML/Graphics.hpp>

class DrawStrategy;

class Drawer
{
private:
    static int idGen;
    static std::map<int, DrawStrategy*> drawStrategies;
public:
    int static addDrawStrategy(DrawStrategy* drawStrategy);
    void static removeDrawStrategy(int id);

    static void flush(sf::RenderWindow& window);
};
#endif