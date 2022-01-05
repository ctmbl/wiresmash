#include "Controller/Controller.hpp"

//? Initialisation du tableau statique nbFrames[][], obligatoirement hors de la déclaration de classe
//? Fonctionne même si le tableau est privé somehow
int Controller::nbFrames[PLAYER_MAX_COUNT][BUTTON_COUNT] = { 0 };

//!\\ A vérifier
int Controller::nbConnected() {
    int count = 0;
    for (int i = 0; i < PLAYER_MAX_COUNT; i++) {
        if (sf::Joystick::isConnected(i)) {
            count++;
        }
    }
    return count;
}

bool Controller::isPlayerConnected(Player player) {
    return sf::Joystick::isConnected((int)player);
}

sf::Joystick::Axis Controller::associatedSFMLAxis(Stick stick, Axis axis) {
    if ((stick == Stick::Main) && (axis == Axis::X)) return sf::Joystick::Axis::X;
    if ((stick == Stick::Main) && (axis == Axis::Y)) return sf::Joystick::Axis::Y;
    if ((stick == Stick::C   ) && (axis == Axis::X)) return sf::Joystick::Axis::U;
    if ((stick == Stick::C   ) && (axis == Axis::Y)) return sf::Joystick::Axis::V;
    if ((stick == Stick::DPad) && (axis == Axis::X)) return sf::Joystick::Axis::PovX;
    if ((stick == Stick::DPad) && (axis == Axis::Y)) return sf::Joystick::Axis::PovY;
    return sf::Joystick::Axis::R;
}

int Controller::associatedSFMLButton(Button button) {
    if (button == Button::A    ) return 1;
    if (button == Button::B    ) return 0;
    if (button == Button::X    ) return 3;
    if (button == Button::Y    ) return 2;
    if (button == Button::Z    ) return 5;
    if (button == Button::Start) return 7;
    return 4;
}

bool Controller::isButtonHeld(Player player, Button button) {
    return sf::Joystick::isButtonPressed((int)player, associatedSFMLButton(button));
}

void Controller::update() {
    for (int i = 0; i < PLAYER_MAX_COUNT; i++) {
        for (int j = 0; j < BUTTON_COUNT; j++) {
            if (isPlayerConnected((Player)i) && isButtonHeld((Player)i, (Button)j)) {
                nbFrames[i][j] ++;
            } else {
                nbFrames[i][j] = 0;
            }
        }
    }
}

bool Controller::isButtonPressed(Player player, Button button) {
    return nbFrames[(int)player][(int)button] == 1;
}

int Controller::nbHeldFrames(Player player, Button button) {
    return nbFrames[(int)player][(int)button];
}

sf::Vector2f* Controller::stickRawPosition(Player player, Stick stick) {
    float x = sf::Joystick::getAxisPosition((int)player, associatedSFMLAxis(stick, Axis::X));
    float y = sf::Joystick::getAxisPosition((int)player, associatedSFMLAxis(stick, Axis::Y));
    return new sf::Vector2f(x,y);
}

bool Controller::isOutOfRadialDeadZone(Player player, Stick stick) {
    // On calcule la norme au carré de la position du stick
    sf::Vector2f* rawPosition = stickRawPosition(player, stick);
    float rawPositionMagniude2 = rawPosition->x * rawPosition->x + rawPosition->y * rawPosition->y;

    // On récupère le seuil de détectabilité du bon stick (au carré)
    float deadZone2 = 0;
    if (stick == Stick::Main) {deadZone2 = MAIN_STICK_RADIAL_DEAD_ZONE * MAIN_STICK_RADIAL_DEAD_ZONE;}
    if (stick == Stick::C   ) {deadZone2 = C_STICK_RADIAL_DEAD_ZONE * C_STICK_RADIAL_DEAD_ZONE;}
    if (stick == Stick::DPad) {deadZone2 = DPAD_RADIAL_DEAD_ZONE * DPAD_RADIAL_DEAD_ZONE;}

    // On renvoie le résultat
    delete rawPosition;
    return (rawPositionMagniude2 > deadZone2);
}

