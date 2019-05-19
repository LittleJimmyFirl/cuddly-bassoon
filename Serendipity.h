#ifndef SERENDIPITY_H
#define SERENDIPITY_H

#include <iostream>
#include <fstream>
#include <iomanip>
#include <stdlib.h>
#include <string>
#include <cstring>
#include "orderedLinkedList.h"
#include "strupper.h"
#include "bookdata.h"
#include "reports.h"


using namespace std;


const int SIZE2 = 20; //Constant size for maximum database entries


void CashModule (orderedLinkedList<BookType>, orderedLinkedList<BookType>, orderedLinkedList<BookType>, orderedLinkedList<BookType>); // funtion to cashier module
void InventoryModule (orderedLinkedList<BookType>, orderedLinkedList<BookType>, orderedLinkedList<BookType>, orderedLinkedList<BookType>); // function to Inventory Module
void ReportsModule(orderedLinkedList<BookType>, orderedLinkedList<BookType>, orderedLinkedList<BookType>, orderedLinkedList<BookType>); // function to reports module
void LookUpBook(orderedLinkedList<BookType>, orderedLinkedList<BookType>, orderedLinkedList<BookType>, orderedLinkedList<BookType>); // function to lookup book
void AddABook(orderedLinkedList<BookType>, orderedLinkedList<BookType>, orderedLinkedList<BookType>, orderedLinkedList<BookType>); // function to add a book
void EditABook(orderedLinkedList<BookType>, orderedLinkedList<BookType>, orderedLinkedList<BookType>, orderedLinkedList<BookType>); // function to edit a book
void DeleteABook(orderedLinkedList<BookType>, orderedLinkedList<BookType>, orderedLinkedList<BookType>, orderedLinkedList<BookType>); // function to book info

#endif
