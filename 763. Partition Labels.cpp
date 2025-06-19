// Approach 1: Two Pointers TC: O(n) SC: O(26) => O(1)
class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int> ch_end(26, 0);
        int n = s.size();

        for(int i=0; i<n; i++){
            int c = s[i]-'a';
            ch_end[c] = i;
        }

        // for(auto& it:ch_st_end){
        //     cout<<it.first<<": "<<it.second.first<<", "<<it.second.second<<"\n";
        // }

        int i=0;
        int l=0;
        int r=0;

        vector<int> result;

        while(i < n){
            if(l == r){
                int c = s[l]-'a';
                r = ch_end[c];
            }
            if(i == r){
                result.push_back(r-l+1);
                l = r = ++i;
            }
            if(i < r){
                int end = ch_end[s[i]-'a'];
                r = max(r, end);
                i++;
            }
        }

        return result;
    }
};
