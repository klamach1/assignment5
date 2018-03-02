//
//  main.cpp
//  assignment5
//
//  Created by Chris Lawrence on 3/1/18.
//  Copyright © 2018 Chris Lawrence. All rights reserved.
//

#include <iostream>
#include <string>
#include "Shape.h"
#include "getShape.cpp"

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Enter a list of shapes - 'done' to end\n";
    
    Shape * theShape = getShape();
    
    theShape->toString();
    

    
    return 0;
}
