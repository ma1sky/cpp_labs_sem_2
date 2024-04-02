#include "fio.h"
#include <iostream>
#include <iomanip>
#include <ostream>

using namespace std;

int main() {
	fio first;
	first.setFam("Yes");
	first.setName("No");
	first.setFather("curva");

	fio second;
	second.setFam("Yes");
	second.setName("No");
	second.setFather("cuva");

	first.printFIO();
	second.printFIO();
	bool res = first == second;
	cout << res;

}