stack<string> s1;
    stack<string> s2;
    
    BrowserHistory(string homepage) {
        while(!s1.empty())
            s1.pop();
        while(!s2.empty())
            s2.pop();
        
        s1.push(homepage);
    }
    
    void visit(string url) {
        
        while(!s2.empty())
            s2.pop();
        
        s1.push(url);
    }
    
    string back(int steps) {
        
        while(steps-- && s1.size() > 1)
        {
            s2.push(s1.top());
            s1.pop();
        }
        return s1.top();
    }
    
    string forward(int steps) {
        
        while(!s2.empty() && steps--)
        {
            s1.push(s2.top());
            s2.pop();
        }
        
        return s1.top();
    }
    
    //Also update it with why only stack why not others
