class Solution {
public:
    // Sieve of Eratosthenes
    int countPrimes(int n) {
        int count=0;
        vector<int> isPrime(n+1, true);

        for(int i=2; i<n; i++){
            if(isPrime[i]){
                count++;

                for(int j=i*2; j<n; j+=i)
                    isPrime[j] = false;
            }
        }
        return count;
    }
};
