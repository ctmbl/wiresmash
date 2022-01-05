#ifndef DRAW_STRATEGY_HPP
#define DRAW_STRATEGY_HPP

#include <SFML/Graphics.hpp>
#include <string>
#include <exception>

class Drawer;

class DrawStrategy
{
protected:
    sf::Texture texture;
    sf::Sprite sprite;
    sf::Vector2f imagePosition;
    int associatedId;
public:
    DrawStrategy(std::string imageFile);
    DrawStrategy(std::string imageFile, sf::Vector2f imagePosition);
    ~DrawStrategy();

    sf::Vector2f getImagePosition();

    void setImagePosition(sf::Vector2f imagePosition);
    void translateImagePosition(sf::Vector2f translation);

    void draw(sf::RenderWindow& window);
};

#endif