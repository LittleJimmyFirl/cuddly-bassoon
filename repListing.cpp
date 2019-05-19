#include "reports.h"

void repListing (orderedLinkedList<BookType> listName, orderedLinkedList<BookType> listWholesale, orderedLinkedList<BookType> listDate, orderedLinkedList<BookType> listQty)
{
	time_t t = time(NULL);
	tm* timePtr = localtime(&t);
	int page = 1;

	string tempBookTitle;
	string tempIsbn;
	string tempAuthor;
	string tempPublisher;
	string tempDateAdded;
	int tempQtyOnHand;
	double tempWholesale;
	double tempRetail;
	linkedListIterator<BookType> it;
	int bookDisplay = 0;

	int index = 0;
	char junk;

			system("clear");
			cout << "********************************************************************************************************************" << endl;
			cout << "                                                SERENDIPITY BOOKSELLERS                                             " << endl;
			cout << "                                                    REPORTS LISTING                                                 " << endl;
			cout << "  Date     " <<(timePtr->tm_mday)<<"/"<< (timePtr->tm_mon)+1 <<"/"<< (timePtr->tm_year)+1900 <<
					"\t Page: " << page << " of 13" << "\t Database Size: 20" <<  "\t Current Book Count: " << BookType::getBookCount() << endl << endl;


			cout << left;
			cout << "  " << setw(27) << "TITLE" << " " << setw(10) << "ISBN" << " " << setw(14) << "AUTHOR" << " " <<
					setw(14) << "PUBLISHER" << " " << setw(10) << "DATE ADDED" << " " << setw(7) << "QTY O/H" << " " <<
					setw(14) << "WHOLESALE COST" << " " << setw(11) << "RETAIL COST" << endl;

			cout << "  " << setw(27) << "___________________________" << " " << setw(10) << "__________" << " " << setw(14)
					<< "______________" << " " <<
						setw(14) << "______________" << " " << setw(10) << "__________" << " " << setw(7) << "_______" << " " <<
						setw(14) << "_____________" << " " << setw(11) << "___________" << endl;
			for (it = listName.begin(); it != listName.end(); ++it)
			{

			  	  if(it == listName.end())
			  	  {
			  		  break;
			  	  }
				tempBookTitle =(*it).getTitle();
				tempIsbn =(*it).getISBN();
				tempAuthor =(*it).getAuthor();
				tempPublisher =(*it).getPub();
				tempDateAdded =(*it).getDateAdded();
				tempQtyOnHand =(*it).getQty();
				tempWholesale =(*it).getWholesale();
				tempRetail =(*it).getRetail();


				string cutTitle = tempBookTitle.substr(0,27);
				string cutAuthor = tempAuthor.substr(0,14);
				string cutPub = tempPublisher.substr(0,14);

				cout << "  " << setw(27) << cutTitle << " " << setw(10) << tempIsbn << " " << setw(14)
						<< cutAuthor << " " <<
							setw(14) << cutPub << " " << setw(10) << tempDateAdded;
				cout << " " << right << setw(7) << tempQtyOnHand << " " << setprecision(2) << fixed <<
							setw(14) << tempWholesale << " " << setw(11) << tempRetail << left << endl << endl;
				bookDisplay++;
				if(bookDisplay == 0)
				{
					cout << "Press any key to continue...";
					cin.get(junk);
					cin.ignore(10000,'\n');
					page++;
					system("clear");
					cout << "********************************************************************************************************************" << endl;
					cout << "                                                SERENDIPITY BOOKSELLERS                                             " << endl;
					cout << "                                                    REPORTS LISTING                                                 " << endl;
					cout << "  Date     " <<(timePtr->tm_mday)<<"/"<< (timePtr->tm_mon)+1 <<"/"<< (timePtr->tm_year)+1900 <<
							"\t Page: " << page << " of 13" << "\t Database Size: 20" <<  "\t Current Book Count: " << BookType::getBookCount() << endl << endl;


					cout << left;
					cout << "  " << setw(27) << "TITLE" << " " << setw(10) << "ISBN" << " " << setw(14) << "AUTHOR" << " " <<
							setw(14) << "PUBLISHER" << " " << setw(10) << "DATE ADDED" << " " << setw(7) << "QTY O/H" << " " <<
							setw(14) << "WHOLESALE COST" << " " << setw(11) << "RETAIL COST" << endl;

					cout << "  " << setw(27) << "___________________________" << " " << setw(10) << "__________" << " " << setw(14)
							<< "______________" << " " <<
								setw(14) << "______________" << " " << setw(10) << "__________" << " " << setw(7) << "_______" << " " <<
								setw(14) << "_____________" << " " << setw(11) << "___________" << endl;

				}



			}
			cout << "Press any key to continue...";
			cin.get(junk);
			cin.ignore(10000,'\n');
			page++;
		}

