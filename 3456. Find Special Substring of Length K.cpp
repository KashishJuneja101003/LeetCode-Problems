class Solution {
public:
    bool hasSpecialSubstring(string s, int k) {
        int left = 0, right = 0, n = s.size();

        while(right < n){
            // Characters must be same
            if(s[left] != s[right]){
                left++;
            } else if(right-left+1 < k){  // Achieving size k
                right++;
            } else{
                bool status = true;
                if(left > 0 && s[left-1] == s[left]) status = false;
                if(right<n-1 && s[right+1] == s[right]) status = false;

                if(status) return true;
                else left++; right++;
            }
        }

        return false;
    }
};
