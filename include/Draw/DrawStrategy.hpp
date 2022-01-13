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
    int paralaxFactor;
    int priorityScore;
    int associatedId;
public:
    DrawStrategy(std::string imageFile);
    DrawStrategy(std::string imageFile, int paralaxFactor);
    DrawStrategy(std::string imageFile, int paralaxFactor, int priorityScore);
    DrawStrategy(std::string imageFile, sf::Vector2f imagePosition);
    DrawStrategy(std::string imageFile, sf::Vector2f imagePosition, int paralaxFactor);
    DrawStrategy(std::string imageFile, sf::Vector2f imagePosition, int paralaxFactor, int priorityScore);
    ~DrawStrategy();

    sf::Vector2f getImagePosition();
    int getParalaxFactor();
    int getPriorityScore();

    void setImagePosition(sf::Vector2f imagePosition);
    void setParalaxFactor(int paralaxFactor);
    void setPriorityScore(int priorityScore);
    void translateImagePosition(sf::Vector2f translation);

    void draw(sf::RenderWindow& window);
};

#endif