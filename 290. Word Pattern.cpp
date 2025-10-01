class Solution {
public:
    bool wordPattern(string pattern, string s) {
        int r = 0;
        s += " ";
        int n = s.size();

        unordered_map<string, char> mapping1;
        unordered_map<char, string> mapping2;

        int i=0;
        for (i=0; i < pattern.size(); i++) {
            char c = pattern[i];
            string word = "";
            while (r <= n) {
                if (s[r] == ' ') {
                    if(mapping1.find(word) == mapping1.end()) {
                        mapping1[word] = c;
                    } else{
                        if(mapping1[word] != c) return false;
                    }

                    if(mapping2.find(c) == mapping2.end()) {
                        mapping2[c] = word;
                    } else{
                        if(mapping2[c] != word) return false;
                    }

                    word = "";
                    r++; break;
                } else{
                    word += s[r];
                }
                r++;
            }

            if(r == n) break;
        }

        if(r < n || i < pattern.size()-1) return false;
        return true;
    }
};
