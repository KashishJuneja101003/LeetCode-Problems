// Approach 1: TC: O(n) SC: O(n)
class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        int n = nums.size();        
        vector<int> runSum(n);
        runSum[0] = nums[0];

        for(int i=1; i<n; i++) runSum[i] = runSum[i-1] + nums[i];

        return runSum;
    }
};
