//============================================================================
// Name        : RemoveDupliInArray.cpp
// Author      : wp
// Version     :
// Copyright   : wp
// Description : Given a sorted array, remove the duplicates in place such that each element appear only once and return the new length.
//============================================================================

#include <iostream>
#include <vector>
using namespace std;

//leetcode: Runtime: 68 ms
int removeDuplicates(vector<int>& nums)
{
	vector<int> needRemovedIndex;
	int iSize = (int)nums.size();
	for(int i=0; i<iSize-1;)
	{
		if(nums[i] == nums[i+1])
		{
			nums.erase(nums.begin() + (i + 1));
			--iSize;
			continue;
		}
		i++;
	}
	return iSize;
}

void test(vector<int>& vec)
{
	printf("removeDuplicates=%d:\n", removeDuplicates(vec));
	for(int i=0; i<(int)vec.size(); i++)
	{
		printf("%d-", vec[i]);
	}
	printf("\n********************************************\n");
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
	vec.push_back(11);
	vec.push_back(12);
	vec.push_back(12);
	test(vec);

	vector<int> vec2;
	vec2.push_back(11);
	vec2.push_back(11);
	vec2.push_back(11);
	test(vec2);

	vec2.clear();
	vec2.push_back(11);
	vec2.push_back(11);
	vec2.push_back(13);
	test(vec2);

}
