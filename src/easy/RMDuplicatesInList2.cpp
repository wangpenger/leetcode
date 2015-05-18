//============================================================================
// Name        : RMDuplicatesInList2.cpp
// Author      : wp
// Version     :
// Copyright   : wp
// Description : Hello World in C++, Ansi-style
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

//for sorted list
ListNode* deleteDuplicates(ListNode* head)
{
	//only one element or no elements.
	if(!head)
	{
		return head;
	}
	if(!(head->next))
	{
		return new ListNode(head->val);
	}
	ListNode *p = new ListNode(head->val);
	ListNode *p_ret = p;

	while((head = head->next))
	{
		if(head->val != p->val)
		{
			ListNode *p_node = new ListNode(head->val);
			p->next = p_node;
			p = p->next;
		}
	}
	return p_ret;
}

ListNode* deleteDuplicates_mothod2(ListNode* head)
{
	//only one element or no elements.
	if(!head)
	{
		return head;
	}
	if(!(head->next))
	{
		return head;
	}
	ListNode *p_ret = head;

	while(head->next)
	{
		if(head->val == head->next->val)
		{
			head->next = head->next->next;
			continue;
		}
		head = head->next;
	}
	return p_ret;
}

void test(ListNode* header)
{
	printf("¡¾input¡¿ :		");
	ListNode* head = header;
	while(head)
	{
		printf("%d->", head->val);
		head = head->next;
	}
	printf("****************");

	//ListNode* newNode = deleteDuplicates(header);
	ListNode* newNode = deleteDuplicates_mothod2(header);

	printf("¡¾output¡¿ :		");
	while(newNode)
	{
		printf("%d->", newNode->val);
		newNode = newNode->next;
	}
	printf("\n");

	while(newNode)
	{
		delete newNode;
		newNode = newNode->next;
	}
}

/**

int main()
{
	ListNode *n1 = new ListNode(1);
	ListNode *n2 = new ListNode(1);
	ListNode *n3 = new ListNode(2);
	ListNode *n4 = new ListNode(2);

	n1->next = n2;
	n2->next = n3;
	n3->next = n4;

	test(n1);
	ListNode n5(1);
	test(&n5);

	ListNode n6(1);
	ListNode n7(1);
	ListNode n8(2);
	ListNode n9(2);
	ListNode n10(3);
	ListNode n11(3);

	n6.next = &n7;
	n7.next = &n8;
	n8.next = &n9;
	n9.next = &n10;
	n10.next = &n11;

	test(&n6);

	test(NULL);

	ListNode n12(1);
	ListNode n13(2);
	n12.next = &n13;

	test(&n12);

}

*/
