class Solution {
public:
    bool rotateString(string s, string goal) {
        string newS = s + s;
        return (s.length() == goal.length() && (newS.find(goal) != string::npos));
    }
};
