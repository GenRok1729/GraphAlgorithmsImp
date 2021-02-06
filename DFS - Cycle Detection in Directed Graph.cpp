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
