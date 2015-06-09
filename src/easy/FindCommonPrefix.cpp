//============================================================================
// Name        : FindCommonPrefix.cpp
// Author      : wp
// Version     :
// Copyright   : wp
// Description : to find the longest common prefix string amongst an array of strings.
// LeetCode No : 14
//============================================================================

#include <iostream>
#include <vector>
using namespace std;

/**
 *4ms
 *      string longestCommonPrefix(vector<string>& strs)
        {
         if(strs.empty())return "";
         if(strs.size()==1)return strs[0];
        for(int i=0;i<strs.size();i++)
        {
            if(strs[i].length()==0||strs[i][0]!=strs[0][0])
            return "";
        }
        //now it be common
       string result="";
       for(int i=0;i<strs[0].length();i++)
       {
           for(int j=0;j<strs.size();j++)
           {
               if(strs[j][i]!=strs[0][i])
               {
                   return result;
               }
           }
          result+=strs[0][i];
       }
       return result;
        }
    };
 *
 */

//leetcode : 9ms
string longestCommonPrefix(vector<string>& strs)
{
	if(strs.size() == 0)
	{
		return "";
	}
	string tempStr = strs[0];
	for(int i=0; i<(int)strs.size();)
	{
		if(string::npos == strs[i].find(tempStr) || 0 != strs[i].find(tempStr))
		{
			tempStr = tempStr.substr(0, tempStr.length() - 1);
			i = 1;
			continue;
		}
		if(i == (int)strs.size() - 1)
		{
			return tempStr;
		}
		i++;
	}
	return "";
}

int main()
{
	vector<string> strs;
	strs.push_back("abc123");
	strs.push_back("abc1234");
	strs.push_back("abc1236");
	strs.push_back("abc123fdfg");
	strs.push_back("abc123fdfg");

	printf("longestCommonPrefix()=%s\n", longestCommonPrefix(strs).c_str());


	strs.clear();
	printf("longestCommonPrefix().length=%d\n", (int)longestCommonPrefix(strs).length());

	strs.push_back("a");
	printf("longestCommonPrefix()=%s\n", longestCommonPrefix(strs).c_str());

	strs.clear();
	strs.push_back("a");
	strs.push_back("aa");
	printf("longestCommonPrefix()=%s\n", longestCommonPrefix(strs).c_str());
}
