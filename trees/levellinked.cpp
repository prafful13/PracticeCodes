#include<iostream>
#include<queue>
#include<list>
#include "BST.cpp"

class Solution  {
public:
  list<list<Node*> > levelOrderLinked(Node *root) {
    queue<pair<Node *, int> > q;
    list<Node *> curr_list;
    list<list<Node *> > main_list;
    q.push(make_pair(root, 0));

    int level = 0;
    while(!q.empty()) {
      Node *curr = q.front().first;
      int curr_level = q.front().second;
      q.pop();
      if(level != curr_level) {
        main_list.push_back(curr_list);
        curr_list.clear();
        level++;
      }
      curr_list.push_back(curr);
      if(curr->left != NULL)  q.push(make_pair(curr->left, curr_level + 1));
      if(curr->right != NULL)  q.push(make_pair(curr->right, curr_level + 1));
    }
    main_list.push_back(curr_list);
    return main_list;
  }

  void print(list<list<Node*> > ll)  {
    list<list<Node*> >::iterator it = ll.begin();
    while (it != ll.end()) {
      list<Node*>::iterator i = (*it).begin();
      while (i != (*it).end())  {
        cout<<(*i)->data<<" ";
        i++;
      }
      cout<<endl;
      it++;
    }
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

  list<list<Node*> > result = sol.levelOrderLinked(root);

  sol.print(result);

  /*
  Output:
  10
  5 20
  2 6 12 25
  1 9 19
  */

  return 0;
}
