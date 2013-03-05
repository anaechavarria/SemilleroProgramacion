using namespace std;
#include <algorithm>
#include <iostream>
#include <iterator>
#include <numeric>
#include <sstream>
#include <fstream>
#include <cassert>
#include <climits>
#include <cstdlib>
#include <cstring>
#include <string>
#include <cstdio>
#include <vector>
#include <cmath>
#include <queue>
#include <deque>
#include <stack>
#include <list>
#include <map>
#include <set>

#define foreach(x, v) for (typeof (v).begin() x=(v).begin(); x !=(v).end(); ++x)
#define For(i, a, b) for (int i=(a); i<(b); ++i)
#define D(x) cout << #x " is " << x << endl

const int MAXN = 100005;
vector <int> g[MAXN];
vector <int> grev[MAXN];
vector <int> topo_sort;
int scc[MAXN];
bool seen[MAXN];
int in[MAXN];

void dfs1(int u){
	seen[u] = true;
	for (int i = 0; i < g[u].size(); ++i){
		int v = g[u][i];
		if (!seen[v]) dfs1(v);
	}
	topo_sort.push_back(u);
}

void dfs2(int u, int comp){
	scc[u] = comp;
	for (int i = 0; i < grev[u].size(); ++i){
		int v = grev[u][i];
		if (scc[v] == -1) dfs2(v, comp);
	}
}



int main(){
	int cases; cin >> cases;
	while (cases--){
		int n, m; cin >> n >> m;
		for (int i = 0; i <= n; ++i){
			g[i].clear();
			grev[i].clear();
			topo_sort.clear();
			scc[i] = -1;
			seen[i] = false;
			in[i] = 0;
		}
		
		for (int i = 0; i < m; ++i){
			int u, v; cin >> u >> v;
			u--; v--;
			g[u].push_back(v);
			grev[v].push_back(u);
		}
		
		for (int i = 0; i < n; ++i){
			if (!seen[i]) dfs1(i);
		}
		
		reverse(topo_sort.begin(), topo_sort.end());
		assert(topo_sort.size() == n);
		int comp = 0;
		for (int i = 0; i < n; ++i){
			int u = topo_sort[i];
			if (scc[u] == -1) dfs2(u, comp++);
		}
		
		for (int u = 0; u < n; ++u){
			for (int i = 0; i < g[u].size(); ++i){
				int v = g[u][i];
				if (scc[u] != scc[v]) in[scc[v]]++;
			}
		}
		
		int count = 0;
		for (int u = 0; u < comp; ++u){
			if (in[u] == 0) count++;
		}
		
		cout << count << endl;
		
	}
    return 0;
}
