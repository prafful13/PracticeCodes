/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
link: https://leetcode.com/problems/binary-tree-right-side-view/

 */
#define Node TreeNode
#define data val
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> res;
        int max = -1;
        rightView(root, 0, max, res);
        return res;
    }

    void rightView(Node *root, int curr, int& max, vector<int>& res)  {
      if(root == NULL)  return;
      if(curr>max) {
        // cout<<root->data<<" ";
        res.push_back(root->data);
        max = curr;
      }
      rightView(root->right, curr + 1, max, res);
      rightView(root->left, curr + 1, max, res);
    }
};
