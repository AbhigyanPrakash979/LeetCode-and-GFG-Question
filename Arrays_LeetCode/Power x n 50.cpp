class Solution {
public:
    double solve(double x, long n){
        //base case
        if(n==0){
            return 1;
        }
        if(n<0){                // if n is negetove
            return solve(1/x, -n);
        }
        else if(n%2 == 0){      // if n is even
            return solve(x*x, n/2);
        }
        else{                   // if n is off
            return x*solve(x*x, (n-1)/2);
        }
    }
    double myPow(double x, int n) {
    //explicit conversion to long bcoz range se bahr chal jayega   
    return solve(x, (long)n);
    }
};