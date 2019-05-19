#include "Serendipity.h"

void ReportsModule(orderedLinkedList<BookType> listName, orderedLinkedList<BookType> listWholesale, orderedLinkedList<BookType> listDate, orderedLinkedList<BookType> listQty)
{
	char junk;
	int menuThreeOption;

	system ("clear");
	if (BookType::getBookCount() != 0)
	{
					cout << "    Serendipity Booksellers  " << endl;
					cout << "            Reports          " << endl << endl;
					cout << "1.  Inventory Listing" << endl;
					cout << "2.  Inventory Wholesale Value" << endl;
					cout << "3.  Inventory Retail Value" << endl;
					cout << "4.  Listing by Quantity" << endl;
					cout << "5.  Listing by Cost" << endl;
					cout << "6.  Listing by Age" << endl;
					cout << "7.  Return to Main Menu" << endl;

					do //while (menuThreeOption != 1 && menuThreeOption != 2 && menuThreeOption != 3
						//&& menuThreeOption != 4 && menuThreeOption !=5 && menuThreeOption !=6
						//&& menuThreeOption !=7);

					{
					cout << "Enter Your Choice: ";
					cin  >> menuThreeOption;
					cin.ignore (100000, '\n');
					if (cin.fail())
					{
						cout << "Invalid Option Please try Again!";
						cin.clear();
						cin.ignore (100000, '\n');
						cout << endl;
					}
					else if (menuThreeOption != 1 && menuThreeOption != 2 && menuThreeOption != 3
							&& menuThreeOption != 4 && menuThreeOption !=5 &&
							menuThreeOption != 6 && menuThreeOption != 7)
					{
						cout << "Invalid Option Please try Again!";
						cout << endl;
					}
					//else if (menuThreeOption == 7)
					//{
						//break;
					//}
					} while (menuThreeOption != 1 && menuThreeOption != 2 && menuThreeOption != 3
					&& menuThreeOption != 4 && menuThreeOption !=5 && menuThreeOption !=6
					&& menuThreeOption !=7);

					switch (menuThreeOption)
					{
					case 1:
						system ("clear");
						repListing (listName, listWholesale, listDate, listQty);
						break;
					case 2:
						system ("clear");
						repWholesale (listName, listWholesale, listDate, listQty);
						break;
					case 3:
						system ("clear");
						repRetail(listName, listWholesale, listDate, listQty);
						break;
					case 4:
						system ("clear");
						cout << "You chose option 4!" << endl;
						cout << "Press any key to continue...";
						cin.get(junk);
						cin.ignore(10000,'\n');
						break;
					case 5:
						system ("clear");
						cout << "You chose option 5!" << endl;
						cout << "Press any key to continue...";
						cin.get(junk);
						cin.ignore(10000,'\n');
						break;
					case 6:
						system ("clear");
						cout << "You chose option 6!" << endl;
						cout << "Press any key to continue...";
						cin.get(junk);
						cin.ignore(10000,'\n');
						break;
					case 7:
						system ("clear");
						break;
					}
	}
	else
	{
		system("clear");
		cout << "There are no books in the database, add a book before proceeding" << endl;
		cout << "Press any key to continue . . .";
		cin >> junk;
		cin.ignore();

	}
}
