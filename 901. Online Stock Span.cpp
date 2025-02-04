class StockSpanner {
    stack<int> s;
    vector<int> v;
    int i=-1;
public:
    StockSpanner() {
        
    }
    
    int next(int price) {
        v.push_back(price);
        i++;

        while(s.size() > 0 && v[s.top()] <= price){
            s.pop();
        }

        int ans;
        if(s.empty()){
            ans = i+1;
        } else{
            ans = i-s.top();
        }

        s.push(i);
        
        return ans;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */
