bool findLoop(int v) 
{
	if(vis[v]==1)
		return 1;
	if(vis[v]==2)
		return 0;
	vis[v]=1;
	for(auto &it:g[v])
	{
		if(findLoop(it))
			return 1;
	}
	vis[v]=2;
	return 0;
}

bool checkLoop()
{
	fill(vis+1, vis+n+1, 0);
	for(int i=1;i<=n;i++)
	{
		if(!vis[i] && findLoop(i))
			return 1;
	}
	return 0;
}

// https://cp-algorithms.com/graph/depth-first-search.html


//Problem 1 (Marking edges belong to a cycle): https://codeforces.com/contest/915/problem/D
//Solution 1: https://codeforces.com/contest/915/submission/41311663

//Problem 2: https://codeforces.com/contest/937/problem/D
//Solution 2: https://codeforces.com/contest/937/submission/45960040

================================================================================================================================================================

vector<vector<int>> adj; // graph represented as an adjacency list
int n; // number of vertices

vector<bool> visited;

void dfs(int v) {
    visited[v] = true;
    for (int u : adj[v]) {
        if (!visited[u])
            dfs(u);
    }
}

================================================================================================================================================================
	
class Solution {
    int m,n;
public:
    int dfs(vector<vector<int>> &grid,int i,int j){
        if(grid[i][j]==0) return 0;
        int result=0;
        int temp=grid[i][j];
        grid[i][j]=0;
        if(i>0) result=max(result,temp+dfs(grid,i-1,j));
        if(j>0) result=max(result,temp+dfs(grid,i,j-1));
        if(i<m-1) result=max(result,temp+dfs(grid,i+1,j));
        if(j<n-1) result=max(result,temp+dfs(grid,i,j+1));
        grid[i][j]=temp;
        return result;
    }
    int getMaximumGold(vector<vector<int>>& grid) {
        int result=0;
        m=grid.size();
        n=grid[0].size();
        for(int i=0;i<m;i++)
            for(int j=0;j<n;j++)
                result=max(result,dfs(grid,i,j));   
        return result;
    }
=================================================================================================================================================================

//4th type of dfs where you have to also transfer labels as well 
	
class Solution {
public:
    vector<int>ans;
    vector<vector<int>>g;
    
    vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels) {
		//clearing the ans and graph for storing the current ones since these are global, it might happen 
		//that the values from previous test cases might still be present within them which could alter 
		//the answer of present test case.
        ans.resize(n,0);
        g.resize(n,vector<int>{});
        
		//Creating the adjacency list for the graph
        for(auto it:edges) {
            g[it[0]].push_back(it[1]);
            g[it[1]].push_back(it[0]);
        }
        
		//starting traversal of graph from the 0 node and parent as -1
        dfs(0, -1, labels); //<current node, parent node, labels string>
        
        return ans;
    }
    
    vector<int> dfs(int s, int par, string &labels) {
		//maintaining the frequency count of the subtree with **s** as the node
        vector<int>res(26,0);
        res[labels[s]-'a']++; //adding the value of current node
        
        for(int it:g[s]) {
            
            if(it == par)
                continue;
            
            vector<int>f = dfs(it, s, labels); //frequency count of subtree with it(child) as root
            for(int i=0; i<26; ++i) {
                res[i]+=f[i];
            }
        }
        
        ans[s] = res[labels[s]-'a']; //since we want the number of occurences of the char in current node
        
        return res;
    }
    
    
};
==============================================================================================================================================
