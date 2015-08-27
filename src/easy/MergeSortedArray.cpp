//============================================================================
// Name        : MergeSortedArray.cpp
// Author      : wp
// Version     :
// Copyright   : wp
// Description : Given two sorted integer arrays nums1 and nums2, merge nums2 into nums1 as one sorted array.
// LeetCode No : 88
//============================================================================

/**
 * from a friend on leetcode.com:
 * class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = m - 1, j = n - 1, tar = m + n - 1;
        while (j >= 0) {
            nums1[tar--] = i >= 0 && nums1[i] > nums2[j] ? nums1[i--] : nums2[j--];
        }
    }
};
 */
#include <iostream>
#include <queue>
using namespace std;


void merge(vector<int>& nums1, int m, vector<int>& nums2, int n)
{
	vector<int> totalNums;
	vector<int>::iterator it;
	vector<int>::iterator it2;
	it=nums1.begin();
	it2=nums2.begin();
	while(true)
	{
		if(it == nums1.end() && it2 == nums2.end())
		{
			break;
		}
		if(m == 0 && n == 0)
		{
			break;
		}
		if(it == nums1.end())
		{
			if (n > 0)
			{
				totalNums.push_back(*it2);
				++it2;
				--n;
			}
			continue;
		}
		if(it2 == nums2.end())
		{
			if (m > 0)
			{
				totalNums.push_back(*it);
				++it;
				--m;
			}
			continue;
		}
		if(it != nums1.end() && it2 != nums2.end())
		{
			if(*it2 < *it)
			{
				if (n > 0)
				{
					totalNums.push_back(*it2);
					--n;
				}
				++it2;
			}
			else
			{
				if (m > 0)
				{
					totalNums.push_back(*it);
					--m;
				}
				++it;
			}
		}
	}
	nums1 = totalNums;
}


int main()
{
	vector<int> nums1;

	nums1.push_back(3);
	nums1.push_back(5);
	nums1.push_back(9);
	nums1.push_back(11);
	nums1.push_back(23);
	nums1.push_back(25);

	vector<int> nums2;
	nums2.push_back(2);
	nums2.push_back(7);
	nums2.push_back(9);
	nums2.push_back(13);
	nums2.push_back(20);

	vector<int>::iterator it;

	merge(nums1, nums1.size(), nums2, nums2.size());
	for(it=nums1.begin(); it!=nums1.end(); it++)
	{
		printf("%d ", *it);
	}
	printf("\n");

	//case2
//	nums1.clear();
//	nums1.push_back(0);
//	nums2.clear();
//	nums2.push_back(1);
//	merge(nums1, 0, nums2, nums2.size());
//
//	for(it=nums1.begin(); it!=nums1.end(); it++)
//	{
//		printf("%d ", *it);
//	}
//	printf("\n");

	//case3
//	nums2.clear();
//	merge(nums1, nums1.size(), nums2, 0);
//
//	for(it=nums1.begin(); it!=nums1.end(); it++)
//	{
//		printf("%d ", *it);
//	}

	//case4
//	nums1.clear();
//	nums2.clear();
//	merge(nums1, 0, nums2, 0);
//
//	for(it=nums1.begin(); it!=nums1.end(); it++)
//	{
//		printf("%d ", *it);
//	}
}
