using namespace std;
#include <algorithm>
#include <iostream>
#include <iterator>
#include <numeric>
#include <sstream>
#include <fstream>
#include <cassert>
#include <climits>
#include <cstdlib>
#include <cstring>
#include <string>
#include <cstdio>
#include <vector>
#include <cmath>
#include <queue>
#include <stack>
#include <list>
#include <map>
#include <set>

// Template para recorrer contenedores usando iteradores
#define foreach(x, v) for (typeof (v).begin() x=(v).begin(); \
                            x !=(v).end(); ++x)
// Template que imprime valores de variables para depurar
#define D(x) cout << #x " = " << (x) << endl

// Función para comparar dos dobles sin problemas de presición
// Retorna -1 si x < y, 0 si x = y, 1 si x > y
const double EPS = 1e-9;
int cmp (double x, double y, double tol = EPS){
    return (x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1;
}


int main() {
    // Entrada y salida desde / hacia archivo
    // Eliminar si la entrada es estándar
    // Cambiar in.txt / out.txt por los archivos de entrada/salida
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    
    return 0;
}
