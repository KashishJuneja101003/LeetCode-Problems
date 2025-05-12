class Solution {
public:
    
    vector<int> findEvenNumbers(vector<int>& digits) {
        // Store frequency of each digit in a hashmap
        vector<int> element_freq(10, 0);
        for(int i:digits){
            element_freq[i]++;
        }

        set<int> uniqueCombinations;

        // Generate number from digit
        for(int i=1; i<=9; i++){
            if(element_freq[i] == 0) continue;
            element_freq[i]--;
            for(int j=0; j<=9; j++){
                if(element_freq[j] == 0) continue;
                element_freq[j]--;

                for(int k=0; k<=8; k+=2){
                    if(element_freq[k] == 0) continue;
                    element_freq[k]--;

                    int num = i*100 + j*10 + k;
                    // Check if the number satisfies the requirements
                    // If yes, insert it into set
                    if(num >= 100){
                        uniqueCombinations.insert(num);
                    }

                    element_freq[k]++;
                }
                element_freq[j]++;
            }
            element_freq[i]++;
        }
            

        // Iterate through set and insert each value in vector and return it

        vector<int> result(uniqueCombinations.begin(), uniqueCombinations.end());

        return result;
    }
};
