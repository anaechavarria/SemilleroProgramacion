const int MAXN = 105;
// Lista de adyacencia de la red residual
vector <int> g [MAXN];
// Capacidad de aristas de la red de flujos
int c [MAXN][MAXN];
// El flujo de cada arista
int f [MAXN][MAXN];
//El predecesor de cada nodo en el camino de aumentación de s a t
int prev [MAXN];

void connect (int i, int j, int cap){
    // Agregar SIEMPRE las dos aristas a g (red residual) así el
    // grafo sea dirigido. Esto es porque g representa la red 
    // residual que tiene aristas en los dos sentidos.
    g[i].push_back(j);
    g[j].push_back(i);
    c[i][j] += cap;    
    // Omitir esta línea si el grafo es dirigido
    c[j][i] += cap; 
}

// s = fuente, t = sumidero, n = número de nodos
int maxflow(int s, int t, int n){
    for (int i = 0; i <= n; i++){
        for (int j = 0; j <= n; j++){
            f[i][j] = 0;
        }
    }

    int flow = 0;
    while (true){
        for (int i = 0; i <= n; i++) prev[i] = -1;

        queue <int> q;
        q.push(s);
        prev[s] = -2;

        while (q.size() > 0){
            int u = q.front(); q.pop();
            if (u == t) break;
            for (int i = 0; i < g[u].size(); ++i){
                int v = g[u][i];
                if (prev[v] == -1 and c[u][v] - f[u][v] > 0){
                    q.push(v);
                    prev[v] = u;
                }
            }
        }
        if (prev[t] == -1) break;

        int extra = 1 << 30;
        int end = t;
        while (end != s){
            int start = prev[end];
            extra = min(extra, c[start][end] - f[start][end]);
            end = start;
        }

        end = t;
        while (end != s){
            int start = prev[end];
            f[start][end] += extra;
            f[end][start] = -f[start][end];
            end = start;
        }
        
        flow += extra;
    }

    return flow;
}