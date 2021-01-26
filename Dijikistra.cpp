 
        vector<pair<int,int>> we[N+1];
        for(int i = 0;i < times.size();i++)
        {
            we[times[i][0]].push_back(make_pair(times[i][1],times[i][2]));
        }
        
        
        int inf = 1e9;
        bool visited[N+1];
        int EBT[N+1];
        //MIN Heap 
        //Pair<int,int> is the data structure 
        priority_queue< pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>> > pq;
        
        //Initializing them to their respective stating false and visiteds 
        for(int i=1;i<=N;i++)
        {
            visited[i] = false;
            EBT[i] = inf;
        }
        
        
        EBT[k] = 0;
        pq.push({0,k});
        //For the sourse signal passing vertes 
        
        //BFS 
        while(!pq.empty())
        {
            auto ele = pq.top();
            int a  = ele.second;
            pq.pop();
            if(visited[a] == true)
                continue;
            visited[a] = true;
            for(auto u: we[a])
            {
                int b = u.first, w = u.second;
                if(!visited[b] && EBT[a]+w < EBT[b])
                {
                    EBT[b] = EBT[a]+w;
                }
                
                pq.push({EBT[b],b});
            }  
        }
        
        int maxi = INT_MIN;
        for(int i = 1;i <= N;i++)
        {
            if(EBT[i] > maxi)
            {
                maxi = EBT[i];
            }
            if(EBT[i] == inf)
            {
                return -1;
            }
        }
        
        return maxi;
        
        //Implementatiomn assuming only one burning time 
        //https://leetcode.com/problems/network-delay-time/
	//https://cs.stackexchange.com/questions/18797/minimum-spanning-tree-vs-shortest-path
=================================================================================================================================================================
 //Simple Dijkstra: Taking Arrival and Departure into consideration 

int arrival[N][N], departure[N][N];
vector<pair<int, int> > g[N];

void dijkstra(int source, int destination, int arrival[], int departure[])
{
	for(int i=1;i<=n;i++)
	{
		arrival[i]=inf;
		departure[i]=inf;
	}
	arrival[source]=0;
	set<pair<int, int> > s;
	s.insert({0, source});
	while(!s.empty())
	{
		auto x = *(s.begin());
		s.erase(x);
		departure[x.second]=arrival[x.second];
		for(auto it:g[x.second])
		{
			if(arrival[it.first] > departure[x.second] + it.second)
			{
				s.erase({arrival[it.first], it.first});
				arrival[it.first]=departure[x.second] + it.second;
				s.insert({arrival[it.first], it.first});
			}
		}
	}
}
================================================================================================================================================================

//Dijkstra with Path:

int arrival[N], departure[N], vis[N], parent[N];
vector<pair<int, int> > g[N];

void dijkstra(int source, int destination)
{
	for(int i=1;i<=n;i++)
	{
		arrival[i]=1e18;
		departure[i]=1e18;
		vis[i]=0;
	}
	arrival[source]=0;
	set<pair<int, int> > s;
	s.insert({0, source});
	while(!s.empty())
	{
		auto x = *(s.begin());
		s.erase(x);
		vis[x.second]=1;
		departure[x.second]=arrival[x.second];
		for(auto it:g[x.second])
		{
			if(arrival[it.first] > departure[x.second] + it.second)
			{
				s.erase({arrival[it.first], it.first});
				arrival[it.first]=departure[x.second] + it.second;
				s.insert({arrival[it.first], it.first});
				parent[it.first]=x.second;
			}
		}
	}
	if(!vis[destination])
	{
		cout<<"-1";
		return;
	}
	int v=destination;
	vector<int> ans;
	while(parent[v])
	{
		ans.push_back(v);
		v=parent[v];
	}
	ans.push_back(source);
	reverse(ans.begin(), ans.end());
	for(auto it:ans)
		cout<<it<<" ";
}

//Problem 1 (Direct Dijkstra): https://codeforces.com/contest/20/problem/C
//Solution 1: http://codeforces.com/contest/20/submission/39892416

//Problem 2: http://codeforces.com/contest/230/problem/D
//Solution 2: http://codeforces.com/contest/230/submission/39892295

//Problem 3 (count point on edges): https://codeforces.com/problemset/problem/144/D
//Solution 3: https://codeforces.com/contest/144/submission/45963496

//Problem 4 (all source Dijkstra): https://codeforces.com/contest/96/problem/D
//Solution 4: https://codeforces.com/contest/96/submission/45959572

//Problem 5: https://p.ip.fi/woUJ (Lexicographically shortest path from U to V)
===============================================================================================================================================================
