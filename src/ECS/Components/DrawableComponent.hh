//
// Created by steve on 16/03/2018.
//

#ifndef DIEPPLUSPLUS_DRAWABLECOMPONENT_HH
#define DIEPPLUSPLUS_DRAWABLECOMPONENT_HH

#include <SFML/Graphics.hpp>
#include <memory>
#include <iostream>

namespace Diep::_ECS {
    struct DrawableComponent {
        static DrawableComponent Create(const std::string file, const sf::IntRect& textureRect,
                const sf::Vector2f& origin, const sf::Vector2f& position)
        {
            DrawableComponent dc;

            dc.Texture = std::make_shared<sf::Texture>();
            dc.Texture->loadFromFile(file);
            dc.Sprite.setTexture(*dc.Texture);
            dc.Sprite.setTextureRect(textureRect);
            dc.Sprite.setOrigin(origin);
            dc.Sprite.setPosition(position);

            return dc;
        }

        std::shared_ptr<sf::Texture> Texture;
        sf::Sprite Sprite;
    };
}

#endif //DIEPPLUSPLUS_DRAWABLECOMPONENT_HH
