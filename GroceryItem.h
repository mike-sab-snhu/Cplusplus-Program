// Declarations for GroceryItem Class

#ifndef GroceryItem_h // checking to see if header has been defined
#define GroceryItem_h // defining header if it has not yet been defined

class GroceryItem { // class to track unique grocery items and their counts
public:
	GroceryItem(string t_inpName); // default constructor
	void setItemName(string t_inpName); // setter for item name
	string getItemName(); // getter for item name
	void incItemCount(); // increments item count by 1
	int getItemCount(); // getter for item count

private:
	string m_ItemName = "None"; // item name with default to 'none'
	int m_ItemCount = 1; // item count with default to '1'
};

#endif // closing header if-then