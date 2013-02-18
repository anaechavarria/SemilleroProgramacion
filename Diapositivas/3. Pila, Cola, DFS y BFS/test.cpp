#include <iostream>
#include <vector>
using namespace std;

#define D(x) cout << #x " = " << (x) << endl

const int MAXN = 105;

vector <int> g[MAXN];
int color[MAXN];
enum {WHITE, GRAY, BLACK};

void dfs(int u){
   color[u] = GRAY;   // Marcar el nodo como semi-visitado
   for (int i = 0; i < g[u].size(); ++i){
      int v = g[u][i];
      if (color[v] == WHITE) dfs(v);  // Visitar mis vecinos
   }
   color[u] = BLACK;  // Marcar el nodo como visitado
}

void call_dfs(int n){
   // Marcar los nodos como no visitados
   for (int u = 0; u < n; ++u) color[u] = WHITE;
   // Llamar la funcion DFS con los nodos no visitados
   for (int u = 0; u < n; ++u){
      if (color[u] == WHITE) dfs(u);
   }
}

int main(){
   return 0;
}