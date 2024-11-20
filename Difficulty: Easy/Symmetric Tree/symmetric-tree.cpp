//{ Driver Code Starts
//Initial Template for C++


#include <bits/stdc++.h>
using namespace std;
#define MAX_HEIGHT 100000

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
    if (str.length() == 0 || str[0] == 'N') return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;) ip.push_back(str);

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
        if (i >= ip.size()) break;
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
/*
Structure of the node of the tree is as
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/
class Solution{
    public:
    // return true/false denoting whether the tree is Symmetric or not
       bool util(Node* r1,Node* r2)
    {
        if(!r1 && !r2)
            return true;
            
        if(!r1 || !r2)
            return false;
            
        return (r1->data == r2->data) && util(r1->left,r2->right) && 
                util(r1->right,r2->left);
    }
    bool isSymmetric(struct Node* root)
    {
	    return util(root,root);
    }
    
    // r1->data == r2->data:


                        // Is part mein hum r1 aur r2 node ke data ko compare kar rahe hain.
// r1 left subtree ka node hai aur r2 right subtree ka node hai (ya vice versa, yeh recursion ke through change hota hai).
// Agar dono nodes ka data (value) same hai, toh hum aage badhte hain. Agar yeh value different hai, toh tree symmetric nahi hai, aur function false return kar dega.
// util(r1->left, r2->right):

// Yeh part recursively left subtree (of r1) aur right subtree (of r2) ko compare karta hai.
// Matlab, jo left side ka part hai (r1 ka left child), wo right side ke part ke barabar hona chahiye (r2 ka right child).
// Agar yeh left aur right subtree match karte hain, toh true return hota hai, agar nahi, toh false.
// util(r1->right, r2->left):

// Yeh part recursively right subtree (of r1) aur left subtree (of r2) ko compare karta hai.
// Matlab, jo right side ka part hai (r1 ka right child), wo left side ke part ke barabar hona chahiye (r2 ka left child).
// Agar yeh right aur left subtree match karte hain, toh true return hota hai, agar nahi, toh false.

    
    
};

//{ Driver Code Starts.

/* Driver program to test size function*/

  

int main() {

   
    int t;
    scanf("%d ", &t);
    while (t--) {
        string s, ch;
        getline(cin, s);
        
        Node* root = buildTree(s);

        vector<int> ans;
        Solution ob;
        if(ob.isSymmetric(root)){
            cout<<"True"<<endl;
        }
        else{ 
            cout<<"False"<<endl;
        }
    }
    return 0;
}

// } Driver Code Ends