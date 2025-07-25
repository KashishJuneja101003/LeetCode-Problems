// TC: O(n log n + m log m + min(n, m)) SC: O(1)
class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());

        int i = 0;
        int j = 0;

        int content = 0;

        while(i < g.size() && j < s.size()){
            // Increment the size of the cookie until the greed of a child can't be satisfied
            if(s[j] < g[i]) {j++; continue;}

            // Cookie can satisfy the greed
            // Number of contented children incremented by 1
            // Look for next child (i++) and try to assign next cookie (j++)
            content++; i++; j++;
        }

        return content;
    }
};
