class Solution {
public:
    void getSubs(vector<int>& nums, vector<vector<int>>& result, vector<int>& ans, int i){
        // Base Case
        if(nums.size() == i){
            result.push_back({ans});
            return;
        }

        // Include
        ans.push_back(nums[i]);
        getSubs(nums, result, ans, i+1);

        // Backtracking
        ans.pop_back();

        // Exclude
        while(i < nums.size()-1 && nums[i] == nums[i+1]) i++;
        
        getSubs(nums, result, ans, i+1);
    }


    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        vector<vector<int>> result;
        vector<int> ans;
        getSubs(nums, result, ans, 0);
        return result;

    }
};
