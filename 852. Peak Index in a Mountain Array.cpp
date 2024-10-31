class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int start = 1, end = arr.size()-2;
        while(start <= end){
            int mid = start + (end-start)/2;

            // If left < mid > right, return mid
            if (arr[mid-1] < arr[mid] && arr[mid] > arr[mid+1]) return mid;
            else if (arr[mid-1] > arr[mid]) end = mid-1;    //If mid-1 > mid, the peak must be at LHS
            else if (arr[mid+1] > arr[mid]) start = mid+1;  // If mid+1 > mid, the peak must be at RHS
        }
        return -1; // The control will never come here since the peak element always exists
    }
};
