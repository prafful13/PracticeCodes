#include<iostream>
#include<stack>
#include<vector>
#include "BST.cpp"

class Solution  {
public:
  vector<Node *> inorder;
  void inOrderTraversal(Node *node) {
    if(node == NULL)  return;
    inOrderTraversal(node->left);
    inorder.push_back(node);
    inOrderTraversal(node->right);
  }

  vector<Node *> commonNodes(Node *root1, Node *root2)  {
    vector<Node *> res;
    inorder.clear();
    inOrderTraversal(root1);
    vector<Node *> inorder1 = inorder;
    inorder.clear();
    inOrderTraversal(root2);
    vector<Node *> inorder2 = inorder;

    vector<Node *>::iterator it1, it2;
    it1 = inorder1.begin();
    it2 = inorder2.begin();

    while(it1 != inorder1.end() && it2 != inorder2.end()) {
      if((*it1)->data == (*it2)->data)  {
        res.push_back(*it1);
        it1++;
        it2++;
      }
      else if((*it1)->data < (*it2)->data)  it1++;
      else it2++;
    }

    return res;
  }

  void printVector(vector<Node *> v)  {
    vector<Node*>::iterator it = v.begin();
    while(it!=v.end())  {
      cout<<(*it)->data<<" ";
      it++;
    }
    cout<<endl;
  }
};

int main()  {
  BST tree;
  Node *root1 = NULL, *root2 = NULL, *root3 = NULL;

  root1 = tree.insert(root1, 10);
  root1 = tree.insert(root1, 5);
  root1 = tree.insert(root1, 20);
  root1 = tree.insert(root1, 6);
  root1 = tree.insert(root1, 12);
  root1 = tree.insert(root1, 2);
  root1 = tree.insert(root1, 1);
  root1 = tree.insert(root1, 19);
  root1 = tree.insert(root1, 25);
  root1 = tree.insert(root1, 9);

  root2 = tree.insert(root2, 10);
  root2 = tree.insert(root2, 5);
  root2 = tree.insert(root2, 20);
  root2 = tree.insert(root2, 6);
  root2 = tree.insert(root2, 12);
  root2 = tree.insert(root2, 2);
  root2 = tree.insert(root2, 1);
  root2 = tree.insert(root2, 19);
  root2 = tree.insert(root2, 25);
  root2 = tree.insert(root2, 9);

  root3 = tree.insert(root3, 234);
  root3 = tree.insert(root3, 54);
  root3 = tree.insert(root3, 12);
  root3 = tree.insert(root3, 6342);
  root3 = tree.insert(root3, 25);
  root3 = tree.insert(root3, 2432);
  root3 = tree.insert(root3, 1);
  root3 = tree.insert(root3, 194);
  root3 = tree.insert(root3, 20);
  root3 = tree.insert(root3, 9);

  Solution sol;
  sol.printVector(sol.commonNodes(root1, root3));

  /*
  Output:
  1 9 12 20 25 
  */

  return 0;
}
