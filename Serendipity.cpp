/******************************************************************************
 *File name: Seredipity.cpp
 *Project name: Serendipity Menus
 *-----------------------------------------------------------------------------*
 * Creator's name: Sami Hamad
 * Creator's email: mohammed.shamad12@gmail.com
 * Creation Date: 1-20-2019
 * Date last modified: 4-16-2019
 ******************************************************************************
 * Purpose: Navigate through the Menus of the Serendipity bookstore.
 * Print and Format Receipts
 *Add functions to the inventory menus, such as add books, edit books, lookup
 * books, and delete books using parallel arrays.
 * Error checking user inputs.
 * Create a search function using substrings that is not case sensitive.
 * Convert parallel arrays to a series of structs
 * convert array of structs to an array of classes. Add functionality to the
 * cashier menu option.
 * convert the array of classes to an array of pointers.
 * create the first 3 report modules. rep Retail, repWholesale and repListings
 * ****************************************************************************/

//*****************************************************************************
//								Data Dictionary
// Constants
//
// - Name					Data Type				Initial Value
//	SIZE					int						20
// Variables
//
// - Name
//  mainMenuOption			 Int					0
//  menuTwoOption			 Int				    null
//  menuThreeOption			 Int					null
//  bookQuantity  			 int					null
//	bookCount				 int					0
//	subtotal				 double					null
//	taxPrice				 double					null
//	finalTotal				 double					null
//  price					 float					null
//  date					 char					null
//	junk					 char					null
//	menuReturn				 char					'Y'
//	ISBN					 string					null
//  bookTitle				 string					null
//  isbn[SIZE];				string					SIZE
/*	qtyOnHand;				int
	wholesale;				double
	retail;					double
	book					bookType				20
	bookTitle				bookType
	isbn					bookType
	author					bookType
	publisher				bookType
	date					bookType
	qty						bookType
	wholesale				bookType
	retail					bookType
	**book					bookType				nullptr
******************************************************************************/

#include "Serendipity.h"


int main()
{
	int bookCounter = 0;
	int mainMenuOption = 0;
	char menuReturn = 'Y';


	fstream myfile;
	ofstream fout;
	string tempTitle;
	string tempIsbn;
	string tempAuthor;
	string tempPub;
	string tempDateAdded;
	int tempQty;
	double tempWholesale;
	double tempRetail;

	BookType *temp = nullptr;

    orderedLinkedList<BookType> listName, listWholesale, listDate, listQty;

    listName.initializeList();
    listWholesale.initializeList();
    listDate.initializeList();
    listQty.initializeList();

    myfile.open("databse.txt");
    do
    {
    	getline(myfile, tempTitle);
    	getline(myfile, tempIsbn);
    	getline(myfile, tempAuthor);
    	getline(myfile, tempPub);
    	getline(myfile, tempDateAdded);
    	myfile >> tempQty;
    	myfile.ignore(10000, '\n');
    	myfile >> tempWholesale;
    	myfile.ignore(10000, '\n');
    	myfile >> tempRetail;
    	myfile.ignore(10000, '\n');

    	temp = new BookType (tempTitle, tempIsbn, tempAuthor, tempPub, tempDateAdded, tempQty, tempWholesale, tempRetail);

    	listName.insert(*temp);

    	(*temp).setSortCode(2);
    	listWholesale.insert(*temp);

    	(*temp).setSortCode(3);
    	listDate.insert(*temp);

    	(*temp).setSortCode(1);
    	listQty.insert(*temp);

    	BookType::IncBookCount();

    }while (!myfile.eof());
    myfile.close();


	while (mainMenuOption != 4)
	{
		menuReturn = 'Y';
		system ("clear");
		cout << "    Serendipity Booksellers  " << endl;
		cout << "            Main Menu        " << endl << endl;
		cout << "1.  Cashier Module           " << endl;
		cout << "2.  Inventory Database Module" << endl;
		cout << "3.  Report Module            " << endl;
		cout << "4.  Exit                     " << endl << endl;

		do // while (mainMenuOption != 1 && mainMenuOption != 2 && mainMenuOption != 3
		{
		cout << "Enter Your Choice: ";
		cin  >> mainMenuOption;
		cin.ignore (100000, '\n');
		if (cin.fail())
		{
			cout << "Invalid Option Please try Again!";
			cin.clear();
			cin.ignore (100000, '\n');
			cout << endl;
		}
		else if (mainMenuOption != 1 && mainMenuOption != 2 && mainMenuOption != 3
				&& mainMenuOption != 4)
		{
			cout << "Invalid Option Please try Again!";
			cout << endl;
		}
		} while (mainMenuOption != 1 && mainMenuOption != 2 && mainMenuOption != 3
		&& mainMenuOption != 4);

		cout << endl << endl << "You selected menu option number " << mainMenuOption << "!"
			 << endl << endl;

		switch (mainMenuOption)
		{
			case 1:
				CashModule(listName, listWholesale, listDate, listQty);
				break;
			case 2:
				InventoryModule(listName, listWholesale, listDate, listQty);
				break;
			case 3:
				ReportsModule(listName, listWholesale, listDate, listQty);
				break;
			case 4:
				system ("clear");
				cout << "Thank you for Shopping with Serendipity!";
				mainMenuOption = 4;
				break;
			default:
				cout << "no menu option selected";
		}
	}
	return 0;
}

