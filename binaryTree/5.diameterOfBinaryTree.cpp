#include <limits.h>

#include "binaryTreeGeneration.h"

/*
    Diameter of binary tree
    =======================
    Length of the longest path between any two nodes in a tree. This path may or may not pass through the root.
    (The length of a path between two nodes is represented by the "number of edges" between them)

    ALGO1:
    ======
    For each node, find height of left subtree and right subtree and add 2.
    (we are adding 2 for the left and the right edge of the current node)
    TC: O(n^2), n is no. of nodes
    (calculating height will take O(n) and we are doing this operation for every node)

    ALGO2:
    ======
    Instead of calculating heigth of left subtree and rigth subtree at every node and then calculating the diameter,
    directly use the heights
    TC: O(n), n is no. of nodes
    SC: O(h), h is height of binary tree
*/

int calHeight(TreeNode* root) {
    if (!root)
        return -1;

    int leftSubTreeHeight = calHeight(root->left);
    int rightSubTreeHeight = calHeight(root->right);

    return 1 + max(leftSubTreeHeight, rightSubTreeHeight);
}

int diameterOfBinaryTree1(TreeNode* root) {
    if (!root)
        return 0;

    int leftSubtreeHeight = calHeight(root->left);
    int rightSubtreeHeight = calHeight(root->right);

    int leftSubtreeDiameter = diameterOfBinaryTree1(root->left);
    int rightSubtreeDiameter = diameterOfBinaryTree1(root->right);

    return max(max(leftSubtreeDiameter, rightSubtreeDiameter), leftSubtreeHeight + rightSubtreeHeight + 2);
}

//////////////////////////////////////////////////////////////////////////////

int diameterOfBinaryTree2(TreeNode* root, int& diameter) {
    if (!root) {
        diameter = 0;
        return -1;
    }

    int leftSubtreeHeight = diameterOfBinaryTree2(root->left, diameter);
    int rightSubtreeHeight = diameterOfBinaryTree2(root->right, diameter);

    diameter = max(diameter, leftSubtreeHeight + rightSubtreeHeight + 2);

    return 1 + max(leftSubtreeHeight, rightSubtreeHeight);
}

int main() {
    TreeNode* root = nullptr;

    // diameter is passing through root
    // insertNode(root, 1);
    // insertNode(root, 2);
    // insertNode(root, 3);
    // root->left->left = new TreeNode(4);
    // root->left->left->left = new TreeNode(5);
    // root->right->right = new TreeNode(6);
    // root->right->right->right = new TreeNode(7);
    // root->right->right->right->right = new TreeNode(8);

    // diameter is in left subtree of root node
    // insertNode(root, 1);
    // insertNode(root, 2);
    // insertNode(root, 3);
    // root->left->left = new TreeNode(4);
    // root->left->right = new TreeNode(5);
    // root->left->right->right = new TreeNode(6);
    // root->left->right->right->right = new TreeNode(7);
    // root->left->right->right->right->right = new TreeNode(8);

    // diameter is in right subtree of root node
    insertNode(root, 1);
    insertNode(root, 2);
    insertNode(root, 3);
    root->right->left = new TreeNode(4);
    root->right->left->left = new TreeNode(5);
    root->right->left->left->left = new TreeNode(6);
    root->right->right = new TreeNode(7);
    root->right->right->right = new TreeNode(8);
    root->right->right->right->right = new TreeNode(9);

    cout << "Diameter (using algo1): ";
    cout << diameterOfBinaryTree1(root) << "\n";

    int diameter = INT_MIN;
    diameterOfBinaryTree2(root, diameter);
    cout << "Diameter (using algo2): " << diameter << "\n";

    return 0;
}