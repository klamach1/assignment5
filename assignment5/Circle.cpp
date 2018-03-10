//
//  Circle.cpp
//  assignment5
//
//  Created by Chris Lawrence on 3/1/18.
//  Copyright © 2018 Chris Lawrence. All rights reserved.
//
//  Implementation of Circle class, see header for comments


#include "Circle.h"
#include <cmath>
#include <iomanip>
#include <sstream>
const double pi = 3.14159265358979323846;

//pass color to the base class contructor and then set radius
Circle::Circle(const string& color, double radius) : Shape(color) {
    this->radius = radius;
}

Circle::~Circle() {};

//use the math library to get PI and the pow function
double Circle::area() const {
    return pi * pow(radius,2);
};

string Circle::toString() const {
    ostringstream outputString;
    
    outputString << getColor() << " Circle with radius of " << fixed
    << setprecision(2) << radius << " and area of "
    << area() << endl;
    
    return outputString.str();
};
