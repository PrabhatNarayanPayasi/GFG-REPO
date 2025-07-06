/*The Node structure is
class Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int x){
        data = x;
        left = NULL;
        right = NULL;
    }
};*/
bool Dead(Node* root , int lower ,  int upper){
    if(!root){
        return 0;
    }
    if(!root->left && !root->right){
        if(root->data - lower ==1 && upper - root->data == 1){
            return 1;
        }
        return 0;
    }
     
        
   
   return  Dead(root->left , lower , root->data)|| //left child ke liye upper to root->data ban gya ha 
    Dead(root->right , root->data , upper); // lekin right child ke liye lower roo->data ban gaya hai. 
}
class Solution {
  public:
    bool isDeadEnd(Node *root) {
        // Code here
         return Dead(root , 0 , INT_MAX);
    }
};