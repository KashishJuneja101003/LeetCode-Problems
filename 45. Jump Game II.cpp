class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();

        // Base Case
        if(n == 1) return 0;
        
        int goal = n-1;
        int farthest = 0;
        int minJumps = 0;
        int currentGoal = 0;

        for(int i = 0; i < n; i++){
            farthest = max(farthest, i + nums[i]);

            if(i == currentGoal){
                minJumps++;
                currentGoal = farthest;

                if(currentGoal >= goal) break;
            }
        }

        return minJumps;
    }
};
