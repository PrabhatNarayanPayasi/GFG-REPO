// struct Node {
//     int data;
//     Node *left;
//     Node *right;

//     Node(int val) {
//         data = val;
//         left = right = NULL;
//     }
// };

// Checks if this is a special leaf node (connected in circular DLL)
bool isLeaf(Node* node) {
    if (!node || !node->left || !node->right)
        return false;

    return node->left->right == node && node->right->left == node;
}

// Finds height of the binary tree (in edges)
int findTreeHeight(Node* root) {
    if (root == nullptr)
        return -1;

    if (isLeaf(root))
        return 0;

    return 1 + max(findTreeHeight(root->left), findTreeHeight(root->right));
}
