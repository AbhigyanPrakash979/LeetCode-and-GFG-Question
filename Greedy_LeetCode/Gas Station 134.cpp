class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {

        int balance = 0;
        int deficit =0;
        int start =0;

        for(int i=0; i<gas.size(); i++){
            balance += gas[i]- cost[i];

            //check if the balance is negetive// mtlabe ki aage jaa skta hai ki nhi
            if(balance<0){
                deficit += abs(balance);
                start = i+1;
                // balance ko 0 krna krna pdega kyunki negetive case hai
                balance =0;
            }
        }
        
        //check if the process is possible or not
        if(balance >= deficit){
            return start;
        }
        else{
             return -1;
        }
    }
};