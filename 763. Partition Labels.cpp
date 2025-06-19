class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int> ch_end(26, 0);
        int n = s.size();

        for (int i = 0; i < n; i++) {
            int c = s[i] - 'a';
            ch_end[c] = i;
        }

        int i = 0;
        int l = 0;
        int r = 0;

        vector<int> result;

        while (i < n) {
            int end = ch_end[s[i] - 'a'];
            r = max(r, end);
            
            if (i == r) {
                result.push_back(r - l + 1);
                l = r = ++i;
                continue;
            }
            i++;
        }

        return result;
    }
};
