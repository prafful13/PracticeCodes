#include<iostream>
#include<stack>
#include<queue>
// #include<pair>
#include "BST.cpp"

class Traversals {
    public:
    void inOrder(Node *root) {
      if(root == NULL)  return;
      inOrder(root->left);
      cout<<root->data<<" ";
      inOrder(root->right);
    }

    void preOrder(Node *root) {
      if(root == NULL)  return;
      cout<<root->data<<" ";
      preOrder(root->left);
      preOrder(root->right);
    }

    void postOrder(Node *root)  {
      if(root == NULL)  return;
      postOrder(root->left);
      postOrder(root->right);
      cout<<root->data<<" ";
    }

    void inOrderWithoutRecursion(Node *root)  {
      stack<Node *> stack;
      Node *curr = root;
      while(curr!=NULL || stack.empty() == false) {
        while(curr != NULL) {
          stack.push(curr);
          curr = curr->left;
        }
        curr = stack.top();
        stack.pop();

        cout<<curr->data<<" ";
        curr = curr->right;
      }
    }

    void preOrderWithoutRecursion(Node *root) {
      stack<Node *> stack;
      Node *curr = root;
      while(curr!=NULL || stack.empty() == false) {
        while(curr != NULL) {
          stack.push(curr);
          cout<<curr->data<<" ";
          curr = curr->left;
        }
        curr = stack.top();
        stack.pop();

        curr = curr->right;
      }
    }

    void postOrderWithoutRecursion(Node *root) {
      stack<Node *> stack1, stack2;
      stack1.push(root);
      while(!stack1.empty())  {
        Node *curr = stack1.top();
        stack1.pop();
        stack2.push(curr);
        if(curr->left != NULL)  stack1.push(curr->left);
        if(curr->right != NULL)  stack1.push(curr->right);
      }
      while(!stack2.empty())  {
        Node *curr = stack2.top();
        stack2.pop();
        cout<<curr->data<<" ";
      }
    }

    void levelOrder(Node *root) {
      queue<pair<Node *, int> > q;
      q.push(make_pair(root, 0));
      int level = 0;
      while(!q.empty()) {
        Node *curr = q.front().first;
        int curr_level = q.front().second;
        q.pop();
        if(level != curr_level) {
          level++;
          cout<<endl;
        }
        cout<<curr->data<<" ";
        if(curr->left != NULL)  q.push(make_pair(curr->left, curr_level + 1));
        if(curr->right != NULL)  q.push(make_pair(curr->right, curr_level + 1));
      }
    }
};
// 
// int main()  {
//   BST tree;
//   Node *root = NULL;
//
//   root = tree.insert(root, 10);
//   root = tree.insert(root, 5);
//   root = tree.insert(root, 20);
//   root = tree.insert(root, 6);
//   root = tree.insert(root, 12);
//   root = tree.insert(root, 2);
//   root = tree.insert(root, 1);
//   root = tree.insert(root, 19);
//   root = tree.insert(root, 25);
//   root = tree.insert(root, 9);
//
//   Traversals logic;
//   logic.inOrder(root);
//   cout<<endl;
//   logic.preOrder(root);
//   cout<<endl;
//   logic.postOrder(root);
//   cout<<endl;
//   logic.inOrderWithoutRecursion(root);
//   cout<<endl;
//   logic.preOrderWithoutRecursion(root);
//   cout<<endl;
//   logic.postOrderWithoutRecursion(root);
//   cout<<endl;
//   logic.levelOrder(root);
//   cout<<endl;
//
//   /*
//   Output:
//   1 2 5 6 9 10 12 19 20 25
//   10 5 2 1 6 9 20 12 19 25
//   1 2 9 6 5 19 12 25 20 10
//   1 2 5 6 9 10 12 19 20 25
//   10 5 2 1 6 9 20 12 19 25
//   1 2 9 6 5 19 12 25 20 10
//   10
//   5 20
//   2 6 12 25
//   1 9 19
//   */
//
//   return 0;
// }
