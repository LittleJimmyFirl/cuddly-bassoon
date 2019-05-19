#include "Serendipity.h"
#include <cstring>



void CashModule (orderedLinkedList<BookType> listName, orderedLinkedList<BookType> listWholesale, orderedLinkedList<BookType> listDate, orderedLinkedList<BookType> listQty)
{
	int bookQuantity;
	string ISBN;
	char date[10];
	char menuReturn = 'Y';
	string bookTitle;
	double subtotal = 0.0;
	double taxPrice;
	double finalTotal;
	int index = 0;
	string searchTitle;
	char userChoice;
	char junk;
	int arr = 0;
	string cashIsbn[200];
	string cashTitle[200];
	string cashAuthor[200];
	string cashPub[200];
	string cashDate[200];
	double cashWholesale[200];
	double cashRetail[200];
	string tempIsbn;
	string tempTitle;
	string tempAuthor;
	string tempPub;
	string tempDate;
	int tempQty;
	int newQty;
	int cashQty[arr];
	bool found = false;
	char checkTwo = 'Y';
	linkedListIterator<BookType> it;

	while (menuReturn == 'Y')
	{
		if (BookType::getBookCount() != 0)
		{

					system ("clear");
					//Prompting user to input their data
					cout << "Serendipity Booksellers" << endl;
					cout << "    Cashier Module     " << endl << endl;
					do
					{
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
								cout << "Is this the book you would like to add to the transaction? <Y/N>";
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
								cout << "Quantity of book to be added to transaction?: ";
								cin >> bookQuantity;
								cin.ignore();
								(*it).getCartQty(tempQty);
								newQty = tempQty - bookQuantity;
								if(newQty >= 0)
								{
									cout << "You have successfully added " << bookQuantity <<
											" book(s) to the transaction" << endl << endl;
									(*it).setCartQty(newQty);
									cashQty[arr] = bookQuantity;


									cashTitle[arr]=(*it).getTitle();
									cashAuthor[arr]=(*it).getAuthor();
									cashPub[arr]=(*it).getPub();
									cashDate[arr]=(*it).getDateAdded();
									cashIsbn[arr]=(*it).getISBN();
									cashQty[arr]=(*it).getQty();
									cashWholesale[arr]=(*it).getWholesale();
									cashRetail[arr]=(*it).getRetail();
									arr++;
									//cashTitle[arr] = tempTitle;


								}
								else if (newQty < 0)
								{
									do
									{
										cout << "You do not currently have that many books in the inventory" << endl;
										cout << "There are currently " << tempQty <<
												" books in the inventory" << endl << endl;
										cout << "Please enter a valid number of books to be purchased: ";
										cin >> bookQuantity;
										cin.ignore();
										newQty = tempQty - bookQuantity;
										if(newQty >= 0)
										{
											cout << "You have successfully added " << bookQuantity <<
												" book(s) to the transaction" << endl << endl;
											(*it).setCartQty(newQty);
											cashQty[arr] = bookQuantity;


											cashTitle[arr]=(*it).getTitle();
											cashAuthor[arr]=(*it).getAuthor();
											cashPub[arr]=(*it).getPub();
											cashDate[arr]=(*it).getDateAdded();
											cashIsbn[arr]=(*it).getISBN();
											cashQty[arr]=(*it).getQty();
											cashWholesale[arr]=(*it).getWholesale();
											cashRetail[arr]=(*it).getRetail();
											arr++;

										}
									}while (newQty < 0);
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

					}while(!found && index < SIZE2);
					if (!found)
					{
						system("clear");
						cout << "The book you searched for is not in the inventory" << endl << endl;
						cout << "Press any key to continue...";
							cin >> junk;
							cin.ignore();
					}


					cout << "would you like to add another book to the transaction (Y/N)";
					cin >> checkTwo;
					//char checkTwo = Character.toUpperCase(checkTwo);
					cin.ignore();
					index = 0;
					} while (checkTwo =='Y' || checkTwo == 'y');

					system ("clear");
					cout << "Serendipity Booksellers" << endl << endl;
					cout << "Date: " << date << endl << endl;
					cout << left;
					cout << setw(5)  << "QTY"
						 << setw(15) << "ISBN"
						 << setw(70) << "Title"
						 << setw(11) << "Price"
						 << setw(8)  << "Total" << endl;
					cout << right;
					for (int i = 1; i <= 109; i++)
					{
						cout << "_";
					}
					cout << endl;
					arr = 0;
					while (cashTitle[arr] != "")
					{
						cout << left;
						cout << setprecision(2) << fixed;
						cout << setw(5)  << cashQty[arr]
							 << setw(15) << cashIsbn[arr]
							 << setw(70) << cashTitle[arr]
							 << setw(11) << cashRetail[arr]
							 << setw(8)  << (cashRetail[arr] * bookQuantity) << endl;
								subtotal = subtotal + (cashRetail[arr] * bookQuantity);
						cout << right;
						arr++;
					}

					taxPrice = (subtotal * 0.06);
					finalTotal = (subtotal + taxPrice);
					cout << endl     << endl       << endl;
					cout << setw(28) << "Subtotal: " << right << setw(32) << "$" << subtotal << endl
						 << setw(23) << "Tax: "      << right << setw(37) << "$" << taxPrice << endl
						 << setw(25) << "Total: "    << right << setw(35) << "$" << finalTotal << endl << endl;
					cout << "Thank you for Shopping with Serendipity!" << endl << endl;



					do //while(menuReturn != 'Y' && menuReturn != 'y' && menuReturn != 'N' && menuReturn != 'n');
					{
						cin.clear();
						//cin.ignore(1000,'\n');
						cout << "Would you like to process another transaction? (Y/N)";

						while (!(cin.get(menuReturn))) // basic error check
						{
							cin.clear();
							cin.ignore(1000,'\n');
							cout << "Enter a valid option.";
						}

						if (menuReturn == 'Y' || menuReturn == 'y')
						{
							menuReturn = 'Y';
						}
						else if (menuReturn != 'Y' && menuReturn != 'y' && menuReturn != 'N' && menuReturn != 'n')
						{
							cout << "please enter a valid option!" << endl;

						}
						else if (menuReturn == 'N' || menuReturn == 'n')
						{
							//cout << "Thank you for shopping with Serendipty!";
							//mainMenuOption = 4;
						}
					}while(menuReturn != 'Y' && menuReturn != 'y' && menuReturn != 'N' && menuReturn != 'n');

	}
		else
		{
			system("clear");
			cout << "There are no books in the database, add a book before proceeding" << endl;
			cout << "Press any key to continue . . .";
			menuReturn = 'N';
			cin >> junk;
			cin.ignore();

		}
	}
}


