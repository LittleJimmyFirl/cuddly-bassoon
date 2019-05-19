#include "Serendipity.h"
#include "bookdata.h"

void DeleteABook(orderedLinkedList<BookType> listName, orderedLinkedList<BookType> listWholesale, orderedLinkedList<BookType> listDate, orderedLinkedList<BookType> listQty)
{
	const int TEMP_LENGTH = 1;
	bool found = false;
	int index = 0;
	string searchTitle;
	string tempBookTitle[TEMP_LENGTH];
	char confirm;
	char deleteAnother;
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
	int bookCount;

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
	cout << "	                EDIT BOOK							       " << endl;
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
				do
				{
				cout << "Is this the book you want to DELETE <Y/N>?";
				cin.get(confirm);
				cin.ignore();
					if(cin.fail())
					{
						cout << "Invalid Option Please try Again!";
						cin.clear();
						cin.ignore();
						cout << endl;
					}
					else if (confirm != 'Y' && confirm != 'y' && confirm != 'N'
							&& confirm != 'n' )
					{
						cout << "Invalid Option Please Try Again!" << endl;
					}
				}while (confirm != 'Y' && confirm != 'y' && confirm != 'N'
						&& confirm != 'n' );

					if (confirm == 'Y' || confirm == 'y')
					{
						(*it).setTitle("");
						(*it).setISBN("");
						(*it).setAuthor("");
						(*it).setPub("");
						(*it).setDateAdded ("");
						(*it).setQty(0);
						(*it).setWholesale(0.0);
						(*it).setRetail(0.0);
						BookType::DecBookCount();

						cout << "** BOOK DELETED **" << endl;
						do
						{
						cout << "Would you like to delete another book? <Y/N>: ";
						cin.get(deleteAnother);
						cin.ignore();
						if(cin.fail())
						{
							cout << "Invalid Option Please try Again!";
							cin.clear();
							cin.ignore();
							cout << endl;
						}
						else if (deleteAnother != 'Y' && deleteAnother != 'y' && deleteAnother != 'N'
								&& deleteAnother != 'n' )
						{
							cout << "Invalid Option Please Try Again!" << endl;
						}
					}while (deleteAnother != 'Y' && deleteAnother != 'y' && deleteAnother != 'N'
							&& deleteAnother != 'n' );

						if (deleteAnother  == 'Y' || deleteAnother == 'y')
						{
							system("clear");
							DeleteABook(listName, listWholesale, listDate, listQty);
						}
						else if (deleteAnother  == 'N' || deleteAnother == 'n')
						{
							system("clear");
							cout << "Returning to Main Menu" << endl;
							cout << "Press any key to continue ... . . ";
							cin  >> junk;
							cin.ignore();
						}

					}
					else if (confirm == 'N' || confirm == 'n')
					{
						found = false;
						index++;
						cout << "Searching for the next book!" << endl;
						system("clear");
					}
				}

			else if (userChoice == 'N' || userChoice == 'n')
				{
					system("clear");
					found = false;
					index++;
					cout << "Next book found in the Database" << endl;

				}
			}
	}while (!found && index < SIZE2);

		if(!found)
		{
			system("clear");
			cout << "The book you searched for is not in the inventory\n";
			cout << "Returning to Main Menu" << endl;
			cout << "Press any key to continue ... . . ";
			cin  >> junk;
			cin.ignore();

		}
}

}
