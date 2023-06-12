// Definitions for User Functions

#include <iostream> // importing input/output functionality
#include <fstream> // importing file read/write functionality
#include <string> // importing c++ string functionality
#include <vector> // importing vector for easy lists
#include <iomanip> // importing string manipulation for output formatting

using namespace std; // conforms to standardized namespace

#include "GroceryItem.h" // imports class for grocery items
#include "UserFunctions.h" // imports user functions

void PrepareData(vector<GroceryItem>& t_inpList) { // prepares data from input file using ItemList as input

    // This function does the following:
    // 1.) It reads the input file provided
    // 2.) Populates a global ItemList with unique grocery items found in the input file (simultaneous)
    // 3.) Counts the number of times each unique grocery item is present in the input file (simultaneous)
    // 4.) Stores that information in the global list (simultaneous)
    // 5.) Outputs the global list to a new output file
    // 6.) Saves that new file as 'frequency.dat'
    // 7.) Closes both the input and output files


    ifstream inpData; // declaring local variable for input file
    ofstream outData; // declaring local variable for output file
    string inputString; // declaring local variable for data line from input file
    int sizeList = 0; // declaring local variable to track size of unique grocery item list (the input parameter)
    bool matchName = false; // declaring local variable to track if input data matches any item in ItemList

    inpData.open("C:\\Users\\The Workshop\\Desktop\\Project 3\\CS210_Project_Three_Input_File.txt"); // input file location
    outData.open("C:\\Users\\The Workshop\\Desktop\\Project 3\\frequency.dat"); // output file location

    if (!inpData.is_open() || !outData.is_open()) { // if either file has a problem opening
        cout << "There was a problem opening a file..." << endl; // print and end program
    }
    else { // if both files open successfully
        getline(inpData, inputString); // get the first line of input from input file

        while (!inpData.fail()) { // while there are lines left in the file to be read
            sizeList = t_inpList.size(); // takes the current size of the ItemList
            for (int i = 0; i < sizeList; i++) { // iterates through it
                if (inputString == t_inpList.at(i).getItemName()) { // if there is a match between input word and an item from the current list
                    matchName = true; // matchName is true (which means a new item IS NOT added)
                    t_inpList.at(i).incItemCount(); // the count for that unique item is incremented by 1
                }
            }

            if (matchName == false) { // if matchName is false (meaning there was no such item found in the ItemList)
                GroceryItem item = GroceryItem(inputString); // a new object is created with the name set to inputString from the input file
                t_inpList.push_back(item); // the new object is added to the ItemList
            }

            matchName = false; // matchName is reset to false (since it's something of a trigger mechanism, it needs to be reset)
            getline(inpData, inputString); // a new line of data from the input file is read
        }

        sizeList = t_inpList.size(); // once the input file has been scrubbed for unique items
        for (int i = 0; i < sizeList; i++) { // the ItemList including all unique items and their counts is iterated through
            outData << t_inpList.at(i).getItemName() << ": " << t_inpList.at(i).getItemCount() << endl; // data printed to new output file
        }

    }

    inpData.close(); // close input file
    outData.close(); // close output file
}

void PrintMenu() { // prints the main menu
    cout << "=============== Main Menu ========================" << endl;
    cout << "__________________________________________________" << endl;
    cout << "Menu Option 1: Print Single Item Data" << endl;
    cout << "Menu Option 2: Print All Item Data, Numerical" << endl;
    cout << "Menu Option 3: Print All Item Data, Histogram" << endl;
    cout << "Menu Option 4: Quit Program" << endl;
    cout << "==================================================" << endl;
}

char GetCheckInput() { // gets input and runs validation
    string tmpInput; // local variable to store user input on menu option selection
    bool loopBreak = false; // loop break that toggles in or out of a loop
    char menuSelect; // stores the menu selection input once validated

    cout << ">>> "; // input line

    while (!loopBreak) { // while loop break reads false--send it
        getline(cin, tmpInput); // grab the next line of user input

        // if the input contains errant data such as a space with no data, newline, tab, etc.
        if (tmpInput.find("\n") != string::npos || tmpInput.find("\t") != string::npos || tmpInput.find(" ") != string::npos || tmpInput.length() == 0) {
            cout << "Invalid input.  Please try again..." << endl; // tell user they messed up
            cout << ">>> "; // input line
            continue; // restart the loop
        }
        else { // if the input does not contain errant data
            if (isdigit(tmpInput.at(0))) { // run it through the validation check to be sure of its content
                menuSelect = tmpInput.at(0); // menu selection is the first character of the input string
                return menuSelect; // returns the menu selection character
                loopBreak = true; // break the loop
            }
            else { // if the string has no errant data but does not pass the validation check
                cout << "Invalid input.  Please try again..." << endl; // tell the user they messed up
                cout << ">>> "; // input line
            }
        }
    }

    cout << endl; // for the formatting

}

