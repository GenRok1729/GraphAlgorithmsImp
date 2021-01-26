/*1. Sort all the edges in non-decreasing order of their weight. 
2. Pick the smallest edge. Check if it forms a cycle with the spanning tree formed so far. If cycle is not formed, include this edge. Else, discard it. 
3. Repeat step#2 until there are (V-1) edges in the spanning tree.*/

/*typedef struct data
{
	int u, v, w, idx;

	data() {}
 
	data(int u, int v, int w, int idx) : u(u), v(v), w(w), idx(idx) {}
}edge;*/

int n, m;
int connected;
int root[N], sz[N];
//vector<pair<int, int> > g[N];
typedef  pair<int, int> iPair; 
vector< pair<int, iPair> > edges; 
//data edges[N];
==================================================================================================================================================================
void init()
{
	for(int i=1;i<=n;i++)
	{
		root[i]=i;
		sz[i]=1;
	}
	connected=n;
}

int rt(int k)
{
	while(k!=root[k])
	{
		root[k]=root[root[k]];
		k=root[k];
	}
	return k;
}

void merge(int u, int v)
{
	int rt1=rt(u);
	int rt2=rt(v);

	if(rt1==rt2)
		return;

	connected--;

	if(sz[rt1]>sz[rt2])
		swap(rt1, rt2);

	sz[rt2]+=sz[rt1];
	sz[rt1]=0;
	root[rt1]=root[rt2];
}

void add_edge(int u, int v, int w)
{// Utility function to add an edge 
        edges.push_back({w, {u, v}});  
}

//Union find part 
------------------------------------------------------------------------------------------------------------------------------------------------------------------


// Krushkals Part 

/*bool comp(data &d1, data &d2)
{
	return d1.w < d2.w;
}*/	

int kruskalMST()
{	
	init();
	int cost=0;
	sort(edges.begin(),edges.end());
	for (it=edges.begin(); it!=edges.end(); it++) 
    	{ 
		int u = it->second.first; 
		int v = it->second.second;
		int w = it->first;
		int rt1=rt(u), rt2=rt(v);
		if(rt1==rt2)
			continue;
		else
		{
			cost+=w;
			merge(rt1, rt2);
		}
	}
	return cost;
}

//Problem 1 (Kruskal + Flow): https://codeforces.com/gym/101667 : Problem E
//Solution 1: http://p.ip.fi/HHLC
