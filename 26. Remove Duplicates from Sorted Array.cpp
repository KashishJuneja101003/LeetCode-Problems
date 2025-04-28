class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int currentElement = nums[0];
        int currentIndex = 0;
        int idx = 1;
        while(idx != nums.size()){
            if(nums[idx] != currentElement){
                swap(nums[++currentIndex], nums[idx]);
                currentElement = nums[currentIndex];
            }
            idx++;
        }
        
        return currentIndex+1;
    }
};
