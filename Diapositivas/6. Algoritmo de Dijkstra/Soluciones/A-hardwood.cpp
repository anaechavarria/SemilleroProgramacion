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
#include <deque>
#include <stack>
#include <list>
#include <map>
#include <set>

#define foreach(x, v) for (typeof (v).begin() x=(v).begin(); x !=(v).end(); ++x)
#define For(i, a, b) for (int i=(a); i<(b); ++i)
#define D(x) cout << #x " is " << x << endl

map <string, int> m;   // Mapa con las frecuencias

int main(){
   int cases;
   cin >> cases;
   string tmp;
   getline(cin, tmp); // Leer el final de la linea de los casos
   getline(cin, tmp); // Leer la siguiente linea en blanco
   while (cases--){
      m.clear();     // Limpiar los valores del mapa
      
      string line;
      int total = 0; // El numero total de arboles
      while (getline(cin, line)){
         if (line == "") break; // Fin del caso de prueba
         m[line]++;  // Si no existe el valor, lo crea en 0
         total++;  
      }
      
      map <string, int> :: iterator it;
      for (it = m.begin(); it != m.end(); it++){
         double percent = 100.0 * it->second / total;
         printf("%s %.4lf\n", (it->first).c_str(), percent);
      }
      if (cases != 0) cout << endl; // Linea en blanco entre casos
   }
   return 0;
}
