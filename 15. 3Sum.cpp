class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(), nums.end());

        vector<vector<int>> uniqueTriplets;

        for(int i=0; i<n; i++){
            if(i > 0 && nums[i] == nums[i-1]) continue;
            int j=i+1, k = n-1;

            while(j < k){
                int sum = nums[i] + nums[j] + nums[k];
                if(sum == 0){
                    vector<int> vec = {nums[i], nums[j], nums[k]};
                    uniqueTriplets.push_back(vec);
                    j++; k--;
                    while(j<k && nums[j]==nums[j-1]) j++;                    
                }
                else if(sum < 0) j++;
                else k--;

            }
        }

        return uniqueTriplets;
    }
};
