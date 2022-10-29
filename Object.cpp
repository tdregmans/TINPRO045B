/*
    Object.cpp

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

Object::Object () {};

Object::Object (float x, float y, float z):
            center(x, y, z)
        {}