
/*

Definition for Binary Tree Node
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
};
*/

class Solution {
  public:

    void findPath(Node* root, vector<vector<int>>& ans, vector<int> path){
        //base case
        if(root== NULL){
            return;
        }
        
        //for leafnode Node
        if(root->left == NULL && root->right == NULL){
            path.push_back(root->data);
            // pushing it in final vector
            ans.push_back(path);
            //backtrack
            path.pop_back();
        }
        
        //for root, left and right subtree
        path.push_back(root->data);
        //rr
        findPath(root->left, ans, path);
        findPath(root->right, ans, path);
    }
    vector<vector<int>> Paths(Node* root) {
        // code here
        vector<vector<int>> ans;
        vector<int> path;
        
        findPath(root, ans, path);
        return ans;
    }
};