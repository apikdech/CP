/**
 * author:  apikdech
 * created: 14.12.2019 18:53:20
**/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1000000007, N = 2e5 + 5;

map<int, int> x;
int p[N], cnt = 0, vis[N];
ll sz[N], ans = 0;
vector<int> edz[N];

void pre(int n) {
	for (int i = 0; i < n+5; i++) p[i] = i, sz[i] = 1, vis[i] = 0;
	for (int i = 0; i < n; i++) edz[i].clear();
	ans = 0;
	x.clear();
	cnt = 0;
}

int f(int v) {
	return (v == p[v] ? v : p[v] = f(p[v]));
}

void unite(int u, int v) {
	u = f(u), v = f(v);
	if (u == v) return;
	if (sz[u] < sz[v]) p[u] = v, sz[v] += sz[u], sz[u] = 0;
	else p[v] = u, sz[u] += sz[v], sz[v] = 0;
}

class Edge { 
    public: 
        int u; 
        int v; 
        Edge(int u, int v); 
};

Edge::Edge(int u, int v) { 
    this->u = u; 
    this->v = v; 
} 
  
class GGraph { 
    int V; 
    int E; 
    list<int>* adj; 
  
    void BCCUtil(int u, int disc[], int low[], 
                 list<Edge>* st, int parent[]); 
  
    public: 
        GGraph(int V);
        void addEdge(int v, int w); 
        void BCC();
}; 
  
GGraph::GGraph(int V) { 
    this->V = V; 
    this->E = 0; 
    adj = new list<int>[V]; 
} 
  
void GGraph::addEdge(int v, int w) { 
    adj[v].push_back(w); 
    E++; 
} 
  
void GGraph::BCCUtil(int u, int disc[], int low[], list<Edge>* st, int parent[]) { 
    static int time = 0; 
  
    disc[u] = low[u] = ++time; 
    int children = 0; 
  
    // list<int>::iterator i; 
    for (int v : adj[u]) { 
        // int v = *i; 
  
        if (disc[v] == -1) { 
            children++; 
            parent[v] = u; 
            st->push_back(Edge(u, v)); 
            BCCUtil(v, disc, low, st, parent); 

            low[u] = min(low[u], low[v]); 
  
            if ((disc[u] == 1 && children > 1) || (disc[u] > 1 && low[v] >= disc[u])) { 
                while (st->back().u != u || st->back().v != v) { 
                    // cout << st->back().u << "--" << st->back().v << " "; 
                    edz[cnt].push_back(st->back().u);
                    edz[cnt].push_back(st->back().v);
                    st->pop_back(); 
                } 
                // cout << st->back().u << "--" << st->back().v; 
                edz[cnt].push_back(st->back().u);
                edz[cnt].push_back(st->back().v);
                st->pop_back(); 
                // cout << endl; 

                cnt++; 
            } 
        } 

        else if (v != parent[u]) { 
            low[u] = min(low[u], disc[v]); 
            if (disc[v] < disc[u]) { 
                st->push_back(Edge(u, v)); 
            } 
        } 
    } 
} 
  
void GGraph::BCC() { 
    int* disc = new int[V]; 
    int* low = new int[V]; 
    int* parent = new int[V]; 
    list<Edge>* st = new list<Edge>[E]; 

    for (int i = 0; i < V; i++) { 
        disc[i] = -1; 
        low[i] = -1; 
        parent[i] = -1; 
    } 
  
    for (int i = 0; i < V; i++) { 
        if (disc[i] == -1) 
            BCCUtil(i, disc, low, st, parent); 
  
        bool ok = false; 
        while (st->size() > 0) { 
            ok = true;
            // cout << st->back().u << "--" << st->back().v << " "; 
            edz[cnt].push_back(st->back().u);
            edz[cnt].push_back(st->back().v);
            st->pop_back(); 
        } 
        if (ok) { 
            // cout << endl; 
            cnt++; 
        } 
    } 
} 

class Graph 
{ 
    int V;    // No. of vertices 
    list<int> *adj;    // A dynamic array of adjacency lists 
    void APUtil(int v, bool visited[], int disc[], int low[],  
                int parent[], bool ap[]); 
public: 
    Graph(int V);   // Constructor 
    void addEdge(int v, int w);   // function to add an edge to graph 
    void AP();    // prints articulation points 
}; 
  
Graph::Graph(int V) 
{ 
    this->V = V; 
    adj = new list<int>[V]; 
} 
  
void Graph::addEdge(int v, int w) 
{ 
    adj[v].push_back(w); 
    adj[w].push_back(v);  // Note: the graph is undirected 
} 
  
