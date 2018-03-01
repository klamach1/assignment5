//
//  Square.cpp
//  assignment5
//
//  Created by Chris Lawrence on 3/1/18.
//  Copyright © 2018 Chris Lawrence. All rights reserved.
//

#include "Square.h"
#include "math.h"

Square::Square(const string& color, double side) : Shape(color) {
    this->side = side;
}

double Square::area() const {
    return pow(side, 2);
}

string Square::toString() const {
    return "Rectangle";
}
