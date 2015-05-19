//============================================================================
// Name        : SingleNumber.cpp
// Author      : wp
// Version     :
// Copyright   : wp
// Description : Given an array of integers, every element appears twice except for one. Find that single one.
//============================================================================

#include <iostream>
#include <vector>
using namespace std;


//this solution is according to the XOR:a ^ b ^ a = b.
int singleNumber(vector<int>& nums)
{
	int iRet = 0;
	vector<int>::iterator it;
	for(it=nums.begin(); it!=nums.end(); it++)
	{
		iRet ^= *it;
	}
	return iRet;
}

int main()
{
	//test case1
	vector<int> vec;
	for(int i=0; i<10; i++)
	{
		vec.push_back(i);
		vec.push_back(i);
	}
	vec.push_back(10);

	printf("singleNumber=%d\n", singleNumber(vec));

	vector<int> vec2;
	printf("singleNumber=%d\n", singleNumber(vec2));

}
