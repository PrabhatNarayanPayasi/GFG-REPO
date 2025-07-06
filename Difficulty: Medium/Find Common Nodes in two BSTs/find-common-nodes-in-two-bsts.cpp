class Solution {
  public:
    vector<int> findCommon(Node *root1, Node *root2) {
        vector<int> result;
        stack<Node*> s1, s2;

        while (true) {
            // Push all left nodes of root1
            while (root1) {
                s1.push(root1);
                root1 = root1->left;
            }

            // Push all left nodes of root2
            while (root2) {
                s2.push(root2);
                root2 = root2->left;
            }

            // If any of the stacks is empty, we're done
            if (s1.empty() || s2.empty()) break;

            Node* top1 = s1.top();
            Node* top2 = s2.top();

            // If both nodes are same, add to result
            if (top1->data == top2->data) {
                result.push_back(top1->data);
                s1.pop();
                s2.pop();
                // Move to right children
                root1 = top1->right;
                root2 = top2->right;
            }
            // Move in the tree which has smaller value
            else if (top1->data < top2->data) {
                s1.pop();
                root1 = top1->right;
                root2 = nullptr;
            }
            else {
                s2.pop();
                root2 = top2->right;
                root1 = nullptr;
            }
        }

        return result;
    }
};
