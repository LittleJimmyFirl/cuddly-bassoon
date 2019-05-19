#include "Serendipity.h"

void EditABook(orderedLinkedList<BookType> listName, orderedLinkedList<BookType> listWholesale, orderedLinkedList<BookType> listDate, orderedLinkedList<BookType> listQty)
{
	const int TEMP_LENGTH = 1;
	bool found = false;
	int index = 0;
	int choice = 0;
	char userChoice;
	char junk;
	string searchTitle;
	string tempBookTitle[TEMP_LENGTH];
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
					cout << "Which of the Following Categories would you like to edit? " << endl;
					cout << "1. ISBN\n";
					cout << "2. Title\n";
					cout << "3. Author\n";
					cout << "4. Publisher\n";
					cout << "5. Date book was added to inventory\n";
					cout << "6. Quantity on hand\n";
					cout << "7. Wholesale cost\n";
					cout << "8. Retail Price\n";
					cout << "9. Exit\n\n";
					cin >> choice;

					while (choice < 1 || choice > 9)
					{
						cout << "\nPlease enter a number in the range between 1 and 9." << endl;
						cout << "Enter your choice :";
						cin >> choice;
					}

					switch (choice)
					{
					case 1:
						cout << "\nCurrent ISBN: ";
						cout << tempIsbn << endl;
						cin.ignore();
						cout << "Enter new ISBN: ";
						getline(cin, tempIsbn);
						(*it).setISBN(tempIsbn);
						break;
					case 2:
						cout << "\nCurrent Title: ";
						cout << tempTitle << endl;
						cin.ignore();
						cout << "Enter new Title: ";
						getline(cin, tempTitle);
						(*it).setTitle(tempTitle);
						break;
					case 3:
						cout << "\nCurrent Author: ";
						cout << tempAuthor << endl;
						cin.ignore();
						cout << "Enter new Author: ";
						getline(cin, tempAuthor);
						(*it).setAuthor(tempAuthor);
						break;
					case 4:
						cout << "\nCurrent Publisher: ";
						cout << tempPub << endl;
						cin.ignore();
						cout << "Enter new Publisher: ";
						getline(cin, tempPub);
						(*it).setPub(tempPub);
						break;
					case 5:
						cout << "\nCurrent Date Added: ";
						cout << tempDate << endl;
						cin.ignore();
						cout << "Enter new Date: ";
						getline(cin, tempDate);
						(*it).setDateAdded(tempDate);
						break;
					case 6:
						cout << "\nCurrent Quantity on Hand: ";
						cout << tempQty << endl;
						cin.ignore();
						cout << "Enter new Quantity On Hand: ";
						cin >> tempQty;
						(*it).setQty(tempQty);
						break;
					case 7:
						cout << "\nCurrent Wholesale Cost: ";
						cout << tempWholesale << endl;
						cin.ignore();
						cout << "Enter new Wholesale Cost: ";
						cin >> tempWholesale;
						(*it).setWholesale(tempWholesale);
						break;
					case 8:
						cout << "\nCurrent Retail Price: ";
						cout << tempRetail << endl;
						cin.ignore();
						cout << "Enter new Retail Price: ";
						cin >> tempRetail;
						(*it).setRetail(tempRetail);
						break;
					}
				} while (choice != 9);

				}

				else if (userChoice == 'N' || userChoice == 'n')
				{
					system("clear");
					found = false;
					index++;
					cout << "Next book found in the Database" << endl;

				}
			}
	}while (!found);

		if (!found)
			cout << "The book you searched for is not in the inventory\n\n";
}
}