void MenuOption1(vector<GroceryItem>& t_inpList) { // executes menu option 1: single item data
    string tmpInput; // local variable to store user input on which grocery item they want data for
    bool loopBreak = false; // loop break that toggles in or out of a loop
    int sizeList = t_inpList.size(); // stores the size of the ItemList for later use

    cout << endl; // formatting
    cout << "Please enter the desired item..." << endl; // user prompt
    cout << ">>> "; // input line

    while (!loopBreak) { // while loop break reads false--send it
        getline(cin, tmpInput); // grab the next line of user input

        // if the input contains errant data such as a space with no data, newline, tab, etc.
        if (tmpInput.find("\n") != string::npos || tmpInput.find("\t") != string::npos || tmpInput.find(" ") != string::npos || tmpInput.length() == 0) {
            cout << "Invalid input.  Please try again..." << endl; // tell user they messed up
            cout << ">>> "; // input line
            continue; // restart the loop
        }

        if (tmpInput == "Quit" || tmpInput == "quit") { // just in case the user wants to back out of option 1 they can enter 'Quit'
            break; // break to main loop (they still need to select option 4 to quit program)
        }

        else { // if the input does not contain errant data
            for (int i = 0; i < sizeList; i++) { // iterates through ItemList
                if (tmpInput == t_inpList.at(i).getItemName()) { // if user input matches a unique grocery item in ItemList
                    cout << endl; // print new line
                    cout << setfill(' ') << setw(15) << t_inpList.at(i).getItemName(); // print item name
                    cout << " | "; // print divider bar for formatting
                    cout << t_inpList.at(i).getItemCount() << endl; // print item count and new line
                    loopBreak = true; // break the loop
                }
            }
            if (!loopBreak) { // if the string has no errant data but does not pass the validation check
                cout << "Invalid input.  Please try again..." << endl; // tell the user they messed up
                cout << ">>> "; // input line
            }
        }
    }

    cout << endl << "[enter] to continue..." << endl; // prompt user to press enter to continue
    cin.get(); // enter continues

}

void MenuOption2(vector<GroceryItem>& t_inpList) { // executes menu option 2: all item data, numerical
    int sizeList = t_inpList.size(); // stores the size of the ItemList for later use

    for (int i = 0; i < sizeList; i++) { // iterates through ItemList
        cout << setfill(' ') << setw(15) << t_inpList.at(i).getItemName(); // prints each items name
        cout << " | "; // prints a space and a divider bar
        cout << t_inpList.at(i).getItemCount() << endl; // prints the numerical value of the item count
    }

    cout << endl << "[enter] to continue..." << endl; // prompt user to press enter to continue
    cin.get(); // enter continues

}

void MenuOption3(vector<GroceryItem>& t_inpList) { // executes menu option 3: all item data, histogram
    int sizeList = t_inpList.size(); // stores the size of the ItemList for later use

    for (int i = 0; i < sizeList; i++) { // iterates through ItemList
        cout << setfill(' ') << setw(15) << t_inpList.at(i).getItemName(); // prints each items name
        cout << " | "; // prints a space and a divider bar
        cout << setfill(']') << setw(t_inpList.at(i).getItemCount()) << "" << endl; // prints a historgram of the item count
    }

    cout << endl << "[enter] to continue..." << endl; // prompt user to press enter to continue
    cin.get(); // enter continues

}

void ExecuteMenuOption(char t_inpOption, vector<GroceryItem>& t_inpList) { // execution block for chosen menu item
    switch (t_inpOption) { // switch statement for menu options
    case '1': // option 1: single item data
        cout << endl; // formatting
        cout << "Print Single Item Data..." << endl; // reminder what was chosen
        MenuOption1(t_inpList); // run function for menu option 1
        cout << endl; // formatting
        break;
    case '2': // option 2: all item data, numerical
        cout << endl; // formatting
        cout << "Print All Item Data, Numeric..." << endl; // reminder what was chosen
        cout << endl; // formatting
        MenuOption2(t_inpList); // run function for menu option 2
        cout << endl; // formatting
        break;
    case '3': // option 3: all item data, histogram
        cout << endl; // formatting
        cout << "Print All Item Data, Histogram..." << endl; // reminder what was chosen
        cout << endl; // formatting
        MenuOption3(t_inpList); // run function for menu option 3
        cout << endl; // formatting
        break;
    case '4': // option 4: quit program
        cout << endl; // formatting
        cout << "Quitting Program..." << endl; // reminder what was chosen
        cin.get(); // waiting for user to press enter
        break;
    default: // default
        cout << "Default case selected..." << endl;
        break;
    }
}

void MenuLoop(vector<GroceryItem>& t_inpList) { // main program loop starting from menu print
    char choice = ' '; // default menu option choice is a blank space to get us into the loop

    while (choice != '4') { // repeat as long as the user does not select menu option 4...
        PrintMenu(); // print the main menu
        choice = GetCheckInput(); // get their choice of menu option
        ExecuteMenuOption(choice, t_inpList); // execute that menu option 
    }
}