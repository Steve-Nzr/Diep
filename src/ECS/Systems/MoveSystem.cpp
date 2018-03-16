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
    auto drawable = event.entity->get<DrawableComponent>();

    if (event.X == MoveDirectionX::Left && move->VelocityX > -4.0f) move->VelocityX -= (move->VelocityX > 0.0f ? 0.2f : 0.05f);
    else if (event.X == MoveDirectionX::Right && move->VelocityX < 4.0f) move->VelocityX += (move->VelocityX < 0.0f ? 0.2f : 0.05f);

    if (event.Y == MoveDirectionY::Top && move->VelocityY > -4.0f) move->VelocityY -= (move->VelocityY > 0.0f ? 0.2f : 0.05f);
    else if (event.Y == MoveDirectionY::Bottom && move->VelocityY < 4.0f) move->VelocityY += (move->VelocityY < 0.0f ? 0.2f : 0.05f);


    if (event.X == MoveDirectionX::None) move->VelocityX /= 1.06f;
    if (event.Y == MoveDirectionY::None) move->VelocityY /= 1.06f;

    auto spritePosition = drawable->Sprite.getPosition();
    drawable->Sprite.setPosition(spritePosition.x + move->VelocityX, spritePosition.y + move->VelocityY);
}
