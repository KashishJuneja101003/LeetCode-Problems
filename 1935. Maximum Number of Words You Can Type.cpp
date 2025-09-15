class Solution {
public:
    int canBeTypedWords(string text, string brokenLetters) {
        int count = 0;
        int right = 0;

        int n = text.size();

        unordered_set<char> broken;
        for(char& c:brokenLetters) broken.insert(c);

        while(right < n){
            // Broken letter present, skip the word
            if(broken.find(text[right]) != broken.end()){
                while(right < n && text[right] != ' ') right++;
                right++;
                continue;
            }

            // If we exhaust a word, it is not broken, so count++
            if(right == n-1 || text[right] == ' ') {
                count++;
            }

            right++;
        }

        return count;
    }
};
