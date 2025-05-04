class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        unordered_map<int, int> element_freq;
        int countEquivPairs = 0;
        for(auto domino : dominoes){
            int a = domino[0];
            int b = domino[1];

            // Formula to represent each domino pair uniquely
            int key = min(a, b) * 10 + max(a, b);

            // If the unique pair exists in hashmap, its frequency is added
            // Else, its frequency is 0
            countEquivPairs += element_freq[key];

            // Increase the frequency of key
            element_freq[key]++;
        }

        return countEquivPairs;
    }
};
