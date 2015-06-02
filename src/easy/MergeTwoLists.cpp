//============================================================================
// Name        : MergeTwoLists.cpp
// Author      : wp
// Version     :
// Copyright   : wp
// Description : Merge two sorted linked lists and return it as a new list.
//============================================================================

#include <iostream>

//Definition for singly-linked list.
struct ListNode
{
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

ListNode* mergeTwoLists(ListNode* l1, ListNode* l2)
{
	if(!l1)
	{
		return l2;
	}
	if(!l2)
	{
		return l1;
	}

	ListNode* tmp = (l1->val > l2->val) ? l2:l1;
	ListNode* header = tmp;

	while(l1)
	{
		while(l2)
		{
			if(tmp == l2)
			{
				l2 = l2->next;
			}
			else
			{
				l1 = l1->next;
			}

            if(l1 == NULL)
            {
                tmp->next = l2;
                return header;
            }

            else if(l2 == NULL)
            {
                tmp->next = l1;
                return header;
            }

            tmp->next = (l1->val > l2->val) ? l2 : l1;
            tmp = tmp->next;
		}
	}

	return header;
}

/**
int main()
{
	ListNode n6(2);
	ListNode n7(3);
	ListNode n8(5);
	ListNode n9(10);
	ListNode n10(12);
	ListNode n11(100);

	n6.next = &n7;
	n7.next = &n8;
	n8.next = &n9;
	n9.next = &n10;
	n10.next = &n11;

	ListNode n16(1);
	ListNode n17(6);
	ListNode n18(13);
	ListNode n19(22);

	n16.next = &n17;
	n17.next = &n18;
	n18.next = &n19;

	printf("***********n6*********\n");
	ListNode *node = &n6;
	while(node)
	{
		printf("%d->", node->val);
		node = node->next;
	}
	printf("\n***********n6*********\n");

	node = mergeTwoLists(&n6, &n16);

	printf("\n********************\n");
	while(node)
	{
		printf("%d->", node->val);
		node = node->next;
	}

}
*/
