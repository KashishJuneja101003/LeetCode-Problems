class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int count5 = 0, count10 = 0;

        for (int bill : bills) {
            if (bill == 5) {
                count5++;
            } else if (bill == 10) {
                if (count5 == 0) return false;
                count5--;
                count10++;
            } else {  // bill == 20
                if (count10 > 0 && count5 > 0) {  
                    count10--;  // Give one $10 bill
                    count5--;   // Give one $5 bill
                } else if (count5 >= 3) {  
                    count5 -= 3;  // Give three $5 bills
                } else {
                    return false;  // Not enough change
                }
            }
        }

        return true;
    }
};
