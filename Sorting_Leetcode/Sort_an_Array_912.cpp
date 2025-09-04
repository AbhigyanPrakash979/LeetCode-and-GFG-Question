//merge sort

class Solution {
public:
    void merge(vector<int>& nums, int start, int end){

        int mid = (start+end)/2;
        int leftLength = mid -start +1;
        int rightLength = end - mid;

        //creating dynamic array
        int* leftArray = new int[leftLength];
        int* rightArray = new int[rightLength];

        //now copying values to left and right 
        int k = start;
        for(int i = 0; i<leftLength; i++){
            leftArray[i] = nums[k];
            k++;
        }

        k = mid+1;
        for(int i = 0; i<rightLength; i++){
            rightArray[i] = nums[k];
            k++;
        }

        //merge logic
        int leftIndex =0;
        int rightIndex =0;
        int mainArrayIndex = start;

        while(leftIndex < leftLength && rightIndex < rightLength){
            if(leftArray[leftIndex] < rightArray[rightIndex]){
                nums[mainArrayIndex++] = leftArray[leftIndex++];
            }
            else{
                    nums[mainArrayIndex++] = rightArray[rightIndex++];
            }
        }
        //for left-out array element
        while(leftIndex < leftLength){
            nums[mainArrayIndex++] = leftArray[leftIndex++];
        }
        while(rightIndex < rightLength){
            nums[mainArrayIndex++] = rightArray[rightIndex++];
        }

        delete[] leftArray;
        delete[] rightArray;

    }

    void mergeSort(vector<int>& nums, int start, int end){
        //base case
        if(start>= end){
            return;
        }

        //mid logic
        int mid = (start + end)/2;

        //left rr
        mergeSort(nums, start, mid);

        //right rr
        mergeSort(nums, mid+1, end);

        //now merging
        merge(nums, start, end);

    }

    vector<int> sortArray(vector<int>& nums) {

        int start =0;
        int end = nums.size()-1 ;
        mergeSort(nums, start, end);
        return nums;
    }
};




// Quick SOrt Logic

class Solution {
public:
    int partition(vector<int> &nums, int start, int end){
        int pivotIndex = start;
        int pivotElement = nums[pivotIndex];

        // Count elements less than pivot
        int count = 0;
        for(int i = start + 1; i <= end; i++){
            if(nums[i] < pivotElement){
                count++;
            }
        }

        // Place pivot at correct position
        int correctIndex = start + count;
        swap(nums[pivotIndex], nums[correctIndex]);
        pivotIndex = correctIndex;
        pivotElement = nums[pivotIndex];  // ✅ Update pivotElement after swap

        // Partition the array using two pointers
        int i = start;
        int j = end;

        while (i < pivotIndex && j > pivotIndex) {
            while (i < pivotIndex && nums[i] < pivotElement) {
                i++;
            }
            while (j > pivotIndex && nums[j] > pivotElement) {
                j--;
            }
            if (i < pivotIndex && j > pivotIndex) {
                swap(nums[i], nums[j]);
                i++;
                j--;
            }
        }


        return pivotIndex;
    }

    void quickSort(vector<int> &nums, int start, int end){
        if(start >= end){
            return;
        }

        int part = partition(nums, start, end);
        quickSort(nums, start, part - 1);
        quickSort(nums, part + 1, end);
    }

    vector<int> sortArray(vector<int>& nums) {
        quickSort(nums, 0, nums.size() - 1);
        return nums;
    }
};


