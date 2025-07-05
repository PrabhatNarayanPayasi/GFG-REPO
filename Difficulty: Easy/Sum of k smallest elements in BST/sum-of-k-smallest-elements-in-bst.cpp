// User function Template for C++

/*
struct Node {
    int data;
    Node* right;
    Node* left;

    Node(int x){
        data = x;
        right = NULL;
        left = NULL;
    }
};
*/

// Function to find ceil of a given input in BST. If input is more
// than the max key in BST, return -1
void ksum(Node* root  , int &Sum  , int &k){
    if(!root){
        return;
    }
    ksum(root->left , Sum , k);
    k--;
    if(k>=0){
        Sum += root->data;
    }
    if(k<=0){
        return; 
    }
    ksum(root->right , Sum , k);
    
 }
int sum(Node* root, int k) {
int Sum = 0;
 ksum(root , Sum , k);
    return Sum;
}
