//
//  Square.h
//  assignment5
//
//  Created by Chris Lawrence on 3/1/18.
//  Copyright © 2018 Chris Lawrence. All rights reserved.
//
// child class of Shape, concrete class representing a square

#ifndef Square_h
#define Square_h

#include <stdio.h>
#include "Shape.h"

using namespace std;

class Square : public Shape {
public:
    //constructor takes color and side measure
    Square(const string&, double);
    //virtual destructor
    virtual ~Square();
    
    //override of virtual function area specific to a square
    virtual double area() const override;
    
    //override of virtual function toString specific to a square
    virtual string toString() const override;
    
private:
    double side;
};
#endif /* Square_h */
