// Approach 1: Linear Search: TC: O(n) SC: O(1)
/*
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        for(int i=0; i<n; i++){
            if(nums[i] == target) return i;
        }

        return -1;
    }
};
*/
    
// Approach 2: BS TC: O(log n) SC: O(1)
class Solution {
public:
    int search(vector<int>& arr, int target) {
        int start = 0, end = arr.size()-1;

        while(start <= end){
            int mid = start + (end-start)/2;

            if(arr[mid] == target) return mid;
            else if(arr[mid] > target) end = mid-1;
            else start = mid+1;
        }

        return -1;
    }
};
