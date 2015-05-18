//============================================================================
// Name        : StrStrImpl.cpp
// Author      : wp
// Version     :
// Copyright   : wp
// Description : simulate strStr.
//============================================================================

#include <iostream>
#include <string>
using namespace std;

//the method is correct but Time Limit Exceeded when i in loop
//0..iStrLen, but 0..iStrLen-iSubLen+1 is ok.
int strStr(string haystack, string needle)
{
	//if needle is empty, return 0 directly.
	if(needle.length() == 0)
	{
		return 0;
	}
	//if haystack is empty but needle is not empty, return 0 directly.
	if(haystack.length() == 0)
	{
		return -1;
	}
	int iStrLen = haystack.length();
	int iSubLen = needle.length();

	for(int i=0; i<iStrLen-iSubLen+1; i++)
	{
		int k = i;
		for(int j=0; j<=iSubLen; j++)
		{
			//if needle comes to the end.
			if(needle[j] == '\0')
			{
				return k - j;
			}
			//start to compare at the first same char.
			if((haystack[k] == needle[j]))
			{
				//if(haystack[i+iSubLen-1-j] == needle[iSubLen-1-j])
				{
					k++;
					continue;
				}
			}
			else
			{
				break;
			}
		}
	}
	return -1;
}

int main()
{
	//test case1
	string str = "0123456789";
	string strSub = "2345";
	printf("\"%s\" at \"%s\" is %d\n", strSub.c_str(), str.c_str(), strStr(str, strSub));

	//test case2
	str = "0123456789";
	strSub = "345";
	int iRet = strStr(str, strSub);
	printf("\"%s\" at \"%s\" is %d\n", strSub.c_str(), str.c_str(), iRet);

	//test case3
	str = "0123456789";
	strSub = "0";
	printf("\"%s\" at \"%s\" is %d\n", strSub.c_str(), str.c_str(), strStr(str, strSub));

	//test case4
	str = "0123456789";
	strSub = "9";
	printf("\"%s\" at \"%s\" is %d\n", strSub.c_str(), str.c_str(), strStr(str, strSub));

	//test case5
	str = "0123456789";
	strSub = "0123456789";
	printf("\"%s\" at \"%s\" is %d\n", strSub.c_str(), str.c_str(), strStr(str, strSub));

	//test case6
	str = "0123456789";
	strSub = "";
	printf("\"%s\" at \"%s\" is %d\n", strSub.c_str(), str.c_str(), strStr(str, strSub));

	//test case7
	str = "";
	strSub = "";
	printf("\"%s\" at \"%s\" is %d\n", strSub.c_str(), str.c_str(), strStr(str, strSub));

	//test case8
	str = "0123456789";
	strSub = "a";
	printf("\"%s\" at \"%s\" is %d\n", strSub.c_str(), str.c_str(), strStr(str, strSub));

	/**
	 *  Input:	"mississippi", "issip"
		Output:	-1
		Expected:	4
	 */
	//test case9
	string str2 = "mississippi";
	string strSub2 = "issip";
	printf("\"%s\" at \"%s\" is %d\n", strSub2.c_str(), str2.c_str(), strStr(str2, strSub2));

	str = "babba";
	strSub = "bbb";
	printf("\"%s\" at \"%s\" is %d\n", strSub.c_str(), str.c_str(), strStr(str, strSub));
}
