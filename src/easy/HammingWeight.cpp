//============================================================================
// Name        : HammingWeight.cpp
// Author      : wp
// Version     :
// Copyright   : wp
// Description : takes an unsigned integer and returns the number of ¡¯1' bits it has
//				 (also known as the Hamming weight).
//============================================================================

//from leetcode friends:
//return (n%2?1:0)+(n==0?0:hammingWeight(n/2));

/**
 * int hammingWeight(uint32_t n) {
    int map[] = {0, 1,  1, 2,   1, 2, 2, 3,   1, 2, 2, 3, 2, 3, 3, 4};
    register int count = 0;
    register uint32_t a = n;
    while (a > 0) {
        count += map[0xf & a];
        a >>= 4;
    }
    return count;
}
 */

#include <iostream>
#include <string>


using namespace std;


int hammingWeight(unsigned int n)
{
	unsigned int iOneBitCount = 0;
	do
	{
		unsigned int tmp = n % 2;
		n = n / 2;
		if(tmp)
		{
			++iOneBitCount;
		}
	} while(n);
	return iOneBitCount;
}


int main()
{
	for(int i=1; i<32; i++)
	{
		int iRet = hammingWeight(i);
		printf("test: input=%d, 1 bit count = %d\n", i, iRet);
	}
}
