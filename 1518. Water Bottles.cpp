// numBottles = a, numExchange = b
// TC: O(log_{b}(a)) SC: O(1)
class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int waterDrunk = 0;

        while(numBottles >= numExchange){
            int remBottles = numBottles % numExchange;
            int newBottles = numBottles / numExchange;
            waterDrunk += numBottles - remBottles;
            numBottles = remBottles + newBottles;
        }
        waterDrunk += numBottles;

        return waterDrunk;
    }
};
