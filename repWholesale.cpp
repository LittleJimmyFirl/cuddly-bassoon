#include "reports.h"

void repWholesale (orderedLinkedList<BookType> listName, orderedLinkedList<BookType> listWholesale, orderedLinkedList<BookType> listDate, orderedLinkedList<BookType> listQty)
{
	  time_t t = time(NULL);
	  tm* timePtr = localtime(&t);
	  int page = 1;

	  string tempBookTitle;
	  string tempIsbn;
	  int tempQtyOnHand;
	  double tempWholesale;
	  double totalWholesale;

	  int index = 0;
	  char junk;
	  int bookDisplay = 0;
	  linkedListIterator<BookType> it;


			system("clear");
			cout << "********************************************************************************************************************" << endl;
			cout << "                                                SERENDIPITY BOOKSELLERS                                             " << endl;
			cout << "                                                    REPORTS LISTING                                                 " << endl;
		  cout << "  Date     " <<(timePtr->tm_mday)<<"/"<< (timePtr->tm_mon)+1 <<"/"<< (timePtr->tm_year)+1900 <<
				"\t Page: " << page << " of 3" << "\t Database Size: 20" <<  "\t Current Book Count: " << BookType::getBookCount() << endl << endl;


		  cout << left;
		  cout << "     " << setw(45) << "TITLE" << "     " << setw(10) << "ISBN" << "     " << setw(7) << "QTY O/H" << "     " <<
					setw(14) << "WHOLESALE COST" << endl;

		  cout << "     " << setw(45) << "_____________________________________________" << "     " << setw(10) << "__________" << "     " << setw(7) << "_______" <<
				  "     " << setw(14) << "_____________" << endl;


		for (it = listName.begin(); it != listName.end(); ++it)
		{

		  	  if(it == listName.end())
		  	  {
		  		  break;
		  	  }
				tempBookTitle =(*it).getTitle();
				tempIsbn =(*it).getISBN();
				tempQtyOnHand =(*it).getQty();
				tempWholesale =(*it).getWholesale();
				totalWholesale = totalWholesale + (tempWholesale * tempQtyOnHand);


			string cutTitle = tempBookTitle.substr(0,45);


			  cout << "     " << setw(45) << cutTitle << "     " << setw(10) << tempIsbn << "     " << setw(14)
					  << setw(7) << right << tempQtyOnHand << "     " << setw(14) << setprecision(2) << fixed << tempWholesale << left << endl << endl;
			  bookDisplay++;
			  if(bookDisplay == 0)
			  {
					cout << "Press any key to continue...";
					cin.get(junk);
					cin.ignore(10000,'\n');
					page++;
					cout << "********************************************************************************************************************" << endl;
					cout << "                                                SERENDIPITY BOOKSELLERS                                             " << endl;
					cout << "                                                    REPORTS LISTING                                                 " << endl;
				  cout << "  Date     " <<(timePtr->tm_mday)<<"/"<< (timePtr->tm_mon)+1 <<"/"<< (timePtr->tm_year)+1900 <<
						"\t Page: " << page << " of 3" << "\t Database Size: 20" <<  "\t Current Book Count: " << BookType::getBookCount() << endl << endl;


				  cout << left;
				  cout << "     " << setw(45) << "TITLE" << "     " << setw(10) << "ISBN" << "     " << setw(7) << "QTY O/H" << "     " <<
							setw(14) << "WHOLESALE COST" << endl;

				  cout << "     " << setw(45) << "_____________________________________________" << "     " << setw(10) << "__________" << "     " << setw(7) << "_______" <<
						  "     " << setw(14) << "_____________" << endl;

			  }

		  }
			cout << "     " << "TOTAL VALUE OF THE WHOLESALE INVENTORTY: " << setprecision(2) << fixed << totalWholesale << endl << endl;

			cout << "Press any key to continue...";
			cin.get(junk);
			cin.ignore(10000,'\n');
			page++;
}

