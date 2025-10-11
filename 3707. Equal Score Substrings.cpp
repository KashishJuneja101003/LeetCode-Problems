// TC: O(n) SC: O(1)
class Solution {
public:
    bool scoreBalance(string s) {
        int right = 0;

        for(char& c:s) right += c - 'a' + 1;

        int left = 0;

        for(int i=0; i<s.size(); i++){
            int sum = s[i] - 'a' + 1;
            left += sum;
            right -= sum;

            if(left == right) return true;
        }

        return false;
    }
};
