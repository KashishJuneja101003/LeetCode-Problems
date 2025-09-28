// TC: O(n) SC: O(1)
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int n = nums.size();
        int left = 0;
        int right = n-1;

        while(left <= right){
            if(nums[left] != val) {
                left++;
                continue;
            }

            if(nums[right] == val){
                right--;
                continue;
            }

            swap(nums[left], nums[right]);
        }

        return left;
    }
};
