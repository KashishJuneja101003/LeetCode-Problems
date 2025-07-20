class Solution {
public:
    vector<bool> sieve(int n){
        vector<bool> isPrime(n+1, true);
        isPrime[0] = isPrime[1] = false;

        for(int i=2; i*i <= n; i++){
            if(isPrime[i]){
                for(int j=i*i; j<=n; j+=i){
                    isPrime[j] = false;
                }
            }
        }

        return isPrime;
    }
    
    long long splitArray(vector<int>& nums) {
        int n = nums.size();

        vector<bool> isPrime = sieve(n-1);
        
        long long primeSum = 0;        
        long long nonPrimeSum = 0;       

        for(int i=0; i<n; i++){
            if(isPrime[i]) primeSum += nums[i];
            else nonPrimeSum += nums[i];
        }

        return abs(primeSum - nonPrimeSum);
    }
};
