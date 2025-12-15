class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        // Step 1: Build graph (adjacency list) and email → name mapping
        unordered_map<string, vector<string>> adj;
        unordered_map<string, string> emailToName;

        for (auto &acc : accounts) {
            string name = acc[0];
            for (int i = 1; i < acc.size(); i++) {
                emailToName[acc[i]] = name;
                if (i == 1) continue;
                // connect acc[i] with acc[1]
                adj[acc[1]].push_back(acc[i]);
                adj[acc[i]].push_back(acc[1]);
            }
        }

        // Step 2: BFS traversal to find connected components
        unordered_set<string> visited;
        vector<vector<string>> result;

        for (auto &p : emailToName) {
            string email = p.first;
            if (!visited.count(email)) {
                vector<string> component;
                queue<string> q;
                q.push(email);
                visited.insert(email);

                while (!q.empty()) {
                    string node = q.front(); q.pop();
                    component.push_back(node);

                    for (auto &neigh : adj[node]) {
                        if (!visited.count(neigh)) {
                            visited.insert(neigh);
                            q.push(neigh);
                        }
                    }
                }

                sort(component.begin(), component.end());
                component.insert(component.begin(), emailToName[email]); // prepend name
                result.push_back(component);
            }
        }

        return result;
    }
};
