/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        //if no node exist
        if(node== NULL){
            return NULL;
        }

        // Creation of ClonedMap to ensure sabki ek he copy ho
        // given:- node ki index node ki value jaisi same hai
        unordered_map<Node*, Node*> cloneMap;
        queue<Node*> q;

        // pehle ki node ki cloning krro
        //Step 1: Pehle node daalo
        Node* cloneFirst = new Node(node->val);
        //Step 2: phir map mein node ke corresponding clone bna do
        cloneMap[node] = cloneFirst;

        //As Usual BFS Traversa;
        q.push(node);

        while(!q.empty()){
            Node* frontNode = q.front();
            q.pop();

            // neighbors already given hai question mein
            for(auto nbr: frontNode->neighbors){
                //check if already exist
                if(cloneMap.find(nbr) == cloneMap.end() ){
                    //agar dhundhte dhundhte aage aa gaye aur nhi mila 
                    //toh nya create krdo
                    Node* cloneNbr = new Node(nbr->val);
                    cloneMap[nbr] = cloneNbr;
                    q.push(nbr);
                }
                cloneMap[frontNode] -> neighbors.push_back(cloneMap[nbr]);
            }
        }
        return cloneFirst;
    }
};