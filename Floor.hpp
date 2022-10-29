/*
    Floor.hpp

    version 3 (final version)
    
    CMI-TI 22 TINPRO045B
    Student: Thijs Dregmans (1024272)
    C++ eindopdracht
    Last edited: 29-10-2022

*/

#include <iostream>
#include <math.h>
#include <vector>

#define VPO st::vector<Object*>

namespace st = std;

#include "Vec3D.hpp"
#include "Ray.hpp"
#include "Object.hpp"

class Floor: public Object {
    private:
        // Floor has a Vec3D center, but this is part of Object.

    public:
        Floor (float x, float y, float z);

        float hit (Ray const &ray) const;
};