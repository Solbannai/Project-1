
#ifndef REFBOOK_H_
#define REFBOOK_H_

#include "LibraryItemBase.h"

class RefBook: public LibraryItemBase{
private:
	string type;
	string author;
public:
	//constructor using the base-constructor of libraryitembase
	RefBook(string n_type, int n_id, string n_title, string n_author) : LibraryItemBase(n_id, n_title), type(n_type), author(n_author){}
	//override borrow method to never allow borrowing
	virtual bool borrow(){
		cout << " Item is REFFERENCE and cannot be borrowed";
		return false;
	}
	//search the item if it contains a string
	virtual bool search(string searchStr){
		string  s_find = type + " " + author;
		transform(s_find.begin(), s_find.end(), s_find.begin(), ::tolower);
		transform(searchStr.begin(), searchStr.end(), searchStr.begin(), ::tolower);
		return LibraryItemBase::search(searchStr) || (s_find.find(searchStr) != string::npos);
	}
	//turn the item properties into a string
	virtual string toString(){
		string item = LibraryItemBase::toString() + "AUTHOR: " + author + " REFERENCE ONLY";
		return item;
	}

};

#endif
