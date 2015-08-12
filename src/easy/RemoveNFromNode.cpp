//============================================================================
// Name        : RemoveNFromNode.cpp
// Author      : wp
// Version     :
// Copyright   : wp
// Description : Remove Nth Node From End of List.
// LeetCode No : 19
//============================================================================

#include <iostream>
#include <string>
using namespace std;


//Definition for singly-linked list.
struct ListNode
{
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

ListNode* removeNthFromEnd(ListNode* head, int n)
{
	ListNode* nodeHead = head;

	int iLen = 0;
	while(nodeHead != NULL)
	{
		++iLen;
		nodeHead = nodeHead->next;
	}

	ListNode* nodeInitHead = head;
	if(n == iLen)
	{
		return nodeInitHead->next;
	}

	int index = 0;
	while(nodeInitHead != NULL)
	{
		++index;
		if(index == iLen - n)
		{
			nodeInitHead->next = nodeInitHead->next->next;
			return head;
		}
		nodeInitHead = nodeInitHead->next;
	}
	return head;
}

int main()
{
	ListNode n6(10);
	ListNode n7(3);
	ListNode n8(45);
	ListNode n9(1);
	ListNode n10(38);
	ListNode n11(89);

	n6.next = &n7;
	n7.next = &n8;
	n8.next = &n9;
	n9.next = &n10;
	n10.next = &n11;

	ListNode* n = NULL;
	n = &n6;
	while(n)
	{
		printf("%d->", n->val);
		n = n->next;
	}
	printf("\n");
	n = removeNthFromEnd(&n6, 1);

	while(n)
	{
		printf("%d->", n->val);
		n = n->next;
	}
    return 0;
}
