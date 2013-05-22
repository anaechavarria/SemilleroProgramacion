const int MAXN = 100005;
int p[MAXN];// El padre del conjunto al que pertenece cada nodo

// Inicializar cada conjunto como unitario
void initialize(int n){
   for (int i = 0; i <= n; ++i) p[i] = i; 
}

// Encontrar el padre del conjunto al que pertenece u
int find(int u){
    if (p[u] == u) return u;
    return p[u] = find(p[u]);
}

// Unir los conjunto a los que pertenecen u y v
void join(int u, int v){
     int a = find(u);
     int b = find(v);
     if (a == b) return;
     p[a] = b;  
}