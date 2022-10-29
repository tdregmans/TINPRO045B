/*
    RayTracer.cpp

    version 3 (final version)
    
    CMI-TI 22 TINPRO045B
    Student: Thijs Dregmans (1024272)
    C++ eindopdracht
    Last edited: 29-10-2022

    Requirements
        -   Program must result in a Ray Tracer.
        -   The Program is programmed in c++.
        -   In the Ray Tracer, there are objects: 3 Spheres and 1 Floor.
        -   The Floor is made out of black and white squares, like a chessboard.
        -   The Program contains the methods laid out in all previous assignments.

    Tests
        Tests are done visually. The result of the program must look like the example
        provided in the assignment: 
        http://wiztech.nl/module_c++_voor_industriele_toepassingen/les_5_templates/overig_lesmateriaal/eindopdracht/ray_tracer/eindopdracht.pdf
        There are 4 Objects visible: 3 Spheres and 1 Floor.
        The Spheres reflect other Spheres and the Floor.
        The Floor is like a chessboard.

    Design
        Space
        This raytracer gives an image of a 3D space. You'll be able to see what is close and what is far.
        We work with 3 axis: x, y and z. The x-axis is the horizontal axis. The y-axis is the vertical axis.
        The z-axis is the axis that is rightly angeled on the other axes. It determines how far an Object is.
        The coördinate: (0, 0, 0) is in the center of the screen, on the screen.
        x=1 is one meter to the right. y=1 is one meter up. And z=1 is one meter behind the screen. 
        The class RayScanner calculates the x and y of the screen, based on the dimensions of my screen.

        There is a class Vec3D.
        It has methods to perform calulations on the 3D Vectors, like add. 
        Which methods are implemented by this class is determined by the assignment.

        There is a class Ray.
        It has the methods provided in the assignment.
        A Ray has two Vec3Ds, a support and a direction vector. With Rays, 
        we can check whether there is a object in the way of the camera.
        Rays start in the camera, and go through the screen. If they hit a Object,
        the program displays a char on the place of the screen.
        This way an image becomes visible.

        There is a class Sphere.
        It has the methods provided in the assignment: bool Sphere::hit(Ray const &ray) const;
        Sphere is a typ of Object, and therefore a child-class.
        A Shpere is a object in 3 dimensions. It has a center, which is stored as a Vec3D
        and a radius.

        There is a class Floor.
        It has the methods provided in the assignment: bool Floor::hit(Ray const &ray) const;
        The Floor is a typ of Object, and therefore a child-class.
        The Floor is a object in 3 dimensions. It is a surface behind the screen.

        There is a class Object.
        The classes Sphere and Floor are childs of this class.
        Object has a virtual method: virtual bool hit (Ray const &ray) const = 0;
        With this method, we can loop through Spheres and Floors, which are both Objects, and call the hit method in one line.

        There is a class RayScanner.
        It has 4 objects with which the image is to be constructed.
        The main function creates the Objects in a vector<Object*>.
        An instance of RayScanner is than defined.
        RayScanner has a scan() method. This method constructs the image by doing this basic process:
        -   Take the width and height of the screen. Calculate how many pixels/chars are needed.
        -   For each pixel/char, construct a Ray that goes from the camera through the screen on the place of the pixel.
        -   Go through all Objects: check whether the Ray hits any Object.
        -   Whether it hits determines what char is printed.


        There are some things I have to change before handing in the assignment:
        -   Follow Rays after impact. 
        -   Check whether the y-axis is at the center of the image.
        -   Implement the bounce of a Ray.
        -   Use a brightness in Ray.
            In each bounce on a Sphere, the brightness is reduced with 40%.
            In each bounce on the Floor, if a black square is hit,
            brightness is reduced with 100%. If a white square is hit,
            brightness is reduced with 0%. A Ray cannot have more than 3 bounces.

*/

#include <iostream>
#include <math.h>
#include <vector>

#define VPO st::vector<Object*>

#define VF st::vector<float>
#define VVF st::vector<VF>

namespace st = std;

#include "Ray.hpp"
#include "Object.hpp"
#include "Sphere.hpp"
#include "Floor.hpp"
#include "RayScanner.hpp"

int main() {

    // Create objects
    Sphere object1 = Sphere(0.3, 0, 10, 0.2);
    Sphere object2 = Sphere(-0.2, -0.1, 10, 0.1);
    Sphere object3 = Sphere(0, 0, 20, 1);
    Floor object4 = Floor(0, -0.1, 1);

    auto objects = VPO ();
    // Push objects in vector
    objects.push_back(&object1);
    objects.push_back(&object2);
    objects.push_back(&object3);

    objects.push_back(&object4);

    // Start RayScanner
    RayScanner rayScanner(objects);
    st::cout << "Scanning ... \n";
    rayScanner.scan();

    return 0;

    // to run program:
        // g++ *.cpp -o RayTracer.exe
}