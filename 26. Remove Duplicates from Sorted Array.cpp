class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n=nums.size();
        int i = 0, current = nums[i], j = 0, count = 0;

        while(i < n){
            if(nums[i] == current){
                if(count == 0){
                    nums[j] = current;
                    count++; i++; j++;
                }
                else{
                    i++;
                }
            } 
            else{
                current = nums[i];
                count = 0;
            }           
        }

        return j;
    }
};
