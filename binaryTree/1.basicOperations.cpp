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
    if(!newNode) {
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
    Deletion code for a node
    
*/

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
*/
void levelOrderTraversal(TreeNode* root) {
    if(!root)
        return;

    queue<TreeNode*> q;
    q.push(root);
    while(!q.empty()) {
        TreeNode* currNode = q.front();
        cout << currNode->data << " ";
        q.pop();

        if(currNode->left)
            q.push(currNode->left);

        if(currNode->right)
            q.push(currNode->right);
    }
}

int main() {
    TreeNode* root = nullptr;

    insertNode(root, 1);
    insertNode(root, 2);
    insertNode(root, 3);
    insertNode(root, 4);
    insertNode(root, 5);

    cout << "Inorder Traversal: ";
    inorderTraversal(root);
    cout << "\n";

    cout << "Preorder Traversal: ";
    preorderTraversal(root);
    cout << "\n";

    cout << "Postorder Traversal: ";
    postorderTraversal(root);
    cout << "\n";

    cout << "Levelorder Traversal: ";
    levelOrderTraversal(root);
    cout << "\n";

    return 0;
}