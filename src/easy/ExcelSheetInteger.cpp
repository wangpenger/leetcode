//============================================================================
// Name        : ExcelSheetInteger.cpp
// Author      : wp
// Version     :
// Copyright   : wp
// Description : Given a positive integer, return its corresponding column title as appear in an Excel sheet.
//============================================================================

#include <iostream>
#include <vector>
#include <cmath>
using namespace std;


string convertToTitle(int n)
{
   string str;
   while (n) {
	   str = char((--n)%26 + 'A') + str;
	   n /= 26;
   }
   return str;
}

/**
int main()
{
	//test case1
	int n[] = {1,2,3,4,5,6,7,8,9,0,26,27,28,702};
	for(int i=0; i<sizeof(n) / sizeof(n[0]); i++)
	{
		printf("convertToTitle(%d)=%s\n",n[i], convertToTitle(n[i]).c_str());
	}

	printf("convertToTitle(%d)=%s\n",53, convertToTitle(53).c_str());

	printf("convertToTitle(%d)=%s\n",52, convertToTitle(52).c_str());

	printf("convertToTitle(%d)=%s\n",703, convertToTitle(703).c_str());

	printf("convertToTitle(%d)=%s\n",1379, convertToTitle(1379).c_str());

	printf("convertToTitle(%d)=%s\n",1378, convertToTitle(1378).c_str());
}
*/
