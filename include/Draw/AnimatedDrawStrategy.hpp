#ifndef ANIMATED_DRAW_STRATEGY_HPP
#define ANIMATED_DRAW_STRATEGY_HPP

#include "Draw/DrawStrategy.hpp"

class AnimatedDrawStrategy : public DrawStrategy
{
private:
    /**
     * @brief La hauteur en pixel du sprite animé
     */
    int height;
    /**
     * @brief La largeur en pixel du sprite animé
     */
    int width;
    /**
     * @brief Le nombre de lignes du spritesheet donné,
     *        donc le nombre d'animations différentes de l'AnimatedDrawStrategy
     */
    int nbLines;
    int currentLine;
    int currentFrame;

public:
    AnimatedDrawStrategy(std::string imageFile, int height, int width, int nbLines);
    AnimatedDrawStrategy(std::string imageFile, int height, int width, int nbLines, int paralaxFactor);
    AnimatedDrawStrategy(std::string imageFile, int height, int width, int nbLines, int paralaxFactor, int priorityScore);
    AnimatedDrawStrategy(std::string imageFile, sf::Vector2f imagePosition, int height, int width, int nbLines);
    AnimatedDrawStrategy(std::string imageFile, sf::Vector2f imagePosition, int height, int width, int nbLines, int paralaxFactor);
    AnimatedDrawStrategy(std::string imageFile, sf::Vector2f imagePosition, int height, int width, int nbLines, int paralaxFactor, int priorityScore);
    ~AnimatedDrawStrategy();

    /**
     * @brief Modifie la partie visible du spritesheet pour correspondre à la frame donnée de l'animation donnée
     * @param line Le numéro de ligne de l'animation à afficher. (L'indexation commence par 0)
     * @param frame Le numéro de la frame à afficher. (L'indexation commence par 0) 
     */
    void goToImage(int line, int frame);
};

#endif