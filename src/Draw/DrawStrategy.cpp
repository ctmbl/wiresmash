#include "Draw/DrawStrategy.hpp"
#include "Draw/Drawer.hpp"

DrawStrategy::DrawStrategy(std::string imageFile) {
    this->texture = sf::Texture();
    if (!this->texture.loadFromFile(imageFile)) {
        throw std::exception();
    }

    this->sprite = sf::Sprite();
    this->sprite.setTexture(this->texture);
    this->paralaxFactor = 10;
    this->priorityScore = 0;

    this->associatedId = Drawer::addDrawStrategy(this);
}

DrawStrategy::DrawStrategy(std::string imageFile, int paralaxFactor) {
    this->texture = sf::Texture();
    if (!this->texture.loadFromFile(imageFile)) {
        throw std::exception();
    }

    this->sprite = sf::Sprite();
    this->sprite.setTexture(this->texture);
    this->paralaxFactor = paralaxFactor;
    this->priorityScore = 0;

    this->associatedId = Drawer::addDrawStrategy(this);
}

DrawStrategy::DrawStrategy(std::string imageFile, int paralaxFactor, int priorityScore) {
    this->texture = sf::Texture();
    if (!this->texture.loadFromFile(imageFile)) {
        throw std::exception();
    }

    this->sprite = sf::Sprite();
    this->sprite.setTexture(this->texture);
    this->paralaxFactor = paralaxFactor;
    this->priorityScore = priorityScore;

    this->associatedId = Drawer::addDrawStrategy(this);
}

DrawStrategy::DrawStrategy(std::string imageFile, sf::Vector2f imagePosition) {
    this->texture = sf::Texture();
    if (!this->texture.loadFromFile(imageFile)) {
        throw std::exception();
    }

    this->sprite = sf::Sprite();
    this->sprite.setTexture(this->texture);
    this->sprite.setPosition(imagePosition);
    this->paralaxFactor = 10;
    this->priorityScore = 0;

    this->associatedId = Drawer::addDrawStrategy(this);
}

DrawStrategy::DrawStrategy(std::string imageFile, sf::Vector2f imagePosition, int paralaxFactor) {
    this->texture = sf::Texture();
    if (!this->texture.loadFromFile(imageFile)) {
        throw std::exception();
    }

    this->sprite = sf::Sprite();
    this->sprite.setTexture(this->texture);
    this->sprite.setPosition(imagePosition);
    this->paralaxFactor = paralaxFactor;
    this->priorityScore = 0;

    this->associatedId = Drawer::addDrawStrategy(this);
}

DrawStrategy::DrawStrategy(std::string imageFile, sf::Vector2f imagePosition, int paralaxFactor, int priorityScore) {
    this->texture = sf::Texture();
    if (!this->texture.loadFromFile(imageFile)) {
        throw std::exception();
    }

    this->sprite = sf::Sprite();
    this->sprite.setTexture(this->texture);
    this->sprite.setPosition(imagePosition);
    this->paralaxFactor = paralaxFactor;
    this->priorityScore = priorityScore;

    this->associatedId = Drawer::addDrawStrategy(this);
}

DrawStrategy::~DrawStrategy() {}

sf::Vector2f DrawStrategy::getImagePosition() {return sprite.getPosition();}
int DrawStrategy::getParalaxFactor() {return paralaxFactor;}
int DrawStrategy::getPriorityScore() {return priorityScore;}

void DrawStrategy::setImagePosition(sf::Vector2f imagePosition) {this->sprite.setPosition(imagePosition);}
void DrawStrategy::setParalaxFactor(int paralaxFactor) {this->paralaxFactor = paralaxFactor;}
void DrawStrategy::setPriorityScore(int priorityScore) {this->priorityScore = priorityScore;}
void DrawStrategy::translateImagePosition(sf::Vector2f translation) {this->sprite.move(translation);}

void DrawStrategy::draw(sf::RenderWindow& window) {
    window.draw(sprite);
}