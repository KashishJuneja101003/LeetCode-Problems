// TC: O(1) SC: O(1)
class Solution {
public:
    int findClosest(int x, int y, int z) {
        int t1 = abs(z - x);
        int t2 = abs(z - y);

        if (t1 == t2)
            return 0;
        else if (t1 < t2)
            return 1;
        else
            return 2;
    }
};
