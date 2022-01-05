#include "Draw/DrawStrategy.hpp"
#include "Draw/Drawer.hpp"

DrawStrategy::DrawStrategy(std::string imageFile) {
    this->texture = sf::Texture();
    if (!this->texture.loadFromFile(imageFile)) {
        throw std::exception();
    }

    this->sprite = sf::Sprite();
    this->sprite.setTexture(this->texture);
    this->imagePosition = sf::Vector2f(0, 0);

    this->associatedId = Drawer::addDrawStrategy(this);
}

DrawStrategy::DrawStrategy(std::string imageFile, sf::Vector2f imagePosition) {
    this->texture = sf::Texture();
    if (!this->texture.loadFromFile(imageFile)) {
        throw std::exception();
    }

    this->sprite = sf::Sprite();
    this->sprite.setTexture(this->texture);
    this->imagePosition = imagePosition;

    this->associatedId = Drawer::addDrawStrategy(this);
}

DrawStrategy::~DrawStrategy() {}

sf::Vector2f DrawStrategy::getImagePosition() {return imagePosition;}

void DrawStrategy::setImagePosition(sf::Vector2f imagePosition) {this->imagePosition = imagePosition;}
void DrawStrategy::translateImagePosition(sf::Vector2f translation) {this->imagePosition += translation;}

void DrawStrategy::draw(sf::RenderWindow& window) {
    window.draw(sprite);
}