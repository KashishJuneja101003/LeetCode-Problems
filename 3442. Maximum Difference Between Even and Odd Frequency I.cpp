class Solution {
public:
    int maxDifference(string s) {
        vector<int> freq(26, 0);

        for(char c:s){
            freq[c-'a']++;
        }

        int oddMax = INT_MIN;
        int evenMin = INT_MAX;

        for(int i:freq){
            if(i%2 == 0 && i != 0){
                evenMin = min(evenMin, i);
            } else{
                oddMax = max(oddMax, i);
            }

            cout<<"OddMax: "<<oddMax<<", EvenMin: "<<evenMin<<"\n";
        }
        return oddMax-evenMin;
    }
};
