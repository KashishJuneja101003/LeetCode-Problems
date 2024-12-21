class Solution {
public:
    int strStr(string haystack, string needle) {
        int n=haystack.size();

        for(int i=0; i<n; i++){
            if(haystack[i] == needle[0]){
                int idx = i, j = 0, temp = i;

                while(temp<n && haystack[temp] == needle[j]){
                    j++; temp++;
                }
                
                if(j == needle.size()) return idx;
            }
            else continue;
        }

        return -1;
    }
};
