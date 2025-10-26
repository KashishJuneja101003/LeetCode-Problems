class Solution {
public:
    string lexSmallest(string s) {
        int n = s.size();
        string ans = s;
        string s1 = s;
        string s2 = s;

        for (int k = 1; k <= n; k++) {
            s1 = s;
            s2 = s;
            reverse(s1.begin(), s1.begin() + k);
            reverse(s2.begin() + n - k, s2.end());

            ans = min({ans, min(s1, s2)});
        }

        return ans;
    }
};
