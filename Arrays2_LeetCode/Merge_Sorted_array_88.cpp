
// method 2
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = m - 1;
        int j = n - 1;
        int k = m + n - 1;

        while (i >= 0 && j >= 0) {
            if (nums1[i] > nums2[j]) {
                nums1[k] = nums1[i];
                k--;
                i--;
            } else {
                nums1[k] = nums2[j];
                k--;
                j--;
            }
        }

        while (j >= 0) {
            nums1[k] = nums2[j];
            k--;
            j--;
        }
    }
};





// method 1
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        
        int leftIndex = 0;
        int rightIndex = 0;
        vector<int> mainArray;
        while(leftIndex < m && rightIndex <n){
            if(nums1[leftIndex] <= nums2[rightIndex]){
                mainArray.push_back(nums1[leftIndex]);
                leftIndex++;
            }
            else{
                    mainArray.push_back(nums2[rightIndex]);
                    rightIndex++;
            }   
        }

        //Agar nums1 mein kuch khaali reh gya ho toh
        while(leftIndex < m){
            mainArray.push_back(nums1[leftIndex]);
            leftIndex++;
            
        }

        //Agar nums2 mein kuch khaali reh gya ho toh
        while(rightIndex < n){
            mainArray.push_back(nums2[rightIndex]);
            rightIndex++;
        }

        for(int i=0; i<m+n;i++){
            nums1[i] = mainArray[i];
        }
        
    }
};