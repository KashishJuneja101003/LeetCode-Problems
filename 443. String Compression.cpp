class Solution {
public:
    int compress(vector<char>& chars) {
        int n = chars.size(), idx = 0;

        for(int i=0; i<n; ){
            char c = chars[i];
            int count = 0;

            while(i < n && chars[i] == c){
                count++; i++;
            }

            chars[idx++] = c;

            if(count > 1){
                string s = to_string(count);
                
                for(char ch:s){
                    chars[idx] = ch;
                    idx++;
                }
            }

        }

        return idx;
    }
};
