//
// Created by steve on 16/03/2018.
//

#ifndef DIEPPLUSPLUS_POSITIONCOMPONENT_HH
#define DIEPPLUSPLUS_POSITIONCOMPONENT_HH

namespace Diep::_ECS {
    struct PositionComponent {
    public:
        PositionComponent(const float x, const float y) :
                X(x), Y(y) { }

        PositionComponent() :
                X(0.f), Y(0.f) { }

        float X;
        float Y;
    };
}

#endif //DIEPPLUSPLUS_POSITIONCOMPONENT_HH
