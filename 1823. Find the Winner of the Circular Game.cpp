class Solution {
public:
    int findTheWinner(int n, int k) {
        vector<int> friends(n+1, 1);
        friends[0] = 0;
        int total = n;

        int idx = 1;
        while(total != 1){
            int k_ = k;
            while(k_){
                if(friends[idx] == 1){
                    k_--;
                }

                if(k_ == 0){
                    friends[idx] = 0;
                    total--;
                }
                
                idx = (idx+1) % (n+1);
            }

        }

        for(int i=0; i<=n; i++){
            if(friends[i] == 1) return i;
        }
        return -1;
    }
};
