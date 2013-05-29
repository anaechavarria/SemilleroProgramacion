const int MAXN = 1000000;
bool sieve[MAXN + 5];
vector <int> primes;

void build_sieve(){
    memset(sieve, false, sizeof(sieve));
    sieve[0] = sieve[1] = true;

    for (int i = 2; i * i <= MAXN; i ++){
        if (!sieve[i]){
            for (int j = i * i; j <= MAXN; j += i){
                sieve[j] = true;
            }
        }
    }
    for (int i = 2; i <= MAXN; ++i){
        if (!sieve[i]) primes.push_back(i);
    }
}