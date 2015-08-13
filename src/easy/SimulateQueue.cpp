//============================================================================
// Name        : SimulateQueue.cpp
// Author      : wp
// Version     :
// Copyright   : wp
// Description : Implement Queue using Stacks. learned by leetcode friend.
// LeetCode No : 225
//============================================================================

#include <iostream>
#include <queue>
using namespace std;


class Stack {
public:
	queue<int> que;

    // Push element x onto stack.
    void push(int x) {
    	que.push(x);
    	for(int i=0; i<que.size()-1; ++i)
    	{
    		que.push(que.front());
    		que.pop();
    	}
    }

    // Removes the element on top of the stack.
    void pop() {
    	return que.pop();
    }

    // Get the top element.
    int top() {
    	return que.front();
    }

    // Return whether the stack is empty.
    bool empty() {
    	return que.empty();
    }
};

/**
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
**/
