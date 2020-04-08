// Christina Gerstner
// clgdtf@mail.umkc.edu
// 10/15/2019
// CS201L Lab 09

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "LibraryBook.h"
using namespace std;

int main() {

	string title;
	string author;
	string isbn;
	string the_isbn;
	vector<LibraryBook> books;

	ifstream fin("books.txt");
	ifstream fin_isbn("isbns.txt");
	ofstream fout("checkedout.txt");
	
	while (fin.good()) {
		getline(fin, title);
		getline(fin, author);
		getline(fin, isbn);
		LibraryBook book(title, author, isbn);
		books.push_back(book);
	}
	fin.close();

	while (fin_isbn.good()) {
		getline(fin_isbn, the_isbn);

		for (int i = 0; i < books.size(); ++i) {
			if (books.at(i).get_isbn() == the_isbn) {	// checks if objects' isbn matches isbn in "isbns.txt" file
				// checkout or checkin?
				if (books.at(i).is_checked_out() == false) {
					books.at(i).check_out();	// makes status of book true
				}
				else if (books.at(i).is_checked_out() == true) {
					books.at(i).check_in();		// makes status of book false
				}
			}
		}
	}
	fin_isbn.close();

	// prints report to output file => only books that are checked_out
	fout << "Books checked out :\n" << endl;
	fout << "--------------------\n\n" << endl;
	fout << "Title          Author          ISBN" << endl;
	for (int i = 0; i < books.size(); ++i) {
		if (books.at(i).is_checked_out() == true) {
			fout << endl << books.at(i).get_title() << "       " << books.at(i).get_author() << "       " << books.at(i).get_isbn() << endl;
		}
	}

	return 0;
}