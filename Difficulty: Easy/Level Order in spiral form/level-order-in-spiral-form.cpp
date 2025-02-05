//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// Tree Node
struct Node {
    int data;
    Node* left;
    Node* right;
};

// Utility function to create a new Tree Node
Node* newNode(int val) {
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}

// Function to Build Tree
Node* buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input string after splitting by space
    vector<string> ip;
    istringstream iss(str);
    for (string str; iss >> str;)
        ip.push_back(str);

    // Create the root of the tree
    Node* root = newNode(stoi(ip[0]));

    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {
        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();

        // Get the current node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {
            // Create the left child for the current node
            currNode->left = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {
            // Create the right child for the current node
            currNode->right = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}


// } Driver Code Ends
/* A binary tree node has data, pointer to left child
   and a pointer to right child
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
}; */

// Function to return a list containing the level order traversal in spiral form.
class Solution {
  public:
    vector<int> findSpiral(Node* root) {
    //   Node * cur = root;
    //     vector<int>ans;
    //     if(root == nullptr)     return ans;
    //     queue<Node*>q;
    //     int level = 0;
    //     q.push(cur);
    //     while(!q.empty()){
    //         int siz = q.size();
    //         level++;
    //         for(int i=0 ; i<siz ; i++){
    //             Node* el = q.front();
    //             q.pop();
    //             if(el->left){
    //                 q.push(el->left);
    //             }
    //             if(el->right){
    //                 q.push(el->right);
    //             }
    //             ans.push_back(el->data);
    //         }
    //         if(level % 2){
    //             reverse(ans.end()-siz , ans.end());
    //         }
    //     }
    //     return ans;
    
    stack<Node*>s1;
    stack<Node*>s2;
    vector<int>ans;
    s1.push(root);
    while(!s1.empty() || !s2.empty()){
        if(!s1.empty()){
            while(!s1.empty()){
                Node* temp = s1.top();
                s1.pop();
                ans.push_back(temp->data);
                if(temp->right){
                     s2.push(temp->right);
                }
                if(temp->left){
                         s2.push(temp->left );
                }
       
            }
           
        }
        else{
            while(!s2.empty()){
                  Node* temp = s2.top();
                s2.pop();
               ans.push_back(temp->data);
                if(temp->left){
                         s1.push(temp->left );
                }
                 if(temp->right){
                     s1.push(temp->right);
                }
            }
         
        }
    }
    return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    string tc;
    getline(cin, tc);
    t = stoi(tc);
    Solution sol; // Create Solution object
    while (t--) {
        string s;
        getline(cin, s);
        Node* root = buildTree(s);

        // Call the findSpiral function from Solution class
        vector<int> vec = sol.findSpiral(root);
        for (int x : vec)
            cout << x << " ";
        cout << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends