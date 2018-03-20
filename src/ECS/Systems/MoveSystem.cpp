//
// Created by steve on 15/03/2018.
//

#include <iostream>
#include "MoveSystem.hh"
#include "../Components/PositionComponent.hh"
#include "../Components/MoveComponent.hh"
#include "../Components/DrawableComponent.hh"

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
    auto move = event.entity->get<MoveComponent>();

    if (event.X == MoveDirectionX::Left && move->VelocityX > -4.0f) move->VelocityX -= (move->VelocityX > 0.0f ? 0.2f : 0.05f);
    else if (event.X == MoveDirectionX::Right && move->VelocityX < 4.0f) move->VelocityX += (move->VelocityX < 0.0f ? 0.2f : 0.05f);

    if (event.Y == MoveDirectionY::Top && move->VelocityY > -4.0f) move->VelocityY -= (move->VelocityY > 0.0f ? 0.2f : 0.05f);
    else if (event.Y == MoveDirectionY::Bottom && move->VelocityY < 4.0f) move->VelocityY += (move->VelocityY < 0.0f ? 0.2f : 0.05f);

    move->MovedX = !(event.X == MoveDirectionX::None);
    move->MovedY = !(event.Y == MoveDirectionY::None);
}

void MoveSystem::tick(ECS::World* world, ECS_TICK_TYPE data)
{
    world->each<MoveComponent>([](ECS::Entity* ent, ECS::ComponentHandle<MoveComponent> move) {
        if (move->VelocityX == 0.0f && move->VelocityY == 0.0f)
            return;

        auto drawable = ent->get<DrawableComponent>();
        auto position = ent->get<PositionComponent>();

        position->X += move->VelocityX;
        position->Y += move->VelocityY;

        drawable->Sprite.setPosition(position->X, position->Y);

        if (!move->MovedX) move->VelocityX /= 1.06f;
        if (!move->MovedY) move->VelocityY /= 1.06f;
    });
}
