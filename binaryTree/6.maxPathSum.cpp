#include "binaryTreeGeneration.h"

/*
    Max Path Sum
    ============
    A path in a binary tree is a sequence of nodes where each pair of adjacent nodes in the sequence has an edge connecting them.
    A node can only appear in the sequence at most once. Note that the path does not need to pass through the root.

    The path sum of a path is the sum of the node's values in the path.

    Given the root of a binary tree, return the maximum path sum of any non-empty path.
    For empty tree return sum as 0.

    ALGO:
    =====
    For each node find left path sum and right path sum.
    maintain a maxSum, update maxSum value by using
        max(maxSum, currNode->data + leftPathSum, rightPathSum)
    return currNdoe->data + max(leftPathSum + rightPathSum)

    ** Note: if at any point we are getting leftPathSum or rigthPathSum as negative values
    we will not consider(because -ve value will only decrease the path sum), instead we
    will use 0.

    TC: O(n), n = no. of nodes
    SC: O(h), h = height of the given binary tree
*/

int maxPathSum(TreeNode* root, int& maxSum) {
    if (!root)
        return 0;

    int leftSubtreeSum = max(0, maxPathSum(root->left, maxSum));
    int rightSubtreeSum = max(0, maxPathSum(root->right, maxSum));

    maxSum = max(maxSum, root->data + leftSubtreeSum + rightSubtreeSum);

    return root->data + max(leftSubtreeSum, rightSubtreeSum);
}

int main() {
    TreeNode* root = nullptr;

    insertNode(root, 1);
    insertNode(root, 2);
    insertNode(root, 8);
    insertNode(root, 4);
    insertNode(root, 5);

    int maxSum = 0;
    maxPathSum(root, maxSum);
    cout << "Max path sum: " << maxSum << "\n";

    return 0;
}