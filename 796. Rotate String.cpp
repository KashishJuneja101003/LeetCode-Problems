class Solution {
public:
    bool rotateString(string s, string g) {
        string ss = s+s;
        return (s.size() == g.size()) && (ss.find(g) != string::npos);
    }
};
