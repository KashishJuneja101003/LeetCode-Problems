class Solution {
public:
    int lengthOfLastWord(string s) {
        int j=s.size()-1;
        while(s[j] == ' ') j--;
        
        int length = 0;
        while(j >= 0 && s[j] != ' '){
            j--; length++;
        }

        return length;
    }
};
