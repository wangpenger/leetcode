//============================================================================
// Name        : SameTree.cpp
// Author      : wp
// Version     :
// Copyright   : wp
// Description : Given two binary trees, write a function to check if they are equal or not.
// LeetCode No : 100
//============================================================================

#include <iostream>

//Definition for a binary tree node.
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

//leetcode :Runtime: 0 ms
bool isSameTree(TreeNode* p, TreeNode* q)
{
	if(!p && !q)
	{
		return true;
	}
	else if(!p)
	{
		return false;
	}
	else if(!q)
	{
		return false;
	}
	if(p->val != q->val)
	{
		return false;
	}
	return isSameTree(p->right, q->right) && isSameTree(p->left, q->left);
}

//Time Limit Exceeded
/**
bool isSameTree(TreeNode* p, TreeNode* q)
{
	TreeNode* r = p;
	TreeNode* s = q;

	//get the first node.
	while(p)
	{
		if(p->left)
		{
			p = p->left;
		}
	}
	while(q)
	{
		if(q->left)
		{
			q = q->left;
		}
	}

	//get the last node.
	while(r)
	{
		if(r->right)
		{
			r = r->right;
		}
	}
	while(s)
	{
		if(s->right)
		{
			s = s->right;
		}
	}

	while(p && q)
	{
		if(p->val != q->val || r->val != s->val)
		{
			return false;
		}
		if(p == r && q == s)
		{
			return true;
		}
		else if(p->right == r && q->right == s)
		{
			return true;
		}
		else
		{
			p = p->right;
			q = q->right;

			r = r->left;
			s = s->left;
		}
	}
	return false;
}
*/

//Time Limit Exceeded
/**
bool isSameTree(TreeNode* p, TreeNode* q)
{
	while(p)
	{
		if(p->left)
		{
			p = p->left;
		}
	}
	while(q)
	{
		if(q->left)
		{
			q = q->left;
		}
	}

	while(p && q)
	{
		if(p->val != q->val)
		{
			return false;
		}
		else
		{
			p = p->right;
			q = q->right;
		}
	}
	return !p && !q;
}
*/
