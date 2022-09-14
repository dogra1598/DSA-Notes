#include "binaryTreeGeneration.h"

/*
    Condition for balanced binary tree:
    =================================
    abs(height of left subtree - height of right subtree) <= 1, for every node

    ALGO1:
    ======
    For each node find, height of left subtree and right subtree and check the condition
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

bool isBalancedBinaryTree1(TreeNode* root) {
    if (!root)
        return true;

    int leftHeight = calHeight(root->left);
    int rightHeight = calHeight(root->right);

    if (abs(leftHeight - rightHeight) > 1)
        return false;

    bool isBalancedLeftBinaryTree = isBalancedBinaryTree1(root->left);
    bool isBalancedRightBinaryTree = isBalancedBinaryTree1(root->right);

    return isBalancedLeftBinaryTree && isBalancedRightBinaryTree;
}

/////////////////////////////////////////////////////////////////////////////////

/*
    return -2 because leaf nodes will return -1, we cannot check based on -1 height condition
*/
int isBalancedBinaryTree2(TreeNode* root) {
    if (!root)
        return -1;

    int leftSubtreeHeight = isBalancedBinaryTree2(root->left);
    int rigthSubTreeHeight = isBalancedBinaryTree2(root->right);

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

    if (isBalancedBinaryTree1(root))
        cout << "Binary tree is balanced (using algo1)\n";
    else
        cout << "Binary tree is not balanced (using algo1)\n";

    if (isBalancedBinaryTree2(root) == -2)
        cout << "Binary tree is not balanced (using algo2)\n";
    else
        cout << "Binary tree is balanced (using algo2)\n";

    return 0;
}