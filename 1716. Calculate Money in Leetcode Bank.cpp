// TC: O(1) SC: O(1)
class Solution {
public:
    int totalMoney(int n) {
        int weeks = n / 7;
        int days = n % 7;

        int money = (28 * weeks) + 7*((weeks - 1) * weeks / 2);
        money += days * (weeks+1) + (days * (days-1))/2;
        
        return money;
    }
};
