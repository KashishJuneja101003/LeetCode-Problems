class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int n1 = word1.size(), n2 = word2.size();
        string newWord = "";
        int i = 0;

        while(i < n1 || i < n2){
            if(i < n1) newWord += word1[i];
            if(i < n2) newWord += word2[i];
            i++;
        }

        return newWord;
    }
};
