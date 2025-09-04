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
  void printBottomView(Node* root, vector<int>& ans){
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
            //IMPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPP
            // if just update it here
                TopNode[hd] = fNode->data;
            
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
    vector<int> bottomView(Node *root) {
        // Your Code Here
        vector<int> ans;
        printBottomView (root, ans);
        return ans;
    }
};