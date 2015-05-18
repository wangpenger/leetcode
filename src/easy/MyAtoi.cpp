//============================================================================
// Name        : MyAtoi.cpp
// Author      : wp
// Version     :
// Copyright   : wp
// Description : simulate function atoi.
	/**
	from web.
	int res =0;
	const char *p = str.c_str();
	bool negflag = false;
	while(*p==' ' || *p == '\t')
		p++;
	if('+' == *p || '-' == *p)
		negflag =(*p++ == '-');
	while(isdigit(*p))
		res = res*10 +  (*p++-'0');

	return negflag?(0-res):res;
	*/
//============================================================================

#include <iostream>
#include <string>
#include <stdlib.h>
#include <cmath>

using namespace std;

int myAtoi(string str)
{
	const static unsigned int MAX_LENGTH = 10;
	const static string MAX_NUM_STRING = "2147483647";
	const static string MIN_NUM_STRING = "2147483648";
	string strRetn = str;
	int iRetNum = 0;

	//remove the whitespace and 0 at the header.
	while((strRetn[0] == ' ' || strRetn[0] == '0') && strRetn.length() != 0)
	{
		strRetn = strRetn.substr(1);
	}

	//remove the whitespace at the tail.
	int iStrLen = strRetn.length();
	while(strRetn[iStrLen - 1] == ' ' && iStrLen != 0)
	{
		strRetn = strRetn.substr(0, iStrLen - 1);
		iStrLen = strRetn.length();
	}

	//identify the negative.
	bool bNegative = false;
	if(strRetn[0] == '-')
	{
		bNegative = true;
		strRetn = strRetn.substr(1);
	}
	else if(strRetn[0] == '+')
	{
		bNegative = false;
		strRetn = strRetn.substr(1);
	}

	//substr to the first whitespace.
	if(string::npos != strRetn.find(" "))
	{
		strRetn = strRetn.substr(0, strRetn.find(" "));
	}

	//if non-numeric exists, substr directly.
	for(unsigned int i=0; i<iStrLen; i++)
	{
		if(!(strRetn[i] >= '0' && strRetn[i] <= '9'))
		{
			strRetn = strRetn.substr(0, i);
		}
	}

	//get latest length of the string(only contains digits).
	iStrLen = strRetn.length();
	bool bOverRange = true;
	if(iStrLen > MAX_LENGTH)
	{
		return bNegative ? INT_MIN : INT_MAX;
	}
	else if(iStrLen == MAX_LENGTH)
	{
		string strCompare = bNegative ? MIN_NUM_STRING : MAX_NUM_STRING;
		bOverRange = strRetn.compare(strCompare) > 0;
		if(bOverRange)
		{
			return bNegative ? INT_MIN : INT_MAX;
		}
	}

	for(unsigned int i=0; i<iStrLen; i++)
	{
		iRetNum += (strRetn[i]  - '0') * pow(10, iStrLen-i-1);
	}

	return bNegative ? -iRetNum : iRetNum;

}
void test(string str)
{
	int i = atoi(str.c_str());
	int j = myAtoi(str);
	printf("¡¾¡¾¡¾¡¾¡¾compare=%d¡¿¡¿¡¿¡¿¡¿¡¿str=%s,atoi=%d,myAtoi=%d\n", i==j,str.c_str(), i, j);
}

/**
int main()
{
	test("123234545");
	test("sdfsdfd");
	test("213124243324324");
	test("1233");
	test("    2343");
	test("213124   24332  4324");
	test("-1213124");
	test("-12");
	test("-122342343434");

	test("2147483647");
	test("-2147483648");

	//the first submit,this case failed,
	//passed:199/1045
	//expected:-12, but:0
	test("  -0012a42");

	//the second submit,this case failed,
	//passed:970/1045
	//Output:	2147483647
	//Expected:	1095502006
	test("1095502006p8");
	test("-1095502006p8");

	//the third submit,this case failed,
	//1044/1045
	//Input:	"2147483648"
	//Output:	-2147483648
	//Expected:	2147483647
	test("2147483648");

	return 0;
}
*/
