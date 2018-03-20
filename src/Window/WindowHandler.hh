//
// Created by steve on 15/03/2018.
//

#ifndef DIEPPLUSPLUS_WINDOWHANDLER_HH
#define DIEPPLUSPLUS_WINDOWHANDLER_HH

#include <ECS.h>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window/Event.hpp>
#include <memory>
#include <SFML/Graphics/Sprite.hpp>
#include "../ECS/Systems/MoveSystem.hh"

namespace Diep::Window {
    class WindowHandler {
    private:
        std::unique_ptr<sf::RenderWindow> Window;
        std::unique_ptr<::ECS::World> World;
        ECS::Entity* Player;

        void HandleEvents() const;

    public:
        WindowHandler(const WindowHandler&) = delete;
        WindowHandler& operator=(const WindowHandler&) = delete;

        WindowHandler(uint32_t width, uint32_t height, std::string name);

        void InitializeSystems();
        void InitializeEntities();
        void Start() const;
        void Stop() const;

        void DrawSprite(sf::Sprite& sprite);

        template <typename T>
        T GetDirectionFromKey(sf::Keyboard::Key key) const;

        template<>
        _ECS::MoveDirectionX GetDirectionFromKey<_ECS::MoveDirectionX>(sf::Keyboard::Key key) const;

        template<>
        _ECS::MoveDirectionY GetDirectionFromKey<_ECS::MoveDirectionY>(sf::Keyboard::Key key) const;
    };
}

#endif //DIEPPLUSPLUS_WINDOWHANDLER_HH
