const int MAXN = 66;
unsigned long long choose[MAXN+5][MAXN+5];

void binomial(int N){
    for (int n = 0; n <= N; ++n) choose[n][0] = choose[n][n] = 1;

    for (int n = 1; n <= N; ++n){
        for (int k = 1; k < n; ++k){
            choose[n][k] = choose[n-1][k-1] + choose[n-1][k];
        }
    }
}
