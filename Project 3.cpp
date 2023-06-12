// Mike Sabeiha | CS 210 | Project 3 | Corner Grocer Data Analysis

#include <iostream> // importing input/output functionality
#include <fstream> // importing file read/write functionality
#include <string> // importing c++ string functionality
#include <vector> // importing vector for easy lists
#include <iomanip> // importing string manipulation for output formatting

using namespace std; // conforming to standardized namespace

#include "GroceryItem.h" // imports class for grocery items
#include "UserFunctions.h" // imports user functions

int main() {
    vector<GroceryItem> ItemList; // establishing global list of grocery items to store data internally to app

    PrepareData(ItemList); // pulls data from files, refines, stores internally and externally, closes files
    MenuLoop(ItemList); // main program loop

}


