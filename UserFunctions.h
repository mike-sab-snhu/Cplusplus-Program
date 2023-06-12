// Declarations for User Functions

#ifndef UserFunctions_h // checking if header has been defined
#define UserFucntions_h // defining header if it has not yet been defined

void PrepareData(vector<GroceryItem>& t_inpList); // prepares data from input file
void PrintMenu(); // prints the main menu
char GetCheckInput(); // gets input and runs validation
void MenuOption1(vector<GroceryItem>& t_inpList); // executes menu option 1: single item data
void MenuOption2(vector<GroceryItem>& t_inpList); // executes menu option 2: all item data, numerical
void MenuOption3(vector<GroceryItem>& t_inpList); // executes menu option 3: all item data, histogram
void ExecuteMenuOption(char t_inpOption, vector<GroceryItem>& t_inpList); // execution block for chosen menu item
void MenuLoop(vector<GroceryItem>& t_inpList); // main program loop starting from menu print

#endif // closing header if-then