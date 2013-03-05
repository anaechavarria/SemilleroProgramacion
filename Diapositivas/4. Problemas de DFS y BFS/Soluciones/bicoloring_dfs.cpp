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

const int MAXN = 205;
vector <int> g[MAXN];
int color[MAXN];

bool dfs(int u, int paint){
	assert(color[u] == -1);
	color[u] = paint;
	for (int i = 0; i < g[u].size(); ++i){
		int v = g[u][i];
		bool possible;
		if (color[v] == -1) possible = dfs(v, 1 - paint);
		else possible = (color[v] == (1 - paint));
		if (!possible) return false;
	}
	return true;
}

int main(){
	int n, m;
	while (cin >> n){
		if (n == 0) break;
		for (int i = 0; i < n; ++i){
			g[i].clear();
			color[i] = -1;
		}
		cin >> m;
		for (int i = 0; i < m; ++i){
			int u, v;
			cin >> u >> v;
			g[u].push_back(v);
			g[v].push_back(u);
		}	
		if (dfs(0, 0)) puts("BICOLORABLE.");
		else puts("NOT BICOLORABLE.");
	}
    return 0;
}
