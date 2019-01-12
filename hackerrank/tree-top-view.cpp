#include<bits/stdc++.h>

//  link: https://www.hackerrank.com/challenges/tree-top-view/problem

using namespace std;

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

/*
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

*/

    void topView(Node * root) {
      queue<pair<Node *, int>> q;
      map<int, Node *> m;
      q.push(make_pair(root, 0));
      int l, r;
      l = r = 0;
      m[0] = root;
      while (!q.empty()) {
        Node *curr = q.front().first;
        int curr_dist = q.front().second;
        q.pop();
        if (curr_dist < l) {
          m[curr_dist] = curr;
          l = curr_dist;
        }
        if (curr_dist > r) {
          m[curr_dist] = curr;
          r = curr_dist;
        }
        if (curr->left != NULL)
          q.push(make_pair(curr->left, curr_dist - 1));
        if (curr->right != NULL)
          q.push(make_pair(curr->right, curr_dist + 1));
      }
      while (l <= r) {
        cout << m[l++]->data << " ";
      }
    }

}; //End of Solution
