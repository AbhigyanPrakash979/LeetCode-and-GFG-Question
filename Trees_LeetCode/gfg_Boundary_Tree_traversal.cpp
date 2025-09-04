/*
// Tree Node
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    // Constructor to initialize a new node
    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};
*/

class Solution {
  public:
    void printRightBoundary(Node* root, vector<int>& ans){
        if(root== NULL){
            return;
        }
        //base case2
        if(root->left == NULL && root->right == NULL){
            return;
        }
        if(root->right){
            printRightBoundary(root->right, ans);
        }
        else{
            printRightBoundary(root->left,ans);
        }
        ans.push_back(root->data);
    }
    void printLeafBoundary(Node* root, vector<int>& ans){
        if(root== NULL){
            return;
        }
        //base case2
        if(root->left == NULL && root->right == NULL){
            ans.push_back(root->data);
        }
        
        printLeafBoundary(root->left, ans);
        printLeafBoundary(root->right, ans);
    }
    void printLeftBoundary(Node* root, vector<int>& ans){
        if(root== NULL){
            return;
        }
        //base case2
        if(root->left == NULL && root->right == NULL){
            return;
        }
        
        ans.push_back(root->data);
        if(root->left){
           printLeftBoundary(root->left, ans); 
        }
        else{
            printLeftBoundary(root->right, ans);
        }
        
    }
    
    vector<int> boundaryTraversal(Node *root) {
        // code here
        //base case
        if(root == NULL){
            return{};
        }
        vector<int> ans;
        ans.push_back(root->data);
        
        printLeftBoundary(root->left, ans);
        printLeafBoundary(root->left, ans);  // Avoid duplicate root leaf
        printLeafBoundary(root->right, ans);
        printRightBoundary(root->right, ans);
        return ans;
    }
};