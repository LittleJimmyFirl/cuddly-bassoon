#include "Serendipity.h"
#include "bookdata.h"

void AddABook(orderedLinkedList<BookType> listName, orderedLinkedList<BookType> listWholesale, orderedLinkedList<BookType> listDate, orderedLinkedList<BookType> listQty)
{
	bool found = false;
	int index = 0;
	int userInput = -1;

	char junk;

	string title;
	string isbn;
	string author;
	string publisher;
	string dateAdded;
	int qtyOnHand;
	double wholesale;
	double retail;

	BookType *temp = nullptr;

		system("clear");
		cout << "															   " << endl;
		cout << "			     SERENDIPITY BOOKSELLERS					   " << endl;
		cout << "			             ADD BOOK							       " << endl;
		cout << "																				" << endl;
		cout << "					 DATABASE SIZE: " << BookType::getBookCount() <<" CURRENT BOOK COUNT: " << BookType::getBookCount() << endl;
		cout << "					  -PENDING VALUES	       " << endl;
		cout << " 																			*" << endl;
		cout << "  <1> Enter Book Title 			>>-- EMPTY									 " << endl;
		cout << "  <2> Enter ISBN       			>>-- EMPTY									 " << endl;
		cout << "  <3> Enter AUTHOR     			>>-- EMPTY									 " << endl;
		cout << "  <4> Enter PUBLISHER  			>>-- EMPTY									 " << endl;
		cout << "  <5> Enter Date Added 			>>-- EMPTY									 " << endl;
		cout << "  <6> Enter Quantity on Hand 		>>-- 0										 " << endl;
		cout << "  <7> Enter wholesale Cost 		>>-- 0.00									 " << endl;
		cout << "  <8> Enter Retail Cost     		>>-- 0.00									 " << endl;
		cout << "  <9> Save Book to Database 													 " << endl;
		cout << "  <0> Return to Inventory Menu             									 " << endl;

		while (userInput != 0)
		{

				do // while (mainMenuOption != 1 && mainMenuOption != 2 && mainMenuOption != 3
				{
				//cout << "*																				*" << endl;
				cout << "Choice <0-9>: ";
				cin  >> userInput;
				cin.ignore (100000, '\n');
				if (cin.fail())
				{
					cout << "Invalid Option Please try Again!";
					cin.clear();
					cin.ignore (100000, '\n');
					cout << endl;
				}
				else if (userInput != 1 && userInput != 2 && userInput != 3
						&& userInput != 4 && userInput != 5 && userInput != 6
						&& userInput != 7 && userInput != 8 && userInput != 9
						&& userInput != 0)
				{
					cout << "Invalid Option Please try Again!";
					cout << endl;
				}
				} while (userInput != 1 && userInput != 2 && userInput != 3
						&& userInput != 4 && userInput != 5 && userInput != 6
						&& userInput != 7 && userInput != 8 && userInput != 9
						&& userInput != 0);
				switch(userInput)
				{
					case 1:
						system("clear");
						cout << "Enter Title: ";
						getline(cin, title);

						system("clear");
						cout << "															   " << endl;
						cout << "			     SERENDIPITY BOOKSELLERS					   " << endl;
						cout << "			             ADD BOOK							       " << endl;
						cout << "																				" << endl;
						cout << "					 DATABASE SIZE: " << BookType::getBookCount() <<" CURRENT BOOK COUNT: " << BookType::getBookCount() << endl;
						cout << "					  -PENDING VALUES	       " << endl;
						cout << " 																			*" << endl;
						cout << "  <1> Enter Book Title 			>>--" << title << endl;
						cout << "  <2> Enter ISBN       			>>-- EMPTY									 " << endl;
						cout << "  <3> Enter AUTHOR     			>>-- EMPTY									 " << endl;
						cout << "  <4> Enter PUBLISHER  			>>-- EMPTY									 " << endl;
						cout << "  <5> Enter Date Added 			>>-- EMPTY									 " << endl;
						cout << "  <6> Enter Quantity on Hand 		>>-- 0										 " << endl;
						cout << "  <7> Enter wholesale Cost 		>>-- 0.00									 " << endl;
						cout << "  <8> Enter Retail Cost     		>>-- 0.00									 " << endl;
						cout << "  <9> Save Book to Database 													 " << endl;
						cout << "  <0> Return to Inventory Menu             									 " << endl;
						break;

					case 2:
						system("clear");
						cout << "Enter ISBN: ";
						getline(cin,isbn);

						system("clear");
						cout << "															   " << endl;
						cout << "			     SERENDIPITY BOOKSELLERS					   " << endl;
						cout << "			             ADD BOOK							       " << endl;
						cout << "																				" << endl;
						cout << "					 DATABASE SIZE: " << BookType::getBookCount() <<" CURRENT BOOK COUNT: " << BookType::getBookCount() << endl;
						cout << "					  -PENDING VALUES	       " << endl;
						cout << " 																			*" << endl;
						cout << "  <1> Enter Book Title 			>>--" << title << endl;
						cout << "  <2> Enter ISBN       			>>--" << isbn << endl;
						cout << "  <3> Enter AUTHOR     			>>-- EMPTY									 " << endl;
						cout << "  <4> Enter PUBLISHER  			>>-- EMPTY									 " << endl;
						cout << "  <5> Enter Date Added 			>>-- EMPTY									 " << endl;
						cout << "  <6> Enter Quantity on Hand 		>>-- 0										 " << endl;
						cout << "  <7> Enter wholesale Cost 		>>-- 0.00									 " << endl;
						cout << "  <8> Enter Retail Cost     		>>-- 0.00									 " << endl;
						cout << "  <9> Save Book to Database 													 " << endl;
						cout << "  <0> Return to Inventory Menu             									 " << endl;
						break;

					case 3:
						system("clear");
						cout << "Enter Author: ";
						getline(cin,author);
						system("clear");
						cout << "															   " << endl;
						cout << "			     SERENDIPITY BOOKSELLERS					   " << endl;
						cout << "			             ADD BOOK							       " << endl;
						cout << "																				" << endl;
						cout << "					 DATABASE SIZE: " << BookType::getBookCount() <<" CURRENT BOOK COUNT: " << BookType::getBookCount() << endl;
						cout << "					  -PENDING VALUES	       " << endl;
						cout << " 																			*" << endl;
						cout << "  <1> Enter Book Title 			>>--" << title << endl;
						cout << "  <2> Enter ISBN       			>>--" << isbn << endl;
						cout << "  <3> Enter AUTHOR     			>>--" << author << endl;
						cout << "  <4> Enter PUBLISHER  			>>-- EMPTY									 " << endl;
						cout << "  <5> Enter Date Added 			>>-- EMPTY									 " << endl;
						cout << "  <6> Enter Quantity on Hand 		>>-- 0										 " << endl;
						cout << "  <7> Enter wholesale Cost 		>>-- 0.00									 " << endl;
						cout << "  <8> Enter Retail Cost     		>>-- 0.00									 " << endl;
						cout << "  <9> Save Book to Database 													 " << endl;
						cout << "  <0> Return to Inventory Menu             									 " << endl;
						break;

					case 4:
						system("clear");
						cout << "Enter Publisher: ";
						getline(cin,publisher);
						system("clear");
						cout << "															   " << endl;
						cout << "			     SERENDIPITY BOOKSELLERS					   " << endl;
						cout << "			             ADD BOOK							       " << endl;
						cout << "																				" << endl;
						cout << "					 DATABASE SIZE: " << BookType::getBookCount() <<" CURRENT BOOK COUNT: " << BookType::getBookCount() << endl;
						cout << "					  -PENDING VALUES	       " << endl;
						cout << " 																			*" << endl;
						cout << "  <1> Enter Book Title 			>>--" << title << endl;
						cout << "  <2> Enter ISBN       			>>--" << isbn << endl;
						cout << "  <3> Enter AUTHOR     			>>--" << author << endl;
						cout << "  <4> Enter PUBLISHER  			>>--" << publisher << endl;
						cout << "  <5> Enter Date Added 			>>-- EMPTY									 " << endl;
						cout << "  <6> Enter Quantity on Hand 		>>-- 0										 " << endl;
						cout << "  <7> Enter wholesale Cost 		>>-- 0.00									 " << endl;
						cout << "  <8> Enter Retail Cost     		>>-- 0.00									 " << endl;
						cout << "  <9> Save Book to Database 													 " << endl;
						cout << "  <0> Return to Inventory Menu             									 " << endl;
						break;

					case 5:
						system("clear");
						cout << "Enter Date Added to Inventory: ";
						getline(cin,dateAdded);
						system("clear");
						cout << "															   " << endl;
						cout << "			     SERENDIPITY BOOKSELLERS					   " << endl;
						cout << "			             ADD BOOK							       " << endl;
						cout << "																				" << endl;
						cout << "					 DATABASE SIZE: " << BookType::getBookCount() <<" CURRENT BOOK COUNT: " << BookType::getBookCount() << endl;
						cout << "					  -PENDING VALUES	       " << endl;
						cout << " 																			*" << endl;
						cout << "  <1> Enter Book Title 			>>--" << title << endl;
						cout << "  <2> Enter ISBN       			>>--" << isbn << endl;
						cout << "  <3> Enter AUTHOR     			>>--" << author << endl;
						cout << "  <4> Enter PUBLISHER  			>>--" << publisher << endl;
						cout << "  <5> Enter Date Added 			>>--" << dateAdded << endl;
						cout << "  <6> Enter Quantity on Hand 		>>-- 0										 " << endl;
						cout << "  <7> Enter wholesale Cost 		>>-- 0.00									 " << endl;
						cout << "  <8> Enter Retail Cost     		>>-- 0.00									 " << endl;
						cout << "  <9> Save Book to Database 													 " << endl;
						cout << "  <0> Return to Inventory Menu             									 " << endl;
						break;

					case 6:
						system("clear");
						cout << "Enter Quantity to be Added: ";
						cin >> qtyOnHand;

						system("clear");
						cout << "															   " << endl;
						cout << "			     SERENDIPITY BOOKSELLERS					   " << endl;
						cout << "			             ADD BOOK							       " << endl;
						cout << "																				" << endl;
						cout << "					 DATABASE SIZE: " << BookType::getBookCount() <<" CURRENT BOOK COUNT: " << BookType::getBookCount() << endl;
						cout << "					  -PENDING VALUES	       " << endl;
						cout << " 																			*" << endl;
						cout << "  <1> Enter Book Title 			>>--" << title << endl;
						cout << "  <2> Enter ISBN       			>>--" << isbn << endl;
						cout << "  <3> Enter AUTHOR     			>>--" << author << endl;
						cout << "  <4> Enter PUBLISHER  			>>--" << publisher << endl;
						cout << "  <5> Enter Date Added 			>>--" << dateAdded << endl;
						cout << "  <6> Enter Quantity on Hand 		>>--" << qtyOnHand << endl;
						cout << "  <7> Enter wholesale Cost 		>>-- 0.00									 " << endl;
						cout << "  <8> Enter Retail Cost     		>>-- 0.00									 " << endl;
						cout << "  <9> Save Book to Database 													 " << endl;
						cout << "  <0> Return to Inventory Menu             									 " << endl;
						break;

					case 7:
						system("clear");
						cout << "Enter Wholesale Cost: ";
						cin >> wholesale;

						system("clear");
						cout << "															   " << endl;
						cout << "			     SERENDIPITY BOOKSELLERS					   " << endl;
						cout << "			             ADD BOOK							       " << endl;
						cout << "																				" << endl;
						cout << "					 DATABASE SIZE: " << BookType::getBookCount() <<" CURRENT BOOK COUNT: " << BookType::getBookCount() << endl;
						cout << "					  -PENDING VALUES	       " << endl;
						cout << " 																			*" << endl;
						cout << "  <1> Enter Book Title 			>>--" << title << endl;
						cout << "  <2> Enter ISBN       			>>--" << isbn << endl;
						cout << "  <3> Enter AUTHOR     			>>--" << author << endl;
						cout << "  <4> Enter PUBLISHER  			>>--" << publisher << endl;
						cout << "  <6> Enter Quantity on Hand 		>>--" << qtyOnHand << endl;
						cout << "  <7> Enter wholesale Cost 		>>--" << wholesale << endl;
						cout << "  <8> Enter Retail Cost     		>>-- 0.00									 " << endl;
						cout << "  <9> Save Book to Database 													 " << endl;
						cout << "  <0> Return to Inventory Menu             									 " << endl;
						break;

					case 8:
						system("clear");
						cout << "Enter Retail Cost: ";
						cin >> retail;

						system("clear");
						cout << "															   " << endl;
						cout << "			     SERENDIPITY BOOKSELLERS					   " << endl;
						cout << "			             ADD BOOK							       " << endl;
						cout << "																				" << endl;
						cout << "					 DATABASE SIZE: " << BookType::getBookCount() <<" CURRENT BOOK COUNT: " << BookType::getBookCount() << endl;
						cout << "					  -PENDING VALUES	       " << endl;
						cout << " 																			*" << endl;
						cout << "  <1> Enter Book Title 			>>--" << title << endl;
						cout << "  <2> Enter ISBN       			>>--" << isbn << endl;
						cout << "  <3> Enter AUTHOR     			>>--" << author << endl;
						cout << "  <4> Enter PUBLISHER  			>>--" << publisher << endl;
						cout << "  <5> Enter Date Added 			>>--" << dateAdded << endl;
						cout << "  <6> Enter Quantity on Hand 		>>--" << qtyOnHand << endl;
						cout << "  <7> Enter wholesale Cost 		>>--$" << wholesale << endl;
						cout << "  <8> Enter Retail Cost     		>>--$" << retail << endl;
						cout << "  <9> Save Book to Database 													 " << endl;
						cout << "  <0> Return to Inventory Menu             									 " << endl;
						break;

					case 9:
						system("clear");
				    	temp = new BookType (title, isbn, author, publisher, dateAdded, qtyOnHand, wholesale, retail);

				    	listName.insert(*temp);

				    	(*temp).setSortCode(1);
				    	listWholesale.insert(*temp);

				    	(*temp).setSortCode(2);
				    	listDate.insert(*temp);

				    	(*temp).setSortCode(3);
				    	listQty.insert(*temp);

				    	BookType::IncBookCount();
									cout << "			BOOK HAS BEEN SAVED SUCSESSFULLY					   " << endl;
									cout << "			     SERENDIPITY BOOKSELLERS					   " << endl;
									cout << "			             ADD BOOK							       " << endl;
									cout << "																				" << endl;
									cout << "					 DATABASE SIZE: " << BookType::getBookCount() <<" CURRENT BOOK COUNT: " << BookType::getBookCount() << endl;
									cout << "					  -PENDING VALUES	       " << endl;
									cout << " 																			" << endl;
									cout << "  <1> Enter Book Title 			>>-- EMPTY									 " << endl;
									cout << "  <2> Enter ISBN       			>>-- EMPTY									 " << endl;
									cout << "  <3> Enter AUTHOR     			>>-- EMPTY									 " << endl;
									cout << "  <4> Enter PUBLISHER  			>>-- EMPTY									 " << endl;
									cout << "  <5> Enter Date Added 			>>-- EMPTY									 " << endl;
									cout << "  <6> Enter Quantity on Hand 		>>-- 0										 " << endl;
									cout << "  <7> Enter wholesale Cost 		>>-- 0.00									 " << endl;
									cout << "  <8> Enter Retail Cost     		>>-- 0.00									 " << endl;
									cout << "  <9> Save Book to Database 													 " << endl;
									cout << "  <0> Return to Inventory Menu             									 " << endl;
									//cout << title;
									//cout << index;
									index++;



				}
			}

		}


