/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
link: https://leetcode.com/problems/path-sum-iii/

 */
#define data val
#define Node TreeNode

class Solution {
public:
    int count;
    void dfs(Node *root, int sum, int curr_sum)  {
        if(root == NULL)    return;
        curr_sum += root->data;

        if(curr_sum == sum) count++;
        dfs(root->left, sum, curr_sum);
        dfs(root->right, sum, curr_sum);
    }

    void inOrder(Node *root, int sum)    {
        if(root == NULL)    return;
        inOrder(root->left, sum);
        dfs(root, sum, 0);
        inOrder(root->right, sum);
    }

    int pathSum(TreeNode* root, int sum) {
        count = 0;
        inOrder(root, sum);
        return count;
    }
};
