//
// Created by steve on 20/03/2018.
//

#ifndef DIEPPLUSPLUS_PROJECTILEENTITY_HH
#define DIEPPLUSPLUS_PROJECTILEENTITY_HH

#include <ECS.h>
#include "../Components/PositionComponent.hh"

namespace Diep::_ECS {
    class ProjectileEntity {
    public:
        static void Initialize(ECS::Entity* entity, ECS::Entity* player);
    };
}

#endif //DIEPPLUSPLUS_PROJECTILEENTITY_HH
