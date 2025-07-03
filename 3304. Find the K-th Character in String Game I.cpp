class Solution {
public:
    char kthCharacter(int k) {
        vector<int> vec(k);
        vec[0] = 0;

        int i = 0;
        int prev = 0;
        for(int idx = 1; idx < k; idx++){
            vec[idx] = vec[i]+1;
            if(vec[idx] == 26) vec[idx] = 1;
            if(prev == i) {i=0; prev = idx;}
            else i++;
        }
        
        return (char)(vec[k-1]+'a');
    }
};
