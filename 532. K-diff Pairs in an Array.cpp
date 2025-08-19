class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());

        int n = nums.size();
        int i = 0;
        int j = 1;
        int count = 0;

        while (i < n && j < n) {
            if (i == j) {
                j++;
                continue;
            }

            int diff = nums[j] - nums[i];

            if (diff == k) {
                count++;
                int curr = nums[j];
                while (j < n && nums[j] == curr)
                    j++;
                curr = nums[i];
                while (i < n && nums[i] == curr)
                    i++;
            } else if (diff < k)
                j++;
            else
                i++;
        }

        return count;
    }
};
