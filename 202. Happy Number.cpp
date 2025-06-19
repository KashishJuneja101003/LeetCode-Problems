// Approach 1: Hashset TC: O(log n) SC: O(n)
/*
class Solution {
public:
    int sumSq(int n){
        int sum = 0;
        while(n != 0){
            int rem = n%10;
            sum += (rem*rem);
            n /= 10;
        }
        return sum;
    }

    bool isHappy(int n) {
        unordered_set<int> visited;
        
        while(n != 1 && visited.find(n) == visited.end()){
            visited.insert(n);
            n = sumSq(n);
        }

        return n==1;
    }
};
*/

// Appraoch 2: Floyd's Cycle Detection TC: O(log n) SC: O(1)
class Solution {
public:
    int sumSq(int n){
        int sum = 0;
        while(n != 0){
            int rem = n%10;
            sum += (rem*rem);
            n /= 10;
        }
        return sum;
    }

    bool isHappy(int n) {
        int slow = n;
        int fast = sumSq(n);

        while(fast != 1 && slow != fast){
            slow = sumSq(slow);
            fast = sumSq(sumSq(fast));
        }
        return fast==1;
    }
};
