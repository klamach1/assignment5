//
//  Circle.cpp
//  assignment5
//
//  Created by Chris Lawrence on 3/1/18.
//  Copyright © 2018 Chris Lawrence. All rights reserved.
//


#include "Circle.h"
#include "math.h"

Circle::Circle(const string& color, double radius) : Shape(color) {
    this->radius = radius;
}

double Circle::area() const {
    return M_PI * pow(radius,2);
};

string Circle::toString() const {
    return "Circle";
};
