#include <iostream>
#include <queue>
using namespace std;

class TreeNode {
 public:
  int data;
  TreeNode* left;
  TreeNode* right;

  TreeNode(int data) {
    this->data = data;
    this->left = nullptr;
    this->right = nullptr;
  }
};

void insertNode(TreeNode*& root, int data) {
  TreeNode* newNode = new TreeNode(data);
  if (!newNode) {
    cout << "Memory Error\n";
    return;
  }

  if (!root) {
    root = newNode;
    return;
  }

  queue<TreeNode*> q;
  q.push(root);
  while (!q.empty()) {
    TreeNode* currNode = q.front();
    q.pop();

    if (!currNode->left) {
      currNode->left = newNode;
      return;
    } else {
      q.push(currNode->left);
    }

    if (!currNode->right) {
      currNode->right = newNode;
      return;
    } else {
      q.push(currNode->right);
    }
  }
}

// Building tree recursive
TreeNode* buildTree(TreeNode* root) {
  cout << "Enter data: ";
  int data;
  cin >> data;
  root = new TreeNode(data);

  if (data == -1) return nullptr;

  cout << "To insert data in left of " << data << " ";
  root->left = buildTree(root->left);
  cout << "To insert data in right of " << data << " ";
  root->right = buildTree(root->right);

  return root;
}