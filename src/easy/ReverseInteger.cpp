//============================================================================
// Name        : ReverseInteger.cpp
// Author      : wp
// Version     :
// Copyright   : wp
// Description : Reverse digits of an integer
//============================================================================

#include <iostream>
#include <cmath>
using namespace std;

int reverse(int x)
{
	bool bNegative = (x < 0);

	long long res = 0;
	do
	{
		int iRedun = x % 10;
		res = res*10 + iRedun;
		x /= 10;
	}while(x != 0);
	if(!bNegative)
	{
		return res>=INT_MAX ? 0 : res;
	}
	else
	{
		return res<=INT_MIN ? 0 : res;
	}
}

int main()
{
	printf("reverse(%d)=%d\n", 0, reverse(0));
	printf("reverse(%d)=%d\n", 123, reverse(123));
	printf("reverse(%d)=%d\n", 321, reverse(321));
	printf("reverse(%d)=%d\n", -123, reverse(-123));
	printf("reverse(%d)=%d\n", -321, reverse(-321));
	printf("reverse(%d)=%d\n", INT_MAX, reverse(INT_MAX));
	printf("reverse(%d)=%d\n", INT_MIN, reverse(INT_MIN));
	printf("reverse(%d)=%d\n", 1000000007, reverse(1000000007));
	printf("reverse(%d)=%d\n", -2000000007, reverse(-2000000007));
	printf("reverse(%d)=%d\n", -1000000002, reverse(-1000000002));
}
