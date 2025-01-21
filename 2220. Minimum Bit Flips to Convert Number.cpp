class Solution {
public:
    int minBitFlips(int start, int goal) {
        int count = 0, xorResult = start^goal;
        while(xorResult != 0){
            count++;
            xorResult = xorResult & (xorResult-1);
        }
        return count;
    }
};
