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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        //base case
        if( (p == NULL) && (q == NULL) ){
            return true;
        }
        //base case
        if( (p == NULL) || (q == NULL) ){
            return false;
        }
        //base case2
        if(p->val != q->val){
            return false;
        }

        // //base case 3
        // if(p->val == q->val){ // yeh isliye nhi likh skte kyunki yeh sidha true return krdega
        //     return true;       // aage check krre bina
        // }

        // RR call
        bool leftSubTree = isSameTree(p->left, q->left);
        bool rightSubTree = isSameTree(p->right, q->right);

        return leftSubTree && rightSubTree;
    }
};