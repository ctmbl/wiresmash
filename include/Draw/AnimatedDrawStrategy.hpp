#ifndef ANIMATED_DRAW_STRATEGY_HPP
#define ANIMATED_DRAW_STRATEGY_HPP

#include "Draw/DrawStrategy.hpp"

class AnimatedDrawStrategy : public DrawStrategy
{
private:
    int height;
    int width;
    int nbLines;
    int currentLine;
    int currentFrame;

public:
    AnimatedDrawStrategy(std::string imageFile, int height, int width, int nbLines);
    AnimatedDrawStrategy(std::string imageFile, sf::Vector2f imagePosition, int height, int width, int nbLines);
    ~AnimatedDrawStrategy();

    void goToImage(int line, int frame);
};

#endif