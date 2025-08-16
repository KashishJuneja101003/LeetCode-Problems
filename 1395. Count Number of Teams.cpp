// BF TC: O(n^3) SC: O(1)
class Solution {
public:
    int numTeams(vector<int>& rating) {
        int n = rating.size();
        int count = 0;
        for (int i = 0; i < n - 2; i++) {
            for (int j = i + 1; j < n - 1; j++) {
                for (int k = j + 1; k < n; k++) {
                    int ri = rating[i];
                    int rj = rating[j];
                    int rk = rating[k];

                    if((ri < rj && rj < rk) || (ri > rj && rj > rk)) count++;
                }
            }
        }

        return count;
    }
};

// Optimized TC: O(n^2) SC: O(n)
class Solution {
public:
    int numTeams(vector<int>& rating) {
        int n = rating.size();
        int count = 0;
        vector<int> smallLeft(n);
        vector<int> largeLeft(n);
        vector<int> smallRight(n);
        vector<int> largeRight(n);

        for (int i = 0; i < n; i++) {
            int cs = 0;
            int cl = 0;

            for (int j = 0; j < i; j++) {
                if (rating[j] < rating[i])
                    cs++;
                else
                    cl++;
            }
            smallLeft[i] = cs;
            largeLeft[i] = cl;
        }

        for (int i = 0; i < n; i++) {
            int cs = 0;
            int cl = 0;
            for (int j = i+1; j < n; j++) {
                if (rating[j] > rating[i])
                    cl++;
                else
                    cs++;
            }
            largeRight[i] = cl;
            smallRight[i] = cs;
        }

        for (int i = 0; i < n; i++) {
            count += (smallLeft[i] * largeRight[i]);
            count += (smallRight[i] * largeLeft[i]);
        }
        return count;
    }
};
