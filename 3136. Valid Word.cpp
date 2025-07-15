class Solution {
public:
    bool isValid(string word) {
        int n = word.size();

        if(n < 3) return false;

        bool isVowel = false;
        bool isConsonant = false;
        
        for(char& c:word){
            if(isdigit(c)) {continue;}
            else if(isalpha(c)){
                c = tolower(c);
                if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') isVowel = true;
                else isConsonant = true; 
            } else{
                return false;
            }
        }
        return isVowel && isConsonant;
    }
};
