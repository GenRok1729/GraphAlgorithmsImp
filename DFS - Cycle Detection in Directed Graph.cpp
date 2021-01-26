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
