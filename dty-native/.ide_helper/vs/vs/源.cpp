#include"../../../utils/iterator.g.h"
#include<iostream>

using namespace dty::collection;

void fnMap(int& elem)
{
	std::cout << elem << std::endl;
}

int main()
{
	Iterator<int> iterator(new int[10]{ 1, 2, 3, 4,5,6,7,8,9,10 }, 10, true);

	iterator.ForEach(fnMap);

	return 0;
}