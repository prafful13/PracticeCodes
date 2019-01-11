#include <bits/stdc++.h>

using namespace std;

// Link to problem statement: https://www.hackerrank.com/challenges/binary-search-tree-lowest-common-ancestor/problem

class Node {
    public:
        int data;
        Node *left;
        Node *right;
        Node(int d) {
            data = d;
            left = NULL;
            right = NULL;
        }
};

class Solution {
    public:
  		Node* insert(Node* root, int data) {
            if(root == NULL) {
                return new Node(data);
            } else {
                Node* cur;
                if(data <= root->data) {
                    cur = insert(root->left, data);
                    root->left = cur;
                } else {
                    cur = insert(root->right, data);
                    root->right = cur;
               }

               return root;
           }
        }

/*The tree node has data, left child and right child
class Node {
    int data;
    Node* left;
    Node* right;
};

*/
    Node *lca(Node *node, int a,int b) {
		// Write your code here.
        if(node->data < a && node->data < b )   {
            return lca(node->right, a, b);
        }
        else if(node->data > a && node->data > b)   {
            return lca(node->left, a, b);
        }
        else    return node;
    }

}; //End of Solution
