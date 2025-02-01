class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();

        // Edge Case
        if(n == 0 || n == 1){
            return n;
        }

        unordered_set<int> s;
        for(int i:nums) {
            s.insert(i);
        }

        int maxLength=1;
        for(auto it:s){
            if(s.find(it-1) == s.end()){
                int count = 0, x = it;

                while(s.find(x+1) != s.end()){
                    count++; x++;
                }

                maxLength = max(maxLength, count+1);
            }
        }

        return maxLength;
    }
};
