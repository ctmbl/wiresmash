#include "Draw/Drawer.hpp"
#include "Draw/DrawStrategy.hpp"

std::map<int, DrawStrategy*> Drawer::drawStrategies = std::map<int, DrawStrategy*>();
int Drawer::idGen = 0;
int Drawer::zoom = 1;
sf::Vector2f Drawer::center = sf::Vector2f(0,0);

int Drawer::addDrawStrategy(DrawStrategy* drawStrategy) {
    idGen++;
    drawStrategies.insert({idGen, drawStrategy});
    return idGen;
}

void Drawer::removeDrawStrategy(int id) {
    drawStrategies.erase(id);
}

int Drawer::getZoom() {return zoom;}
sf::Vector2f Drawer::getCenter() {return center;}

void Drawer::setZoom(int zoom) {Drawer::zoom = zoom;}
void Drawer::setCenter(sf::Vector2f center) {Drawer::center = center;}

void Drawer::moveCenter(sf::Vector2f translation) {
    Drawer::center.x += translation.x;
    Drawer::center.y += translation.y;
}

void Drawer::flush(sf::RenderWindow& window) {

    for (int paralaxFactor = BACKGROUND_PARALAX_PLANE; paralaxFactor <= CLOSEST_PARALAX_PLANE; paralaxFactor++) {
        // On calcule les vraies coordonnées du centre pour ce paralaxFactor
        int xTrueCenter = (float)center.x * ((float)paralaxFactor/FOREGROUND_PARALAX_PLANE);
        int yTrueCenter = (float)center.y * ((float)paralaxFactor/FOREGROUND_PARALAX_PLANE);

        // On récupère la taille de la fenêtre
        sf::Vector2u windowSize = window.getSize();
        // On calcule les coordonnées de l'angle de la vue
        int viewLeft = xTrueCenter - ((float)windowSize.x / zoom / 2);
        int viewTop = yTrueCenter - ((float)windowSize.y / zoom / 2);
        // On calcule la largeur de la vue selon le zoom, et on créé la vue
        sf::FloatRect viewRect = sf::FloatRect(viewLeft, viewTop, windowSize.x / zoom, windowSize.y / zoom);
        sf::View view = sf::View(viewRect);
        // On l'affecte à la fenêtre
        window.setView(view);

        // On affiche tous les éléments qui ont le bon paralaxFactor
        for (std::pair<int, DrawStrategy*> element : drawStrategies) {
            for (int priority = 0; priority <= MAX_PRIORITY_SCORE; priority++) {   
                if ((element.second->getParalaxFactor() == paralaxFactor) && (element.second->getPriorityScore() == priority)) {
                    element.second->draw(window);
                }
            }
        }
    }

}