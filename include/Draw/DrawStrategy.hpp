#ifndef DRAW_STRATEGY_HPP
#define DRAW_STRATEGY_HPP

#include <SFML/Graphics.hpp>
#include <string>
#include <exception>

class Drawer;

class DrawStrategy
{
protected:
    /**
     * @brief La texture plaquée sur le sprite de cette DrawStrategy
     */
    sf::Texture texture;

    /**
     * @brief Le sprite utilisée pour la DrawStrategy
     * 
     */
    sf::Sprite sprite;

    /**
     * @brief Le facteur de paralaxe utilisé lors de l'affichage du sprite.
     *        Les sprites sont affichés sur l'écran par ordre croissant de paralaxFactor.
     *        A paralaxFactor égaux, les sprites sont affichés par ordre de priorityFactor,
     *        puis par ordre de création.
     *        Sa valeur par défaut est Drawer::FOREGROUND_PARALAX_PLANE (10 par défaut).
     *        Pour afficher ce sprite sur l'arrière-plan fixe, on utilise la valeur Drawer::BACKGROUND_PARALAX_PLANE (0 par défaut)
     */
    int paralaxFactor;

    /**
     * @brief Ordre d'affichage des sprites à paralaxFactor égaux.
     */
    int priorityScore;

    /**
     * @brief Id donné à la stratégie dans la liste du handler Drawer
     */
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

    /**
     * @brief Affiche le sprite sur la fenêtre donnée
     * @param window La fenêtre cible de l'affichage
     */
    void draw(sf::RenderWindow& window);
};

#endif