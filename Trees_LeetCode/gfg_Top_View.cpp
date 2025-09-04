/*
struct Node
{
    int data;
    Node* left;
    Node* right;
};
*/
class Solution {
  public:
    // Function to return a list of nodes visible from the top view
    // from left to right in Binary Tree.
    void printTopView(Node* root, vector<int>& ans){
        //base cse
        if(root == NULL){
            return;
        }
        
        //creation of map
        map <int, int> TopNode;
        
        //just same as level order traversal
        queue<pair<Node*, int>> q;// creation of queue
        
        //pushing in queu
        q.push(make_pair(root, 0));
        
        while(!q.empty()){
            
            pair<Node*, int> temp = q.front();
            q.pop();
            
            // Extract frontNode and hd
            Node* fNode = temp.first;
            int hd = temp.second;
            
            //check if hd already exist in map
            if(TopNode.find(hd) == TopNode.end()){
                TopNode[hd] = fNode->data;
            }
            
            //leftSubtree
            if(fNode-> left){
                q.push(make_pair(fNode->left, hd-1));
            }
            //rightSubtree
            if(fNode-> right){
                q.push(make_pair(fNode->right, hd+1));
            }
        }
            //pushing it into final answer
            for(auto i: TopNode){
                ans.push_back(i.second);
            }
            
        
        
    }
    
    vector<int> topView(Node *root) {
        // code here
        vector<int> ans;
        printTopView (root, ans);
        return ans;
        
    }
};