/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
#define Node TreeNode
#define data val
class Solution {
public:
    Node* insertFromTo(int a, int b, vector<int>& nums) {
        // cout<<a<<" "<<b<<endl;
        if(a>b) return NULL;
        Node *root = new Node(nums[(b+a)/2]);
        root->left = insertFromTo(a,(b+a)/2-1, nums);
        root->right = insertFromTo((b+a)/2+1, b, nums);
        return root;
    }

    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int s = nums.size();
        Node *root;
        root = insertFromTo(0,s-1,nums);
        return root;
    }
};
