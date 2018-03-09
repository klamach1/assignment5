//
//  getShape.cpp
//  assignment5
//
//  Created by Chris Lawrence on 3/1/18.
//  Copyright © 2018 Chris Lawrence. All rights reserved.
//


#include <stdio.h>
#include <iostream>
#include <sstream>
#include <string>
#include "Rectangle.h"
#include "Square.h"
#include "Circle.h"


// getShape function that takes user input for shapes

Shape * getShape() {
    
    Shape * theShape = nullptr;
    string typeOfShape;
    string colorOfShape;
    double side;
    double radius;
    double length;
    double width;
    
    std::cout << "Enter the shape's color (or 'done')...\n";
    std::cin >> colorOfShape;
    
    if (colorOfShape != "done") {
        std::cout << "Enter shape type...\n";
        std::cin >> typeOfShape;
        
        if (typeOfShape == "circle") {
            std::cout << "Enter the radius...\n";
            std::cin >> radius;
            theShape = new Circle(colorOfShape, radius);
        }
        else if (typeOfShape == "rectangle") {
            std::cout << "Enter the length...\n";
            std::cin >> length;
            std::cout << "Enter the width...\n";
            std::cin >> width;
            theShape = new Rectangle(colorOfShape, length, width);
        } else if (typeOfShape == "square") {
            std::cout << "Enter the side...\n";
            std::cin >> side;
            theShape = new Square(colorOfShape, side);
        }
        
    } else {
        theShape = nullptr;
    }
    return theShape;
    
}

// getShape function that takes a string for input

Shape * getShape(string input) {
    
    Shape * theShape = nullptr;
    string typeOfShape;
    string colorOfShape;
    double firstMeasure = 0.0;
    double secondMeasure = 0.0;
    
    int pos = 0;
    
    string splitString[4];
    
    istringstream stream(input);
    
    while (stream) {
        
        switch (pos) {
            case 0:
                stream >> colorOfShape;
            case 1:
                stream >> typeOfShape;
            case 2:
                stream >> firstMeasure;
            case 3:
                stream >> secondMeasure;
        }
        
        ++pos;
    }
    
    
    
    
    if (typeOfShape == "circle") {
        theShape = new Circle(colorOfShape, firstMeasure);
    }
    else if (typeOfShape == "rectangle") {
        theShape = new Rectangle(colorOfShape, firstMeasure, secondMeasure);
    } else if (typeOfShape == "square") {
        theShape = new Square(colorOfShape, firstMeasure);
    }
    
    return theShape;
    
}

