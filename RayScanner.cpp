/*
    RayScanner.cpp

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

#define VF st::vector<float>
#define VVF st::vector<VF>

namespace st = std;

#include "Object.hpp"
#include "RayScanner.hpp"
#include "Ray.hpp"

RayScanner::RayScanner(VPO objects):
    objects (objects)
    {}

void RayScanner::scan() {
    // take all objects, screen dimensions and use Ray
    auto const nrOfRows = 300;
    auto const nrOfCols = 2.5 * nrOfRows;
    auto const aspectRatio = 2;

    auto const pixelChars = " M";

    // distance form screen is 3 meter, given in assignment
    auto const distFromScreen = 3.00;

    auto const screenHeight = 0.20;
    auto const screenWidth = 2.5 * screenHeight;

    auto far = 10000;

    // for each char on the screen:
        // calculate x and y on the screen
        // take a Ray
        // check if Ray touches any Objects
        // return appropiate char in VVF
        
    VVF image;
    // calculate values for each row
    for(auto rowIndex = 0; rowIndex < nrOfRows; rowIndex++) {
        auto y = (nrOfRows / 2.0 - rowIndex) / nrOfRows * screenHeight * aspectRatio;
        VF row;
        // calculate value for each pixel in row
        for(auto colIndex = 0; colIndex < nrOfCols; colIndex++) {
            auto x = (colIndex - nrOfCols / 2.0) / nrOfCols * screenWidth;

            // Create Ray
            auto direction = Vec3D(x, y, 0).sub(Vec3D(0, 0, -distFromScreen));
            Ray ray(0, 0, distFromScreen, direction.x, direction.y, direction.z, objects);

            // check if ray hits objects
            if(ray.scan()) {
                row.push_back(1.0);
            }
            else {
                row.push_back(0.0);
            }
        }
        image.push_back(row);
    }

    // print VVF on screen
    for(auto y: image) {
        for(auto x: y) {
            st::cout << pixelChars[(int) x];
        }
        st::cout << "\n";
    }
}