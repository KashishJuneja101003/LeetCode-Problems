// TC: O(m*n) SC: O(1)
class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();

        vector<int> ans;
        bool reverseFlag = true;

        int j = 0;

        while (j < n) {
            int x = 0;
            int y = j;
            int idx = ans.size();

            // cout<<x<<" "<<y<<"\n";
            while (x < m && y >= 0) {
                ans.push_back(mat[x][y]);
                x++;
                y--;
            }

            if (reverseFlag)
                reverse(ans.begin() + idx, ans.end());
            j++;

            reverseFlag = !reverseFlag;
        }

        int i = 1;
        while (i < m) {
            int x = i;
            int y = n - 1;
            int idx = ans.size();

            while (x < m && y >= 0) {
                ans.push_back(mat[x][y]);
                x++;
                y--;
            }

            if (reverseFlag)
                reverse(ans.begin() + idx, ans.end());
            i++;

            reverseFlag = !reverseFlag;
        }

        return ans;
    }
};
