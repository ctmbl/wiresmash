#ifndef CONTROLLER_HPP
#define CONTROLLER_HPP

#include <SFML/Graphics.hpp>
#include <cmath>

//!\\ Les axes de Controller::Joystick sont orientés de gauche à droite pour X
//!\\                                       orientés de HAUT en BAS pour Y

class Controller
{
public:
    static const int PLAYER_MAX_COUNT         = 4;
    static const int STICK_COUNT              = 3;
    static const int BUTTON_COUNT             = 6;
    static const int DIRECTION_COUNT          = 5;
    static const int DIRECTION_EXTENDED_COUNT = 9;

private:
    static constexpr float MAIN_STICK_RADIAL_DEAD_ZONE = 15.0f;
    static constexpr float MAIN_STICK_AXIAL_DEAD_ZONE  = 20.0f;
    static constexpr float C_STICK_RADIAL_DEAD_ZONE    = 15.0f;
    static constexpr float C_STICK_AXIAL_DEAD_ZONE     = 20.0f;
    static constexpr float DPAD_RADIAL_DEAD_ZONE       = 80.0f;
    static constexpr float DPAD_AXIAL_DEAD_ZONE        = 45.0f;
    static constexpr float SHOULDERS_DEAD_ZONE         = 30.0f;

    static int nbFrames[PLAYER_MAX_COUNT][BUTTON_COUNT];

public:

    //!\\ Ne pas oublier de modifier les comptes plus haut si une enum est modifiée
    enum class Stick {Main, C, DPad};
    enum class Axis {X, Y};
    enum class Player {Player1, Player2, Player3, Player4};
    enum class Button {A, B, X, Y, Z, Start};
    enum class Direction {None, Up, Right, Down, Left};
    enum class DirectionExtended {None, Up, UpRight, Right, DownRight, Down, DownLeft, Left, UpLeft};

    static void update();

    static int nbConnected();
    static bool isPlayerConnected(Player player);

    static bool isButtonPressed(Player player, Button button);
    static bool isButtonHeld(Player player, Button button);
    static int nbHeldFrames(Player player, Button button);

    static bool isOutOfRadialDeadZone(Player player, Stick stick);
    static sf::Vector2f* stickPosition(Player player, Stick stick);
    static float stickAngle(Player player, Stick stick);
    static float stickCorrectedAngle(Player player, Stick stick);
    static bool isStickInDirection(Player player, Stick stick, Direction direction);
    static bool isStickInDirectionExtended(Player player, Stick stick, DirectionExtended direction);

private:
    static sf::Joystick::Axis associatedSFMLAxis(Stick stick, Axis axis);
    static int associatedSFMLButton(Button button);
    static sf::Vector2f* stickRawPosition(Player player, Stick stick);
};


#endif