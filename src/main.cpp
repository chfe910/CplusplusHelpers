
#include <iostream>
#include <string>
#include "QStaticLinkList.h"

using namespace std;

int main(int argc, char* argv[])
{
	QStaticLinkList<string> list;
	cout << list.empty() << endl;
	list.insert(1, "a");
	cout << list.empty() << endl;
	cout << list.find("a") << endl;
	list.insert(1, "b");
	list.insert(3, "c");
	list.Delete(2);

	string v;
	if (list.get (2, v))
	{
		cout << v << endl;
	}
	else
	{
		cout << "error!" << endl;
	}

	return EXIT_SUCCESS;
}
