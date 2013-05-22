// Máximo tamaño de los strings
const int MAXN = 1005;
// dp[i][j] lcs de los substrings s[0..i-1] y t[0..j-1]
int dp[MAXN][MAXN];

int lcs(const string &s, const string &t){
    int n = s.size(), m = t.size();
    
    for (int j = 0; j <= m; ++j) dp[0][j] = 0;
    for (int i = 0; i <= n; ++i) dp[i][0] = 0;

    for (int i = 1; i <= n; ++i){
        for (int j = 1; j <= m; ++j){
            dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            if (s[i-1] == t[j-1]){
                dp[i][j] = max(dp[i][j], dp[i-1][j-1] + 1);
            }
        }
    }
    return dp[n][m];
}