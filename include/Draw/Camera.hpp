#ifndef CAMERA_HPP
#define CAMERA_HPP

#include <SFML/Graphics.hpp>
#include <iostream>
#include <cmath>

class Camera
{
private:
    static sf::Vector2f center;
    static int zoom;
    static sf::Vector2f targetCenter;
    static float speed;
    static bool isTravellingInstantly;

public:
    static int getZoom();
    static sf::Vector2f getCenter();

    static void setZoom(int zoom);
    static void setTargetCenter(sf::Vector2f targetCenter);
    static void setSpeed(int speed);
    static void setIsTravellingInstantly(bool isTravellingInstantly);

    static void moveCenter(sf::Vector2f translation);

    static void flush(sf::RenderWindow& window);

};


#endif