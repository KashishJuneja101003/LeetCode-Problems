// Approach 1: Brute Force TC: O(n^2) SC: O(n)
/*
class Solution {
public:
    bool isPalindrome(string s){
        int i=0; 
        int j=s.size()-1;

        while(i < j){
            if(s[i] != s[j]) return false;
            i++; j--;
        }
        return true;
    }

    bool validPalindrome(string s) {
        int n = s.size();
        if(n == 1) return true;

        for(int i=0; i<n; i++){
            string newStr = s;
            newStr.erase(newStr.begin()+i);

            if(isPalindrome(newStr)) return true;
        }
        return false;
    }
};
*/

// Approach 2: Two-Pointers TC: O(n) SC: O(1)
class Solution {
public:
    bool isPalindrome(string s, int i, int j){
        while(i < j){
            if(s[i] != s[j]){
                return false;
            }
            i++; j--;
        }
        return true;
    }

    bool validPalindrome(string s) {
        int n = s.size();
        if(n == 1) return true;

        int i=0;
        int j=n-1;
        while(i < j){
            if(s[i] == s[j]){
                i++; j--;
            } else{
                return isPalindrome(s, i+1, j) || isPalindrome(s, i, j-1);
            }
        }

        return true;
    }
};
