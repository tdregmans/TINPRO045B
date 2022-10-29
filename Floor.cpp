/*
    Floor.cpp

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
#include "Floor.hpp"
#include "Object.hpp"

Floor::Floor (float x, float y, float z):
            // The Floor has a center: Vec3D(x, y, z)
            Object(x, y, z)
        {}

float Floor::hit (Ray const &ray) const {
        // check if ray hits the Floor

        // The width of the white and black squares is 0.10 meter.
        auto widthSquares = 0.1;
        // The Floor has a length of 10 meter and a width of infinity.

        // Given in assignment: ((int) rowIndex % 2) == ((int) colIndex % 2);

        // There is a normal vector that stands with 90 degrees on the floor
        // To check whether a Ray hits the floor, we calculate the point the
        // Ray hits when y = height of the floor relative to the screen center

        // Source: https://en.wikipedia.org/wiki/Line%E2%80%93plane_intersection

        auto normalVector = Vec3D(0,1,0);
        
        // We calculate the difference between the center and the hitpoint
        // resulting in a vector. The dotproduct of this vector with the normal vector
        // if the dotproduct is zero, the vector and normal vector are right-angled.
        // if the dotproduct is zero, the floor is hit, so the method should return true

        // https://en.wikipedia.org/wiki/Line%E2%80%93plane_intersection#Algebraic_form

        auto d = center.sub(ray.support).dot(normalVector) / ray.direction.dot(normalVector);

        // d is the distance between the hit point to the start of the Ray.
        // We can calculate x, y and z with the formula: p = l0 + l * d

        auto hitpoint = ray.support.add(ray.direction.mul(d));

        hitpoint = ray.direction.mul(d);

        // return true if:
            // The Floor is hit,
            // the hitpoint is behind the screen,
            // there is a white square at the hitpoint and
            // the hitpoint z-coordinate is less than 10.

        return (d > 0 && hitpoint.z > 0 && ((int) (hitpoint.z / widthSquares) % 2 == 0 ^ (int) (hitpoint.x / widthSquares) % 2 == 0) ^ hitpoint.x > 0 && hitpoint.z < 10);
        
    }