#ifndef DRAWER_HPP
#define DRAWER_HPP

#include <map>
#include <SFML/Graphics.hpp>
#include <iostream>

class DrawStrategy;

class Drawer
{
private:
    /**
     * @brief Un compteur interne qui indique le dernier id attribué à une DrawStrategy,
     *        et qui est incrémenté à chaque fois qu'une DrawStrategy est ajoutée
     */
    static int idGen;

    /**
     * @brief La liste des DrawStrategy actives, et leurs id associés
     */
    static std::map<int, DrawStrategy*> drawStrategies;

    /**
     * @brief Les coordonnées-monde au centre de la vision de la caméra
     */
    static sf::Vector2f center;

    /**
     * @brief Le facteur de zoom de la caméra.
     *        Un facteur n signifie qu'un pixel du monde est représenté par un carré de nxn pixels sur l'écran
     */
    static int zoom;

public:
    /**
     * @brief Valeur maximale de paralaxFactor affectable à une DrawStrategy
     */
    static const int CLOSEST_PARALAX_PLANE = 20;

    /**
     * @brief Valeur par défaut du paralaxFactor.
     *        Ce plan n'est pas modifié lors des calculs de paralaxe.
     *        Ainsi, le centre de l'affichage de ce plan est exactement le centre de la caméra
     */
    static const int FOREGROUND_PARALAX_PLANE = 10;

    /**
     * @brief Valeur de paralaxFactor pour l'arrière-plan statique
     *        Ce plan de paralaxe n'est pas déplacé quand la caméra est déplacée
     */
    static const int BACKGROUND_PARALAX_PLANE = 0;

    /**
     * @brief Score maximal pour le priorityScore des DrawStrategy
     */
    static const int MAX_PRIORITY_SCORE = 3;

public:
    /**
     * @brief Ajoute un pointeur vers une DrawStrategy à la liste des DrawStrategy
     *        Cette méthode est appelée dans le constructeur de DrawStrategy
     *        Appeler cette méthode incrémente idGen de 1.
     * @param drawStrategy Un pointeur vers la DrawStrategy à stocker
     * @return L'id attribué à la DrawStrategy ajoutée.
     */
    int static addDrawStrategy(DrawStrategy* drawStrategy);

    /**
     * @brief Retire de la liste la DrawStrategy qui possède l'id spécifié
     * @param id L'id de la DrawStrategy à retirer
     */
    void static removeDrawStrategy(int id);

    static int getZoom();
    static sf::Vector2f getCenter();

    static void setZoom(int zoom);
    static void setCenter(sf::Vector2f center);

    static void moveCenter(sf::Vector2f translation);

    /**
     * @brief Affiche toutes les DrawStrategy de la liste, en respectant le cadrage de la caméra
     * 
     * @param window La fenêtre cible de l'affichage
     */
    static void flush(sf::RenderWindow& window);
};
#endif