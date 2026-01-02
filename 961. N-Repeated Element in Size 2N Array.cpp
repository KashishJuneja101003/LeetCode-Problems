// TC: O(n) SC: O(1)
class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        vector<int> freq(1e4+1, 0);
        int n = nums.size()/2;
        
        for(int& i:nums){
            freq[i]++;

            if(freq[i] == n) return i;
        }

        return -1;
    }
};
