//
//  Rectangle.h
//  assignment5
//
//  Created by Chris Lawrence on 3/1/18.
//  Copyright © 2018 Chris Lawrence. All rights reserved.
//
// child class of Shape, concrete class representing a rectangle

#ifndef Rectangle_h
#define Rectangle_h

#include <stdio.h>

#include "Shape.h"

using namespace std;

class Rectangle : public Shape {
public:
    
    //color, length, width
    Rectangle(const string&, double, double);
    
    virtual ~Rectangle();
    
    //override of virtual function area specific to a rectangle
    virtual double area() const override;
    
    //override of virtual function toString specific to a rectangle
    virtual string toString() const override;
    
private:
    double length;
    double width;
};

#endif /* Rectangle_h */
