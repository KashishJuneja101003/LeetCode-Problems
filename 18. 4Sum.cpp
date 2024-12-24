class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int n = nums.size();

        vector<vector<int>> quads;
        for(int i=0; i<n-3; i++){
            if(i > 0 && nums[i] == nums[i-1]) continue;
            for(int j=i+1; j<n-2; ){
                int p=j+1, q = n-1;

                while(p<q){
                    long long sum = (long long)nums[i]+(long long)nums[j]+(long long)nums[p]+(long long)nums[q];
                    if(sum < target){
                        p++;
                    } else if(sum > target){
                        q--;
                    } else{
                        quads.push_back({nums[i], nums[j], nums[p], nums[q]});
                        p++; q--;
                        while(p<q && nums[p] == nums[p-1]) p++;
                    }
                }
                j++;
                while(j<n && nums[j-1]==nums[j]) j++;
            }
        }

        return quads;
    }
};
