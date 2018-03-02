//
//  getShape.cpp
//  assignment5
//
//  Created by Chris Lawrence on 3/1/18.
//  Copyright © 2018 Chris Lawrence. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include "Rectangle.h"
#include "Square.h"
#include "Circle.h"




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
        std::cout << "Enter shape type...";
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
        
    }
    return theShape;

}
