const int MAXN = 105;
const int INF = 1 << 30;  // Para long long INF = 1LL << 60
typedef pair <int, int> edge; // Modificar según el problema
vector <edge> g[MAXN]; // g[u] = (v = nodo, w = peso)
int d[MAXN];           // d[u] = distancia más corta de s a u

// Retorna verdadero si el grafo tiene un ciclo de peso negativo
// alcanzable desde s y falso si no es así.
// Al finalizar el algoritmo, si no hubo ciclo de peso negativo,
// la distancia más corta entre s y u está almacenada en d[u]
bool bellman_ford(int s, int n){ // s = fuente, n = número nodos
   for (int u = 0; u <= n; ++u) d[u] = INF;
   d[s] = 0;

   for (int i = 1; i <= n - 1; ++i){
      for (int u = 0; u < n; ++u){
         for (int k = 0; k < g[u].size(); ++k){
            int v = g[u][k].first;
            int w = g[u][k].second;
            d[v] = min(d[v], d[u] + w);
         }
      }
   }

   for (int u = 0; u < n; ++u){
      for (int k = 0; k < g[u].size(); ++k){
         int v = g[u][k].first;
         int w = g[u][k].second;
         if (d[v] > d[u] + w) return true;
      }
   }
   return false;
}