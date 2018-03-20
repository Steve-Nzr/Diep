//
// Created by steve on 20/03/2018.
//

#include "ProjectileEntity.hh"
#include "../Components/MoveComponent.hh"
#include "../Components/DrawableComponent.hh"

using namespace Diep::_ECS;

void ProjectileEntity::Initialize(ECS::Entity* entity, ECS::Entity* player)
{
    auto position = player->get<PositionComponent>();
    auto move = player->get<MoveComponent>();

    entity->assign<PositionComponent>(position->X, position->Y);
    entity->assign<MoveComponent>(18.0f, 0.0f);
    entity->assign<DrawableComponent>(DrawableComponent::Create("../assets/entity_bullet.png",
            {0, 0, 16, 16}, {8, 8}, {position->X, position->Y}));
}
