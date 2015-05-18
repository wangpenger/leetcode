//============================================================================
// Author      : wp
// Version     :
// Copyright   : wp
// Description : get the max depth of the given binary tree.
//============================================================================

#include <iostream>
#include <string>


using namespace std;


struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

int maxDepth(TreeNode* root)
{
    if(NULL == root)
	{
    	return 0;
	}

    int l_d=maxDepth(root->left);
    int r_d=maxDepth(root->right);

    return l_d>r_d ? l_d+1 : r_d+1;
}

/**
int main()
{
	TreeNode root(1);
	TreeNode n_2left(2);
	TreeNode n_2right(3);
	TreeNode n_3left(4);
	TreeNode n_3right(5);
	TreeNode n_4right(6);

	root.left = &n_2left;
	root.right = &n_2right;
	n_2left.left = &n_3left;
	n_2left.right = &n_3right;
	n_3right.right = &n_4right;

	int i = maxDepth(&root);
	printf("i=%d\n", i);


	TreeNode root2(1);
	TreeNode root2_child_left(5);
	root2.left = &root2_child_left;

	int j = maxDepth(&root2);
	printf("j=%d\n", j);
}
*/

