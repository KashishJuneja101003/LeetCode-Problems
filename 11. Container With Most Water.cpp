class Solution {
public:
    int maxArea(vector<int>& height) {
        // O(n) using 2 pointer approach
      
        int n = height.size(), maxVol = 0;
        int i=0, j=n-1;
        while(i < j){
            int minHeight = min(height[i], height[j]);
            int width = j-i;
            maxVol = max(maxVol, minHeight*width);
            
            if (height[i] < height[j]) i++;
            else j--;
        }
        return maxVol;
    }
};
