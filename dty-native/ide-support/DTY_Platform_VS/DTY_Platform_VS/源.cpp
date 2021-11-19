#include"../../../smartPointer.h"
#include<iostream>

using namespace std;

int main()
{
	dty::SmartPointer<int32> SP1(new int32[10], 10);
	for (int i = 0; i < SP1.Size(); ++i)
		SP1[i] = i;

	for (int i = 0; i < SP1.Size(); ++i)
		cout << SP1[i] << endl;

	return 0;
}