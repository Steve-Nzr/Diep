//
// Created by steve on 16/03/2018.
//

#include "DrawableSystem.hh"

using namespace Diep::_ECS;

DrawableSystem::DrawableSystem(std::unique_ptr<sf::RenderWindow>& window) :
    Window(window) {}

void DrawableSystem::tick(ECS::World* world, const float deltaTime)
{
    world->each<DrawableComponent>([this](ECS::Entity* ent, ECS::ComponentHandle<DrawableComponent> drawable) {
        Window->draw(drawable->Sprite);
    });
}
