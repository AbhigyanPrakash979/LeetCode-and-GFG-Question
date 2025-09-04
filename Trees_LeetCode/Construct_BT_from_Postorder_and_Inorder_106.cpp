/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
int findPosition(vector<int>& inorder, int element){
        for(int i =0; i<inorder.size(); i++){
            if(inorder[i] == element){
                return i;
            }
        }
        return -1;
    }

    TreeNode* solve(vector<int>& inorder, vector<int>& postorder,
            int inorderStart, int inorderEnd, int& postorderIndex, int n){

                //base case
                if(inorderStart>inorderEnd || postorderIndex<0){
                    return NULL;
                }

                // take out first preorder element
                int element = postorder[postorderIndex--];
                // create the root from that element
                TreeNode* root = new TreeNode(element);
                //find position in inorder array
                int pos = findPosition(inorder, element);

                // pehle right ki call jayegi phir left ki call jayegi
                root->right = solve(inorder, postorder, pos+1, inorderEnd, postorderIndex, n);
                root-> left = solve(inorder, postorder, inorderStart, pos-1, postorderIndex, n);

                return root;
                
            }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {

        int n = inorder.size();
        int inorderStart = 0;
        int inorderEnd = n-1;
        int postorderIndex = n-1;
        
        return solve(inorder, postorder, inorderStart, inorderEnd, postorderIndex, n);

        
    }
};