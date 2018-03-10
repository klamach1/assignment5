//
//  Shape.h
//  assignment5
//
//  Created by Chris Lawrence on 3/1/18.
//  Copyright © 2018 Chris Lawrence. All rights reserved.
//
// Abstract class to define the basis for a shape

#ifndef Shape_h
#define Shape_h

#include <stdio.h>
#include <string>

using namespace std;

class Shape {
public:
    //contructor to set color
    Shape(const string&);
    
    //virtual destructor to facilitate deletes
    virtual ~Shape();
    
    //function to get the object colot
    string getColor() const;
    
    //abstract function to calculate area
    virtual double area() const = 0;
    
    //abstract function to display shape attributes
    virtual string toString() const = 0;

private:
    string color;
};
#endif /* Shape_h */
