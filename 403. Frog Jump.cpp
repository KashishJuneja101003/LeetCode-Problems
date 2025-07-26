// Recursion TC: O(3^n) SC: O(n)
class Solution {
public:
    bool check(vector<bool>& present, int curr, int n, int k){
        // If reached at last stone, return true
        if(curr == n) return true;

        // Check whether stone is present after (k-1)th, kth and (k+1)th jump from current 
        bool minusOne = false, equal = false, plusOne = false;
        if(curr + k-1 <= n && curr + k-1 != curr && present[curr + k-1]) {
            minusOne = check(present, curr + k-1, n, k-1);
        }
        
        if(curr + k <= n && present[curr + k]) {
            equal = check(present, curr + k, n, k);
        }
        if(curr + k+1 <= n && present[curr + k+1]) {
            plusOne = check(present, curr + k+1, n, k+1);
        }

        return (minusOne || equal || plusOne);
    }
    bool canCross(vector<int>& stones) {
        int last = stones[stones.size()-1];
        vector<bool> present(last+1, false);

        if(stones[1] != 1) return false;
        
        for(int i:stones){
            present[i] = true;
        }

        return check(present, 0, last, 1);
    }
};
