/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        if (root == NULL)
            return NULL; 

        queue<Node*> q;
        q.push(root);
        q.push(NULL); 

        while (!q.empty()) {
            Node* temp = q.front();
            q.pop();

            if (temp == NULL) {
                // End of current level
                if (!q.empty()) {
                    q.push(NULL); 
                }
            } else {
                // Set next pointer
                temp->next = q.front(); // yeh main hai to link

                // Push children into queue
                if (temp->left) {
                    q.push(temp->left);
                }
                if (temp->right) {
                    q.push(temp->right);
                }
            }
        }

        return root; 
    }
};
