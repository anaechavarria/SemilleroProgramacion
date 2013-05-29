void divisors(int n){
    int i;
    for (i = 1; i * i < n; ++i){
        if (n % i == 0) printf("%d\n%d\n", i, n/i);
    }
    // Si existe, imprimir su raiz cuadrada una sola vez
    if (i * i == n) printf("%d\n", i);
}