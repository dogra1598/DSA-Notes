#include <limits.h>

#include <vector>

#include "binaryTreeGeneration.h"

/*
    Same binary Trees
    =================
    Two binary trees are considered the same if they are structurally identical,
    and the nodes have the same value.

    ** We can use any traversal.

    ALGO
    ====
    1. if both of the roots are null
        -- return true
       if !root1 && root2 OR root1 && !root2
        -- return false
    2. now compare the both roots value
        -- if not same return false
    3. recur both tree to left
       recur both tree to right
       return AND of both the recurrence.

    TC: O(n + m), n = no. of nodes of tree1, m = no. of nodes of tree2
    SC: O(h1 + h2), h = height of the binary tree
    (in case of any of the DFS traversal the space will be auxiliary)

*/

bool isSameTree(TreeNode *root1, TreeNode *root2) {
    if (!root1 && !root2)
        return true;
    
    if ((!root1 && root2) || (root1 && !root2))
        return false;

    if (root1->data != root2->data)
        return false;

    bool isLeftSubtreeSame = isSameTree(root1->left, root2->left);
    bool isRightSubtreeSame = isSameTree(root1->right, root2->right);

    return isLeftSubtreeSame && isRightSubtreeSame;
}

int main() {
    TreeNode *root1 = nullptr;
    insertNode(root1, 1);
    insertNode(root1, 2);
    insertNode(root1, 3);
    insertNode(root1, 4);
    insertNode(root1, 5);
    insertNode(root1, 6);

    TreeNode *root2 = nullptr;
    insertNode(root2, 1);
    insertNode(root2, 2);
    insertNode(root2, 3);
    insertNode(root2, 4);
    insertNode(root2, 5);
    insertNode(root2, 6);

    cout << "Are the given binary trees are same: ";
    cout << isSameTree(root1, root2) << "\n";

    return 0;
}