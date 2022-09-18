/*
    Zig Zag Traversal
    =================
    print level order but in zig zag manner

    Input:
            1
           / \
          /   \
         2     3
        / \   / \
       4   5 6   7

    Output:
    1 3 2 4 5 6 7

    TC: O(n), n = no. of nodes
    SC: O(h), h = height of binary tree
*/

#include <vector>

#include "binaryTreeGeneration.h"

void zigZagTraversal(TreeNode* root) {
    if (!root) {
        cout << "Binary tree is empty!\n";
        return;
    }

    queue<TreeNode*> q;
    q.push(root);
    bool isMovinfLeftToright = true;

    while (!q.empty()) {
        int currSizeOfQueue = q.size();
        vector<int> temp(currSizeOfQueue);

        for (int i = 0; i < currSizeOfQueue; i++) {
            TreeNode* currNode = q.front();
            q.pop();

            int idx = isMovinfLeftToright ? i : currSizeOfQueue - i - 1;
            temp[idx] = currNode->data;

            if (currNode->left)
                q.push(currNode->left);
            if (currNode->right)
                q.push(currNode->right);
        }

        if (isMovinfLeftToright)
            cout << "L to R: ";
        else
            cout << "R to L: ";

        for (auto element : temp)
            cout << element << " ";
        cout << "\n";

        isMovinfLeftToright = !isMovinfLeftToright;
    }
}

int main() {
    TreeNode* root = nullptr;
    insertNode(root, 1);
    insertNode(root, 2);
    insertNode(root, 3);
    insertNode(root, 4);
    insertNode(root, 5);
    insertNode(root, 6);

    zigZagTraversal(root);

    return 0;
}