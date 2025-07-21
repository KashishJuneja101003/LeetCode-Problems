class Solution {
public:
    string makeFancyString(string s) {
        char cand;
        int freq = 0;

        string newS = "";

        for(char& c:s){
            if(c != cand){
                cand = c;
                freq = 0;
            }
            if(freq == 2) continue;
            newS += c;
            freq++;
        }

        return newS;
    }
};
