// TC: O(n) SC: O(n)
class Solution {
public:
    int findFinalValue(vector<int>& nums, int original) {
        unordered_set<int> st;

        for(int& i:nums) st.insert(i);

        while(st.find(original) != st.end()){
            original *= 2;
        }

        return original;
    }
};
