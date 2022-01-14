#ifndef CONTROLLER_HPP
#define CONTROLLER_HPP

#include <SFML/Graphics.hpp>
#include <cmath>

//!\\ Les axes de Controller::Joystick sont orientés de gauche à droite pour X
//!\\                                       orientés de HAUT en BAS pour Y

class Controller
{
public:
    /**
     * @brief Le nombre maximal de manettes qu'il est possible de connecter
     * 
     */
    static const int PLAYER_MAX_COUNT         = 4;
    /**
     * @brief Le nombre de sticks d'une manette
     */
    static const int STICK_COUNT              = 3;
    /**
     * @brief Le nombre de boutons d'une manette. 
     * Attention : Ce nombre est le nombre de boutons "réels" et pas celui détecté par SFML
     * 
     */
    static const int BUTTON_COUNT             = 6;
    /**
     * @brief Le nombre de directions cardinales (en incluant None)
     */
    static const int DIRECTION_COUNT          = 5;
    /**
     * @brief Le nombre de directions cardinales étendues (en incluant None)
     * 
     */
    static const int DIRECTION_EXTENDED_COUNT = 9;

private:
    /**
     * @brief Distance du centre en-dessous de laquelle le stick gauche est considéré comme dans la zone morte
     */
    static constexpr float MAIN_STICK_RADIAL_DEAD_ZONE = 15.0f;
    /**
     * @brief Distance angulaire (en degrés) d'une direction cardinale (0, 90°, 180°, 270°) en-dessous de laquelle
     *        l'angle du stick gauche est arrondi à la direction cardinale la plus proche
     */
    static constexpr float MAIN_STICK_AXIAL_DEAD_ZONE  = 20.0f;
    /**
     * @brief Distance du centre en-dessous de laquelle le stick droit est considéré comme dans la zone morte
     */
    static constexpr float C_STICK_RADIAL_DEAD_ZONE    = 15.0f;
    /**
     * @brief Distance angulaire (en degrés) d'une direction cardinale (0, 90°, 180°, 270°) en-dessous de laquelle
     *        l'angle du stick droit est arrondi à la direction cardinale la plus proche
     */
    static constexpr float C_STICK_AXIAL_DEAD_ZONE     = 20.0f;
    /**
     * @brief Distance du centre en-dessous de laquelle la croix directionnelle est considérée comme dans la zone morte
     */
    static constexpr float DPAD_RADIAL_DEAD_ZONE       = 80.0f;
    /**
     * @brief Distance angulaire (en degrés) d'une direction cardinale (0, 90°, 180°, 270°) en-dessous de laquelle
     *        l'angle de la croix directionnelle est arrondi à la direction cardinale la plus proche
     */
    static constexpr float DPAD_AXIAL_DEAD_ZONE        = 45.0f;
    /**
     * @brief Distance de la position neutre en-dessous de laquelle les gachettes sont considérées comme inactives
     */
    static constexpr float SHOULDERS_DEAD_ZONE         = 30.0f;

    /**
     * @brief nbFrames[i][j] contient la durée de la pression du bouton j du joueur i, en frames.
     *        Il contient en particulier 0 si le bouton n'est pas pressé.
     * 
     */
    static int nbFrames[PLAYER_MAX_COUNT][BUTTON_COUNT];

public:

    //!\\ Ne pas oublier de modifier les comptes plus haut si une enum est modifiée

    enum class Stick {Main, C, DPad};
    enum class Axis {X, Y};
    enum class Player {Player1, Player2, Player3, Player4};
    enum class Button {A, B, X, Y, Z, Start};
    enum class Direction {None, Up, Right, Down, Left};
    enum class DirectionExtended {None, Up, UpRight, Right, DownRight, Down, DownLeft, Left, UpLeft};

    /**
     * @brief Actualise le comptage des durées de pression de chaque bouton de chaque joueur.
     *        Cette fonction est à exécuter à chaque frame.
     */
    static void update();

    //*****************************************************************************************************
    //*        TESTS SUR LES JOUEURS
    //*****************************************************************************************************/
    /**
     * @brief Compte et renvoie le nombre de manettes connectées.
     * @return Le nombre de manettes connectées 
     */
    static int nbConnected();

    /**
     * @brief Teste si le joueur donné est connecté
     * @param player Le joueur à tester
     * @return Retourne true si le joueur donné est connecté
     */
    static bool isPlayerConnected(Player player);

    //*****************************************************************************************************
    //*        TESTS SUR LES BOUTONS
    //*****************************************************************************************************/
    /**
     * @brief Teste si le bouton donné vient d'être enfoncé à cette frame
     * @param player Le joueur auquel appartient le bouton à tester
     * @param button Le bouton de la manette à tester
     * @return Retourne true is le bouton donné vient d'être pressé
     */
    static bool isButtonPressed(Player player, Button button);

    /**
     * @brief Teste si le bouton donné est enfoncé (a priori depuis un temps quelconque)
     * @param player Le joueur auquel appartient le bouton à tester
     * @param button Le bouton de la manette à tester
     * @return Retourne true is le bouton donné est pressé
     */
    static bool isButtonHeld(Player player, Button button);

