//============================================================================
// Name        : ZigZag.cpp
// Author      : wp
// Version     :
// Copyright   : wp
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <string>
using namespace std;

string convert(string s, int numRows)
{
	if(numRows <= 1 || s.length() == 0)
	{
		return s;
	}
	string strRetn = "";
	int iStrLen = s.length();
	for(int i=0; i<iStrLen && i<numRows; i++)
	{
		int iIndex = i;
		strRetn += s[iIndex];
		for(int j=1; iIndex<iStrLen; j++)
		{
			if(i == 0 || i == numRows - 1)
			{
				iIndex += (2 * numRows) - 2;
			}
			else
			{
                if (j % 2 != 0)
                {
                	iIndex += 2 * (numRows - 1 - i);
                }
                else
				{
                	iIndex += 2 * i;
				}
			}
            if (iIndex < iStrLen)
            {
            	strRetn += s[iIndex];
            }
		}

	}
	return strRetn;
}

/*
int main()
{

	string str = "PAYPALISHIRING";
	string strRtn = convert(str, 3);
	printf("the result of convert is %s\n", strRtn.c_str());

	strRtn = convert("abcdefghijklmnopq", 5);

	printf("the result of convert is %s\n", strRtn.c_str());
	return 0;
}
*/
