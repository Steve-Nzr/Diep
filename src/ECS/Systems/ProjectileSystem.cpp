//
// Created by steve on 20/03/2018.
//

#include "ProjectileSystem.hh"
#include "../Entities/ProjectileEntity.hh"

using namespace Diep::_ECS;

void ProjectileSystem::configure(ECS::World* world)
{
    world->subscribe<LaunchEvent>(this);
}

void ProjectileSystem::unconfigure(ECS::World* world)
{
    world->unsubscribeAll(this);
}

void ProjectileSystem::receive(ECS::World* world, const LaunchEvent& event)
{
    ECS::Entity* entity = world->create();
    ProjectileEntity::Initialize(entity, event.entity);
}
