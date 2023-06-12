// Definitions for GroceryItem Class

#include <iostream> // importing input/output functionality
#include <fstream> // importing file read/write functionality
#include <string> // importing c++ string functionality
#include <vector> // importing vector for easy lists
#include <iomanip> // importing string manipulation for output formatting

using namespace std; // conforming to standardized namespace

#include "GroceryItem.h" // imports class for grocery items

GroceryItem::GroceryItem(string t_inpName) { m_ItemName = t_inpName; } // default constructor
void GroceryItem::setItemName(string t_inpName) { m_ItemName = t_inpName; } // sets item name to input name
string GroceryItem::getItemName() { return m_ItemName; } // returns item name as string
void GroceryItem::incItemCount() { m_ItemCount++; } // increments item count by 1
int GroceryItem::getItemCount() { return m_ItemCount; } // returns item count as integer