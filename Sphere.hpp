/*
    Sphere.hpp

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

class Sphere: public Object {
    private:
        // Floor has a Vec3D center, but this is part of Object.
        float radius;
    public:
        Sphere (float x, float y, float z, float radius);

        float distFromRay (Ray const &ray) const;

        float hit (Ray const &ray) const;

        Vec3D hitPoint (Ray const &ray) const;

};