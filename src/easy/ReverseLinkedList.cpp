//============================================================================
// Name        : ReverseLinkedList.cpp
// Author      : wp
// Version     :
// Copyright   : wp
// Description : Reverse a singly linked list.
// LeetCode No : 206
//============================================================================

#include <iostream>


// Definition for singly-linked list.
struct ListNode
{
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};
/**
 * c solution from leetcode's
 * struct ListNode* reverseList(struct ListNode* head)
{
        struct ListNode* last = 0;

        while (head)
        {
            struct ListNode* next = head->next;
            head->next = last;
            last = head;
            head = next;
        };

        return last;
}

ListNode* reverseList_iterative(ListNode *head)
{
	  ListNode *pre = nullptr, *next = nullptr;
	  while (head)
	  {
			next = head->next;      //save the current's next node
			head->next = pre;       //let the current point to its previous one
			pre = head;             //save the current node as pre
			head = next;            //move to next node
	  }
	  return pre;                   //just point to the last node we wanted
}
 *
 *
 */

ListNode* reverseList(ListNode* head)
{
	if(!head || !head->next)
	{
		return head;
	}

	//set the first node.
	ListNode* node = head;

	//reverse the first two nodes.
	head = head->next;
	ListNode* q = head->next;
	head->next = node;
	node->next = NULL;	//very important, and forgettable.

	while(q)
	{
		ListNode* temp = q->next;
		q->next = head;
		head = q;
		q = temp;
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

	ListNode* n = reverseList(&n6);

	while(n)
	{
		printf("%d->", n->val);
		n = n->next;
	}
    return 0;
}

