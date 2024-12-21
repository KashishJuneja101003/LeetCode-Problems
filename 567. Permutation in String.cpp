class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n1 = s1.size(), n2 = s2.size();

        if(n1 > n2) return false;
        vector<int> freq(26, 0);

        // Iterating through s1 and calculating frequency
        for(char c:s1){
            freq[c-'a']++;
        }

        // Sliding Window
        for(int i=0; i<=n2-n1; i++){
            vector<int> check(26, 0);
            for(int j=i; j<i+n1; j++){
                check[s2[j]-'a']++;
            }

            // Equality of both vectors
            if(freq == check) return true;
        }
        return false;
    }
};
