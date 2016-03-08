#include <iostream>
#include <algorithm>
#include <vector>
#include <functional>
#include <cassert>
typedef std::vector<int>::iterator IntIterator;
using namespace std;

void TestFindIf()
{
	int elements[] = { 1, 2, 3, 23, 432, 596 };
	std::vector<int> v(elements, elements + 6);
	std::vector<int>::iterator it = std::find_if(v.begin(), v.end(), std::bind2nd(std::greater<int>(), 100));
	cout << *it << endl;
	assert(*it > 100);

	it = std::find_if(v.begin(), v.end(), std::bind2nd(std::greater<int>(), 1000));
	cout << *it << endl;
	
}

void TestFindAdjacent()
{
	int elements[] = { 1, 2, 3, 100, 100, 5 };
	int n = sizeof(elements) / sizeof(int);
	std::vector<int> v(elements, elements + n);
	std::vector<int>::iterator it = std::adjacent_find(v.begin(), v.end());
	cout << *it << endl;
	cout << *(it + 1) << endl;
	assert(*it == *(it + 1));

	// *it > *(it+1)
	it = std::adjacent_find(v.begin(), v.end(), std::greater<int>());
}

void TestCount_if()
{
	int elements[] = { 1, 2, 3, 100, 100, 5 };
	int n = sizeof(elements) / sizeof(int);
	std::vector<int> v(elements, elements + n);

	int count = std::count_if(v.begin(), v.end(), std::bind1st(std::less<int>(), 100));

	cout << count << endl;
}


void TestMismatch()
{
	int elements[] = { 1, 2, 3, 100, 100, 5 };
	int elements2[] = { 1, 2, 3, 200 };
	std::vector<int> v(elements, elements + 6);
	std::vector<int> v2(elements2, elements2 + 4);
	
	std::pair<IntIterator, IntIterator> p = std::mismatch(v.begin(), v.end(), v2.begin());
	cout << *p.first << endl;
	cout << *p.second << endl;

	cout << 3 << endl;
}



int main()
{
	//TestCount_if();
	TestMismatch();
	return 0;
}

