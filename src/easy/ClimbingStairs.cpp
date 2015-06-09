//============================================================================
// Name        : ClimbingStairs.cpp
// Author      : wp
// Version     :
// Copyright   : wp
// Description : Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top.
// LeetCode No : 70
//============================================================================

#include <iostream>
#include <windows.h>

//this mothod over time limit.
int climbStairs2(int n)
{
	if(n <= 0)
	{
		return 0;
	}
	else if(n <= 3)
	{
		return n;
	}
	else
	{
		return climbStairs2(n - 1) + climbStairs2(n - 2);
	}
}

int climbStairs(int n)
{
	if(n <= 0)
	{
		return 0;
	}
	else if(n <= 2)
	{
	    return n;
	}
	int iReturn = 0;

	int f_n_1 = 1;
	int f_n_2 = 2;
	for(int i=3; i<=n; i++)
	{
		iReturn = f_n_1 + f_n_2;
		f_n_1 = f_n_2;
		f_n_2 = iReturn;
	}
	return iReturn;
}

/**
int main()
{
	double start = GetTickCount();
	int iRet = climbStairs(44);
	double end = GetTickCount();
    printf("\niRet=%d, cost=%lfms\n",iRet, end - start);

    start = GetTickCount();
    iRet = climbStairs2(44);
    end = GetTickCount();
    printf("\niRet=%d, cost=%lfms\n",iRet, end - start);
    return 0;
}
**/

