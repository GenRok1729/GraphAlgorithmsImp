int dist[N][N];


//The Floyd Warshall Algorithm is for solving the All Pairs Shortest Path problem. The problem is to find shortest distances between every pair of vertices in a 
//given edge weighted directed Graph

//The idea is to one by one pick all vertices and updates all shortest paths which include the picked vertex as an intermediate vertex in the shortest path. 
//When we pick vertex number k as an intermediate vertex, we already have considered vertices {0, 1, 2, .. k-1} as intermediate vertices. For every pair (i, j) of the source and destination vertices respectively, there are two possible cases.
//1) k is not an intermediate vertex in shortest path from i to j. We keep the value of dist[i][j] as it is.
//2) k is an intermediate vertex in shortest path from i to j. We update the value of dist[i][j] as dist[i][k] + dist[k][j] if dist[i][j] > dist[i][k] + dist[k][j]

void FloydWarshall()
{
	for(int k=1;k<=n;k++)
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				dist[i][j]=min(dist[i][j], dist[i][k] + dist[k][j]);
}

//Problem 1: https://codeforces.com/contest/189/problem/D
//Solution 1: https://codeforces.com/contest/189/submission/48938763
