#ifndef BOOKDATA_H
#define BOOKDATA_H

#include <iostream>
#include <iomanip>
#include <stdlib.h>
#include <string>
#include <cstring>
#include "strupper.h"

using namespace std;

//const int STR_SIZE = 51;

class BookType
{
private:

	string bookTitle;
	string isbn;
	string author;
	string publisher;
	string dateAdded;
	int qtyOnHand;
	double wholesale;
	double retail;

	int cartQty;
	int bookSortCode;

	static int bookCount;

public:

	BookType();
	BookType (string, string, string, string, string, int, double, double);
	void setTitle (string);
	void setISBN(string);
	void setAuthor(string);
	void setPub(string);
	void setDateAdded(string);
	void setQty(int);
	void setWholesale(double);
	void setRetail(double);
	void setSortCode(int);
	void setCartQty(int);
	int getSortCode()const;
	void getCartQty(int);
	string getTitle () const;
	string getISBN()const;
	string getAuthor() const;
	string getPub() const;
	string getDateAdded() const;
	int getQty() const;
	double getWholesale()const;
	double getRetail() const;
	void BookInfo(string isbn, string title, string author, string publisher,
		string date, int qty, double wholesale, double retail);
	static int getBookCount() ;
	static void IncBookCount();
	static void DecBookCount();
	bool operator>=(const BookType& other_book) const
		{
			bool found = false;
			bool greaterThan = false;
			string temp1 = this->getTitle();
			string temp2 = other_book.getTitle();
			string one;
			string two;
			int oneTemp = 0;
			int twoTemp = 0;

			if (this != &other_book)
			{
				switch (other_book.getSortCode())
				{
					case 0:
						if (temp1.compare(temp2) >= 0)
							found = true;
						break;
					case 1:
						if (this->getQty() <= other_book.getQty())
						{
							found = true;
						}
						break;

					case 2:
						if (this->getWholesale() <= other_book.getWholesale())
						{
							found = true;
						}
						break;
					case 3:
						greaterThan = false;
						one = this->getDateAdded().substr(6,10);
						oneTemp = atoi(two.c_str());

						two = other_book.getDateAdded().substr(6,10);
						twoTemp = atoi(two.c_str());

						if (oneTemp > twoTemp)
							greaterThan = true;
						else
						{
							if (oneTemp == twoTemp)
							{
								one = this->getDateAdded().substr(0,2);
								oneTemp = atoi(one.c_str());

								two = other_book.getDateAdded().substr(0,2);
								twoTemp = atoi(two.c_str());

								if (oneTemp > twoTemp)
									greaterThan = true;
								else
								{
									if (oneTemp == twoTemp)
									{
										one = this->getDateAdded().substr(3,5);
										oneTemp = atoi(one.c_str());

										two = other_book.getDateAdded().substr(3,5);
										twoTemp = atoi(two.c_str());

										if (oneTemp > twoTemp)
											greaterThan = true;
									}
								}

							}
						}
						if (greaterThan == true)
							found = true;
						break;

				}

			}
			return found;
		}
	bool operator==(const BookType& other_book) const
		{
		if((this->bookTitle == other_book.getTitle()) && (this->isbn == other_book.getISBN()))
			return true;
		else
			return false;
		}
	bool operator!=(const BookType& other_book) const
		{
		if((this->bookTitle == other_book.getTitle()) && (this->isbn == other_book.getISBN()))
			return false;
		else
			return true;
		}
	//~BookType();



	int isEmpty(int, BookType *book[]);
	void removeBook(int, BookType *book[]);
};

#endif
