class ExamTracker {
public:
    vector<int> times;
    vector<long long> prefix;

    ExamTracker() {
    }
    
    void record(int time, int score) {
        times.push_back(time);
        if (prefix.empty())
            prefix.push_back(score);
        else
            prefix.push_back(prefix.back() + score);
    }
    
    long long totalScore(int startTime, int endTime) {
        // Find left index: first time >= startTime
        auto itL = lower_bound(times.begin(), times.end(), startTime);
        // Find right index: last time <= endTime
        auto itR = upper_bound(times.begin(), times.end(), endTime);
        
        if (itL == times.end() || itL >= itR) return 0;
        
        int leftIdx = itL - times.begin();
        int rightIdx = (itR - times.begin()) - 1;
        
        long long total = prefix[rightIdx];
        if (leftIdx > 0) total -= prefix[leftIdx - 1];
        
        return total;
    }
};
