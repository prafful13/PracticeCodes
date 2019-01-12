/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
link: https://leetcode.com/problems/kth-smallest-element-in-a-bst/

 */

#define Node TreeNode
#define data val
class Solution {
public:
    int element;
    int kth;
    int kthSmallest(TreeNode* root, int k) {
        kth = k;
        inOrder(root);
      return element;
    }
  void inOrder(Node *node) {
    if(node == NULL)  return;

    inOrder(node->left);
    kth--;
    if(kth==0)  {element = node->data; return;}
    inOrder(node->right);
  }
};
