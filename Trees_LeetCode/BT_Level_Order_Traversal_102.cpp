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
    void solve(TreeNode* root, vector<vector<int>>& v){

        //base condition to prevent from crash
        if(root== NULL){
            return;
        }
        
        queue<TreeNode*> q;
        q.push(root);
        q.push(NULL);

        //
        vector<int> currLevel;

        while(!q.empty()){

            TreeNode* fNode = q.front();
            q.pop();

            if(fNode == NULL){
                v.push_back(currLevel); // vector ki ek entry ban gayi
                currLevel.clear();         //  temp vector ko clear kar diya

                if(!q.empty()){
                    q.push(NULL);
                }
            }
            else{
                // pushing into vector 
                currLevel.push_back(fNode->val);

                //call for Left Subtree // children
                if(fNode-> left){
                    q.push(fNode-> left);
                }

                //call for right Subtree // children
                if(fNode->right){
                    q.push(fNode->right);
                }
            }
        }

    }

    vector<vector<int>> levelOrder(TreeNode* root) {

        vector<vector<int>> v;
        solve(root, v);
        return v;
    }
};