// A recursive function that find articulation points using DFS traversal 
// u --> The vertex to be visited next 
// visited[] --> keeps tract of visited vertices 
// disc[] --> Stores discovery times of visited vertices 
// parent[] --> Stores parent vertices in DFS tree 
// ap[] --> Store articulation points 
void Graph::APUtil(int u, bool visited[], int disc[],  
                                      int low[], int parent[], bool ap[]) 
{ 
    // A static variable is used for simplicity, we can avoid use of static 
    // variable by passing a pointer. 
    static int time = 0; 
  
    // Count of children in DFS Tree 
    int children = 0; 
  
    // Mark the current node as visited 
    visited[u] = true; 
  
    // Initialize discovery time and low value 
    disc[u] = low[u] = ++time; 
  
    // Go through all vertices aadjacent to this 
    list<int>::iterator i; 
    for (i = adj[u].begin(); i != adj[u].end(); ++i) 
    { 
        int v = *i;  // v is current adjacent of u 
  
        // If v is not visited yet, then make it a child of u 
        // in DFS tree and recur for it 
        if (!visited[v]) 
        { 
            children++; 
            parent[v] = u; 
            APUtil(v, visited, disc, low, parent, ap); 
  
            // Check if the subtree rooted with v has a connection to 
            // one of the ancestors of u 
            low[u]  = min(low[u], low[v]); 
  
            // u is an articulation point in following cases 
  
            // (1) u is root of DFS tree and has two or more chilren. 
            if (parent[u] == -1 && children > 1) 
               ap[u] = true; 
  
            // (2) If u is not root and low value of one of its child is more 
            // than discovery value of u. 
            if (parent[u] != -1 && low[v] >= disc[u]) 
               ap[u] = true; 
        } 
  
        // Update low value of u for parent function calls. 
        else if (v != parent[u]) 
            low[u]  = min(low[u], disc[v]); 
    } 
} 
  
// The function to do DFS traversal. It uses recursive function APUtil() 
void Graph::AP() 
{ 
    // Mark all the vertices as not visited 
    bool *visited = new bool[V]; 
    int *disc = new int[V]; 
    int *low = new int[V]; 
    int *parent = new int[V]; 
    bool *ap = new bool[V]; // To store articulation points 
  
    // Initialize parent and visited, and ap(articulation point) arrays 
    for (int i = 0; i < V; i++) 
    { 
        parent[i] = -1; 
        visited[i] = false; 
        ap[i] = false; 
    } 
  
    // Call the recursive helper function to find articulation points 
    // in DFS tree rooted with vertex 'i' 
    for (int i = 0; i < V; i++) 
        if (visited[i] == false) 
            APUtil(i, visited, disc, low, parent, ap); 
  
    // Now ap[] contains articulation points, print them 
    for (int i = 0; i < V; i++) 
        if (ap[i] == true) 
        	x[i] = 1;
} 

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	int t;
	cin >> t;
	while(t--) {
		int n, m, a, b;
		cin >> n >> m >> a >> b;
		vector<int> va, vb;
		pre(n);
		Graph g(n);
		GGraph gg(n);
		a--, b--;
		for (int i = 0; i < m; i++) {
			int u, v;
			cin >> u >> v;
			u--, v--;
			if (u == a && v != b) va.push_back(v);
			if (u == b && v != a) vb.push_back(v);
			if (v == b && u != a) vb.push_back(u);
			if (v == a && u != b) va.push_back(u);
			g.addEdge(u, v);
			g.addEdge(v, u);
			gg.addEdge(u, v);
			gg.addEdge(v, u);
		}
		sort(va.begin(), va.end());
		va.erase(unique(va.begin(), va.end()), va.end());
		sort(vb.begin(), vb.end());
		vb.erase(unique(vb.begin(), vb.end()), vb.end());
		g.AP();
		gg.BCC();
		if (x[a] && x[b]) {
			for (int i = 0; i < cnt; i++) {
				if (edz[i].size() < 2) continue;
				// for (auto it : edz[i]) cout << it << " ";
				// cout << "\n";
				int rep = -1;
				if (edz[i].size() == 2) {
					if (edz[i][0] == a && edz[i][1] == b || edz[i][0] == b && edz[i][1] == a) continue;
					else if (edz[i][0] == a || edz[i][0] == b) rep = edz[i][1];
					else rep = edz[i][0];
				} else {
					if (edz[i][0] == a && edz[i][1] == b || edz[i][0] == b && edz[i][1] == a) rep = edz[i][2];
					else if (edz[i][0] == a || edz[i][0] == b) rep = edz[i][1];
					else rep = edz[i][0];
				}
				for (int j = 0; j < edz[i].size(); j++) {
					if (edz[i][j] == a || edz[i][j] == b) continue;
					unite(rep, edz[i][j]);
				}
			}
			// cout << "TES\n";
			// for (int i = 0; i < n; i++) {
			// 	if (i == p[i]) cout << sz[i] << " ";
			// 	else cout << "-1 ";
			// }
				// cout << "TES\n";
			map<int, int> mid;
			for (auto i : va) {
				for (auto j : vb) {
					if (f(i) == f(j)) mid[f(i)]++;
				}
			}
			for (auto i : va) {
				for (auto j : vb) {
					if (f(i) == f(j)) continue;
					if (vis[f(i)] && vis[f(j)]) continue;
					if (mid.count(f(i)) || mid.count(f(j))) continue;
					vis[f(i)] = vis[f(j)] = 1;
					ans += sz[f(i)] * sz[f(j)];
				}
			}
		} 
		cout << ans << "\n";
	}
	return 0;
}
