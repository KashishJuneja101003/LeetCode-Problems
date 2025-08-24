class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n = nums.size();
        if (n == 1)
            return 0;

        int left = 0;
        int right = 0;

        int maxLen = 0;

        int numZeroes = 0;

        while (right < n) {
            if (nums[right] == 0)
                numZeroes++;

            // Shrink the window
            while (numZeroes > 1) {
                if (nums[left] == 0)
                    numZeroes--;
                left++;
            }

            maxLen = max(maxLen, right - left);

            right++;
        }

        return maxLen;
    }
};
