class Solution {
public:
    string largestGoodInteger(string& num) {
        int count = 0;
        char curr = 'X', maxd = ' ';
        for (char c : num) {
            if (c == curr)
                count++;
            else
                count = 1;
            if (count == 3)
                maxd = max(maxd, c);
            curr = c;
        }
        return (maxd == ' ') ? "" : string(3, maxd);
    }
};
