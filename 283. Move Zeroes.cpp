// Approach 1: Brute Force (Not in-place) TC: O(n) SC: O(n)
/*
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size();
        vector<int> nums1(n, 0);
        int idx = 0;
        for(int i:nums){
            if(i != 0) nums1[idx++] = i;
        }
        idx = 0;
        for(int i:nums1){
            nums[idx] = nums1[idx];
            idx++;
        }
    }
};
*/

// Approach 2: Two Pointers TC: O(n) SC: O(1)
/*
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int currZero = 0;
        int currNonZero = 0;
        int size = nums.size();

        while(currZero < size && currNonZero < size){
            if(nums[currZero] != 0){
                currZero++; continue;
            }

            if(nums[currNonZero] == 0){
                currNonZero++; continue;
            }

            if(currNonZero < currZero){
                currNonZero++; continue;
            }

            swap(nums[currZero], nums[currNonZero]);
        }
    }
};
*/

// Approach 3: Single Pass (without swap) TC: O(n) SC: O(1)
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int insertPos = 0;
        int n = nums.size();

        for(int i=0; i<n; i++){
            if(nums[i] != 0){
                nums[insertPos++] = nums[i];
            }
        }

        while(insertPos < n){
            nums[insertPos++] = 0;
        }
    }
};
