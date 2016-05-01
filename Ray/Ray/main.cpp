#include <iostream>
#include "Vector3.h"

using namespace std;

int main(int argc, char **argv)
{
	(void)argc; /* UNUSED */
	(void)argv; /* UNUSED */

	cout << "HelloWorld !" << endl;

	Vector3 v;

	cout << "First vector: " << v << endl;

	Vector3 w(1.0, 2.0, 3.0);

	cout << "Second vector: " << w + v << endl;

	return 0;
}