//
//  getShape.cpp
//  assignment5
//
//  Created by Chris Lawrence on 3/1/18.
//  Copyright © 2018 Chris Lawrence. All rights reserved.
//
// file containing two version of getShape.  One version takes
// no parameters and prompts the user for the details of a shape,
// and then creates the new object and returns a pointer.
// the other version takes a space-delimited string and parses it
// and then creates the new object and returns a pointer


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
    
    //collect the input, if the color == "done" then return nullptr
    
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
    //generic variables to simplify parsing logic
    double firstMeasure = 0.0;
    double secondMeasure = 0.0;
    
    //helper var to track the parser
    int pos = 0;
    
    //use istringstream to parse the string
    //with the space delimiter
    istringstream stream(input);
    
    //while the string is being parsed
    while (stream) {
        //assign the values based on the pos loop counter
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
    
    
    
    //create the object and return it
    
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

