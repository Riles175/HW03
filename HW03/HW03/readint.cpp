#include "stdafx.h"
#include "readint.h"
#include <string>
#include <iostream>
#include <limits>
#include <ios>
#include <stdexcept>
using namespace std;

int read_int(const string &prompt, int low, int high){
	cin.exceptions(ios_base::failbit);
	int num = 0;
	while (true) {
		try {
			cout << prompt;
			cin >> num;
			if (num <= low || num >= high) {
				throw range_error("This number is out side of the range");
			}
			if (num > 2147483647) //INT_MAX works too btw -RS
				throw range_error("Input is too large.");
			return num;
		} catch (ios_base::failure& ex) {
			cout << "Bad numeric string -- try again\n";
			cin.clear();
			cin.ignore(numeric_limits<int>::max(), '\n');
		}
		catch (range_error& ex2) {
			cout << ex2.what() << "! -- try again\n";
			cin.clear();
			cin.ignore(numeric_limits<int>::max(), '\n');
		}
		
	}
}
