#ifndef ANIMATOR_HPP
#define ANIMATOR_HPP

#include <vector>
#include <map>

class AnimationStrategy;

class Animator
{
private:
    /**
     * @brief Un compteur interne qui indique le dernier id attribué à un AnimationStrategy,
     *        et qui est incrémenté à chaque fois qu'un AnimationStrategy est ajouté
     */
    static int idGen;
    /**
     * @brief La liste des AnimationStrategy actives, et leurs id associés
     */
    static std::map<int, AnimationStrategy*> animationStrategies;
public:
    /**
     * @brief Ajoute un pointeur vers une AnimationStrategy à la liste des AnimationStrategy
     *        Cette méthode est appelée dans le constructeur de AnimationStrategy
     *        Appeler cette méthode incrémente idGen de 1.
     * @param animationStrategy Un pointeur vers l'AnimationStrategy à stocker
     * @return L'id attribué à l'AnimationStrategy ajoutée.
     */
    int static addAnimationStrategy(AnimationStrategy* animationStrategy);

    /**
     * @brief Retire de la liste l'AnimationStrategy qui possède l'id spécifié
     * @param id L'id de l'AnimationStrategy à retirer
     */
    void static removeAnimationStrategy(int id);

    /**
     * @brief Fait passer à la frame suivante, puis exécute l'action de toutes les AnimationStrategy de la liste
     *        Les AnimationStrategy sont parcourues dans leur ordre d'ajout à la liste
     */
    void static flush();
};

#endif