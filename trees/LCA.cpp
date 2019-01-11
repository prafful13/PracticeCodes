#include<iostream>
#include<stack>
#include<queue>
#include<set>
#include "BST.cpp"

class Solution  {
public:
  vector<Node *> findPathFromRoot(Node *root, int a)  {
    vector<Node *> path;
    stack<Node *> stack, temp_stack;
    set<Node *> set;
    stack.push(root);
    while(!stack.empty()) {
      Node *curr = stack.top();
      if(curr->data == a) break;
      if(curr->left != NULL && set.find(curr->left) == set.end()) {
          stack.push(curr->left);
          set.insert(curr->left);
      }
      else if(curr->right != NULL && set.find(curr->right) == set.end()) {
          stack.push(curr->right);
          set.insert(curr->right);
      }
      else  {
        stack.pop();
      }
    }
    while(!stack.empty()) {
      temp_stack.push(stack.top());
      stack.pop();
    }
    while(!temp_stack.empty()) {
      path.push_back(temp_stack.top());
      temp_stack.pop();
    }
    return path;
  }

  void printPath(vector<Node *> v)  {
    vector<Node *>::iterator it;
    it = v.begin();
    while(it != v.end())  {
      cout<<(*it)->data<<" ";
      it++;
    }
    cout<<endl;
  }

  Node* LCA(Node* root, int a, int b) {
    vector<Node *> path_a, path_b;
    path_a = findPathFromRoot(root, a);
    path_b = findPathFromRoot(root, b);

    if(path_a.empty()) {
      cout<<a<<" not found\n";
      return NULL;
    }
    else if(path_b.empty())  {
      cout<<b<<" not found\n";
      return NULL;
    }

    vector<Node *>::iterator it1, it2;
    it1 = path_a.begin();
    it2 = path_b.begin();

    // printPath(path_a);
    // printPath(path_b);

    Node *curr = *it1;
    while(*it1 == *it2) {
      curr = *it1;
      it1++;
      it2++;
    }

    return curr;
  }

};

int main()  {
  BST tree;
  Node *root = NULL;

  root = tree.insert(root, 10);
  root = tree.insert(root, 5);
  root = tree.insert(root, 20);
  root = tree.insert(root, 6);
  root = tree.insert(root, 12);
  root = tree.insert(root, 2);
  root = tree.insert(root, 1);
  root = tree.insert(root, 19);
  root = tree.insert(root, 25);
  root = tree.insert(root, 9);

  Solution sol;

  Node *lca = sol.LCA(root, 1,25);
  if(lca != NULL) cout<<lca->data<<endl;

  /*
  Output:
  10
  */

  return 0;
}
