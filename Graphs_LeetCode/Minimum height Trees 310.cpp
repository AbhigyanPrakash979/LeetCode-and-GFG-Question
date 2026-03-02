//Using Topological Sorting
//T.C : O(V+E)
//S.C : O(V+E)
class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if(n == 1)
            return {0};
        
        vector<int> result;
        vector<int> indegree(n);
        unordered_map<int, vector<int>> adj;
        
        for(vector<int> vec:edges) {
            int u = vec[0];
            int v = vec[1];
            // increment hum dono u and v kr rhe hai kyunki undirected graph hai
            indegree[u]++;
            indegree[v]++;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        queue<int> que;
        for(int i = 0; i<n; i++) {
            if(indegree[i] == 1) //adding all leafs node so that we can remove them later
                que.push(i);
        }

        // n > 2 isliye liya kyunki had se had 2 he nodes possible hai jiski indegree 1 hogi
        while(n > 2) {      
            int size = que.size();
            n -= size; //removing nodes with indegreee 1 mtlab leaf nodes htta rhe hain
            
            while(size--) { // har eke iteration mein ek leaf nikal jata hai
                int frontNode = que.front();
                que.pop();
                for(int nbr:adj[frontNode]) {
                    indegree[nbr]--;
                    if(indegree[nbr] == 1)
                        que.push(nbr);
                }
            }
        }
        
        while(!que.empty()) {
            result.push_back(que.front());
            que.pop();
        }
        return result;
    }
};
