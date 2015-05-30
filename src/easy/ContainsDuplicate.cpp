//============================================================================
// Name        : ContainsDuplicate.cpp
// Author      : wp
// Version     :
// Copyright   : wp
// Description : Given an array of integers, find if the array contains any duplicates. Your function should return true if any value appears at least twice in the array, and it should return false if every element is distinct.
//============================================================================

#include <iostream>
#include <vector>
#include <set>
using namespace std;

bool containsDuplicate(vector<int>& nums)
{
	set<int> numsSet(nums.begin(), nums.end());
	return numsSet.size() < nums.size();
}

int main()
{
	//case 1
	vector<int> nums;
	nums.push_back(-1);
	nums.push_back(0);
	nums.push_back(1);
	nums.push_back(2);
	nums.push_back(5);
	nums.push_back(7);
	nums.push_back(5);
	printf("result()=%d\n", containsDuplicate(nums));

	//case 2
	nums.clear();
	nums.push_back(-1);
	nums.push_back(0);
	printf("result()=%d\n", containsDuplicate(nums));

	//case 3
	nums.clear();
	nums.push_back(-1);
	nums.push_back(-1);
	printf("result()=%d\n", containsDuplicate(nums));

	//case 4
	nums.clear();
	nums.push_back(-1);
	nums.push_back(0);
	nums.push_back(0);
	printf("result()=%d\n", containsDuplicate(nums));

	//case 5
	nums.clear();
	nums.push_back(3);
	nums.push_back(1);
	printf("result()=%d\n", containsDuplicate(nums));
}
