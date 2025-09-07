// Function to search a node in BST.
class Solution {

  public:
    int floor(Node* root, int x) {
        // Code here
        //base case 1
        if(root == NULL){
            return -1;
        }
        //base case 2
        if(root->data == x){
            return root->data;
        }
        // call for left Subtree
        if(root->data > x){
            int leftFloor= floor(root->left, x);
            return leftFloor;
        }
        //call for right SubTree
        if(root->data < x){
            int rightFloor = floor(root->right, x);
            //check for non null values
            if(rightFloor != -1 && rightFloor <=x){
                return rightFloor;
            }
            else{
                return root->data;
            }
            
        }
        
    }
};