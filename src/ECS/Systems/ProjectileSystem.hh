//
// Created by steve on 20/03/2018.
//

#ifndef DIEPPLUSPLUS_PROJECTILESYSTEM_HH
#define DIEPPLUSPLUS_PROJECTILESYSTEM_HH

#include <ECS.h>
#include "EventSystem.hh"

namespace Diep::_ECS {
    struct LaunchEvent : EventSystem {
        LaunchEvent(ECS::Entity* entity) :
                EventSystem({entity}) {}
    };

    class ProjectileSystem : public ECS::EntitySystem, public ECS::EventSubscriber<LaunchEvent> {
    public:
        void configure(ECS::World* world) override;
        void unconfigure(ECS::World* world) override;

        void receive(ECS::World* world, const LaunchEvent& event);
    };
}

#endif //DIEPPLUSPLUS_PROJECTILESYSTEM_HH
