// Approach 1: Brute Force TC: O(n^2) SC: O(1)
/*
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();

        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                if(nums[i] + nums[j] == target){
                    return {i+1, j+1};
                }
            }
        }

        return {};
    }
};
*/

// Approach 2: Using Hashmap TC: O(n) SC: O(n)
/*
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        unordered_map<int, int> el_idx;

        for(int i=0; i<n; i++){
            int rem = target-nums[i];

            if(el_idx.find(rem) != el_idx.end()){
                return {el_idx[rem]+1, i+1};
            }

            el_idx[nums[i]] = i;
        }

        return {};
    }
};
*/

// Approach 3: Two Pointers TC: O(n) SC: O(1)
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();

        int left = 0;
        int right = n-1;

        while(left < right){
            int sum = nums[left]+nums[right];

            if(sum == target){
                return {left+1, right+1};
            } else if (sum < target){
                left++;
            } else {
                right--;
            }
        }
        
        return {};
    }
};
