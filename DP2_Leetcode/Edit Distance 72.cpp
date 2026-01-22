class Solution {
public:
    int m, n;

    // i==m mtlab s1 ke end tak aagya hoon aur s2 pdda hua hai , aur humme pura exact match krna pdega
    // islye baaki ke operations ke liye hum s2 ki length mein se delete krna pdega baaki  ka j jitna
    //    pdda hua hai
    // toh compensate kitna aur operations krna baaki hai
    int solve(string& s1, string& s2, int i, int j, vector<vector<int>> &dp) {
        if(i == m) {
            return n-j; // insert in s1
        } else if(j == n) {
            return m-i; // delete from s1
        }

        // agar dp mein already answer pada hai toh wahi return krdo
        if(dp[i][j] != -1){
            return dp[i][j];
        }

        if(s1[i] == s2[j]) {
            dp[i][j] = solve(s1, s2, i+1, j+1, dp);
        } else {
            // j+1 kyunki ho skta hai s2 ke next element se match hojaye
            int insertC = 1 + solve(s1, s2, i, j+1, dp); 
            // i+1 kyunki j ko abhi tak match nhi kiya hai i+1 badhane ke baad dekhenge
            int deleteC = 1 + solve(s1, s2, i+1, j, dp);
            // i+1, j+1 kyunki replace toh kr diya he diya match toh ho he jayega toh dono aage badhao
            int replaceC = 1 + solve(s1, s2, i+1, j+1, dp);

            dp[i][j] = min({insertC, deleteC, replaceC});
        }

        // maan letein by chance aga nhi mila vrna zarurui bhi nhi hai
        return dp[i][j];
    }

    int minDistance(string s1, string s2) {
        m = s1.length();
        n = s2.length();

        // dp table banayenge aur -1 se initialize krdenge
        vector<vector<int>> dp(m, vector<int>(n, -1));

        return solve(s1, s2, 0, 0, dp);
    }
};