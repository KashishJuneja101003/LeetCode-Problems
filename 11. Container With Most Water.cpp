// Approach 1: Brute Force TC: O(n^2) SC: O(1)
/*
class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int maxArea = 0;
        for(int i=0; i<n; i++){
            int ht = height[i];
            for(int j=i+1; j<n; j++){
                int ht2 = height[j];
                ht2 = (ht2 <= ht) ? ht2 : ht;
                int area = ht2 * (j-i);
                maxArea = max(maxArea, area);
            }
        }

        return maxArea;
    }
};
*/

// Approach 2: Two Pointers TC: O(n) SC: O(1)
class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int i = 0;
        int j = n-1;
        int maxArea = 0;
        
        while(i < j){
            int h = min(height[i], height[j]);
            int w = j-i;
            int area = h*w;
            maxArea = max(maxArea, area);
            if(height[i] < height[j]) i++;
            else j--;
        }

        return maxArea;
    }
};
