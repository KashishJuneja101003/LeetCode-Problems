// TC: O(n logn) SC: O(1)
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return nums[0];

        sort(nums.begin(), nums.end());

        for(int i=0; i<n-2; i+=3){
            if(nums[i] != nums[i+2]) return nums[i];
        }

        return nums[n-1];
    }
};

// TC: O(n) SC: O(k)
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return nums[0];

        unordered_map<int, int> freq;

        for(int i:nums) freq[i]++;

        for(auto& it:freq){
            if(it.second == 1) return it.first;
        }

        return -1;
    }
};
