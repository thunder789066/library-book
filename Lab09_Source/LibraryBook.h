#pragma once
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class LibraryBook {
public:
	LibraryBook();
	LibraryBook(string title_name, string author_name, string isbn_num);
	string get_title() const;
	string get_author() const;
	string get_isbn() const;
	void check_out();
	void check_in();
	bool is_checked_out() const;
private:
	string title;
	string author;
	string isbn;
	bool checked_out;
};




