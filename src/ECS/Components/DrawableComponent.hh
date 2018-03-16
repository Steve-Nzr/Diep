//
// Created by steve on 16/03/2018.
//

#ifndef DIEPPLUSPLUS_DRAWABLECOMPONENT_HH
#define DIEPPLUSPLUS_DRAWABLECOMPONENT_HH

#include <SFML/Graphics.hpp>
#include <memory>

namespace Diep::_ECS {
    struct DrawableComponent {
        static DrawableComponent Create(const std::string file)
        {
            DrawableComponent dc;

            dc.Texture = std::make_shared<sf::Texture>();
            dc.Texture->loadFromFile(file);
            dc.Sprite.setTexture(*dc.Texture);
            dc.Sprite.setTextureRect(sf::IntRect(0, 0, 32, 32));
            dc.Sprite.setOrigin(sf::Vector2f(16, 16));
            dc.Sprite.setPosition(sf::Vector2f(50, 50));

            return dc;
        }

        std::shared_ptr<sf::Texture> Texture;
        sf::Sprite Sprite;
    };
}

#endif //DIEPPLUSPLUS_DRAWABLECOMPONENT_HH
