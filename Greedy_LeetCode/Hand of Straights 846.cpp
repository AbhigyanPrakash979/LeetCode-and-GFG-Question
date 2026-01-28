//Approach (Simply using map)
//T.C  : O(nlogn) + O(n*groupSize)
//S.C  : O(n)
class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int n = hand.size();

        if(n % groupSize !=0) { // mtlab uss particular group size mein divide nhi hopaya
            return false;
        }

        map<int, int> mp;   // ordered map
        for(int &handNumber : hand) {
            mp[handNumber]++; //O(nlogn) kyunki n elements log n time le rhe hai
        }

        while(!mp.empty()) { //O(n*groupSize)
            int curr = mp.begin()->first; //->second : frequency
                for(int i = 0; i < groupSize; i++) {
                    // curr+i kyunki i agar 0 hai toh voh agle vale ko point krega and so on
                    if(mp[curr + i] == 0) { 
                        return false;
                    }

                    mp[curr+i]--; // mtlab curr+i use krliya aur mp mein se 1 ka krdo
                    if(mp[curr+i] < 1) {
                        mp.erase(curr+i); // map mei se entry htta do kyunki use hogya
                    }
                }

        }

        return true;
        
    }
};