class Solution {
public:
    int getLeastFrequentDigit(int n) {
        vector<int> freq(10, 0);

        while(n > 0){
            int rem = n % 10;
            n /= 10;
            freq[rem]++;
        }

        int digit = 0;
        int f = INT_MAX;

        for(int i=0; i<10; i++){
            if(freq[i] != 0 && freq[i] < f){
                f = freq[i];
                digit = i;
            }
        }

        return digit;
    }
};
