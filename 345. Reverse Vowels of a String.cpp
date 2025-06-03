// Brute Force
/*
class Solution {
public:
    bool isVowel(char c){
        c = tolower(c);
        switch(c){
            case 'a':
            case 'e':
            case 'i':
            case 'o':
            case 'u':
                return true;
            default:
                return false;
        }
    }
    
    string reverseVowels(string s) {
        vector<char> chars;

        // Push vowels in chars vector
        for(char c:s){
            if(isVowel(c)) {
                chars.push_back(c);
            }
        }

        // Reverse the order of vowels
        int idx = 0;
        for(int i=chars.size()-1; i>=0; i--){
            while(!isVowel(s[idx])){
                idx++;
            }

            s[idx++] = chars[i];
        }

        return s;
    }
};
*/

// Two Pointers Approach
class Solution {
public:
    bool isVowel(char c){
        c = tolower(c);
        switch(c){
            case 'a':
            case 'e':
            case 'i':
            case 'o':
            case 'u':
                return true;
            default:
                return false;
        }
    }
    
    string reverseVowels(string s) {
        int left = 0;
        int right = s.size()-1;

        while(left < right){
            if(!isVowel(s[left])){
                left++;
                continue;
            }
            if(!isVowel(s[right])){
                right--;
                continue;
            }

            swap(s[left], s[right]);
            left++; right--;
        }

        return s;
    }
};
