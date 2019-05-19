#include "Serendipity.h"
#include "strupper.h"

void LookUpBook(orderedLinkedList<BookType> listName, orderedLinkedList<BookType> listWholesale, orderedLinkedList<BookType> listDate, orderedLinkedList<BookType> listQty)
{
	const int TEMP_LENGTH = 1;
	//char YesNo = ' ';
	bool found = false;
	int index = 0;
	string searchTitle;
	string tempBookTitle[TEMP_LENGTH];
	char userChoice;
	char junk;
	string tempIsbn;
	string tempTitle;
	string tempAuthor;
	string tempPub;
	string tempDate;
	int tempQty;
	double tempWholesale;
	double tempRetail;
	linkedListIterator<BookType> it;


	if(BookType::getBookCount() <= 0)
	{
		system("clear");
		cout << "There are no books in the Database!" << endl;
		cout << "Returning to Main Menu" << endl;
		cout << "press any key to continue . . . ";
		cin >> junk;
		cin.ignore();
	}
	else
	{
	system("clear");
	cout << "--------------------------------------------------------------" << endl;
	cout << "		   SERENDIPITY BOOKSELLERS					   " << endl;
	cout << "	                LOOKUP BOOK							       " << endl;
	cout << "																				" << endl;
	cout << "					 DATABASE SIZE: " << BookType::getBookCount() <<" CURRENT BOOK COUNT: " << BookType::getBookCount() << endl;
	cout << "--------------------------------------------------------------" << endl;
	cout << "Enter the title or ISBN of the book you wish to search for: ";
	getline(cin,searchTitle);



	do
	{

		for (linkedListIterator<BookType> it = listName.begin(); it != listName.end(); ++it)
		{
			tempTitle = (*it).getTitle();

			transform(tempTitle.begin(), tempTitle.end(), tempTitle.begin(), ::tolower);
			transform(searchTitle.begin(), searchTitle.end(), searchTitle.begin(), ::tolower);

			int find = tempTitle.find(searchTitle);

			tempIsbn = (*it).getISBN();
			if(find != -1)
			{
				found = true;
				break;
			}
			else if (tempIsbn == searchTitle)
			{
				found = true;
				break;
			}

		}

		if(found)
		{
			cout << "\nRESULT: " << tempTitle << endl;
			do
				{
					cout << "View this books record? <Y/N>";
					cin.get(userChoice);
					cin.ignore (100000, '\n');
					if (cin.fail())
					{
						cout << "Invalid Option Please try Again!";
						cin.clear();
						cin.ignore (100000, '\n');
						cout << endl;
					}
					else if (userChoice != 'Y' && userChoice != 'y' && userChoice != 'N'
							&& userChoice != 'n')
					{
						cout << "Invalid Option Please try Again!";
						cout << endl;
					}
				}while (userChoice != 'Y' && userChoice != 'y' && userChoice != 'N'
							&& userChoice != 'n');
			if(userChoice == 'Y' || userChoice == 'y')
			{
				tempAuthor = (*it).getAuthor();
				tempPub = (*it).getPub();
				tempDate = (*it).getDateAdded();
				tempIsbn = (*it).getISBN();
				tempQty = (*it).getQty();
				tempWholesale = (*it).getWholesale();
				tempRetail = (*it).getRetail();
				(*it).BookInfo(tempIsbn, tempTitle, tempAuthor, tempPub,
									tempDate, tempQty, tempWholesale, tempRetail);
			cout << endl << endl << "Press any key to continue...";
			cin >> junk;
			cin.ignore();
			}

			else if (userChoice == 'N' || userChoice == 'n')
			{
				system("clear");
				found = false;
				index++;
				cout << "Next book found in the Database" << endl;

			}
		}
	}while(!found);
	}

	if (!found)
	{
		system("clear");
		cout << "The book you searched for is not in the inventory" << endl << endl;
		cout << "Press any key to continue...";
			cin >> junk;
			cin.ignore();
	}
}





