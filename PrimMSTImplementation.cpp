/* Like Kruskal’s algorithm, Prim’s algorithm is also a Greedy algorithm. It starts with an empty spanning tree. The idea is to maintain two sets of vertices.
The first set contains the vertices already included in the MST, the other set contains the vertices not yet included. At every step, it considers all the edges
that connect the two sets, and picks the minimum weight edge from these edges. After picking the edge, it moves the other endpoint of the edge to the set
containing MST. A group of edges that connects two set of vertices in a graph is called cut in graph theory. So, at every step of Prim’s algorithm, we find a
cut (of two sets, one contains the vertices already included in MST and other contains rest of the vertices), pick the minimum weight edge from the cut
and include this vertex to MST Set (the set that contains already included vertices).

How does Prim’s Algorithm Work? The idea behind Prim’s algorithm is simple, a spanning tree means all vertices must be connected. So the two disjoint subsets
(discussed above) of vertices must be connected to make a Spanning Tree. 
And they must be connected with the minimum weight edge to make it a Minimum Spanning Tree.*/


void Graph::primMST() 
{ 
 
    // http://geeksquiz.com/implement-min-heap-using-stl/ 
    priority_queue< iPair, vector <iPair> , greater<iPair> > pq; 
  
    int src = 0; // Taking vertex 0 as source 
  
    // Create a vector for keys and initialize all  keys as infinite (INF) 
    vector<int> key(V, INF); 
  
    // To store parent array which in turn store MST 
    vector<int> parent(V, -1); 
  
    // To keep track of vertices included in MST 
    vector<bool> inMST(V, false); 
  
    // Insert source itself in priority queue and initialize its distance as 0. 
    pq.push(make_pair(0, src)); 
    dist[src] = 0; 
  
    /* Looping till priority queue becomes empty */
    while (!pq.empty()) 
    { 
        // The first vertex in pair is the minimum key vertex, extract it from priority queue vertex label is stored in second of pair (it 
        // has to be done this way to keep the vertices 
        // sorted key (key must be first item 
        // in pair) 
        int u = pq.top().second; 
        pq.pop(); 
  
        inMST[u] = true;  // Include vertex in MST 
  
        // 'i' is used to get all adjacent vertices of a vertex 
        auto i; 
        for (i = adj[u].begin(); i != adj[u].end(); ++i) 
        { 
            // Get vertex label and weight of current adjacent 
            // of u. 
            int v = (*i).first; 
            int weight = (*i).second; 
  
            //  If v is not in MST and weight of (u,v) is smaller 
            // than current key of v 
            if (inMST[v] == false && key[v] > weight) 
            { 
                // Updating key of v 
                key[v] = weight; 
                pq.push(make_pair(key[v], v)); 
                parent[v] = u; 
            } 
        } 
    }
 
 /**
 Dijkstra’s algorithm finds the shortest path, but Prim’s algorithm finds the MST
Dijkstra’s algorithm can work on both directed and undirected graphs, but Prim’s algorithm only works on undirected graphs
Prim’s algorithm can handle negative edge weights, but Dijkstra’s algorithm may fail to accurately compute distances if at least one negative edge weight exists
 **/
  
  
 //Network design - Add How Clearly 
 //Indirect applications.
 //Cluster analysis


 
