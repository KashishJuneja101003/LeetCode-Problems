// TC: O(n^3) SC: O(1)
class Solution {
public:
    int countTriples(int n) {
        int triples = 0;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                for (int k = n; k >= 1; k--) {
                    int lhs = i * i + j * j;
                    int rhs = k * k;

                    if (lhs > rhs) {
                        break;
                    }
                    if (lhs == rhs) {
                        triples++;
                    }
                }
            }
        }

        return triples;
    }
};
