class Solution {
public:
    bool isSubsequence(string s, string t) {
        int i = 0;
        int j = 0;
        int n1 = s.size();
        int n2 = t.size();

        if(n2 < n1) return false;

        while(i < n1 && j < n2){
            while(j < n2 && t[j] != s[i]) j++;
            if(j == n2) return false;
            i++; j++;
        }

        return i == n1;
    }
};
