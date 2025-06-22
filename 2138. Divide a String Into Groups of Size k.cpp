// Approach 1: TC: O(n) SC: O(n)
class Solution {
public:
    vector<string> divideString(string s, int k, char fill) {
        string str = "";
        vector<string> vec;
        for (int i = 0; i < s.size(); i++) {
            if (str.size() == k) {
                vec.push_back(str);
                str = "";
            }

            str += s[i];
        }

        while (str.size() < k)
            str += fill;

        vec.push_back(str);
        str = "";
        return vec;
    }
};
