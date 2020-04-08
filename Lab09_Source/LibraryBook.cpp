#include <iostream>
#include <string>
#include <vector>
#include "LibraryBook.h"
using namespace std;

LibraryBook::LibraryBook() {
	title = " ";
	author = " ";
	isbn = " ";
	checked_out = false;
}

LibraryBook::LibraryBook(string title_name, string author_name, string isbn_num) {		// sets values from file to objects' variables
	title = title_name;
	author = author_name;
	isbn = isbn_num;
	checked_out = false;
}

string LibraryBook::get_title() const {		// gets title of book
	return title;
}

string LibraryBook::get_author() const {		// gets author's name of book
	return author;
}

string LibraryBook::get_isbn() const {		// gets ISBN of book
	return isbn;
}

void LibraryBook::check_out() {
	checked_out = true;
}

void LibraryBook::check_in() {
	checked_out = false;
}

bool LibraryBook::is_checked_out() const {		// gets status of book, if checked_out => true OR if checked_in => false
	return checked_out;
}
