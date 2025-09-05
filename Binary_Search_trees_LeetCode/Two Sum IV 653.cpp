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
    void storeInOrder(TreeNode* root, vector<int>& inOrder){
        if(root == NULL){
            return;
        }
        //LNR
        storeInOrder(root->left, inOrder);
        inOrder.push_back(root->val);
        storeInOrder(root->right, inOrder);
    }

    bool findTarget(TreeNode* root, int k) {
        vector<int> inOrder;
        storeInOrder(root, inOrder);
        
        int s = 0;
        int e = inOrder.size() - 1;
        int sum =0;

        while(s<e){
            sum = inOrder[s] + inOrder[e];

            if(sum == k )
                return true;
            
            if(sum > k) 
                e--;
            else
                s++;
        }
        return false;
    }
};