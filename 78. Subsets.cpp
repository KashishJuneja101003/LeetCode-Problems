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
        getSubs(nums, result, ans, i+1);
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> ans;
        getSubs(nums, result, ans, 0);
        return result;
    }
};
