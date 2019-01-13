/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if(root == NULL)    return true;
        TreeNode *l, *r;
        l = new TreeNode(0);
        r = new TreeNode(0);
        if(root->left && root->right)
        if(root->left->val == root->right->val) {
            l->left = root->left->left;
            l->right = root->right->right;
            r->left = root->left->right;
            r->right = root->right->left;
            return isSymmetric(r) && isSymmetric(l);
        }
        if(root->left == NULL && root->right == NULL)   return true;
        return false;
    }
};
