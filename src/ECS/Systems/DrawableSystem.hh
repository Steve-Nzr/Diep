//
// Created by steve on 16/03/2018.
//

#ifndef DIEPPLUSPLUS_DRAWABLESYSTEM_HH
#define DIEPPLUSPLUS_DRAWABLESYSTEM_HH

#include <ECS.h>
#include "../Components/PositionComponent.hh"
#include "../Components/DrawableComponent.hh"

using namespace ECS;

namespace Diep::_ECS {
    class DrawableSystem : public ECS::EntitySystem {
        std::unique_ptr<sf::RenderWindow>& Window;

    public:
        DrawableSystem(std::unique_ptr<sf::RenderWindow>& window);

        virtual void tick(World* world, float deltaTime) override;
    };
}

#endif //DIEPPLUSPLUS_DRAWABLESYSTEM_HH
