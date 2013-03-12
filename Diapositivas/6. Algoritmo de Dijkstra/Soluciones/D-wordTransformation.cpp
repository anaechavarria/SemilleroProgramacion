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

map <string, int> m;
string dic [MAXN];
vector <int> g[MAXN];
int d[MAXN];

int bfs(int s, int t){
   for (int i = 0; i < MAXN; ++i) d[i] = -1;
   queue <int> q;
   q.push(s);
   d[s] = 0;
   while (q.size() > 0){
      int cur = q.front(); q.pop();
      if (cur == t) break;
      for (int i = 0; i < g[cur].size(); ++i){
         int next = g[cur][i];
         if (d[next] == -1){
            q.push(next);
            d[next] = d[cur] + 1;
         }
      }
   }
   return d[t];
}

int main(){
   int cases; cin >> cases;
   while (cases--){
      m.clear();
      for (int i = 0; i < MAXN; ++i) g[i].clear();
      
      int total_words = 0;
      string word;
      while (cin >> word){
         if (word == "*") break;
         dic[total_words] = word;
         m[word] = total_words;
         total_words++;
      }
      
      for (int i = 0; i < total_words; ++i){
         string s1 = dic[i];
         for (int j = i+1; j < total_words; ++j){
            string s2 = dic[j];
            if (s1.size() != s2.size()) continue;
            int diff = 0;
            for (int k = 0; k < s1.size(); ++k){
               if (s1[k] != s2[k]) diff++;
            }
            if (diff == 1){
               g[m[s1]].push_back(m[s2]);
               g[m[s2]].push_back(m[s1]);
            }
         }
      }
      
      string line;
      getline(cin, line);
      while (getline(cin, line)){
         if (line == "") break;
         stringstream ss(line);
         string s1, s2;
         ss >> s1 >> s2;
         int s = m[s1];
         int t = m[s2];
         cout << s1 << " " << s2 << " " << bfs(s, t) << endl;
      }
      if (cases != 0) cout << endl;
   }
    return 0;
}
