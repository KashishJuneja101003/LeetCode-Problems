class Solution {
public:
    int maxBottlesDrunk(int numBottles, int numExchange) {
        int count = 0;

        while(numBottles >= numExchange){
            count += numExchange;
            numBottles -= numExchange;
            numExchange++;
            numBottles++;
        }
        count += numBottles;
        
        return count;
    }
};
