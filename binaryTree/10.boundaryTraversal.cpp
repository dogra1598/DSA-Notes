/*
    Boundary Traversal
    ==================
    Given a Binary Tree, find its Boundary Traversal. The traversal should be in the following order: 

    Left boundary nodes: defined as the path from the root to the left-most node ie- the leaf node you could reach when you 
                         always travel preferring the left subtree over the right subtree. 

    Leaf nodes: All the leaf nodes except for the ones that are part of left or right boundary.

    Reverse right boundary nodes: defined as the path from the right-most node to the root. The right-most node is the leaf 
                                  node you could reach when you always travel preferring the right subtree over the left subtree. 
                                  Exclude the root from this as it was already included in the traversal of left boundary nodes.

    Note: If the root doesn't have a left subtree or right subtree, then the root itself is the left or right boundary. 

    Ex:
    Input:
            1 
          /   \
         2     3  
        / \   / \ 
       4   5 6   7
      / \
     8   9
   
    Output: 1 2 4 8 9 6 7 3
*/

#include <vector>

#include "binaryTreeGeneration.h"

void findLeftBoundary(TreeNode* root, vector<int>& res) {
    if (!root || (!root->left && !root->right))
        return;

    res.push_back(root->data);

    if (root->left)
        findLeftBoundary(root->left, res);
    else
        findLeftBoundary(root->right, res);
}

void findBottomBoundary(TreeNode* root, vector<int>& res) {
    if (!root)
        return;

    if (!root->left && !root->right) {
        res.push_back(root->data);
        return;
    }

    findBottomBoundary(root->left, res);
    findBottomBoundary(root->right, res);
}

void findRightBoundary(TreeNode* root, vector<int>& res) {
    if (!root || (!root->left && !root->right))
        return;

    if (root->right)
        findRightBoundary(root->right, res);
    else
        findRightBoundary(root->left, res);

    res.push_back(root->data);
}

void boundaryTraversal(TreeNode* root) {
    vector<int> res;

    if (!root)
        return;

    res.push_back(root->data);

    // traverse left boundary
    findLeftBoundary(root->left, res);

    // traverse leaf nodes
    findBottomBoundary(root->left, res);
    findBottomBoundary(root->right, res);

    // traverse right boundary
    findRightBoundary(root->right, res);

    for (auto element : res)
        cout << element << " ";
    cout << "\n";
}

int main() {
    TreeNode* root = nullptr;
    insertNode(root, 1);
    insertNode(root, 2);
    insertNode(root, 3);
    insertNode(root, 4);
    insertNode(root, 5);

    root->left->left->left = new TreeNode(6);
    root->left->left->right = new TreeNode(7);
    root->left->left->right->left = new TreeNode(8);
    root->left->left->right->right = new TreeNode(9);
    root->right->left = new TreeNode(10);
    root->right->right = new TreeNode(11);
    root->right->right->left = new TreeNode(12);
    root->right->right->right = new TreeNode(13);
    root->right->right->right->left = new TreeNode(14);
    root->right->right->right->left->right = new TreeNode(15);

    // case where rigth child of root doesn't exist
    // insertNode(root, 1);
    // insertNode(root, 2);
    // root->left->left = new TreeNode(3);
    // root->left->right = new TreeNode(4);
    // root->left->left->left = new TreeNode(5);
    // root->left->right->left = new TreeNode(6);
    // root->left->right->right = new TreeNode(7);

    boundaryTraversal(root);

    return 0;
}