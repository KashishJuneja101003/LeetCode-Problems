// Approach 1: TC: O(n) SC: O(1)
class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> freq(10e5 + 1, 0);
        for (int i : nums)
            freq[i]++;
        vector<int> result;
        for (int i = 1; i < 10e5 + 1; i++)
            if (freq[i] == 2)
                result.push_back(i);
        return result;
    }
};

// Approach 2: TC: O(n) SC: O(1) => More Efficient
class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> result;
        for (int i = 0; i < nums.size(); i++){
            int idx = abs(nums[i]) - 1;
            if(nums[idx] < 0) result.push_back(abs(nums[i]));
            else nums[idx] *= -1;
        }
        return result;
    }
};
