//============================================================================
// Name        : PlusOneInDigits.cpp
// Author      : wp
// Version     :
// Copyright   : wp
// Description : Given a non-negative number represented as an array of digits, plus one to the number.
// LeetCode No.: 66
//============================================================================

#include <iostream>
#include <vector>
using namespace std;

//leetcode: Runtime:  4ms
vector<int> plusOne(vector<int>& digits)
{
	int iSize = (int)digits.size();
	for(int i=iSize-1; i>=0; i--)
	{
		if(digits[i] < 9)
		{
			digits[i]++;
			return digits;
		}
		else
		{
			if(i > 0)
			{
				digits[i] = 0;
				continue;
			}
			else
			{
				digits[i] = 1;
				digits.push_back(0);
			}
		}
	}
	return digits;
}

void test(vector<int>& vec)
{
	for(int i=0; i<(int)vec.size(); i++)
	{
		printf("%d", vec[i]);
	}
	printf("\n********************************************\n");
}

/**
int main()
{
	//test case1
	vector<int> vec;
	for(int i=1; i<9; i++)
	{
		vec.push_back(i);
	}
	test(vec);
	plusOne(vec);
	test(vec);

	//test case2
	vector<int> vec2;
	vec2.push_back(1);
	vec2.push_back(1);
	vec2.push_back(1);
	test(vec2);
	plusOne(vec2);
	test(vec2);

	//test case3
	vec2.clear();
	vec2.push_back(9);
	vec2.push_back(9);
	vec2.push_back(9);
	test(vec2);
	plusOne(vec2);
	test(vec2);
}
**/
