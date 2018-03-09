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

int getManualInput(Shape**);
int getFileInput(Shape**);

int main(int argc, const char * argv[]) {
    
    int inputOption = 0;
    
    int shapeCount = 0;
    
    Shape* shapes[10];
    
    std::cout << "Enter 1 for manual shape input or 2 for a file input\n";
    
    std::cin >> inputOption;
    
    if (inputOption == 1) {
        shapeCount = getManualInput(shapes);
    } else if (inputOption == 2) {
        shapeCount = getFileInput(shapes);
    }
    
    for (int i = 0; i < shapeCount; ++i) {
        std::cout << shapes[i]->toString();
        delete shapes[i];
    }
    
    return 0;
}

int getManualInput(Shape** shapes) {
    
    int shapeCount = 0;
    
    Shape * theShape = nullptr;

     std::cout << "Enter a list of shapes - 'done' to end\n";
     
     do {
     
     theShape = getShape();
     
     if (theShape != nullptr) {
     shapes[shapeCount] = theShape;
     ++shapeCount;
     }
     
     } while (theShape != nullptr);
    
    return shapeCount;
}

int getFileInput(Shape** shapes) {
    
    string fileName;
    
    int shapeCount = 0;
    
    Shape * theShape = nullptr;
    
    std::cout << "Enter a file to process\n";
    
    std::cin >> fileName;
    
    std::ifstream inputFile(fileName);
    
    std::string str;
    while (std::getline(inputFile, str))
    {
        theShape = getShape(str);
        shapes[shapeCount] = theShape;
        ++shapeCount;
    }
    
    return shapeCount;
}

