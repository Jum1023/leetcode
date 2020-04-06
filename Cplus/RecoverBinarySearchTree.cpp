#include <algorithm>
#include <climits>
using namespace std;

//Definition for a binary tree node.
struct TreeNode
{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution
{
public:
	void recoverTree(TreeNode *root)
	{
		TreeNode *pre = new TreeNode(INT_MIN);
		TreeNode *node[2];
		int count = 0;
		inorder(root, node, count, pre);
		swap(node[0]->val, node[1]->val);
	}

	void inorder(TreeNode *root, TreeNode **node, int &count, TreeNode *&pre)
	{
		if (root == NULL || count >= 2)
			return;
		inorder(root->left, node, count, pre);
		if (pre->val > root->val)
		{
			if (count == 0)
			{
				node[0] = pre;
				node[1] = root;
			}
			else if (count == 1)
			{
				node[1] = root;
			}
			++count;
		}
		pre = root;
		inorder(root->right, node, count, pre);
	}
};