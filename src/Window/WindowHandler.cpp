//
// Created by steve on 15/03/2018.
//

#include "WindowHandler.hh"
#include "../ECS/Systems/MoveSystem.hh"
#include "../ECS/Components/PositionComponent.hh"
#include "../ECS/Components/MoveComponent.hh"
#include "../ECS/Components/DrawableComponent.hh"
#include "../ECS/Systems/DrawableSystem.hh"

using namespace Diep::Window;
using namespace Diep;

const auto LeftKey = sf::Keyboard::Q;
const auto RightKey = sf::Keyboard::D;
const auto TopKey = sf::Keyboard::Z;
const auto BottomKey = sf::Keyboard::S;

WindowHandler::WindowHandler(const uint32_t width, const uint32_t height, const std::string name) :
        Window(new sf::RenderWindow(sf::VideoMode(width, height), name)),
        World(::ECS::World::createWorld())
{ }

void WindowHandler::Start() const
{
    sf::Clock deltaClock;
    Window->setFramerateLimit(60);

    while (Window->isOpen()) {
        HandleEvents();

        Window->clear(sf::Color::Blue);
        World->tick(static_cast<ECS::DefaultTickData>(deltaClock.restart().asMilliseconds()));
        Window->display();
    }
}

void WindowHandler::InitializeSystems()
{
    World->registerSystem(new _ECS::DrawableSystem(Window));
    World->registerSystem(new _ECS::MoveSystem());
}

void WindowHandler::Stop() const
{
    //World->destroyWorld(); // (Crash because of unique_ptr...)
}

void WindowHandler::InitializeEntities()
{
    Player = World->create();
    Player->assign<_ECS::PositionComponent>();
    Player->assign<_ECS::MoveComponent>();
    Player->assign<_ECS::DrawableComponent>(_ECS::DrawableComponent::Create("assets/entity_player.png"));
}

void WindowHandler::HandleEvents() const
{
    _ECS::MoveDirectionX dx = GetDirectionFromKey<_ECS::MoveDirectionX>(LeftKey);
    if (dx == _ECS::MoveDirectionX::None) dx = GetDirectionFromKey<_ECS::MoveDirectionX>(RightKey);

    _ECS::MoveDirectionY dy = GetDirectionFromKey<_ECS::MoveDirectionY>(TopKey);
    if (dy == _ECS::MoveDirectionY::None) dy = GetDirectionFromKey<_ECS::MoveDirectionY>(BottomKey);

    World->emit<_ECS::MoveEvent>({Player, dx, dy});

    sf::Event event;
    while (Window->pollEvent(event)) {
        switch (event.type) {
        case sf::Event::Closed:
            Window->close();
            return;
        }
    }
}

template<typename T>
T WindowHandler::GetDirectionFromKey(sf::Keyboard::Key key) const
{
    return NULL;
}

void WindowHandler::DrawSprite(sf::Sprite& sprite)
{
    Window->draw(sprite);
}

template <>
_ECS::MoveDirectionX WindowHandler::GetDirectionFromKey<_ECS::MoveDirectionX>(sf::Keyboard::Key key) const
{
    if (!sf::Keyboard::isKeyPressed(key))
        return _ECS::MoveDirectionX::None;

    switch (key)
    {
    case LeftKey:
        return _ECS::MoveDirectionX::Left;
    case RightKey:
        return _ECS::MoveDirectionX::Right;
    default:
        return _ECS::MoveDirectionX::None;
    }
}

template <>
_ECS::MoveDirectionY WindowHandler::GetDirectionFromKey<_ECS::MoveDirectionY>(sf::Keyboard::Key key) const
{
    if (!sf::Keyboard::isKeyPressed(key))
        return _ECS::MoveDirectionY::None;

    switch (key)
    {
    case TopKey:
        return _ECS::MoveDirectionY::Top;
    case BottomKey:
        return _ECS::MoveDirectionY::Bottom;
    default:
        return _ECS::MoveDirectionY::None;
    }
}
