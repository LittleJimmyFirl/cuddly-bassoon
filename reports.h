#ifndef REPORTS_H
#define REPORTS_H

#include <iostream>
#include <iomanip>
#include <stdlib.h>
#include <string>
#include <cstring>
#include <cmath>
#include <ctime>

#include "Serendipity.h"

using namespace std;

void repListing (orderedLinkedList<BookType>, orderedLinkedList<BookType>, orderedLinkedList<BookType>, orderedLinkedList<BookType>);
void repWholesale (orderedLinkedList<BookType>, orderedLinkedList<BookType>, orderedLinkedList<BookType>, orderedLinkedList<BookType>);
void repRetail (orderedLinkedList<BookType>, orderedLinkedList<BookType>, orderedLinkedList<BookType>, orderedLinkedList<BookType>);

#endif
