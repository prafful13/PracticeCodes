/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };

link : https://leetcode.com/problems/binary-tree-paths/

 */
#define data val
#define Node TreeNode
class Solution {
public:

      list<list<Node *> > pathToLeaf(Node *root)  {

    stack<Node *> stack;
    list<list<Node *> > res;
    list<Node *> curr_path;
    set<Node *> set;
          if(root == NULL)  return res;
    stack.push(root);
    curr_path.push_back(root);
    while(!stack.empty()) {
      Node *curr = stack.top();
      if(curr->left != NULL && set.find(curr->left) == set.end()) {
        stack.push(curr->left);
        curr_path.push_back(curr->left);
        set.insert(curr->left);
      }
      else if(curr->right != NULL && set.find(curr->right) == set.end()) {
        stack.push(curr->right);
        curr_path.push_back(curr->right);
        set.insert(curr->right);
      }
      else  if(curr->left == NULL && curr->right == NULL) {
        res.push_back(curr_path);
        curr_path.pop_back();
        stack.pop();
      }
      else  {
        curr_path.pop_back();
        stack.pop();
      }
    }
    return res;
  }


    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> res;
        list<list<Node *> > paths = pathToLeaf(root);

        list<list<Node *> >::iterator it = paths.begin();
        while(it != paths.end())    {
            string s = "";
            list<Node *>::iterator i = (*it).begin();
            while(i != (*it).end()) {
                s = s + to_string((*i)->data);
                i++;
                if( i != (*it).end())    s = s + "->";
            }
            res.push_back(s);
            it++;
        }
        return res;
    }
};
