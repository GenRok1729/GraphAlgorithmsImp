class MyStack {
public:
    
	queue<int> que;
	// Push element x onto stack.
	void push(int x) {
		que.push(x);
        //cout << que.size() << '\n';
		for(int i=0;i<que.size()-1;i++){//Bring all  remaining forwrd elements t back of thisand this has to be t the begining obviously inorder to iimplement lifo 
            
			que.push(que.front());
			que.pop();
		}
        
        //cout << que.size() << '\n';
        
	}

	// Removes the element on top of the stack.
	int pop() {
        int  t = top();
		que.pop();
        return t;
	}

	// Get the top element.
	int top() {
		return que.front();
	}

	// Return whether the stack is empty.
	bool empty() {
		return !que.empty();
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
