class Solution {
public:
    set<vector<int>> s;
    void helper(vector<int>& cand, int tar, vector<vector<int>>& ans, vector<int>& vec, int i){
        if(i == cand.size() || 0 > tar){
            return;
        }

        if(0 == tar){
            if(s.find(vec) == s.end()){
                ans.push_back({vec});
                s.insert(vec);
            }
            return;
        }

        vec.push_back(cand[i]);

        // Single Inclusion
        helper(cand, tar-cand[i], ans, vec, i+1);

        // Multiple Inclusion
        helper(cand, tar-cand[i], ans, vec, i);

        // Exclusion
        vec.pop_back(); // Backtracking Step
        helper(cand, tar, ans, vec, i+1);
    }

    vector<vector<int>> combinationSum(vector<int>& cand, int tar) {
        vector<vector<int>> ans;
        vector<int> vec;
        helper(cand, tar, ans, vec, 0);
        return ans;
    }
};
