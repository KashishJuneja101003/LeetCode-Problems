// TC: O(n) SC: O(n)
class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> num_idx;

        for(int i=0; i<n; i++){
            if(num_idx.find(nums[i]) != num_idx.end()){
                if(i - num_idx[nums[i]] <= k){
                    return true;
                }
            }

            num_idx[nums[i]] = i;
        }

        return false;
    }
};
