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

    TreeNode* solve(vector<int>& inorder, vector<int>& preorder,
            int inorderStart, int inorderEnd, int& preorderIndex, int n){

                //base case
                if(inorderStart>inorderEnd || preorderIndex>n){
                    return NULL;
                }

                // take out first preorder element
                int element = preorder[preorderIndex++];
                // create the root from that element
                TreeNode* root = new TreeNode(element);
                //find position in inorder array
                int pos = findPosition(inorder, element);

                root-> left = solve(inorder, preorder, inorderStart, pos-1, preorderIndex, n);
                root->right = solve(inorder, preorder, pos+1, inorderEnd, preorderIndex, n);

                return root;
                
            }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) { 

        int n = inorder.size();
        int inorderStart = 0;
        int inorderEnd = n-1; 
        int preorderIndex = 0;

        return solve(inorder, preorder, inorderStart, inorderEnd, preorderIndex, n);

    }
};