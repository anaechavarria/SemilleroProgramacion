vector <int> g[MAXN];    // La lista de adyacencia
bool seen[MAXN];         // El arreglo de visitados para el dfs
vector <int> topo_sort;  // El vector del ordemamiento

void dfs(int u){
   seen[u] = true;
   for (int i = 0; i < g[u].size(); ++i){
      int v = g[u][i];
      if (!seen[v]) dfs(v);
   }
   topo_sort.push_back(u); // Agregar el nodo al ordenamiento
}
void topological(int n){   // n = número de nodos
   topo_sort.clear();
   for (int i = 0; i < n; ++i) seen[i] = false;
   for (int i = 0; i < n; ++i) if (!seen[i]) dfs(i);
   reverse(topo_sort.begin(), topo_sort.end());
}