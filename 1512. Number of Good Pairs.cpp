// Brute Force
// TC: O(n^2) SC: O(1)
/*
class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        int numPairs = 0;
        int n = nums.size();
        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                if(nums[i] == nums[j]){
                    numPairs++;
                }
            }
        }
        return numPairs;
    }
};
*/

// Using hashmap
// TC: O(n) SC: O(n)
class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        vector<int> freq(101, 0);
        int numPairs = 0;
        int n = nums.size();
        for(int i=0; i<n; i++){
            numPairs += freq[nums[i]];
            freq[nums[i]]++;
        }
        return numPairs;
    }
};
