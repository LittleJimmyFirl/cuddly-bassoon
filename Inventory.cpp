#include "Serendipity.h"

void InventoryModule(orderedLinkedList<BookType> listName, orderedLinkedList<BookType> listWholesale, orderedLinkedList<BookType> listDate, orderedLinkedList<BookType> listQty)
{
	int menuTwoOption;

	system ("clear");
			cout << "    Serendipity Booksellers  " << endl;
			cout << "       Inventory Database    " << endl << endl;
			cout << "1.  Look Up a Book           " << endl;
			cout << "2.  Add a Book               " << endl;
			cout << "3.  Edit a Book's Record     " << endl;
			cout << "4.  Delete a Book            " << endl;
			cout << "5.  Return to Main Menu      " << endl << endl;

			do //menuTwoOption != 1 && menuTwoOption != 2 && menuTwoOption != 3
				//&& menuTwoOption != 4 && menuTwoOption !=5);

			{
			cout << "Enter Your Choice: ";
			cin  >> menuTwoOption;
			cin.ignore (100000, '\n');
			if (cin.fail())
			{
				cout << "Invalid Option Please try Again!";
				cin.clear();
				cin.ignore (100000, '\n');
				cout << endl;
			}
			else if (menuTwoOption != 1 && menuTwoOption != 2 && menuTwoOption != 3
					&& menuTwoOption != 4 && menuTwoOption !=5)
			{
				cout << "Invalid Option Please try Again!";
				cout << endl;
			}
			else if (menuTwoOption == 5)
			{
				break;
			}
			} while (menuTwoOption != 1 && menuTwoOption != 2 && menuTwoOption != 3
			&& menuTwoOption != 4 && menuTwoOption !=5);

				switch (menuTwoOption)
				{
					case 1:
						LookUpBook(listName, listDate, listWholesale, listQty);
						break;
					case 2:
						AddABook(listName, listDate, listWholesale, listQty);
						break;
					case 3:
						EditABook(listName, listDate, listWholesale, listQty);
						break;
					case 4:
						system ("clear");
						DeleteABook(listName, listDate, listWholesale, listQty);
						break;
				}
}
