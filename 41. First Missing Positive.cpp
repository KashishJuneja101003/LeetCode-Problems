// Approach 1: Hashset TC: O(n) SC: O(n)
/*
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        unordered_set<int> st;
        for(int i:nums){
            if(i > 0) st.insert(i);
        }

        int num;
        for(num = 1; num<INT_MAX; num++){
            if(st.find(num) == st.end()) break;
        }
        return num;
    }
};
*/
