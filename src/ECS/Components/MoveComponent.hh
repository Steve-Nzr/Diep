//
// Created by steve on 16/03/2018.
//

#ifndef DIEPPLUSPLUS_MOVECOMPONENT_HH
#define DIEPPLUSPLUS_MOVECOMPONENT_HH

namespace Diep::_ECS {
    struct MoveComponent {
        MoveComponent(const float velocityX, const float velocityY) :
                VelocityX(velocityX), VelocityY(velocityY), MovedX(false), MovedY(false) {}

        MoveComponent() :
                VelocityX(0.0f), VelocityY(0.0f), MovedX(false), MovedY(false) {}

        float VelocityX;
        float VelocityY;
        bool MovedX;
        bool MovedY;
    };
}

#endif //DIEPPLUSPLUS_MOVECOMPONENT_HH
