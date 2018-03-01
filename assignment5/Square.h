//
//  Square.h
//  assignment5
//
//  Created by Chris Lawrence on 3/1/18.
//  Copyright © 2018 Chris Lawrence. All rights reserved.
//

#ifndef Square_h
#define Square_h

#include <stdio.h>
#include "Shape.h"

using namespace std;

class Square : public Shape {
public:
    
    Square(const string&, double side);
    
    virtual double area() const override;
    
    virtual string toString() const override;
    
private:
    double side;
};
#endif /* Square_h */
