#ifndef _STL_NUMERIC_H
#define _STL_NUMERIC_H

#include <numeric>
#include <vector>
using namespace std;

void TestAccumulate()
{

	std::vector<int> v(100);
	std::iota(v.begin(), v.end(), 1);
	// 1 + 2 + ... 100
	int sum = std::accumulate(v.begin(), v.end(), 0);

	// 1 x 2 x ... x 10
	sum = std::accumulate(v.begin(), v.end(), 1, std::multiplies<int>());

}

void TestInnerProduct()
{
	int a[] = { 1, 2, 3 };
	int b[] = { 4, 5, 6 };

	// a[0] x b[0] + a[1] x b[1] + a[2] x b[2]
	int sum = std::inner_product(a, a + 3, b, 0);

	// (a[0] + b[0]) x (a[1] + b[1]) x (a[2] + b[2])
	sum = std::inner_product(a, a + 3, b, 1, std::multiplies<int>(), std::plus<int>());
}

void TestPartialSum()
{
	int elements[] = { 1, 2, 3, 4, 5 };
	const int n = sizeof(elements) / sizeof(int);
	std::vector<int> v(elements, elements + n);
	std::partial_sum(v.begin(), v.end(), v.begin());
}

#endif