int bigmod(int b, int p, int m){
    if (p == 0) return 1;
    if (p % 2 == 0){
        int mid = bigmod(b, p/2, m);
        return (1LL * mid * mid) % m;
    }else{
        int mid = bigmod(b, p-1, m);
        return (1LL * mid * b) % m;
    }
}