//
// Created by steve on 15/03/2018.
//

#include "MoveSystem.hh"

using namespace Diep::_ECS;

void MoveSystem::configure(ECS::World* world)
{
    world->subscribe<MoveEvent>(this);
}

void MoveSystem::unconfigure(ECS::World* world)
{
    world->unsubscribeAll(this);
}

void MoveSystem::receive(ECS::World* world, const MoveEvent& event)
{
    if (event.X == MoveDirectionX::None &&
            event.Y == MoveDirectionY::None)
        return;

    throw new std::exception("Ah");
}
