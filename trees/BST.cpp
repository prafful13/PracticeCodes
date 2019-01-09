#include "Node.cpp"

class BST {
public:
  Node* insert(Node *root, int new_data)  {
    if(root == NULL)  return new Node(new_data);
    else  {
      if(new_data <= root->data)  root->left = insert(root->left, new_data);
      else root->right = insert(root->right, new_data);
    }
    return root;
  }
};
