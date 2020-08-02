#include <iostream>
#include <fstream>
#include "C:/Users/DELL/source/repos/test/head.h"

using std::cout;
using std::cerr;
using std::ifstream;
using std::endl;

int main(int argc, char* argv[])
{
	if (argc != 2) {
		cerr << "Please give the file name." << endl;
		return -1;
	}
	ifstream in(argv[1]);
	if (!in) {
		cerr << "Can't open the file." << endl;
		return -1;
	}

	Sales_data total;
	if (read(in, total)) {
		Sales_data trans;
		while (read(in, trans)) {
			if (total.isbn() == trans.isbn())
				total.combine(trans);
			else {
				print(cout, total) << endl;
				total = trans;
			}
		}
		print(cout, total) << endl;
	}
	else {
		cerr << " No data?!" << endl;
	}
	return 0;
}