sf::Vector2f* Controller::stickPosition(Player player, Stick stick) {
    if (isOutOfRadialDeadZone(player, stick)) {
        return stickRawPosition(player, stick);
    } else {
        return new sf::Vector2f(0,0);
    }
}

float Controller::stickAngle(Player player, Stick stick) {
    if (isOutOfRadialDeadZone(player, stick)) {

        sf::Vector2f* position = stickPosition(player, stick);

        // On effectue un produit scalaire avec le vecteur (1,0), puis on norme pour obtenir le cos de l'angle
        float cosAngle = position->x / (std::sqrt(position->x * position->x + position->y * position->y));

        // On calcule l'angle, en degré
        float angle = std::acos(cosAngle) * 180 / 3.14159;

        // Si on est au-dessus de l'équateur, on renvoie une valeur de [0,179]
        // Sinon, on renvoie une valeur de [180,359]
        if (position->y < 0) {
            return angle;
        } else {
            return 360 - angle;
        }

    } else {
        return -1;
    }
}

float Controller::stickCorrectedAngle(Player player, Stick stick) {
    if (isOutOfRadialDeadZone(player, stick)) {

        // On récupère l'angle du stick
        float angle = stickAngle(player, stick);

        // On récupère la bonne valeur de zone morte
        float deadZone = 0;
        if (stick == Stick::Main) {deadZone = MAIN_STICK_AXIAL_DEAD_ZONE;}
        if (stick == Stick::C   ) {deadZone = C_STICK_AXIAL_DEAD_ZONE;}
        if (stick == Stick::DPad) {deadZone = DPAD_AXIAL_DEAD_ZONE;}

        // Si l'angle est trop près d'une direction cardinale, on le ramène dedans
        if ((angle <= deadZone) || (360-angle <= deadZone)) {return 0;}
        if (std::abs(angle-90 ) <= deadZone) {return 90;}
        if (std::abs(angle-180) <= deadZone) {return 180;}
        if (std::abs(angle-270) <= deadZone) {return 270;}
        return angle;
    } else {
        return -1;
    }
}

bool Controller::isStickInDirection(Player player, Stick stick, Direction direction) {
    if (!isOutOfRadialDeadZone(player, stick)) {
        return (direction == Direction::None);
    }

    float angle = stickAngle(player, stick);
    if (direction == Direction::Right) {return (angle <= 45) || (360 - angle <= 45);}
    if (direction == Direction::Up   ) {return std::abs(angle-90 ) <= 45;}
    if (direction == Direction::Left ) {return std::abs(angle-180) <= 45;}
    return std::abs(angle-270) <= 90;
}

bool Controller::isStickInDirectionExtended(Player player, Stick stick, DirectionExtended directionExtended) {
    if (!isOutOfRadialDeadZone(player, stick)) {
        return (directionExtended == DirectionExtended::None);
    }

    float angle = stickAngle(player, stick);
    if (directionExtended == DirectionExtended::Right    ) {return (angle <= 22.5) || (360 - angle <= 22.5);}
    if (directionExtended == DirectionExtended::UpRight  ) {return std::abs(angle-45 ) <= 22.5;}
    if (directionExtended == DirectionExtended::Up       ) {return std::abs(angle-90 ) <= 22.5;}
    if (directionExtended == DirectionExtended::UpLeft   ) {return std::abs(angle-135) <= 22.5;}
    if (directionExtended == DirectionExtended::Left     ) {return std::abs(angle-180) <= 22.5;}
    if (directionExtended == DirectionExtended::DownLeft ) {return std::abs(angle-225) <= 22.5;}
    if (directionExtended == DirectionExtended::Down     ) {return std::abs(angle-270) <= 22.5;}
    return std::abs(angle-315) <= 22.5;
}
