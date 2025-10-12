// TC: O(n) SC: O(1)
class Solution {
public:
    int sumDivisibleByK(vector<int>& nums, int k) {
        vector<int> freq(101, 0);
        for(int& x:nums) freq[x]++;

        int ans = 0;

        for(int x=1; x <= 100; x++){
            if(freq[x]%k == 0){
                ans += (x * freq[x]);
            }
        }
        return ans;
    }
};
