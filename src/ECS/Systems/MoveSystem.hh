//
// Created by steve on 15/03/2018.
//

#ifndef DIEPPLUSPLUS_MOVESYSTEM_HH
#define DIEPPLUSPLUS_MOVESYSTEM_HH

#include <ECS.h>
#include "EventSystem.hh"

namespace Diep::_ECS {
    enum class MoveDirectionX {
        None,
        Left,
        Right
    };

    enum class MoveDirectionY {
        None,
        Top,
        Bottom
    };

    struct MoveEvent : EventSystem {
        MoveEvent(ECS::Entity* entity, MoveDirectionX x, MoveDirectionY y) :
            EventSystem({entity}), X(x), Y(y) {}

        MoveDirectionX X;
        MoveDirectionY Y;
    };

    class MoveSystem : public ECS::EntitySystem, public ECS::EventSubscriber<MoveEvent> {
    public:
        void configure(ECS::World* world) override;
        void unconfigure(ECS::World* world) override;

        void receive(ECS::World* world, const MoveEvent& event);

        void tick(ECS::World* world, ECS_TICK_TYPE data) override;
    };
}

#endif //DIEPPLUSPLUS_MOVESYSTEM_HH
