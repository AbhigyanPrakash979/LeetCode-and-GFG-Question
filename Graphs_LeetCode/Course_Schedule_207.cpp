class Solution {
public:

 bool topoSortBfs(int n, unordered_map<int, list<int> >& adjList) {
        vector<int> ans;
		queue<int> q;
		unordered_map<int, int> indegree;

		//indegree calculate
		for(auto i: adjList ) {
			int src = i.first;
			for(auto nbr:i.second) {
				indegree[nbr]++;
			}
		}

		//put all nodes inside queue, which has indegree=0
		for(int i=0; i<n; i++) {
			if(indegree[i] == 0) {
				q.push(i);
			}
		}

		//bfs logic
		while(!q.empty()) {
			int fNode = q.front();
			q.pop();

			ans.push_back(fNode);
			//or we can do count++

			for(auto nbr: adjList[fNode]) {
				indegree[nbr]--;
				//check for zero again
				if(indegree[nbr] == 0) {
					q.push(nbr);
				}	
			}
			
		}
        // this is the condition which will tell us about the cyclic graph
        if(ans.size() == n){
            return true;
        }
        else{
            return false;
        }
		
	}

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {

        //creating adjList
        unordered_map<int, list<int>> adjList;

        //adding to adjList
        for(auto temp: prerequisites){
            int u = temp[0];
            int v = temp[1];
            adjList[v].push_back(u);
        }
        bool ans = topoSortBfs(numCourses, adjList);
        return ans;
    }
};