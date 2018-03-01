//
//  Circle.h
//  assignment5
//
//  Created by Chris Lawrence on 3/1/18.
//  Copyright © 2018 Chris Lawrence. All rights reserved.
//

#ifndef Circle_h
#define Circle_h

#include <stdio.h>
#include <string>
#include "Shape.h"

using namespace std;

class Circle : public Shape {
public:
  
    Circle(const string&, double radius);
    
    virtual double area() const override;
    
    virtual string toString() const override;
    
private:
    double radius;
};

#endif /* Circle_h */
