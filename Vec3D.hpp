/*
    Vec3D.hpp

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

namespace st = std;

class Vec3D { 
    public: 
        float x, y, z;

        Vec3D ();

        Vec3D (float newX, float newY, float newZ);

        void show (st::string label);

        void show (st::string label, float scalar);

        void show ();

        Vec3D minus () const;

        Vec3D add (Vec3D const &other) const;

        Vec3D sub (Vec3D const &other) const;

        Vec3D mul (float const &scalar) const;

        Vec3D div (float const &scalar) const;

        float norm () const;

        Vec3D unit () const;

        float dot (Vec3D const &other) const;

        Vec3D cross (Vec3D const &other) const;
};