#include "Serendipity.h"
#include "bookdata.h"

void BookType::BookInfo(string isbn, string title, string author, string publisher,
		string date, int qty, double wholesale, double retail)
{
	system ("clear");
	cout << "    Serendipity Booksellers  " << endl;
	cout << "       Inventory Database    " << endl << endl;
	cout << "1.  ISBN: " << isbn << endl;
	cout << "2.  Title: " <<  title << endl;
	cout << "3.  Author: " << author << endl;
	cout << "4.  Publisher: " << publisher << endl;
	cout << "5.  Date Added: " << date << endl;
	cout << "6.  Quantity on Hand: " << qty << endl;
	cout << "7.  Wholesale Cost: " << wholesale << endl;
	cout << "8.  Retail Price: " << retail << endl << endl << endl;
}
