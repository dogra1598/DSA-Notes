#include <stack>

#include "binaryTreeGeneration.h"

/*
    Iterative Inorder Traversal (using stack)
    ALGO:
    1. run loop infinitely
    2. if node != nullptr, push node into stack and move to the left
    3. if node == nullptr
        -- check for empty stack, if true break loop
        -- take the top node, print it and remove it from stack
        -- move to right

    TC: O(n), n = no. of nodes
    SC: O(height of binary tree)
*/
void iterativeInorder(TreeNode* root) {
    if (!root) {
        cout << "Binary Tree is empty!\n";
        return;
    }

    stack<TreeNode*> st;
    TreeNode* node = root;

    while (true) {
        if (node) {
            st.push(node);
            node = node->left;
        } else {
            if (st.empty())
                break;
            node = st.top();
            st.pop();
            cout << node->data << " ";
            node = node->right;
        }
    }
}

/*
    Iterative Preorder Traversal (using stack)
    Note: first push "right" node and then "left" node

    TC: O(n), n = no. of nodes
    SC: O(height of binary tree)
*/
void iterativePreorder(TreeNode* root) {
    if (!root) {
        cout << "Binary Tree is empty!\n";
        return;
    }

    stack<TreeNode*> st;
    st.push(root);
    while (!st.empty()) {
        TreeNode* currNode = st.top();
        st.pop();
        cout << currNode->data << " ";

        if (currNode->right)
            st.push(currNode->right);
        if (currNode->left)
            st.push(currNode->left);
    }
}

/*
    Iterative Postorder Traversal (using 2 stacks)
    ALGO:
    1. maintain 2 stacks, push root into stack1
    2. while stack1 not empty
    3. take the top node from stack1, push node into stack2
    4. if node's left exists, push node's left into stack1
    5. if node's right exists , push node's right into stack1
    6. after the loop, stack2 will have postorder of the given binary trees

    TC: O(n), n = no. of nodes
    SC: O(n), as stack2 will contain all elements at the end
*/
void iterativePostorderUsing2Stacks(TreeNode* root) {
    if (!root) {
        cout << "Binary Tree is empty!\n";
        return;
    }

    stack<TreeNode*> st1, st2;
    st1.push(root);

    while (!st1.empty()) {
        TreeNode* currNode = st1.top();
        st1.pop();
        st2.push(currNode);

        if (currNode->left)
            st1.push(currNode->left);
        if (currNode->right)
            st1.push(currNode->right);
    }

    while (!st2.empty()) {
        cout << st2.top()->data << " ";
        st2.pop();
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
    insertNode(root, 7);

    cout << "Inorder Traversal: ";
    iterativeInorder(root);
    cout << "\n";

    cout << "Preorder Traversal: ";
    iterativePreorder(root);
    cout << "\n";

    cout << "Postorder Traversal: ";
    iterativePostorderUsing2Stacks(root);
    cout << "\n";

    return 0;
}