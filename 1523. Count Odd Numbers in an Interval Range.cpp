// TC: O(n) SC: O(1)
class Solution {
public:
    int countOdds(int low, int high) {
        int count = 0;

        for(int i=low; i<= high; i++){
            if((i&1) != 0) count++;
        }
        
        return count;
    }
};

// TC: O(1) SC: O(1)
class Solution {
public:
    int countOdds(int low, int high) {
        int num = high-low+1;
        if((num&1) == 0) return num/2;
        
        if((low&1) == 0) return num/2;

        return num/2+1;
    }
};
