
#include <iostream>
#include "QStaticLinkList.h"

using namespace std;

int main(int argc, char* argv[])
{
	QStaticLinkList<int> list;
	cout << list.empty() << endl;
	list.insert(1, 1);
	cout << list.empty() << endl;
	cout << list.find(1) << endl;
	cout << list.get (1) << endl;

	return EXIT_SUCCESS;
}
