// Approach 1: Brute Force TC: O(n^2) SC: O(1)
/*
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n=nums.size();
        int miss;
        for(int i=0; i<=n; i++){
            bool found = false;
            for(int j=0; j<n; j++){
                if(nums[j] == i){
                    found = true; break; 
                }
            }

            if(!found){
                miss = i;
                break;
            }
        }

        return miss;
    }
};
*/

// Approach 2: Sorting TC: O(n log n) SC: O(1)
/*
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int miss = 0;

        for(int i:nums){
            if(i != miss) break;
            miss++;
        }

        return miss;
    }
};
*/

// Approach 3: Binary Search TC: O(n log n) SC: O(1)
/*
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int l = 0;
        int r = nums.size();

        while(l < r){
            int m = l + (r-l)/2;

            if(nums[m] == m) l = m+1;
            else r = m;
        }

        return l;
    }
};
*/

// Approach 4: Bit Manipulation TC: O(n) SC: O(1)
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int miss = nums.size();

        for(int i=0; i<nums.size(); i++){
            miss ^= i;
            miss ^= nums[i];
        }

        return miss;
    }
};

// Approach 5: Math TC: O(n) SC: O(1)
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int miss = n*(n+1)/2;
        for(int i:nums) miss -= i;
        return miss;
    }
};
