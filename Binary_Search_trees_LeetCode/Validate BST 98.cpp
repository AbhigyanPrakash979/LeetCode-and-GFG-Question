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
    bool checkValidity ( TreeNode* root, long long minVal, long long maxVal){
        //base case
        if(root == NULL){
            return true;
        }
        //rr
        if(root->val > minVal && root->val < maxVal){
            //for left subtree
            bool leftAns = checkValidity(root->left, minVal, root->val); 
            //for right subTree
            bool rightAns = checkValidity(root->right, root->val, maxVal);

            return leftAns && rightAns;
        }
        else{
            return false;
        }
    }

    bool isValidBST(TreeNode* root) {
        long long minVal = LLONG_MIN;
        long long maxVal = LLONG_MAX;

        //IMPORTANT CHECK MIN AND MAX VAL
         return checkValidity(root, minVal, maxVal);
    }
};