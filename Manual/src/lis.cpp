// Máximo tamaño del string
const int MAXN = 1005;
// dp[i] = la longitud de la máxima subsecuencia creciente que 
// termina en el caracter i (usándolo)
int dp[MAXN];

int lis(const string &s){
    int n = s.size();
    dp[0] = 1;
    for (int i = 1; i < n; i++){
        dp[i] = 1;
        for (int j = 0; j < i; j++){
            // Cambiar el < por <= si la secuencia tiene que ser
            // es estrictamente creciente
            if (s[j] <= s[i]) dp[i] = max(dp[i], dp[j] + 1);
        }
    }

    int best = 0;
    for (int i = 0; i < n; i++) best = max(best, dp[i]);
    return best;
}