    /**
     * @brief Renvoie la durée de pression du bouton donné.
     * @param player Le joueur auquel appartient le bouton à tester
     * @param button Le bouton de la manette à tester
     * @return Le nombre de frames depuis lequel le bouton donné est pressé.
     *         En particulier, on renvoie 0 si le bouton n'est pas enfoncé.
     */
    static int nbHeldFrames(Player player, Button button);

    //*****************************************************************************************************
    //*        TESTS SUR LES STICKS
    //*****************************************************************************************************/
    /**
     * @brief Teste si le stick donné est en dehors de sa zone morte radiale.
     *        Ce test dépend de la constante XXX_RADIAL_DEAD_ZONE du stick correspondant.
     * @param player Le joueur auquel appartient le stick à tester 
     * @param stick Le stick de la manette à tester
     * @return Retourne true is le stick donné est en dehors de sa zone morte radiale
     */
    static bool isOutOfRadialDeadZone(Player player, Stick stick);

    /**
     * @brief Renvoie la position du stick donné, corrigée s'il est dans sa zone morte
     * @param player Le joueur auquel appartient le stick à tester 
     * @param stick Le stick de la manette à tester
     * @return Un vecteur représentant la position du stick donné.
     *         La coordonnée x est orientée de gauche à droite et la coordonnée y est orientée de haut en bas.
     *         Si le stick est dans sa zone morte, on renvoie les coordonnées du centre (0,0)
     */
    static sf::Vector2f stickPosition(Player player, Stick stick);

    /**
     * @brief Renvoie l'angle du stick donné, corrigée s'il est dans sa zone morte radiale
     * @param player Le joueur auquel appartient le stick à tester 
     * @param stick Le stick de la manette à tester
     * @return Si le stick est dans sa zone morte, on renvoie -1.
     *         Sinon, on renvoie son angle en degrés entre 0 et 359°,
     *         où 0° est dirigé vers la droite, et où le sens trigonométrique est croissant.
     */
    static float stickAngle(Player player, Stick stick);

    /**
     * @brief Renvoie l'angle du stick donné, corrigée s'il est dans sa zone morte radiale ou dans une zone morte axiale.
     *        Les zones mortes axiales dépendent de la constante XXX_AXIAL_DEAD_ZONE du stick testé.
     * @param player Le joueur auquel appartient le stick à tester 
     * @param stick Le stick de la manette à tester
     * @return Si le stick est dans sa zone morte, on renvoie -1.
     *         Sinon, on renvoie son angle en degrés entre 0 et 359°,
     *         où 0° est dirigé vers la droite, et où le sens trigonométrique est croissant.
     *         Si le stick est dans une zone morte axiale, on renvoie l'angle de la direction cardinale la plus proche (0°, 90°, 180° ou 270°)
     */
    static float stickCorrectedAngle(Player player, Stick stick);

    /**
     * @brief Teste si le stick donné est dans la zone de la direction cardinale donnée.
     * @param player Le joueur auquel appartient le stick à tester 
     * @param stick Le stick de la manette à tester
     * @param direction La direction cardinale à tester.
     *                  La zone de None est la zone morte radiale.
     *                  La zone des autres directions est le quart de disque hors de la zone morte radiale le plus proche
     * @return Renvoie true si le stick donné est dans la zone de la direction cardinale donnée.
     */
    static bool isStickInDirection(Player player, Stick stick, Direction direction);

    /**
     * @brief Teste si le stick donné est dans la zone de la direction cardinale étendue donnée.
     * @param player Le joueur auquel appartient le stick à tester 
     * @param stick Le stick de la manette à tester
     * @param direction La direction cardinale étendue à tester.
     *                  La zone de None est la zone morte radiale.
     *                  La zone des autres directions est le huitième de disque hors de la zone morte radiale le plus proche
     * @return Renvoie true si le stick donné est dans la zone de la direction cardinale étendue donnée.
     */
    static bool isStickInDirectionExtended(Player player, Stick stick, DirectionExtended direction);

private:
    /**
     * @brief Donne l'élément de l'enum de la SFML de l'axe donné.
     * @param stick Le stick qui contient l'axe qu'on veut donner.
     * @param axis L'axe dont on veut l'élément dans l'enum sf::Joystick::Axis
     * @return L'élément de l'enum sf::Joystick::Axis associé à l'axe donné
     */
    static sf::Joystick::Axis associatedSFMLAxis(Stick stick, Axis axis);

    /**
     * @brief Donne l'id du bouton donné dans la SFML.
     * @param button Le bouton dont on veut l'id.
     * @return L'id du bouton donné
     */
    static int associatedSFMLButton(Button button);
    
    /**
     * @brief Renvoie la position du stick donné.
     * @param player Le joueur auquel appartient le stick à tester 
     * @param stick Le stick de la manette à tester
     * @return Un vecteur représentant la position du stick donné.
     *         La coordonnée x est orientée de gauche à droite et la coordonnée y est orientée de haut en bas.
     */
    static sf::Vector2f stickRawPosition(Player player, Stick stick);
};


#endif