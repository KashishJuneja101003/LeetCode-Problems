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

// Approach 2: Boolean Vector TC: O(n) SC: O(n)
/*
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        vector<bool> integers(n+2, false);

        for(int i:nums){
            if(i > 0 && i <= n+1) integers[i] = true;
        }

        for(bool b:integers){
            cout<<b<<" ";
        }

        for(int i=1; i<n+2; i++){
            if(!integers[i]) return i;
        }

        return -1;
    }
};
*/

// Approach 3: TC: O(n) SC: O(1)
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        bool hasOne = false;

        for(int i=0; i<n; i++){
            if(nums[i] == 1) hasOne = true;
            else if(nums[i] < 1 || nums[i] > n) nums[i] = 1;
        }

        if(!hasOne) return 1;

        for(int i=0; i<n; i++){
            int idx = abs(nums[i])-1;
            if(nums[idx] > 0) nums[idx] *= -1;
        }

        for(int i=0; i<n; i++){
            if(nums[i] > 0) return i+1;
        }

        return n+1;
    }
};
