#include <iostream>
#include "BinaryTree.h"
using namespace std;

/**
 * target function
 * global state: max_sum at that node including max_left + max_right
 * return: max branch = max(left_branch, right_branch)
*/
int Solution::dfs_sum(TreeNode *currentNode, int &maxSum)
{
    // base case
    if (!currentNode) return 0;
    int max_left = max(0,dfs_sum(currentNode->left, maxSum));
    int max_right = max(0,dfs_sum(currentNode->right, maxSum));
    int max_current = max_left + currentNode->val + max_right;

    cout<< "Max_Left:" << max_left << endl;
    cout<< "Max_Right:" << max_right<< endl;
    cout<< "Found conjuntion Node - max_current:"<< max_current << endl;
    maxSum = max(maxSum, max_current);
    return max(max_left + currentNode->val, max_right + currentNode->val);
}

/**
 * target method
*/
int Solution::maxPathSum(TreeNode *root)
{
    int maxSum = root->val;
    dfs_sum(root, maxSum);
    return maxSum;
}
