#ifndef DRAWER_HPP
#define DRAWER_HPP

#include <map>
#include <SFML/Graphics.hpp>
#include <iostream>

class DrawStrategy;

class Drawer
{
private:
    static int idGen;
    static std::map<int, DrawStrategy*> drawStrategies;
    static sf::Vector2f center;
    static int zoom;

public:
    static const int CLOSEST_PARALAX_PLANE = 20;
    static const int FOREGROUND_PARALAX_PLANE = 10;
    static const int BACKGROUND_PARALAX_PLANE = 0;
    static const int MAX_PRIORITY_SCORE = 3;

    int static addDrawStrategy(DrawStrategy* drawStrategy);
    void static removeDrawStrategy(int id);

    static int getZoom();
    static sf::Vector2f getCenter();

    static void setZoom(int zoom);
    static void setCenter(sf::Vector2f center);

    static void moveCenter(sf::Vector2f translation);

    static void flush(sf::RenderWindow& window);
};
#endif