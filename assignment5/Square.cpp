//
//  Square.cpp
//  assignment5
//
//  Created by Chris Lawrence on 3/1/18.
//  Copyright © 2018 Chris Lawrence. All rights reserved.
//
// implementation of Square class, see header for comments

#include "Square.h"
#include "math.h"
#include <iomanip>
#include <sstream>

//set the color in the base class constructor, then set the side
Square::Square(const string& color, double side) : Shape(color) {
    this->side = side;
}

Square::~Square() {};

//use the math library for the pow function

double Square::area() const {
    return pow(side, 2);
}

string Square::toString() const {
    ostringstream outputString;
    
    outputString << getColor() << " Square with side of " << fixed
    << setprecision(2) << side
    << " and area of " << area() << endl;
    
    return outputString.str();
}
