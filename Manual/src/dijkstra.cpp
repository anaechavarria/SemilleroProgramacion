typedef pair <int, int> dist_node; // Datos para el heap (dist, nodo)
typedef pair <int, int> edge; // Dato para las arista (nodo, peso)
const int MAXN = 100005;      // El máximo número de nodos
const int INF = 1 << 30;      // Usar 1LL << 60 para long long
vector <edge> g[MAXN];        // g[u] = (v = nodo, w = peso)
int d[MAXN];    // d[u] La distancia más corta de s a u
int p[MAXN];    // p[u] El predecesor de u en el camino más corto

// La función recibe la fuente s y el número total de nodos n
void dijkstra(int s, int n){
   for (int i = 0; i <= n; ++i){
      d[i] = INF;  p[i] = -1;
   }
   priority_queue < dist_node, vector <dist_node>, 
                    greater<dist_node> > q;
   d[s] = 0;
   q.push(dist_node(0, s));
   while (!q.empty()){
      int dist = q.top().first;
      int cur = q.top().second;
      q.pop();
      if (dist > d[cur]) continue;
      for (int i = 0; i < g[cur].size(); ++i){
         int next = g[cur][i].first;
         int w_extra = g[cur][i].second;
         if (d[cur] + w_extra < d[next]){
            d[next] = d[cur] + w_extra;
            p[next] = cur;
            q.push(dist_node(d[next], next));
         }
      }
   }  
}

// La función que retorna los nodos del camino más corto de s a t
// Primero hay que correr dijktra desde s.
// Eliminar si no se necesita hallar el camino.
vector <int> find_path (int t){
   vector <int> path;
   int cur = t;
   while(cur != -1){
      path.push_back(cur);
      cur = p[cur];
   }
   reverse(path.begin(), path.end());
   return path;
}