/*
    Vec3D.cpp

    version 3 (final version)
    
    CMI-TI 22 TINPRO045B
    Student: Thijs Dregmans (1024272)
    C++ eindopdracht
    Last edited: 29-10-2022

*/

#include <iostream>
#include <math.h>
#include <vector>

namespace st = std;

#include "Vec3D.hpp"

Vec3D::Vec3D() {}

Vec3D::Vec3D (float newX, float newY, float newZ): 
        x(newX),
        y(newY),
        z(newZ)
    {}

void Vec3D::show (st::string label) {
        st::cout << "Vec3D '" << label << "' coordinates: x=" << x << ", y=" << y << ", z=" << z << "\n";
    }

void Vec3D::show (st::string label, float scalar) {
        // label scalar and print in console
        st::cout << "Scalar=" << scalar << "\n";
    }

void Vec3D::show () {
        st::cout << "\n";
    }

Vec3D Vec3D::minus () const {
        return Vec3D(-x, -y, -z);
    }

Vec3D Vec3D::add (Vec3D const &other) const {
        return Vec3D(x + other.x, y + other.y, z + other.z);
    }

Vec3D Vec3D::sub (Vec3D const &other) const {
        return Vec3D(x - other.x, y - other.y, z - other.z);
    }

Vec3D Vec3D::mul (float const &scalar) const {
        return Vec3D(x * scalar, y * scalar, z * scalar);
    }

Vec3D Vec3D::div (float const &scalar) const {
        return Vec3D(x / scalar, y / scalar, z / scalar);
    }

float Vec3D::norm () const {
        return sqrt(pow(x, 2) + pow(y, 2) + pow(z, 2));
    }

Vec3D Vec3D::unit () const {
        auto vectorNorm = norm();
        return Vec3D(x / vectorNorm, y / vectorNorm, z / vectorNorm);
    }

float Vec3D::dot (Vec3D const &other) const {
        return (x * other.x) + (y * other.y) + (z * other.z);
    }

Vec3D Vec3D::cross (Vec3D const &other) const {
        return Vec3D(
            (y*other.z - z*other.y), 
            (z*other.x - x*other.z), 
            (x*other.y - y*other.x)
            );
    }