//
// Created by steve on 16/03/2018.
//

#ifndef DIEPPLUSPLUS_MOVECOMPONENT_HH
#define DIEPPLUSPLUS_MOVECOMPONENT_HH

namespace Diep::_ECS {
    struct MoveComponent {
        MoveComponent() :
                VelocityX(0.0f), VelocityY(0.0f) { }

        float VelocityX;
        float VelocityY;
    };
}

#endif //DIEPPLUSPLUS_MOVECOMPONENT_HH
