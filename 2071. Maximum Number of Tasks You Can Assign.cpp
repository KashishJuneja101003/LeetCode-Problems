class Solution {
public:
    bool check(vector<int>& tasks, vector<int>& workers, int pills, int strength, int mid){
        int pillsUsed = 0;
        multiset<int> st(workers.begin(), workers.begin()+mid);

        for(int i=mid-1; i>=0; i--){
            int required = tasks[i];
            auto it = prev(st.end());

            if(*it >= required){
                st.erase(it);
            } else if(pillsUsed >= pills){
                return false;
            } else {
                // Find the weakest worker which can do this strong task using pills
                auto weakestWorkerIt = st.lower_bound(required-strength);
                if(weakestWorkerIt == st.end()){
                    return false;
                }
                st.erase(weakestWorkerIt);
                pillsUsed++;
            }
        }

        return true;
    }

    int maxTaskAssign(vector<int>& tasks, vector<int>& workers, int pills,
                      int strength) {
        // n = no of tasks and m = no of workers
        int n = tasks.size(), m = workers.size();

        int left = 0, right = min(m, n);
        
        sort(tasks.begin(), tasks.end());
        sort(workers.begin(), workers.end(), greater<int>());

        // num_tasks stores the number of tasks that are assigned
        int num_tasks = 0;

        while(left <= right){
            int mid = left + (right-left)/2;

            if(check(tasks, workers, pills, strength, mid)){
                num_tasks = mid;
                left = mid+1;
            } else {
                right = mid-1;
            }
        }

        return num_tasks;
    }
};
