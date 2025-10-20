class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int el = k;

        for(int& i:nums){
            if(i == el) el += k;
        }

        return el;
    }
};
