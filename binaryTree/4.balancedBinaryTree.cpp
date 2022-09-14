#include "binaryTreeGeneration.h"

/*
    Property of balanced binary tree:
    =================================
    abs(height of left subtree - height of right subtree) <= 1, for every node

    ALGO1:
    ======
    For each node find height of left subtree and right subtree and check the condition
    TC: O(n^2), n is no. of nodes
    (calculating height will take O(n) and we are doing this operation for every node)

    ALGO2:
    ======
    Instead of calculating heigth of left subtree and rigth subtree at every node and then checking for balanced condition,
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

bool isBalancedBinaryTree(TreeNode* root) {
    if (!root)
        return true;

    int leftHeight = calHeight(root->left);
    int rightHeight = calHeight(root->right);

    if (abs(leftHeight - rightHeight) > 1)
        return false;

    bool isBalancedLeftBinaryTree = isBalancedBinaryTree(root->left);
    bool isBalancedRightBinaryTree = isBalancedBinaryTree(root->right);

    return isBalancedLeftBinaryTree && isBalancedRightBinaryTree;
}

/////////////////////////////////////////////////////////////////////////////////

/*
    return -2 because leaf nodes will return -1, we cannot check based on -1 height condition
*/
int checkBalancedBinaryTree(TreeNode* root) {
    if (!root)
        return -1;

    int leftSubtreeHeight = checkBalancedBinaryTree(root->left);
    int rigthSubTreeHeight = checkBalancedBinaryTree(root->right);

    if (leftSubtreeHeight == -2 || rigthSubTreeHeight == -2)
        return -2;

    int heightDiff = abs(leftSubtreeHeight - rigthSubTreeHeight);
    if (heightDiff > 1)
        return -2;

    return 1 + max(leftSubtreeHeight, rigthSubTreeHeight);
}

int main() {
    TreeNode* root = nullptr;

    insertNode(root, 1);
    insertNode(root, 2);
    insertNode(root, 3);
    insertNode(root, 4);
    insertNode(root, 5);

    // root->right->right = new TreeNode(6);
    // root->right->right->right = new TreeNode(7);
    // root->right->right->right->right = new TreeNode(8);

    // if (isBalancedBinaryTree(root))
    //     cout << "Binary tree is balanced\n";
    // else
    //     cout << "Binary tree is not balanced\n";

    if (checkBalancedBinaryTree(root) == -2)
        cout << "Binary tree is not balanced\n";
    else
        cout << "Binary tree is balanced\n";

    return 0;
}