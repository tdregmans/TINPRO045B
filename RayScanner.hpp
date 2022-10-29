/*
    RayScanner.hpp

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

#include "Object.hpp"

class RayScanner {
    private:
        VPO objects;
    public:
        RayScanner(VPO objects);

        void scan();
};
