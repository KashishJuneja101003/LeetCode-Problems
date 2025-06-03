// Brute Force Approach
/*
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        set<int> s;
        for(int i:nums){
            s.insert(i);
        }

        int idx = 0;
        for(int i:s){
            nums[idx++] = i;
        }

        return idx;
    }
};
*/

// Two Pointers Approach
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i=0;

        for(int j=1; j<nums.size(); j++){
            if(nums[i] != nums[j]){
                nums[++i] = nums[j];
            }
        }

        return i+1;
    }
};
