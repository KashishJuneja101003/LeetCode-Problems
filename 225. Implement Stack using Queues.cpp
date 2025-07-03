// Approach 1: Using 2 Queues push(x): O(1), pop(): O(n), top(): O(n), empty(): O(1)
class MyStack {
public:
    queue<int> q1;
    queue<int> q2;
    MyStack() {
        
    }
    
    void push(int x) {
        q1.push(x);
    }
    
    int pop() {
        while(q1.size () > 1){
            q2.push(q1.front());
            q1.pop();
        }

        int val = q1.front();
        q1.pop();
        swap(q1,q2);

        return val;
    }
    
    int top() {
        while(q1.size () > 1){
            q2.push(q1.front());
            q1.pop();
        }

        int val = q1.front();
        q2.push(val);
        q1.pop();
        swap(q1, q2);

        return val;
    }
    
    bool empty() {
        return q1.size() == 0;
    }
};

// Approach 2: Using 1 Queue push(x): O(n), pop(): O(1), top(): O(1), empty(): O(1)
class MyStack {
public:
    queue<int> q1;
    MyStack() {
        
    }
    
    void push(int x) {
        q1.push(x);

        for(int i=0; i<q1.size()-1; i++){
            q1.push(q1.front());
            q1.pop();
        }        
    }
    
    int pop() {
        int val = q1.front();
        q1.pop();
        return val;
    }
    
    int top() {
        return q1.front();
    }
    
    bool empty() {
        return q1.empty();
    }
};

// Approach 3: Using Deque push(x): O(1), pop(): O(1), top(): O(1), empty(): O(1)
// Not acceptable everywhere as deque offers control fron front end too
class MyStack {
public:
    deque<int> dq;
    MyStack() {
        
    }
    
    void push(int x) {
        dq.push_back(x);
    }
    
    int pop() {
        int val = dq.back();
        dq.pop_back();
        return val;
    }
    
    int top() {
        return dq.back();
    }
    
    bool empty() {
        return dq.size() == 0;
    }
};
