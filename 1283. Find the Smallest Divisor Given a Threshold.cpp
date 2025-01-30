class Solution {
public:
    int divisionSum(vector<int>& nums, int d){
        int sum = 0;

        for(int i:nums) {
            sum += (ceil((double)i/d));
        }
        return sum;
    }

    int smallestDivisor(vector<int>& nums, int threshold) {
        int n = nums.size();

        // Find maximum element in array and initialize end with that element
        int start = 1, end = *max_element(nums.begin(), nums.end());
        int smallestDivisor = -1;

        // Loop to find the smallest divisor
        while(start <= end){
            int mid = start + (end-start)/2;

            if(divisionSum(nums, mid) <= threshold){
                smallestDivisor = mid;
                end = mid-1;
            } else{
                start = mid+1;
            }
        }

        return smallestDivisor;
    }
};
