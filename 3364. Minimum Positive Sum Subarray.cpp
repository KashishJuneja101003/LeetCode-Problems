class Solution {
public:
    int minimumSumSubarray(vector<int>& nums, int l, int r) {
        long int minSum = INT_MAX;
        int n = nums.size();

        while(l <= r){
            int left = 0, right = 0;
            int currentWindowSize = l;
            long int sum = 0;
            while(right < n){
                sum += nums[right];

                if(right-left+1 < currentWindowSize){right++;}
                else if(right-left+1 == currentWindowSize){
                    if(sum > 0) minSum = min(minSum, sum);
                    sum -= nums[left];
                    left++; right++;
                }
            }
            l++;
        }

        return (minSum == INT_MAX) ? -1 : minSum;
    }
};
