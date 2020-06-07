#include <iostream>
#include <string>
#include "List.h"

using namespace std;
using namespace mylist;

int main() {
	List<int> l1;
	List<string> l2;
	const int num = 10;

	cout << "Testing list with integer values ..." << endl << endl;
	cout << "pushing back " << num << " integer values" << endl;

	for (int i = 0; i < num; ++i) {
		l1.push_back(i);
	}
	cout << "size " << l1.size() << endl;

	;
	//cout << *itr++;
	for (auto itr = l1.begin(); itr != l1.end(); ++itr) {
		cout << *itr << " ";
	}
	cout << endl << "_____________________________" << endl << endl;

	cout << "pushing front " << num << " integer values" << endl;

	for (int i = 0; i < num; ++i) {
		l1.push_front(i);
	}

	cout << "size " << l1.size() << endl;

	for (auto itr = l1.begin(); itr != l1.end(); ++itr) {
		cout << *itr << " ";
	}
	cout << endl << "_____________________________" << endl << endl;

	cout << "pop front " << num/2 << " integer values" << endl;
	for (int i = 0; i < num/2; ++i) {
		l1.pop_front();
	}

	cout << "size " << l1.size() << endl;

	for (auto itr = l1.begin(); itr != l1.end(); ++itr) {
		cout << *itr << " ";
	}
	cout << endl << "_____________________________" << endl << endl;

	cout << "pop back " << num/2 << " integer values" << endl;
	for (int i = 0; i < num/2; ++i) {
		l1.pop_back();
	}

	cout << "size " << l1.size() << endl;
	
	for (auto itr = l1.begin(); itr != l1.end(); ++itr) {
		cout << *itr << " ";
	}
	cout << endl << "_____________________________" << endl << endl;

	cout << "removing 0" << endl;
	l1.remove(0);
	cout << "size " << l1.size() << endl;
	cout << l1 << endl;
	cout << endl << "_____________________________" << endl << endl;

	cout << "reverse list" << endl;
	l1.reverse();
	cout << "size " << l1.size() << endl;
	cout << l1 << endl;
	cout << endl << "_____________________________" << endl << endl;

	cout << "clearing list" << endl;
	l1.clear();

	if (l1.empty()) {
		cout << "all cleared" << endl;
	} else {
		cout << "wrong with clear() function" << endl;
	}

	cout << endl << "_____________________________" << endl << endl;

	/* testing string list */
	cout << "Testing list with string values ..." << endl;
	cout << "pushing back " << num << " string values" << endl;

	for (int i = 1; i <= num; ++i) {
		string str(i, 'a');
		l2.push_back(str);
	}
	cout << "size " << l2.size() << endl;

	for (auto itr2 = l2.begin(); itr2 != l2.end(); ++itr2) {
		cout << *itr2 << " ";
	}
	cout << endl;
	cout << endl << "_____________________________" << endl << endl;

	cout << "pushing front " << num << " integer values" << endl;

	for (int i = 1; i <= num; ++i) {
		string str(i, 'b');
		l2.push_front(str);
	}

	cout << "size " << l2.size() << endl;

	for (auto itr2 = l2.begin(); itr2 != l2.end(); ++itr2) {
		cout << *itr2 << " ";
	}
	cout << endl;
	cout << endl << "_____________________________" << endl << endl;

	cout << "pop back " << num/2 << " string values" << endl;
	for (int i = 0; i < num/2; ++i) {
		l2.pop_back();
	}

	cout << "size " << l2.size() << endl;

	for (auto itr2 = l2.begin(); itr2 != l2.end(); ++itr2) {
		cout << *itr2 << " ";
	}
	cout << endl;
	cout << endl << "_____________________________" << endl << endl;

	cout << "removing a" << endl;
	l2.remove("a");
	cout << "size " << l2.size() << endl;
	cout << l2 << endl;
	cout << endl << "_____________________________" << endl << endl;

	cout << "reverse list" << endl;
	l2.reverse();
	cout << "size " << l2.size() << endl;
	cout << l2 << endl;
	cout << endl << "_____________________________" << endl << endl;

	cout << "clearing list" << endl;
	l2.clear();

	if (l2.empty()) {
		cout << "all cleared" << endl;
	} else {
		cout << "wrong with clear() function" << endl;
	}
	cout << endl << "_____________________________" << endl << endl;

}
