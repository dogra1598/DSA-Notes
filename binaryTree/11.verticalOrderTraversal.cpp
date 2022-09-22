/*
    Vertical  Order Traversal
    =========================
    Given a Binary Tree, find the vertical traversal of it starting from the leftmost level to the rightmost level.
    If there are multiple nodes passing through a vertical line, then they should be printed as they appear in level order traversal of the tree.
    Input:
            1
          /   \
         2     3
        / \   / \
       4   5 6   7
            \      \
             8      9           
    Output: 
    4 2 1 5 6 3 8 7 9

    ALGO
    ====
    maintain a data structure to storing values first according to vertical distance then level wise

    TC: O(n), n = no. of nodes
    SC: O(n) + O(n), for storing all nodes + ans vector
*/

#include <map>
#include <vector>

#include "binaryTreeGeneration.h"

void helper(TreeNode* root, int currVerticalOrder, int currlevel, map<int, map<int, vector<int>>>& verticalOrder) {
    if (!root)
        return;

    verticalOrder[currVerticalOrder][currlevel].push_back(root->data);

    helper(root->left, currVerticalOrder - 1, currlevel + 1, verticalOrder);
    helper(root->right, currVerticalOrder + 1, currlevel + 1, verticalOrder);
}

void verticalOrderTraversal(TreeNode* root) {
    map<int, map<int, vector<int>>> verticalOrder;
    helper(root, 0, 0, verticalOrder);

    vector<int> ans;
    for (auto i : verticalOrder) {
        for (auto j : i.second) {
            for(auto k : j.second)
                ans.push_back(k);
        }
    }

    for(auto i : ans)
        cout << i << " ";
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

    verticalOrderTraversal(root);

    return 0;
}