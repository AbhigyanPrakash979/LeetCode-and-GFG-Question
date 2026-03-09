//Approach-1 (Using adj of string to vector and sorting it)
//T.C : O(V^2)
class Solution {
public:
    unordered_map<string, vector<string>> adj;
    vector<string> route;
    int numTickets = 0;
    
    bool dfs(string fromAirport, vector<string>& path) {
        path.push_back(fromAirport);
        
        // we have used all tickets, this is a valid path return the result
        // Base case ===  Very Important 
        if (path.size() == numTickets+1) {
            route = path;
            return true;
        }
        
        //You have already found the route (first valid lexicographically path)

        
        vector<string>& nbr = adj[fromAirport];
        
        // at the current layer, try its nbr in the sorted order
        for(int i = 0; i < nbr.size(); i++) {
            
            string toAirport = nbr[i];
            
            // remove ticket(route) from graph so that it won't be reused 
            nbr.erase(nbr.begin()+i); //important
            
            if(dfs(toAirport, path))
                return true;
            
            // if the current path is invalid, restore the current ticket
            nbr.insert(nbr.begin()+i, toAirport);            
        }
        
        path.pop_back();
        return false;
    }


    vector<string> findItinerary(vector<vector<string>>& tickets) {
		numTickets = tickets.size();
        
		for (auto& t : tickets) {
            string u = t[0];        //pehla source hai
            string v = t[1];        //dusra destination
            
			adj[u].push_back(v);    //populate krdo
		}
        
        // Sort vertices in the adjacency list by lexical order because question mein pucha hai
        for (auto &edges : adj) {
            sort(begin(edges.second), end(edges.second));   //edges.second kyunki nbr ko sort krna hai
        }
        
        vector<string> path;
        dfs("JFK", path);   //function call
        return route;
    }
    
    
};
