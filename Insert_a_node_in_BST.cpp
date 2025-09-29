// Given a root binary search tree and a key. If the key is not present in the tree, Insert a new node with a value equal to the key into the tree. If the key is already present in the tree, don't modify the tree. Return the root of the modified tree after inserting the key.

// Note: The generated output contains the in-order traversal of the modified tree.

// Examples :

// Input: root = [2, 1, 3], key = 4

// Output: [1, 2, 3, 4]
// Explanation: After inserting the node 4 Inorder traversal will be 1 2 3 4.
// Input: root = [2, 1, 3, N, N, N, 6], key = 4

// Output: [1, 2, 3, 4, 6]
// Explanation: After inserting the node 4 Inorder traversal of the above tree will be 1 2 3 4 6.
// Input: root = [2, 1, 3], key = 2

// Output: [1, 2, 3]
// Explanation: Node with key=2 already present in BST, Inorder traversal will be 1 2 3.
// Constraints:
// 1 ≤ number of nodes ≤ 105
// 1 ≤ node->data ≤ 109
// 1 ≤ key ≤ 109

// Expected Complexities
// Time Complexity: O(h)
// Auxiliary Space: O(h)

#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};

class Solution
{
public:
    Node *insert(Node *root, int key)
    {
        //  code  here
        if (!root)
        {
            Node *temp = new Node(key);
            return temp;
        }

        if (root->data == key)
        {
            return root;
        }

        if (root->data < key)
        {
            root->right = insert(root->right, key);
        }

        if (root->data > key)
        {
            root->left = insert(root->left, key);
        }

        return root;
    }
};