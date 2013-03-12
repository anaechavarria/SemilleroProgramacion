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

int type(char c){
   if (c == '(' or c == ')') return 1;
   return 2;
}

int main(){
   int cases;
   cin >> cases;
   string endline;
   getline(cin, endline);
   while (cases--){
      string s;
      getline(cin, s);
      int n = s.size();
      bool balanced = true;
      stack <char> p;
      for (int i = 0; i < n and balanced; ++i){
         // Si es uno que abre insertarlo al stack
         if (s[i] == '(' or s[i] == '['){
            p.push(s[i]);
         }else{ // Es uno que cierra
            if (p.empty()){ // Si no hay elementos en el stack
               balanced = false;
               break;
            }
            // Veificar que sean del mismo tipo
            if (type(s[i]) == type(p.top())){
               p.pop();
            }else{
               balanced = false;
               break;
            }
         }
      }
      // Verificar que no haya elementos en el stack
      if (!p.empty()) balanced = false;
      
      if (balanced) puts("Yes");
      else puts("No");
      
   }
    return 0;
}
