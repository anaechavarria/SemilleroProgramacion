struct edge{
   int start, end, weight;
   
   edge(int u, int v, int w){
      start = u; end = v; weight = w;
   }
   bool operator < (const edge &other) const{
      return weight < other.weight;
   }
}; 

const int MAXN = 100005;
vector <edge> edges; // Lista de aristas y no lista de adyacencia
int p[MAXN];         // El padre de cada conjunto (union-find)

// Incluir las operaciones de Union-Find (initialize, find, join)

int kruskal(int n){    
    initialize(n);
    sort(edges.begin(), edges.end());

    int total = 0;
    for (int i = 0; i < edges.size(); ++i){
        int u = edges[i].start;
        int v = edges[i].end;
        int w = edges[i].weight;
        if (find(u) != find(v)){ 
            total += w;
            join(u, v);
        }
    }
    return total;
}