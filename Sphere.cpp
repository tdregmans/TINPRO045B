/*
    Sphere.cpp

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
#include "Sphere.hpp"

Sphere::Sphere (float x, float y, float z, float radius):
            Object(x, y, z),
            radius(radius)
            
        {}

float Sphere::distFromRay (Ray const &ray) const {
        // Distance from Ray.support to center
        return ray.support.sub(center).cross(ray.direction).norm();
    }

float Sphere::hit (Ray const &ray) const {
        return distFromRay(ray) <= radius;
    }

Vec3D Sphere::hitPoint (Ray const &ray) const {
        // Point of impact

        // hitPoint is the point the Ray hits Sphere
        // The point can be calulated: The ray.support and the ray.direction make the ray
        // Ray.support plus a vector in ray.directon with length d is the hitpoint

        auto length = distFromRay(ray) - radius;
        Vec3D const direction = ray.direction.unit().mul(length);

        return ray.support.add(direction);
    }
