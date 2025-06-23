// Approach 1: Brian Kernighan’s Algorithm TC: O(n log n) SC: O(n)
/*
class Solution {
public:
    int countOnes(int i){
        int count = 0;
        while(i){
            i = i & (i-1);
            count++;
        }
        return count;
    }
    
    vector<int> countBits(int n) {
        vector<int> result(n+1, 0);
        for(int i=1; i<=n; i++){
            result[i] = countOnes(i);
        }
        return result;
    }
};
*/

// Approach 2: Built-in function TC: O(n) SC: O(n)
/*
class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> result(n+1, 0);
        for(int i=1; i<=n; i++){
            result[i] = __builtin_popcount(i);
        }
        return result;
    }
};
*/

// Approach 3: Dynamic Programming TC: O(n) SC: O(n)
class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> result(n+1, 0);
        for(int i=1; i<=n; i++){
            result[i] = result[i/2] + (i%2);
        }
        return result;
    }
};
