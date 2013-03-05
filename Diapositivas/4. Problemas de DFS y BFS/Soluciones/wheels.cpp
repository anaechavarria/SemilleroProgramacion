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

const int MAXN = 10005;
vector <int> g[MAXN];
vector <int> forbidden;
int d[MAXN];

int get_num(){
	int ans = 0;
	for (int i = 0; i < 4; ++i){
		int d; cin >> d;
		ans = ans * 10 + d;
	}
	return ans;
}

int find_neighbour(int u, int d, int dir){
	vector <int> a(4);
	for (int i = 0; i < 4; ++i){
		a[i] = u % 10;
		u /= 10;
	}
	a[d] = (a[d] + 10 + dir) % 10;
	
	int ans = 0;
	for (int i = 3; i >= 0; --i){
		ans *= 10; ans += a[i];
	}
	return ans;
}

void bfs(int s){
	for (int i = 0; i < MAXN; ++i) d[i] = -1;
	queue <int> q;
	q.push(s);
	d[s] = 0;
	while (q.size() > 0){
		int cur = q.front(); q.pop();
		for (int i = 0; i < g[cur].size(); ++i){
			int next = g[cur][i];
			bool found = binary_search(forbidden.begin(), forbidden.end(), next);
			if (!found and d[next] == -1){
				d[next] = d[cur] + 1;
				q.push(next);
			}
		}
	}
}


int main(){
	for (int i = 0; i < MAXN; ++i){
		for (int d = 0; d < 4; ++d){
			g[i].push_back(find_neighbour(i, d, -1));
			g[i].push_back(find_neighbour(i, d, +1));
		}
	}
		
	int cases; cin >> cases;
	while (cases--){
		forbidden.clear();
		
		int s = get_num();
		int t = get_num();
		
		int n; cin >> n;
		while (n--) forbidden.push_back(get_num());
		sort(forbidden.begin(), forbidden.end());
		
		bfs(s);
		cout << d[t] << endl;
	}
    return 0;
}
