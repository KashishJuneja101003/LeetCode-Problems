// TC: O(n^2) SC: O(1)
class Solution {
public:
    int countHillValley(vector<int>& nums) {
        int count = 0;
        int n = nums.size();
        // vector<char> v(n);

        for(int i=1; i<n; i++){
            int curr = nums[i];
            int left = -1;
            int right = -1;

            // Check on left
            for(int j=i-1; j>=0; j--){
                if(nums[j] != curr){
                    left = nums[j];
                    break;
                }
            }

            // Check on right
            for(int k=i+1; k<n; k++){
                if(nums[k] != curr){
                    right = nums[k];
                    break;
                }
            }

            // If left or right is -1, curr is neither a hill nor a valley
            if(left == -1 || right == -1) {
              // v[i] = 'x'; 
              continue;
            }

            // If left and right both are less than curr, it is a hill
            if(left < curr && right < curr) {
              // v[i] = 'H';
              count++;
            }

            // If left and right both are greater than curr, it is a valley
            if(left > curr && right > curr) {
              // v[i] = 'V'; 
              count++;
            }

            // If nums[i] == nums[i+1], they're part of same hill or valley, this i++
            while(i+1 < n && nums[i] == nums[i+1]) {
              // v[i+1] = 'x';
              i++;
            }
        }

        // for(char c:v) cout<<c<<" ";
        return count;
    }
};


// Remove duplicates TC: O(n) SC: O(n)
class Solution {
public:
    int countHillValley(vector<int>& nums) {
        int count = 0;
        int n = nums.size();
        vector<int> nums1;

        int last = -1;
        for(int& i:nums){
            if(i != last){
                nums1.push_back(i);
                last = i;
            }
        }

        for(int i=1; i<nums1.size()-1; i++){
            int curr = nums1[i];
            int left = nums1[i-1];
            int right = nums1[i+1];

            // If hill or valley, count++
            if((curr < left && curr < right) || (curr > left && curr > right)) count++;
        }

        return count;
    }
};
