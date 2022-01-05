#include "Draw/AnimatedDrawStrategy.hpp"

AnimatedDrawStrategy::AnimatedDrawStrategy(std::string imageFile, int height, int width, int nbLines) :
DrawStrategy(imageFile), height(height), width(width), nbLines(nbLines), currentFrame(0), currentLine(0) {
    this->sprite.setTextureRect(sf::IntRect(0, 0, width, height));
}

AnimatedDrawStrategy::AnimatedDrawStrategy(std::string imageFile, sf::Vector2f imagePosition, int height, int width, int nbLines) :
DrawStrategy(imageFile, imagePosition), height(height), width(width), nbLines(nbLines), currentFrame(0), currentLine(0) {
    this->sprite.setTextureRect(sf::IntRect(0, 0, width, height));
}

AnimatedDrawStrategy::~AnimatedDrawStrategy() {}

void AnimatedDrawStrategy::goToImage(int line, int frame) {
    this->sprite.setTextureRect(sf::IntRect(width * frame, height * line, width, height));
    this->currentFrame = frame;
    this->currentLine = line;
}