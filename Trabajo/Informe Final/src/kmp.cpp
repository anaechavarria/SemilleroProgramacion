bool kmp(const string &needle, const string &haystack){
   int m = needle.size();
   vector<int> border(m);
   border[0] = 0;

   for (int i = 1; i < m; ++i) {
      border[i] = border[i - 1];
      while (border[i] > 0 and needle[i] != needle[border[i]])
         border[i] = border[border[i] - 1];
      if (needle[i] == needle[border[i]]) border[i]++;
   }

   int n = haystack.size();
   int seen = 0;
   for (int i = 0; i < n; ++i){
      while (seen > 0 and haystack[i] != needle[seen])
         seen = border[seen - 1];
      if (haystack[i] == needle[seen]) seen++;
      if (seen == m) return true; // Ocurre entre [i - m + 1, i]
   }
   return false;
}