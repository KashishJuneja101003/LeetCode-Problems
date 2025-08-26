// TC: O(n) SC: O(1)
class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
        int area = 0;
        int diagonal = 0;

        for (auto& vec : dimensions) {
            int l = vec[0];
            int b = vec[1];

            int lsq = l * l;
            int bsq = b * b;

            int currDiagonal = lsq + bsq;
            int currArea = l * b;

            if (currDiagonal > diagonal) {
                diagonal = currDiagonal;
                area = currArea;
            } else if (currDiagonal == diagonal) {
                area = max(area, currArea);
            }
        }

        return area;
    }
};
