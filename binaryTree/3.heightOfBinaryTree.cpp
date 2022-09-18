#include "binaryTreeGeneration.h"

/*
    For a binary tree  value of depth and heigth are same.
    Here considering leaf nodes are at height 0;

    ALGO:
    If tree is empty return -1
    height of the currNode = 1 + max(height of left subtree, height of right sub tree)
*/

int heightOfBinaryTree(TreeNode* root) {
    if (!root)
        return -1;

    int leftSubTreeHeight = heightOfBinaryTree(root->left);
    int rightSubTreeHeight = heightOfBinaryTree(root->right);

    return 1 + max(leftSubTreeHeight, rightSubTreeHeight);
}

int main() {
    TreeNode* root = nullptr;

    insertNode(root, 1);
    insertNode(root, 2);
    insertNode(root, 3);
    insertNode(root, 4);
    insertNode(root, 5);
    insertNode(root, 6);
    insertNode(root, 7);
    insertNode(root, 8);

    cout << "Height of the given binary tree is: ";
    cout << heightOfBinaryTree(root) << "\n";

    return 0;
}