//
//  Shape.cpp
//  assignment5
//
//  Created by Chris Lawrence on 3/1/18.
//  Copyright © 2018 Chris Lawrence. All rights reserved.
//
// implementation of shape class, see header for comments

#include "Shape.h"
#include <string>

Shape::Shape(const string& color) {
    this->color = color;
}

Shape::~Shape() {};

string Shape::getColor() const {
    return color;
}
