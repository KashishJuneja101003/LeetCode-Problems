// Appraoch 1: TC: O(log n) SC: O(logn)
class Solution {
public:
    string hexadecimal(int n, int base) {
        if(n == 0) return "0";

        string str;
        const string digits = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";

        while(n > 0){
            str += digits[n%base];
            n /= base;
        }
        reverse(str.begin(), str.end());
        return str;
    }

    
    string concatHex36(int n) {
        int sq = n*n;
        int cube = sq*n;

        string hexdec = hexadecimal(sq, 16);
        string hextridec = hexadecimal(cube, 36);

        return hexdec + hextridec;
    }
};
