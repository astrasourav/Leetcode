//Using two queues

class MyStack {
public:
    queue<int> q1, q2;
    MyStack() {}

    void push(int x) {
        q2.push(x);

        while (!q1.empty()) {
            q2.push(q1.front());
            q1.pop();
        }

        swap(q1, q2);
    }

    int pop() {
        int data = q1.front();
        q1.pop();
        return data;
    }

    int top() {
        return q1.front();
    }

    bool empty() {
        if (q1.empty()) {
            return true;
        }

        return false;
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 **/
 
 //using 1 queue
 
 class MyStack {
    queue<int>q1;
public:
    MyStack() {
        
    }
    
    void push(int x) {
        q1.push(x);

        if (q1.size() != 1) {
            for (int i=0; i<q1.size() -1; i++) {
                q1.push(q1.front());
                q1.pop();
            }
        }

    }
    
    int pop() {
        int data  = q1.front();
        q1.pop();
        return data;
    }
    
    int top() {
        return q1.front();
    }
    
    bool empty() {
        if (q1.empty())  {
            return true;
        }

        return false;
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */
 


