// Approach 1: Space: O(2*n)
class MinStack {
    stack<pair<int, int>> s;
public:
    MinStack() {
    }
    
    void push(int val) {
        if(s.empty()){
            s.push({val, val});
        } else{
            s.push({val, min(val, s.top().second)});
        }
    }
    
    void pop() {
        s.pop();
    }
    
    int top() {
        return s.top().first;
    }
    
    int getMin() {
        return s.top().second;
    }
};

// Approach 2: Space: O(n)
class MinStack {
    stack<long long int> s;
    long long int minVal;
public:
    MinStack() {
    }
    
    void push(int val) {
        if(s.empty()){
            s.push(val);
            minVal = val;
        } else if(val < minVal){
            s.push(2LL*val - minVal);
            minVal = val;
        } else{
            s.push(val);
        }
    }
    
    void pop() {
        if(s.top() < minVal){
            minVal = 2*minVal - s.top();
        }
        s.pop();
    }
    
    int top() {
        if(s.top() < minVal){
            return minVal;
        } else{
            return s.top();
        }
    }
    
    int getMin() {
        return minVal;
    }
};
