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

    ALGO3:
    ======
    Maintain a pair of {isBalanced, height}
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

bool isBalancedBinaryTreeUsingHeight(TreeNode* root) {
    if (!root)
        return true;

    int leftHeight = calHeight(root->left);
    int rightHeight = calHeight(root->right);

    if (abs(leftHeight - rightHeight) > 1)
        return false;

    bool isBalancedLeftBinaryTree = isBalancedBinaryTreeUsingHeight(root->left);
    bool isBalancedRightBinaryTree = isBalancedBinaryTreeUsingHeight(root->right);

    return isBalancedLeftBinaryTree && isBalancedRightBinaryTree;
}

/////////////////////////////////////////////////////////////////////////////////

/*
    return -2 because leaf nodes will return -1, we cannot check based on -1 height condition
*/
int isBalancedBinaryTreeUsingHeigthDirectly(TreeNode* root) {
    if (!root)
        return -1;

    int leftSubtreeHeight = isBalancedBinaryTreeUsingHeigthDirectly(root->left);
    int rigthSubTreeHeight = isBalancedBinaryTreeUsingHeigthDirectly(root->right);

    if (leftSubtreeHeight == -2 || rigthSubTreeHeight == -2)
        return -2;

    int heightDiff = abs(leftSubtreeHeight - rigthSubTreeHeight);
    if (heightDiff > 1)
        return -2;

    return 1 + max(leftSubtreeHeight, rigthSubTreeHeight);
}

/////////////////////////////////////////////////////////////////////////////////

/*
    better approach than algo 2
    maintain a pair of {isBalanced, height}
*/
pair<bool, int> isBalancedBinaryTreeUsingPairHelper(TreeNode* root) {
    if (!root) {
        pair<bool, int> temp = {true, -1};
        return temp;
    }

    pair<bool, int> leftPair = isBalancedBinaryTreeUsingPairHelper(root->left);
    pair<bool, int> rightPair = isBalancedBinaryTreeUsingPairHelper(root->right);

    bool isLeftSubtreeBalanced = leftPair.first;
    bool isRigthSubtreeBalanced = rightPair.first;
    int currHeightDiff = abs(leftPair.second - rightPair.second);

    pair<bool, int> resPair;
    resPair.first = currHeightDiff < 2 && isLeftSubtreeBalanced && isRigthSubtreeBalanced;
    resPair.second = 1 + max(leftPair.second, rightPair.second);

    return resPair;
}

bool isBalancedBinaryTreeUsingPair(TreeNode* root) {
    return isBalancedBinaryTreeUsingPairHelper(root).first;
}

int main() {
    TreeNode* root = nullptr;

    insertNode(root, 1);
    insertNode(root, 2);
    insertNode(root, 3);
    insertNode(root, 4);
    insertNode(root, 5);

    root->right->right = new TreeNode(6);
    root->right->right->right = new TreeNode(7);
    root->right->right->right->right = new TreeNode(8);

    if (isBalancedBinaryTreeUsingHeight(root))
        cout << "Binary tree is balanced (using algo1)\n";
    else
        cout << "Binary tree is not balanced (using algo1)\n";

    if (isBalancedBinaryTreeUsingHeigthDirectly(root) == -2)
        cout << "Binary tree is not balanced (using algo2)\n";
    else
        cout << "Binary tree is balanced (using algo2)\n";

    if (isBalancedBinaryTreeUsingPair(root))
        cout << "Binary tree is balanced (using algo3)\n";
    else
        cout << "Binary tree is not balanced (using algo3)\n";

    return 0;
}