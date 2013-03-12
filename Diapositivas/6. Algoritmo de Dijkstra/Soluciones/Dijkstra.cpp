#include <vector>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;


typedef pair <int, int> dist_node; // Tipo de dato para el heap
typedef pair <int, int> edge;     // Arista = pareja de enteros
const int MAXN = 100005;          // El maximo numero de nodos
const int INF = 1 << 30;          // Infinito = 2^30
vector <edge> g[MAXN];            // g[u] = (v, w)
int d[MAXN];    // d[u] La distancia mas corta de s a u
int p[MAXN];    // p[u] El predecesor de u en el camino mas corto

// La función recibe la fuente s y el numero total de nodos n
void dijkstra(int s, int n){
   // Limpiar los valores de las variables
   for (int i = 0; i <= n; ++i){
      d[i] = INF;
      p[i] = -1;
   }
   // Construir la cola de prioridades con la funcion mayor
   priority_queue < dist_node, vector <dist_node>, greater<dist_node> > q;
   d[s] = 0;

   // El comparador del tipo pair ordena primero por la primea componente y si hay empate ordena por la segunda
   // Se ingresa primero la distancia para que el comparador ordene por la distacia y se extraiga el valor de menor distancia
   q.push(dist_node(0, s));
   while (!q.empty()){
      int dist = q.top().first;
      int cur = q.top().second;
      q.pop();
      // Si ya llegue al nodo con menor distancia no se vuelve a procesar
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

int main(){
   int n, m;
   cin >> n >> m;
   for (int i = 0; i < m; ++i){
      int u, v, w;
      cin >> u >> v >> w;
      g[u].push_back(edge(v, w));
   }
   for (int u = 0; u < n; ++u){
      for (int i = 0; i < g[u].size(); ++i){
         int v = g[u][i].first;
         int w = g[u][i].second;
         printf("Edge from %d to %d with weight %d\n", u, v, w);
      }
   }
   return 0;
}

