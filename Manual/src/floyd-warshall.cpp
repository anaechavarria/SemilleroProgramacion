// Los nodos están numerados de 0 a n-1
for (int k = 0; k < n; ++k){
   for (int i = 0; i < n; ++i){
      for (int j = 0; j < n; ++j){
         d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
      }
   }
}
// Acá d[i][j] es la mínima distancia entre el nodo i y el j