//============================================================================
// Name        : DeleteNodeInList.cpp
// Author      : wp
// Version     :
// Copyright   : wp
// Description : Supposed the linked list is 1 -> 2 -> 3 -> 4 and you are given the third node with value 3,
// 				 the linked list should become 1 -> 2 -> 4 after calling your function.
// LeetCode No : 237
//============================================================================

#include <iostream>
#include <queue>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};


/**
 * error when input node is the first node
void deleteNode(ListNode* node)
{
	while(node->next)
	{
		node->val = node->next->val;
		node = node->next;

		if(node->next->next == NULL)
		{
			node->next = NULL;
		}
	}
}
**/

void deleteNode(ListNode* node)
{
	*node = *(node->next);
}


int main()
{
	//case1
	ListNode n6(10);
	ListNode n7(3);
	ListNode n8(45);
	ListNode n9(1);
	ListNode n10(38);
	ListNode n11(89);

	n6.next = &n7;
//	n7.next = &n8;
//	n8.next = &n9;
//	n9.next = &n10;
//	n10.next = &n11;

	deleteNode(&n6);

	ListNode* n = NULL;
	n = &n6;
	while(n)
	{
		printf("%d->", n->val);
		n = n->next;
	}
	printf("\n");

	//case2 is not support for this topic.
//	ListNode n21(50);
//	n = &n21;
//	deleteNode(&n21);
//	while(n)
//	{
//		printf("%d->", n->val);
//		n = n->next;
//	}
//	printf("\n");


}
