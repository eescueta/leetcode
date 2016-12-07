#pragma once
#include <vector>
#include <iostream>
#include <map>
#include <algorithm>
#include <stack>
#include <list>
#include "Solution.h"

using namespace std;

/*
Implement pow(x, n).
*/


/*
8.88023
3
2
6
5
-1
8.88023
-3
8.88023
0
8.88023
8.88023
8.88023
1
8.88023
-1
1.00000
-2147483648
2.00000
-2147483648
1.00500
-2147483648
-1.00000
-2147483648
-1.00000
-2147483647
-1.00000
2147483647
-1.00000
2147483646
*/

double myPow(double x, int n) {
	// negative one cases
	if (x == -1)
	{
		if (n % 2 == 0)
			return 1;
		else
			return -1;
	}


	//special cases
	if (n == 0 || x == 1)
		return 1;
	if (n == 1)
		return x;
	if (n == INT_MIN)
		return 0;

	//positive case
	if (n > 0)
	{
		if (n % 2 != 0)
			return x * myPow(x*x, n / 2);
		else
			return myPow(x*x, n / 2);
	}
	else
	{
		return 1.0 / myPow(x, -n);
	}

	return 0;
}