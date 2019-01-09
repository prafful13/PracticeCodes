using namespace std;

class Node  {
public:
  int data;
  Node *left;
  Node *right;

  Node(int x) {
    data = x;
    left = NULL;
    right = NULL;
  }
};
