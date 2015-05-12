#include "Point2D.h"
#include "DynArray.h"0
#include "iostream"

using namespace std;

int main()
{
	int numbersOf;

	//cout << "A man chooses, a slave obeys!" << endl;	

	DynArray<int> new_array;

	for (int i = 0; i < 10000; ++i)
	{
		new_array.pushBack(i);
	}

	numbersOf = new_array.bubbleSort();

	cout << numbersOf << endl;

	getchar();
}