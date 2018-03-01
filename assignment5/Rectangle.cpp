//
//  Rectangle.cpp
//  assignment5
//
//  Created by Chris Lawrence on 3/1/18.
//  Copyright © 2018 Chris Lawrence. All rights reserved.
//

#include "Rectangle.h"

Rectangle::Rectangle(const string& color, double length, double width) : Shape(color) {
    this->length = length;
    this->width = width;
}

double Rectangle::area() const {
    return length * width;
}

string Rectangle::toString() const {
    return "Rectangle";
}


