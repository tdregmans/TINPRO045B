/*
    Ray.cpp

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
#include "Object.hpp"
#include "Ray.hpp"

Ray::Ray (float xSup, float ySup, float zSup, float xDir, float yDir, float zDir):
            support(xSup, ySup, zSup),
            direction(xDir, yDir, zDir),
            objects(objects)
        {}

Ray::Ray (float xSup, float ySup, float zSup, float xDir, float yDir, float zDir, VPO &objects):
            support(xSup, ySup, zSup),
            direction(xDir, yDir, zDir),
            objects(objects)
        {}

bool Ray::scan () {
        // call hit() for all Objects. True if any Object is hit.
        // should only be used if the second constructor constructed Ray !!!

        for(auto object: objects) {
            if (object->hit(*this)) {
                return true;
            }
        }
        return false;
}