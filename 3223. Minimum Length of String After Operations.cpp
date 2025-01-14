class Solution {
public:
    int minimumLength(string s) {
        if(s.size() < 3){
            return s.size;
        }
        unordered_map<char, int> hash;

        for(char c:s){
            hash[c]++;
        }

        int length=0;
        for(auto pair:hash){
            if(pair.second < 3){
                length += pair.second;
            } else if(pair.second%2 == 1){  // Odd
                length++;
            } else{
                length += 2;
            }
        }

        return length;
    }
};
