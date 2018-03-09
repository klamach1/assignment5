//
//  main.cpp
//  assignment5
//
//  Created by Chris Lawrence on 3/1/18.
//  Copyright © 2018 Chris Lawrence. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <string>
#include "Shape.h"

extern Shape* getShape();
extern Shape* getShape(string);

int main(int argc, const char * argv[]) {
    
    //fstream inputFile;
    
    //inputFile.open("input.txt", ios::in);

    int shapeCount = 0;
    
    Shape* shapes[10];
    
    Shape * theShape = nullptr;
    /*
    std::cout << "Enter a list of shapes - 'done' to end\n";
    
    do {
    
        theShape = getShape();
        
        if (theShape != nullptr) {
            shapes[shapeCount] = theShape;
            ++shapeCount;
        }
    
    } while (theShape != nullptr);
     
    */
    
    std::ifstream inputFile("/Users/claw/input.txt");
    
    std::string str;
    while (std::getline(inputFile, str))
    {
        theShape = getShape(str);
        shapes[shapeCount] = theShape;
        ++shapeCount;
    }
    
    for (int i = 0; i < shapeCount; ++i) {
        std::cout << shapes[i]->toString();
        delete shapes[i];
    }
    
    
    
    

    
    return 0;
}
