class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        if (sum > 9 * num) {
            return "";
        }
        string result = "";
        int current_sum = sum;
        
        for (int i = 0; i < num; ++i) {
            int num_remaining = num - 1 - i;
            int start_digit = (i == 0) ? 9 : 9;
            int end_digit = (i == 0) ? 1 : 0;
            
            bool found_digit = false;
            for (int digit = start_digit; digit >= end_digit; --digit) {
                
                if (digit > current_sum) {
                    continue;
                }
                int remaining_sum = current_sum - digit;
                int max_remaining_sum = 9 * num_remaining;
                
                if (remaining_sum <= max_remaining_sum) {
                    result += std::to_string(digit);
                    current_sum -= digit;
                    found_digit = true;
                    break; 
                }
            }
            
            if (!found_digit) {
                return ""; 
            }
        }
        
        if (current_sum != 0) {
            return ""; 
        }
        
        return result;
    }
};
