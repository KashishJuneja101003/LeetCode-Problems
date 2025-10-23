// TC: O(n) SC: O(n)
class Solution {
public:
    bool hasSameDigits(string s) {
        vector<int> digits;
        for(char& c:s) digits.push_back(c-'0');

        vector<int> newDigits;

        while(digits.size() > 2){
            for(int i=0; i<digits.size()-1; i++){
                newDigits.push_back((digits[i]+digits[i+1])%10);
            }
            digits = newDigits;
            newDigits = {};
        }

        return digits[0] == digits[1];
    }
};
