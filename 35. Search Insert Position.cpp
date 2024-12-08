class Solution {
public:
    int searchInsert(vector<int>& arr, int target) {
        int start = 0, end = arr.size()-1, result;

        while(start <= end){
            int mid = start + (end-start)/2;

            if(arr[mid] <= target){
                result = mid;
                start = mid+1;
            }
            else end = mid-1;
        }

        if(end == -1) return 0;
        return (arr[result] == target) ? result : result+1;
    }
};
