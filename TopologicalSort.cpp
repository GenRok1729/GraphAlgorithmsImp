//For smallest toposort you can use prioirity queue instead of q
/**
Kahn's algorithm is used to perform a topological sort on a directed acyclic graph with time complexity of O ( V + E )
– where V is the number of vertices and E is the number of edges in the graph.


**/

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

//Topological sorting for Directed Acyclic Graph (DAG) is a linear ordering of vertices such that for every directed edge u v, vertex u comes before v in the 
//ordering. Topological Sorting for a graph is not possible if the graph is not a DAG.

//O(V). The extra space is needed for the vector.

/**
Note: Here, we can also use vector instead of the stack. If the vector is used then print the elements in reverse order to get the topological sorting.

Applications: 
Topological Sorting is mainly used for scheduling jobs from the given dependencies among jobs. In computer science, applications of this type arise 
in instruction scheduling, ordering of formula cell evaluation when recomputing formula values in spreadsheets, logic synthesis, determining the order of
compilation tasks to perform in make files, data serialization, and resolving symbol dependencies in linkers [2].
**/
    
 //Problem 1: https://www.spoj.com/problems/TOPOSORT/
//Solution 1: http://p.ip.fi/RTRG
