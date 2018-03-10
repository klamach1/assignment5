//
//  main.cpp
//  assignment5
//
//  Created by Chris Lawrence on 3/1/18.
//  Copyright © 2018 Chris Lawrence. All rights reserved.
//
// This program will prompt the user for entry of up to
// a defined maximum number of shapes.  It presents the user
// with the option of manually entering the shape data or entering
// a file name of a space delimited file with the data.
// Once the data is collected into the array, the program will display the
// shapes, then sort the shapes, and then display the sorted shapes.

#include <iostream>
#include <fstream>
#include <string>
#include "Shape.h"

//defining these functions with extern to prevent OSX compiler issues
extern Shape* getShape();
extern Shape* getShape(string);

//function prototypes
int getManualInput(Shape**, int);
int getFileInput(Shape**, int);
void outputShapes(Shape**, int);

//main driver
int main(int argc, const char * argv[]) {
    
    //var for menu option input
    int inputOption = 0;
    
    //var to hold the input count
    int shapeCount = 0;
    
    //variable to help with bubble sort
    bool swapFlag = 1;
    
    //sort passes
    int sortPassCnt = 0;
    
    //max number of shapes to collect
    const int maxShapeCnt = 10;
    
    //array for the shapes, max of 10
    Shape* shapes[maxShapeCnt];
    
    //prompt the user for the shape entry option
    std::cout << "Enter 1 for manual shape input or 2 for a file input\n";
    
    std::cin >> inputOption;
    
    //call the appropriate function to collect the data
    if (inputOption == 1) {
        shapeCount = getManualInput(shapes, maxShapeCnt);
    } else if (inputOption == 2) {
        shapeCount = getFileInput(shapes, maxShapeCnt);
    }
    

    std::cout << endl << "The list of shapes entered...\n";
    
    //output the unsorted array
    outputShapes(shapes, shapeCount);
    
    std::cout << "Sorting shapes into order by area...\n";
    
    //bubble sort the array
    for (int i = 0; i < shapeCount && swapFlag; i++) {
        
        //flip the flag, if data is sorted the flag will flip back
        //otherwise the sort will finish
        swapFlag = 0;
        
        for (int j = 0; j < (shapeCount - i - 1); j++) {
            
            Shape* temp;
            
            if (shapes[j]->area() > shapes[j+1]->area()) {
                temp = shapes[j];
                shapes[j] = shapes[j+1];
                shapes[j+1] = temp;
                swapFlag = 1;
            }
            
        }
        ++sortPassCnt;
    }
    
    std::cout << "Sort pass count was " << sortPassCnt << endl;
    
    std::cout << endl << "The list of shapes entered...\n";
    
    //output the sorted array
    
    outputShapes(shapes, shapeCount);
    
    //free dynamically allocated memory
    
    for (int i = 0; i < shapeCount; ++i) {
        delete shapes[i];
    }
    
    return 0;
}

//function to collect user entry for shape data.  takes the array
//by reference to populate and the maximum number of shapes that can be collected
//returns the actual number of shapes collected

int getManualInput(Shape** shapes, int maxShapes) {
    
    int shapeCount = 0;
    
    Shape * theShape = nullptr;

     std::cout << "Enter a list of up to " << maxShapes <<
                " shapes - 'done' to end\n";
    
    //call the function getShape() in getShape.cpp to
    //prompt to the details of each shape and get the shape object
    //pointer back, and store it in the array
    //function returns a nullptr when the user signals done
     do {
     
     theShape = getShape();
     
     if (theShape != nullptr) {
     shapes[shapeCount] = theShape;
     ++shapeCount;
     }
     
     } while (theShape != nullptr && shapeCount < maxShapes);
    
    return shapeCount;
}


//function to collect filename for shape data.  takes the array
//by reference to populate and the maximum number of shapes that can be collected
//returns the actual number of shapes collected

int getFileInput(Shape** shapes,int maxShapes) {
    
    string fileName;
    
    int shapeCount = 0;
    
    Shape * theShape = nullptr;
    
    //prompt for the filename
    std::cout << "Enter a file with up to " << maxShapes
                << " to process\n";
    
    std::cin >> fileName;
    
    //use ifstream to open the input file
    std::ifstream inputFile(fileName);
    
    std::string inputLine;
    
    //read the file using getline, getline will return false
    //at the end of the file, loop can also be ended if the max
    //number of shapes has been reached
    while (std::getline(inputFile, inputLine) && shapeCount < maxShapes)
    {
        theShape = getShape(inputLine);
        shapes[shapeCount] = theShape;
        ++shapeCount;
    }
    //close the file to release the resource
    inputFile.close();
    
    return shapeCount;
}

//function to loop through the array and display the shapes.
//takes the shapes array and the number of shapes in the array

void outputShapes(Shape** shapes, int shapeCount) {
    for (int i = 0; i < shapeCount; ++i) {
        std::cout << shapes[i]->toString();
    }
    std::cout << endl;
}

