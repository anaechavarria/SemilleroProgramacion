vector <int> g[MAXN];      // La lista de adyacencia
int color[MAXN];           // El arreglo de visitados
enum {WHITE, GRAY, BLACK}; // WHITE = 1, GRAY = 2, BLACK = 3

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
   for (int u = 0; u < n; ++u)
     if (color[u] == WHITE) dfs(u);
}