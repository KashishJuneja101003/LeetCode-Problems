class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        unordered_map<int, int> freq;
        vector<int> C; int common = 0;
               
        for(int i=0; i<A.size(); i++){
            freq[A[i]]++;
            freq[B[i]]++;

            if(freq[A[i]] == 2){
                common++;
            }
            if(freq[B[i]] == 2){
                common++;
            }
            if(A[i] == B[i]){
                common--;
            }

            C.push_back(common);
        }

        return C;
    }
};
