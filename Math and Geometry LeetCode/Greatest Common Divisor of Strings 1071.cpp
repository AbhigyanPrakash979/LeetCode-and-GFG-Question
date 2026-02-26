class Solution {
public:
    // gcd function (Euclidean algorithm) 
    // yahn pr dono ke sizes milein jispr humne gcs lgaya
    int gcd(int a, int b) {
        while (b != 0) {
            int temp = a % b;
            a = b;
            b = temp;
        }
        return a;
    }

    string gcdOfStrings(string str1, string str2) {
        // Step 1: check karte hain ki dono strings ek hi base repeat se bane hain ya nahi
        // agar str1+str2 != str2+str1 hai -> matlab koi common divisor string exist nahi karti
        if (str1 + str2 != str2 + str1) {
            return ""; // no gcd string
        }

        // Step 2: gcd length nikalna (jaise numbers ka gcd hota hai)
        int gcdLen = gcd(str1.size(), str2.size());

        // Step 3: str1 ke first gcdLen characters hi answer honge
        return str1.substr(0, gcdLen);
    }

   
};