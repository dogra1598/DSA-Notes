#include <iostream>
#include <queue>
using namespace std;

// Node Class
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

/*
    Insertion code for a new node
    (insertion is done as level order)
    TC: O(n), n = no. of nodes
*/
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

/*
    Inorder Traversal of binary tree
    { LEFT, ROOT, RIGHT }
    TC: O(n), n = no. of nodes
*/
void inorderTraversal(TreeNode* root) {
    if (!root)
        return;

    inorderTraversal(root->left);
    cout << root->data << " ";
    inorderTraversal(root->right);
}

/*
    Preorder Traversal of a binary tree
    { ROOT, LEFT, RIGHT }
    TC: O(n), n = no. of nodes
*/
void preorderTraversal(TreeNode* root) {
    if (!root)
        return;

    cout << root->data << " ";
    preorderTraversal(root->left);
    preorderTraversal(root->right);
}

/*
    Postorder Traversal of a binary tree
    { LEFT, RIGHT, ROOT }
    TC: O(n), n = no. of nodes
*/
void postorderTraversal(TreeNode* root) {
    if (!root)
        return;

    postorderTraversal(root->left);
    postorderTraversal(root->right);
    cout << root->data << " ";
}

/*
    Level Order Traversal
    { maintain a queue }
    TC: O(n), n = no. of nodes

    ** Note see elements accoring to level
       1. push null pointer after root
       2. then check if cuurNode in queue is null pointer print new line
            -- if queue is not empty then push null pointer into queue
    ** the logic can also be used where we need to store levels separately
*/
void levelOrderTraversal(TreeNode* root) {
    if (!root)
        return;

    queue<TreeNode*> q;
    q.push(root);
    q.push(nullptr);
    while (!q.empty()) {
        TreeNode* currNode = q.front();
        q.pop();

        if (!currNode) {
            cout << "\n";
            if (!q.empty()) q.push(nullptr);
        } else {
            cout << currNode->data << " ";
            if (currNode->left) q.push(currNode->left);
            if (currNode->right) q.push(currNode->right);
        }
    }
}

int main() {
    TreeNode* root = nullptr;

    insertNode(root, 1);
    insertNode(root, 2);
    insertNode(root, 3);
    insertNode(root, 4);
    insertNode(root, 5);
    insertNode(root, 6);

    cout << "Inorder Traversal: ";
    inorderTraversal(root);
    cout << "\n";

    cout << "Preorder Traversal: ";
    preorderTraversal(root);
    cout << "\n";

    cout << "Postorder Traversal: ";
    postorderTraversal(root);
    cout << "\n";

    cout << "Levelorder Traversal:\n";
    levelOrderTraversal(root);
    cout << "\n";

    return 0;
}