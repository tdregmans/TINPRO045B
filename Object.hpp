/*
    Object.hpp

    version 3 (final version)
    
    CMI-TI 22 TINPRO045B
    Student: Thijs Dregmans (1024272)
    C++ eindopdracht
    Last edited: 29-10-2022

*/

#pragma once

#include <iostream>
#include <math.h>
#include <vector>

#define VPO st::vector<Object*>

namespace st = std;

#include "Vec3D.hpp" 

class Ray;

class Object {
    private:
        friend class Sphere;
        friend class Floor;
        
        Vec3D center;

    public:
        Object ();

        Object (float x, float y, float z);

        virtual float hit (Ray const &ray) const = 0;
};