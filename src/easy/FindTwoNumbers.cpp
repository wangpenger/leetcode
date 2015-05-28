//============================================================================
// Name        : FindTwoNumbers.cpp
// Author      : wp
// Version     :
// Copyright   : wp
// Description : Given an array of integers, find two numbers such that they add up to a specific target number.
//============================================================================

#include <iostream>
#include <cmath>
#include <vector>
#include <tr1/unordered_map>
using namespace std;
using namespace std::tr1;

//this mothod is over time.
/**
vector<int> twoSum(vector<int>& nums, int target)
{
	vector<int> vec;
	int numsSize = nums.size();
	for(int i=0; i<numsSize; i++)
	{
		for(int j=i+1; j<numsSize; j++)
		{
			if(nums[i] + nums[j] == target)
			{
				vec.push_back(i + 1);
				vec.push_back(j + 1);
				return vec;
			}
		}
	}
	return vec;
}
*/

vector<int> twoSum(vector<int>& nums, int target)
{
	vector<int> vec;
	unordered_map<int,int> numsMap;
	int numsSize = nums.size();
	for(int i=0; i<numsSize; i++)
	{
		if(numsMap.end() != numsMap.find(target - nums[i]))
		{
			vec.push_back(numsMap[target - nums[i]] + 1);
			vec.push_back(i +1);
			return vec;
		}
		numsMap[nums[i]] = i;
	}
	return vec;
}

string vector2String(const vector<int>& nums)
{
	string str = "";
	str += "[";
	for(int i=0; i<nums.size(); i++)
	{
		char c[20];
		sprintf(c, "%d", nums[i]);
		str += c;
		if(i != nums.size() - 1)
		{
			str += ",";
		}
	}
	str += "]";
	return str;
}

/**
int main()
{
	vector<int> nums;
	nums.push_back(2);
	nums.push_back(7);
	nums.push_back(11);
	nums.push_back(15);

	vector<int> vec = twoSum(nums, 18);
	printf("twoSum(%s)=%s, target=%d \n", vector2String(nums).c_str(), vector2String(vec).c_str(), 18);

	vec = twoSum(nums, 26);
	printf("twoSum(%s)=%s, target=%d \n", vector2String(nums).c_str(), vector2String(vec).c_str(), 26);

}
*/
