/*
    Given a Binary Tree. Return true if, for every node X in the tree other than the leaves, 
    its value is equal to the sum of its left subtree's value and its right subtree's value. 
    Else return false.
    An empty tree is also a Sum Tree as the sum of an empty tree can be considered to be 0. 
    A leaf node is also considered a Sum Tree.

    Input:
        3
      /   \    
     1     2

    Output: 1
    Explanation:
    The sum of left subtree and right subtree is
    1 + 2 = 3, which is the value of the root node.
    Therefore,the given binary tree is a sum tree.

    LOGIC
    =====
    maintain pair of { isSumTree, sumValue }
*/

#include "binaryTreeGeneration.h"

pair<bool, int> isSumTreeHelper(TreeNode* root) {
    if (!root) {
        pair<bool, int> temp = {true, 0};
        return temp;
    }

    if (!root->left && !root->right) {
        pair<bool, int> temp = {true, root->data};
        return temp;
    }

    pair<bool, int> leftPairValue = isSumTreeHelper(root->left);
    pair<bool, int> rightPairValue = isSumTreeHelper(root->right);

    bool isLeftSum = leftPairValue.first;
    bool isRightSum = rightPairValue.first;
    bool isEqualSum = leftPairValue.second + rightPairValue.second == root->data;

    pair<bool, int> res;
    res.first = isLeftSum && isRightSum && isEqualSum;
    res.second = leftPairValue.second + rightPairValue.second + root->data;

    return res;
}

bool isSumTree(TreeNode* root) {
    return isSumTreeHelper(root).first;
}

int main() {
    TreeNode* root = nullptr;
    insertNode(root, 12);
    insertNode(root, 3);
    insertNode(root, 3);
    insertNode(root, 1);
    insertNode(root, 2);
    insertNode(root, 3);

    cout << isSumTree(root) << "\n";

    return 0;
}