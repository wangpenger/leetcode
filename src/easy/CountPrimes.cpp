//============================================================================
// Name        : CountPrimes.cpp
// Author      : wp
// Version     :
// Copyright   : wp
// Description : Count the number of prime numbers less than a non-negative number, n.
// LeetCode No : 204
//============================================================================

#include <iostream>
#include <windows.h>

bool isPrime(int p)
{
	if(p > 0 && p <= 2)
	{
		return true;
	}
	for(int i=2; i*i<=p; i++)
	{
		if(p % i == 0)
		{
			return false;
		}
	}
	return true;
}

/**
//this method is correct but over time.
int countPrimes(int n)
{
	int iCount = 0;
	for(int i=2; i<n; i++)
	{
		if(isPrime(i))
		{
			++iCount;
			//printf("-[%d]-", i);
		}
    }
	//printf("found!!!\n");
	return iCount;
}
*/
//leetcode :56 ms
int countPrimes(int n)
{
	bool isPrimeArray[n];
	int iCount = 0;
	for(int i=0; i<n; i++)
	{
		isPrimeArray[i] = true;
	}

	for(int i=2; i*i<=n; i++)
	{
		if(isPrimeArray[i])
		{
			for(int j=i; i*j<=n; j++)
			{
				isPrimeArray[i*j] = false;
			}
		}
	}

	isPrimeArray[0] = false;
	isPrimeArray[1] = false;
	for(int i=0; i<n; i++)
	{
		if(isPrimeArray[i])
		{
			//printf("-[%d]-", i);
			++iCount;
		}
	}
	return iCount;
}


int main()
{
	double start = GetTickCount();
	countPrimes(150000);
	double end = GetTickCount();
    printf("\ncost=%lfms\n", end - start);

    return 0;
}

