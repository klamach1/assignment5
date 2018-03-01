//
//  Rectangle.h
//  assignment5
//
//  Created by Chris Lawrence on 3/1/18.
//  Copyright © 2018 Chris Lawrence. All rights reserved.
//

#ifndef Rectangle_h
#define Rectangle_h

#include <stdio.h>

#include "Shape.h"

using namespace std;

class Rectangle : public Shape {
public:
    
    //color, length, width
    Rectangle(const string&, double, double);
    
    virtual double area() const override;
    
    virtual string toString() const override;
    
private:
    double length;
    double width;
};

#endif /* Rectangle_h */
