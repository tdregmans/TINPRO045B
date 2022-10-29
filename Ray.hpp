/*
    Ray.hpp

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
#include "Object.hpp"

class Ray {
    private:
        friend class Sphere;
        friend class Floor;
        friend class RayScanner;

        Vec3D support;
        Vec3D direction;
        VPO &objects;
    public:

        Ray (float xSup, float ySup, float zSup, float xDir, float yDir, float zDir);

        Ray (float xSup, float ySup, float zSup, float xDir, float yDir, float zDir, VPO &objects);

        bool scan ();
};