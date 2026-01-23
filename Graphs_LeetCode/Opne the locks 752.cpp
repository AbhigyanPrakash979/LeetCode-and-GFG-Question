// Jaan buch ke BFS use kiya hia kyunki humme nearest possible dekhna hai  
//T.C : We have n = 10 slots in each wheel and we have w = 4 wheels. In worst case we will explore all possible combinations.  
//      Total Combinations = O(n^w)  
//S.C : In worst case we will store all possible combinations in queue O(n^w)  
class Solution {
public:
    void fillNeighbors(queue<string>& que, string& curr, unordered_set<string>& dead) {
        for(int i = 0; i<4; i++) {
            char ch  = curr[i];

            // agar ch == '0' hai toh dec = '9' else dec = ch-1
            char dec;
            if(ch == '0')
                dec = '9';
            else
                dec = ch - 1;

            // agar ch == '9' hai toh inc = '0' else inc = ch+1
            char inc;
            if(ch == '9')
                inc = '0';
            else
                inc = ch + 1;

            curr[i]  = dec;
            if(!dead.count(curr)) {
                dead.insert(curr);
                que.push(curr);
            }

            curr[i] = inc;
            if(!dead.count(curr)) {
                dead.insert(curr);
                que.push(curr);
            }
            curr[i] = ch;
        }
    }

    int openLock(vector<string>& deadends, string target) {
        unordered_set<string> dead(begin(deadends), end(deadends));
        // set mein isliye dala taaki baar baar vector ko traverse ke deadends na nikalna pdde
        
        string start = "0000";        
        if(dead.count(start))
            return -1;
        
        queue<string> que;
        que.push(start);
        
        int level = 0;
        while(!que.empty()) {
            int n = que.size();
            
            while(n--) {
                string curr = que.front();
                que.pop();
                if(curr == target)
                    return level;
                
                fillNeighbors(que, curr, dead);
            }
            level++;
        }
        return -1;
    }
};