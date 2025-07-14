class Solution {
public:
    bool isPrime(int n){
        if(n <= 1) return false;
        
        for(int i=2; i*i <= n; i++){
            if(n % i == 0) return false;
        }

        return true;
    }
    
    bool checkPrimeFrequency(vector<int>& nums) {
        vector<int> freq(101, 0);

        for(int i:nums) freq[i]++;

        for(int i:freq){
            if(i >= 1 && isPrime(i)) return true;
        }

        return false;
    }
};
