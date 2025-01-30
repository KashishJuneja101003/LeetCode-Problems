class Solution {
public:
    long long eatingTime(vector<int>& piles, int k){
        long long time = 0;

        for(int i:piles){
            time += (i+k-1LL)/k;
        }

        return time;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();
        int start = 1, end = *max_element(piles.begin(), piles.end());
        int minSpeed;

        while(start <= end){
            int mid = start + (end-start)/2;

            if(eatingTime(piles, mid) <= h){
                minSpeed = mid;
                end = mid-1;
            } else{
                start = mid+1;
            }
        }

        return minSpeed;
    }
};
