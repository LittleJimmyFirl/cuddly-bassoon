
#include "bookdata.h"

using namespace std;

//const int NUM_BOOKS = 20;
//extern BookType book[NUM_BOOKS];

int BookType::bookCount = 0;

//Constructor
BookType::BookType()
{
	setTitle("\0");
	setISBN("EMPTY");
	setAuthor("EMPTY");
	setPub("EMPTY");
	setDateAdded("EMPTY");
	setQty(0);
	setWholesale(0.00);
	setRetail(0.00);
	cartQty = 0;
	bookSortCode = 0;

}

//Constructor Dos
BookType::BookType( string t, string i, string a, string p, string d, int q, double w, double r)
{
	setTitle(t);
	setISBN(i);
	setAuthor(a);
	setPub(p);
	setDateAdded(d);
	setQty(q);
	setWholesale(w);
	setRetail(r);
	cartQty = 0;
	bookSortCode = 0;
}

/*BookType::~BookType()
{
	cout << bookTitle << " has been deleted!" << endl;
}
*/
void BookType::setTitle(string newTitle)
{
	//strUpper(newTitle);
	bookTitle =  newTitle;
}

void BookType::setISBN(string newISBN)
{
	//strUpper(newISBN);
	isbn = newISBN;
}

void BookType::setAuthor(string newAuthor)
{
	//strUpper(newAuthor);
	author = newAuthor;
}

void BookType::setPub(string newPublisher)
{
	//strUpper(newPublisher);
	publisher = newPublisher;
}

void BookType::setDateAdded(string newDate)
{
	//strUpper(newDate);
	dateAdded = newDate;
}

void BookType::setQty(int newQuantity)
{
	qtyOnHand = newQuantity;
}

void BookType::setWholesale(double newWholesale)
{
	wholesale = newWholesale;
}

void BookType::setRetail(double newRetail)
{
	retail = newRetail;
}
string BookType::getTitle() const
{
	return bookTitle;
}
string BookType::getISBN() const
{
	return isbn;
}
string BookType::getAuthor() const
{
	return author;
}
string BookType::getPub() const
{
	return publisher;
}
string BookType::getDateAdded() const
{
	return dateAdded;
}
int BookType::getQty() const
{
	return qtyOnHand;
}
double BookType::getWholesale() const
{
	return wholesale;
}
double BookType::getRetail() const
{
	return retail;
}
int BookType::isEmpty(int subscript, BookType *book[])
{
	if (book[subscript]->bookTitle[0] == 0)
		return 1;
	else
		return 0;
}

void BookType::removeBook(int subscript, BookType *book[])
{
	book[subscript]->bookTitle[0] = 0;
	book[subscript]->isbn[0] = 0;
}

void BookType::setSortCode(int s)
{
	bookSortCode = s;
}
void BookType:: setCartQty(int c)
{
	cartQty = c;
}
int BookType::getSortCode() const
{
	return bookSortCode;
}
void BookType::getCartQty(int c)
{
	c= cartQty;
}

void BookType::IncBookCount()
{
	bookCount++;
	return;
}
void BookType::DecBookCount()
{
	bookCount--;
	return;
}
int BookType::getBookCount()
{
	return bookCount;
}

