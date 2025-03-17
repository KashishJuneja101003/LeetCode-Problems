class Solution {
public:
    bool checkValidString(string s) {
        int minOpen = 0, maxOpen = 0; 
        
        for (char c : s) {
            if (c == '(') {
                minOpen++;
                maxOpen++;
            } else if (c == ')') {
                minOpen = max(0, minOpen - 1);
                maxOpen--;
            } else { // '*'
                minOpen = max(0, minOpen - 1); // Treat '*' as ')'
                maxOpen++; // Treat '*' as '('
            }

            // If maxOpen becomes negative, there are too many ')'
            if (maxOpen < 0) return false;
        }
        
        return minOpen == 0;
    }
};
