//
//  Circle.h
//  assignment5
//
//  Created by Chris Lawrence on 3/1/18.
//  Copyright © 2018 Chris Lawrence. All rights reserved.
//
// child class of Shape, concrete class representing a circle

#ifndef Circle_h
#define Circle_h

#include <stdio.h>
#include <string>
#include "Shape.h"

using namespace std;

class Circle : public Shape {
public:
    //constructor takes color and radius
    Circle(const string&, double);
    //virtual destructor
    virtual ~Circle();
    //override of virtual function area specific to a circle
    virtual double area() const override;
    //override of virtual function toString specific to a circle
    virtual string toString() const override;
    
private:
    double radius;
};

#endif /* Circle_h */
