class Solution {
public:
    vector<string> fizzBuzz(int n) {
        vector<string> answer(n);
        for(int i=0; i<n; i++){
            int num = i+1;

            // Divisible by both
            if(num%3 == 0 && num%5 == 0){
                answer[i] = "FizzBuzz";
            } else if(num%3 == 0){
                answer[i] = "Fizz";
            } else if(num%5 == 0){
                answer[i] = "Buzz";
            } else{
                answer[i] = to_string(num);
            }
        }

        return answer;
    }
};
