#include "reports.h"

void repRetail (orderedLinkedList<BookType> listName, orderedLinkedList<BookType> listWholesale, orderedLinkedList<BookType> listDate, orderedLinkedList<BookType> listQty)
{
  time_t t = time(NULL);
  tm* timePtr = localtime(&t);
  int page = 1;

  string tempBookTitle;
  string tempIsbn;
  int tempQtyOnHand;
  double tempRetail;
  double totalRetail;
  int bookDisplay = 0;

  int index = 0;
  char junk;




			system("clear");
			cout << "********************************************************************************************************************" << endl;
			cout << "                                                SERENDIPITY BOOKSELLERS                                             " << endl;
			cout << "                                                    REPORTS LISTING                                                 " << endl;
		cout << "  Date     " <<(timePtr->tm_mday)<<"/"<< (timePtr->tm_mon)+1 <<"/"<< (timePtr->tm_year)+1900 <<
				"\t Page: " << page << " of 13" << "\t Database Size: " << BookType::getBookCount() <<  "\t Current Book Count: " << BookType::getBookCount() << endl << endl;


		cout << left;
		cout << "     " << setw(45) << "TITLE" << "     " << setw(10) << "ISBN" << "     " << setw(7) << "QTY O/H" << "     " <<
					setw(14) << "RETAIL COST" << endl;

		cout << "     " << setw(45) << "_____________________________________________" << "     " << setw(10) << "__________" << "     " << setw(7) << "_______" <<
				  "     " << setw(11) << "__________" << endl;

		for (linkedListIterator<BookType> it = listName.begin(); it != listName.end(); ++it)
		{
		  	  if(it == listName.end())
		  	  {
		  		  break;
		  	  }
			tempBookTitle =(*it).getTitle();
			tempIsbn =(*it).getISBN();
			tempQtyOnHand =(*it).getQty();
			tempRetail =(*it).getRetail();
			totalRetail = totalRetail + (tempRetail * tempQtyOnHand);


			string cutTitle = tempBookTitle.substr(0,45);


			cout << "     " << setw(45) << cutTitle << "     " << setw(10) << tempIsbn << "     " << setw(14)
				  << setw(7) << right << tempQtyOnHand << "     " << setw(11) << setprecision(2) << fixed << tempRetail << left << endl << endl;
			bookDisplay++;
			if (bookDisplay == 10)
			{

				cout << "Press any key to continue...";
				cin.get(junk);
				cin.ignore(10000,'\n');
				bookDisplay = 0;
				page++;
				system("clear");
				cout << "********************************************************************************************************************" << endl;
				cout << "                                                SERENDIPITY BOOKSELLERS                                             " << endl;
				cout << "                                                    REPORTS LISTING                                                 " << endl;
			cout << "  Date     " <<(timePtr->tm_mday)<<"/"<< (timePtr->tm_mon)+1 <<"/"<< (timePtr->tm_year)+1900 <<
					"\t Page: " << page << " of 13" << "\t Database Size: " << BookType::getBookCount() <<  "\t Current Book Count: " << BookType::getBookCount() << endl << endl;


			cout << left;
			cout << "     " << setw(45) << "TITLE" << "     " << setw(10) << "ISBN" << "     " << setw(7) << "QTY O/H" << "     " <<
						setw(14) << "RETAIL COST" << endl;

			cout << "     " << setw(45) << "_____________________________________________" << "     " << setw(10) << "__________" << "     " << setw(7) << "_______" <<
					  "     " << setw(11) << "__________" << endl;

			}
		}

			cout << "     " << "TOTAL VALUE OF THE RETAIL INVENTORTY: " << setprecision(2) << fixed << totalRetail << endl << endl;
			cout << "Press any key to continue...";
			cin.get(junk);
			cin.ignore(10000,'\n');

		}
