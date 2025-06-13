// Backtracking: TC: O(n * n!) Total Space: O(n * n!) Auxiliary Space: O(n)
/*
class Solution {
public:
    void getPermutations(vector<int>& temp, vector<int>& nums, unordered_set<int>& st, vector<vector<int>>& allPermutations){
        if(temp.size() == nums.size()){
            allPermutations.push_back(temp);
            return;
        }

        for(int i=0; i<nums.size(); i++){
            int el = nums[i];
            if(st.find(el) == st.end()){
                temp.push_back(el);
                st.insert(el);
                getPermutations(temp, nums, st, allPermutations);

                // Backtracking Step
                temp.pop_back();
                st.erase(el);
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> temp;
        vector<vector<int>> allPermutations;
        unordered_set<int> st;

        getPermutations(temp, nums, st, allPermutations);
        return allPermutations;
    }
};
*/

// Approach 2: TC: O(n*n!) SC: O(n) of Recursion
class Solution {
public:
    void getPermutations(vector<vector<int>>& allPermutations, vector<int>& nums, int idx){
        if(idx == nums.size()){
            allPermutations.push_back(nums);
            return;
        }

        for(int i=idx; i<nums.size(); i++){
            swap(nums[i], nums[idx]);
            getPermutations(allPermutations, nums, idx+1);

            // BT Step
            swap(nums[i], nums[idx]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> allPermutations;
        
        getPermutations(allPermutations, nums, 0);
        return allPermutations;
    }
};
