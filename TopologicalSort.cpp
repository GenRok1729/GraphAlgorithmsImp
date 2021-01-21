//For smallest toposort you can use prioirity queue instead of q

bool canFinish(int n, vector<vector<int>>& vect) {
        
         //First find indegrees of all vertices 
        vector<int> indeg(n,0);
        vector<vector<int>> edge(n);
        vector<int> order;
        for(int i=0;i<vect.size();i++)
        {
            indeg[vect[i][0]] = indeg[vect[i][0]]+1;
            edge[vect[i][1]].push_back(vect[i][0]);
        }
        queue<int> q;
        for(int i = 0;i<n;i++)
        {
            if(indeg[i] == 0)
            {
                q.push(i);
                order.push_back(i);
            }
        }
        while(!q.empty())
        {
            int j = q.front();
            q.pop();
            for(auto k = edge[j].begin();k != edge[j].end(); ++k)
            {
                int p = *k;
                indeg[p] = indeg[p] - 1;
                if(indeg[p] == 0)
                {
                    q.push(p);
                    order.push_back(p); //Order Stores the order in which they are visited it is topo thing 
                }
            }
        }
        
        if(order.size() < n){
            return false;
        }
        
        return true;
    }
    
 //solution - https://leetcode.com/submissions/detail/349499280/
    
 //Problem 1: https://www.spoj.com/problems/TOPOSORT/
//Solution 1: http://p.ip.fi/RTRG
